# First playable design

The player inherits an empty cargo pad and a small ore deposit. The first shift is about getting one visible chain working, not optimizing a sprawling factory.

| Building | Proposed behavior |
| --- | --- |
| Drill | Places 1 ore in its output per tick if there is space |
| Belt | Transfers up to 1 item per tick to the next cell |
| Smelter | Consumes 2 ore to produce 1 plate when the output has space |
| Cargo pad | Counts incoming plates toward the 12-plate contract |

Keep the first simulation on a rectangular grid. Separate scene rendering from the tick so recipes can be tested without a browser. Define the tick order before adding branching belts. Don't model power, physics, procedural maps or multiple resources for this milestone.

## Acceptance checks

- An uninterrupted chain eventually registers all 12 plates.
- A full output cannot destroy items or double-count a shipment.
- Removing a belt interrupts delivery, and restoring it resumes delivery.
- Resetting the same board with the same inputs produces the same result.

These are planned checks, not implemented tests.
