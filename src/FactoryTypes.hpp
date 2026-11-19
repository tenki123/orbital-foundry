#pragma once

#include <cstdint>

namespace orbital_foundry {

// Identity for the two items in the first production chain.
enum class EItemId : std::uint8_t { Ore, AlloyPlate };

struct FConveyorSlot {
    EItemId ItemId{EItemId::Ore};
    float Distance{0.0f};  // Normalized position from 0 (entry) to 1 (exit).
    bool Occupied{false};  // ItemId is meaningful only when occupied.
};

struct FSmelterState {
    std::int32_t OreCount{0};
    std::int32_t PlateCount{0};
    static constexpr std::int32_t OrePerPlate{2};
    static constexpr std::int32_t OutputCapacity{1};
};

}  // namespace orbital_foundry
