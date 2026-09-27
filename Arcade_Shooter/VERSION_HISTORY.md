# Version History

## 0.0.1 - Rail Foundation

Status: Completed

Version 0.0.1 establishes the first minimal on-rails foundation for the project.

Included functionality:

- `AArcadeRailPath`
  - `USplineComponent` as root component
  - placeable in the Unreal Editor
  - spline points editable in the viewport
  - spline can be extended
  - public spline access interface
- `AArcadeRailMover`
  - editable `RailPath` reference
  - editable `MoveSpeed`
  - automatic movement along the spline
  - position and rotation follow the spline
  - stops at the spline end
  - no loop behavior
  - safe handling when `RailPath` is missing

Validation:

- Build successful
- Unreal Editor recognizes both C++ actor classes
- `ArcadeRailPath` can be placed in the level
- Spline can be edited in the editor
- `ArcadeRailMover` can be placed in the level
- `RailPath` can be assigned in the Details panel
- `MoveSpeed` can be edited in the Details panel
- PIE test successful
- Movement along the spline confirmed
- Stop at the spline end confirmed
- Position and rotation updates implemented

Known note: the installed MSVC version is newer than the Unreal Engine preferred toolchain version. The build still succeeds.
