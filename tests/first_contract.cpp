#include "../src/FactoryLine.hpp"

#include <cassert>
#include <iostream>

int main() {
    using orbital_foundry::FFactoryLine;
    FFactoryLine line;
    FFactoryLine replay;
    int ticks = 0;
    while (!line.Complete() && ticks < 100) {
        line.Tick();
        replay.Tick();
        ++ticks;
        assert(line.Shipped() == replay.Shipped());
        assert(line.MinedOre() == line.AccountedOre());
    }
    assert(line.Complete());
    assert(line.Shipped() == FFactoryLine::Target);
    line.Tick();
    assert(line.Shipped() == FFactoryLine::Target);

    FFactoryLine blocked;
    for (int i = 0; i < 40; ++i) {
        blocked.Tick(false);
        assert(blocked.Shipped() == 0);
        assert(blocked.MinedOre() == blocked.AccountedOre());
    }
    const int staged = blocked.MinedOre();
    blocked.Tick(false);
    assert(staged > 0 && blocked.MinedOre() == staged);
    for (int i = 0; i < 100 && !blocked.Complete(); ++i) {
        blocked.Tick();
        assert(blocked.MinedOre() == blocked.AccountedOre());
    }
    assert(blocked.Complete());

    std::cout << "First contract: " << line.Shipped()
              << " alloy plates delivered in " << ticks << " ticks.\n"
              << "Determinism, cargo stall, recovery and material accounting passed.\n";
}
