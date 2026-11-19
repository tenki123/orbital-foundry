#pragma once

#include "FactoryTypes.hpp"

namespace orbital_foundry {

// Fixed teaching scenario: drill -> inbound belt -> smelter -> outbound belt -> cargo.
// One slot per belt. Process downstream first so nothing crosses two belts in a tick.
class FFactoryLine {
public:
    static constexpr int Target = 12;

    void Tick(bool cargoOpen = true) {
        if (Complete()) return;
        if (cargoOpen && output_.Occupied) {
            output_ = {};
            if (++shipped_ == Target) return;
        }
        if (!output_.Occupied && smelter_.PlateCount > 0) {
            output_ = {EItemId::AlloyPlate, 1.0f, true};
            --smelter_.PlateCount;
        }
        if (smelter_.PlateCount < FSmelterState::OutputCapacity &&
            smelter_.OreCount >= FSmelterState::OrePerPlate) {
            smelter_.OreCount -= FSmelterState::OrePerPlate;
            ++smelter_.PlateCount;
        }
        if (input_.Occupied && smelter_.OreCount < FSmelterState::OrePerPlate) {
            ++smelter_.OreCount;
            input_ = {};
        }
        if (!input_.Occupied) {
            input_ = {EItemId::Ore, 1.0f, true};
            ++mined_;
        }
    }

    int Shipped() const { return shipped_; }
    bool Complete() const { return shipped_ == Target; }

    // Useful for checking that ore has not been lost or duplicated during a stall.
    int MinedOre() const { return mined_; }
    int AccountedOre() const {
        return smelter_.OreCount + (input_.Occupied ? 1 : 0) +
               FSmelterState::OrePerPlate *
                   (smelter_.PlateCount + shipped_ + (output_.Occupied ? 1 : 0));
    }

private:
    FConveyorSlot input_;
    FConveyorSlot output_;
    FSmelterState smelter_;
    int shipped_{0};
    int mined_{0};
};

}  // namespace orbital_foundry
