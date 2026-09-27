# Arcade_Shooter

Arcade_Shooter is an Unreal Engine C++ project.

## Current Version

- Version: 0.0.2
- Name: Player & Camera Foundation
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

## Player & Camera Foundation

Version 0.0.2 establishes the first player pawn and rail-following camera foundation.

Included C++ pawn functionality:

- `AArcadeRailPlayerPawn`
  - derives from `APawn`
  - owns a `SceneRoot`
  - owns a `CameraComponent`
  - exposes editable `RailPath`
  - exposes editable `MoveSpeed`
  - moves automatically along the assigned rail
  - applies rail position and base rotation
  - prevents unwanted camera roll
  - stops at the spline end
  - does not loop
  - safely remains idle if no rail is assigned

Included look functionality:

- free look relative to the rail base direction
- mouse yaw and pitch
- gamepad look implementation
- yaw limit
- pitch-up limit
- pitch-down limit
- movement and look direction kept logically separate

Default values:

- `MoveSpeed = 300.0f`
- `MaxLookYaw = 60.0f`
- `MaxLookPitchUp = 35.0f`
- `MaxLookPitchDown = 35.0f`
- `MouseLookSensitivity = 0.25f`
- `GamepadLookRate = 120.0f`
- `GamepadLookDeadZone = 0.15f`

## Validation

- Build successful
- Unreal Editor recognizes the C++ actor and pawn classes
- `ArcadeRailPath` can be placed in the level
- Spline points can be edited in the viewport
- `ArcadeRailMover` can be placed in the level
- `AArcadeRailPlayerPawn` is available in the Unreal Editor
- `RailPath` can be assigned in the Details panel
- `MoveSpeed` can be edited in the Details panel
- Curved test rail with 5 spline points validated
- Left and right rail curves validated
- Stable rail rotation confirmed
- No visible rotation jumps
- No camera roll
- No visible jitter
- Mouse yaw and pitch validated
- Yaw and pitch clamps validated
- Mouse look during rail curves validated
- Look does not affect rail movement
- Stop at the spline end confirmed

Known note: the installed MSVC version is newer than the Unreal Engine preferred toolchain version. The build still succeeds.

Gamepad note: Gamepad input implemented; physical controller validation pending.
