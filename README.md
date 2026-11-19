# Orbital Foundry

A small factory-automation game concept set on an asteroid mining outpost. The first goal is to turn raw ore into enough alloy plates to ship one cargo crate.

**Status:** Design and static prototype. The mockup is interactive only for machine inspection; belts, production and power are not simulated yet.

## First playable

1. Place a drill beside an ore deposit.
2. Connect the drill to a smelter and the smelter to a cargo pad.
3. Watch material move through the chain and diagnose a blocked output.
4. Deliver 12 alloy plates to complete the first contract.

Open `index.html` in a browser to inspect the starter layout. No dependencies or build step.

## Next steps

- [ ] Add one deterministic simulation tick and machine inventories.
- [ ] Connect the drill, smelter and cargo pad across a fixed grid.
- [ ] Show blocked, starved and working states on the board.
- [ ] Add the first contract and a reset button.

See [DESIGN.md](DESIGN.md) for the proposed rules and [starter-layout.json](starter-layout.json) for the sample board data. The design deliberately starts with one resource and one production chain before adding more factories, power or logistics.
