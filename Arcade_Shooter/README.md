# Arcade_Shooter

Arcade_Shooter is an Unreal Engine C++ project.

## Current Version

- Version: 0.0.1
- Name: Rail Foundation
- Status: Completed

## Rail Foundation

Version 0.0.1 establishes the first minimal rail movement foundation.

Included C++ actors:

- `AArcadeRailPath`
  - uses a `USplineComponent` as the root component
  - can be placed in the Unreal Editor
  - exposes spline access through the public C++ interface
  - supports viewport editing and extension of spline points
- `AArcadeRailMover`
  - exposes an editable `RailPath` instance reference
  - exposes editable `MoveSpeed`
  - moves along the assigned spline during Tick
  - updates position and rotation from the spline in world space
  - stops at the end of the spline
  - does not loop
  - safely remains idle if no `RailPath` is assigned

## Validation

- Build successful
- Unreal Editor recognizes both C++ actor classes
- `ArcadeRailPath` can be placed in the level
- Spline points can be edited in the viewport
- `ArcadeRailMover` can be placed in the level
- `RailPath` can be assigned in the Details panel
- `MoveSpeed` can be edited in the Details panel
- PIE test successful
- Movement along the spline confirmed
- Stop at the spline end confirmed
- Position and rotation updates are implemented

Known note: the installed MSVC version is newer than the Unreal Engine preferred toolchain version. The build still succeeds.
