# Orbital Foundry

A small factory-automation game set on an asteroid mining outpost. The first contract is to turn raw ore into 12 alloy plates and deliver them to a cargo pad.

## Current prototype

- Open `index.html` in a browser to inspect the layout. This preview is not wired to the simulation.
- The [C++ production line](src/FactoryLine.hpp) runs a fixed drill → belt → smelter → belt → cargo chain. A smelter turns two ore into one plate, and a blocked cargo pad eventually stops the drill instead of deleting items.
- The [smoke test](tests/first_contract.cpp) checks delivery, deterministic replay, cargo blocking and recovery, and material accounting.

From the repository root, with a C++17 compiler:

```sh
c++ -std=c++17 -Wall -Wextra -pedantic tests/first_contract.cpp -o first_contract
./first_contract
```

## Next milestone: first playable browser build

1. Move the fixed production rules into the browser prototype and show inventory on each machine.
2. Let the player place or remove the two belts on the starter grid.
3. Show working, empty and blocked states. Add a reset button and a win message at 12 plates.

Out of scope for this milestone: power, procedural terrain, branching belts and multiple resources. See [DESIGN.md](DESIGN.md) for the rules and [starter-layout.json](starter-layout.json) for the sample board.
