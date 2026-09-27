# Current Version

Version: 0.0.2

Name: Player & Camera Foundation

Status: Completed and published

Approval Status:
Released

Project Approval Authority:
Jens Wuerger

Current Milestone:
0.0.2 - Player & Camera Foundation

Completed Functionality:

- `AArcadeRailPath`
- Editable rail splines
- `AArcadeRailMover`
- `AArcadeRailPlayerPawn`
- `SceneRoot` and `CameraComponent` player pawn foundation
- Editable `RailPath` reference on the player pawn
- Editable `MoveSpeed`
- Automatic player pawn movement along an assigned rail
- Rail position and base rotation applied to the player pawn
- Camera look offset relative to the rail base direction
- Mouse yaw and pitch look
- Gamepad look input mappings and runtime handling
- Yaw and pitch limits
- Movement and look direction kept logically separate
- Stop at spline end
- No loop behavior
- Safe idle behavior when no rail is assigned

Current Player / Camera Defaults:

- `MoveSpeed = 300.0f`
- `MaxLookYaw = 60.0f`
- `MaxLookPitchUp = 35.0f`
- `MaxLookPitchDown = 35.0f`
- `MouseLookSensitivity = 0.25f`
- `GamepadLookRate = 120.0f`
- `GamepadLookDeadZone = 0.15f`

Validation Summary:

- Build successful
- `AArcadeRailPlayerPawn` available in the Unreal Editor
- `RailPath` assignable in the Details panel
- Curved temporary test rail with 5 spline points validated
- Left curve validated
- Right curve validated
- Stable rail rotation confirmed
- No visible rotation jumps
- No camera roll
- No visible jitter
- Mouse yaw validated
- Left and right yaw clamps validated
- Pitch-up and pitch-down clamps validated
- Mouse look during rail curves validated
- Look direction does not alter rail movement
- Stop at rail end confirmed

Known Notes:

- Gamepad input implemented; physical controller validation pending.
- The installed MSVC version is newer than the Unreal Engine preferred toolchain version. The build still succeeds.

Next Milestone:
0.0.3 - Aiming & Crosshair

---

## Update Rule

`VERSION.md` muss jederzeit den tatsaechlich erreichten und freigegebenen Projektstand widerspiegeln.

Regeln:

1. Die Versionsnummer orientiert sich an `ROADMAP.md`.
2. Technische Fertigstellung allein schliesst eine Version nicht ab.
3. Unfertige Features erhoehen die abgeschlossene Versionsnummer nicht.
4. Eine technisch fertige Version wird zunaechst als Release Candidate oder Awaiting Approval gefuehrt.
5. Eine Version gilt ausschliesslich nach ausdruecklicher Freigabe durch Jens Wuerger als abgeschlossen.
6. Commits, Merges oder erfolgreiche Tests ersetzen diese Freigabe nicht.
7. Ohne Freigabe darf VERSION.md eine Version nicht als Released, Final, Completed oder Approved fuehren.
8. Nach Freigabe darf der entsprechende Versionsstatus aktualisiert werden.

---

## Documentation Priority

Alle drei Dateien bilden gemeinsam die zentrale Projektdokumentation.

Prioritaet bei Konflikten:

```text
1. ARCHITECTURE_CHARTER.md
2. ausdrueckliche Entscheidung / Freigabe von Jens Wuerger
3. ROADMAP.md
4. VERSION.md
5. konkrete Implementierungsdetails
```

Codex darf die Architecture Charter nicht eigenmaechtig aufgrund einer Roadmap- oder Implementierungsentscheidung umgehen.
