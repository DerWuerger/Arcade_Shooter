# Version History

## 0.0.2 - Player & Camera Foundation

Status: Completed

Version 0.0.2 establishes the first player pawn and camera foundation for the on-rails arcade shooter loop.

Included functionality:

- `AArcadeRailPlayerPawn`
  - `APawn` player foundation
  - `SceneRoot`
  - `CameraComponent`
  - editable `RailPath` reference
  - editable `MoveSpeed`
  - automatic movement along an assigned `AArcadeRailPath`
  - rail position is applied to the pawn
  - rail base rotation is applied to the pawn
  - no unwanted camera roll
  - stops at the spline end
  - no loop behavior
  - safe handling when no rail is assigned
- Camera Look
  - free look relative to the rail base direction
  - mouse yaw
  - mouse pitch
  - gamepad look implemented
  - yaw limit
  - pitch-up limit
  - pitch-down limit
  - look direction and rail movement are logically separated

Default values:

- `MoveSpeed = 300.0f`
- `MaxLookYaw = 60.0f`
- `MaxLookPitchUp = 35.0f`
- `MaxLookPitchDown = 35.0f`
- `MouseLookSensitivity = 0.25f`
- `GamepadLookRate = 120.0f`
- `GamepadLookDeadZone = 0.15f`

Validation:

- Build successful
- `AArcadeRailPlayerPawn` available in the Unreal Editor
- `RailPath` assignable in the Details panel
- Curved test rail with 5 spline points validated
- Left curve successful
- Right curve successful
- Rail rotation stable
- No visible rotation jumps
- No camera roll
- No visible jitter
- Mouse yaw successful
- Left yaw clamp successful
- Right yaw clamp successful
- Pitch-up clamp successful
- Pitch-down clamp successful
- Mouse look during rail curves successful
- Look does not affect rail movement
- Stop at rail end successful

Known note: Gamepad input implemented; physical controller validation pending.

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
