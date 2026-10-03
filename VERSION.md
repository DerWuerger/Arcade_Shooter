# Current Version

Version: 0.0.3

Name: Aiming & Crosshair

Status: Completed and published

Approval Status:
Approved / Released

Approved By:
Jens Wuerger

Project Approval Authority:
Jens Wuerger

Current Milestone:
0.0.3 - Aiming & Crosshair

Completed Functionality:

- `AArcadeRailPath`
- Editable rail splines
- `AArcadeRailMover`
- `AArcadeRailPlayerPawn`
- Player and camera foundation
- Rail-following player pawn movement
- Rail-relative camera look
- Normalized screen-space aim state
- Mouse aim input for crosshair movement
- Gamepad aim input for crosshair movement
- Technical C++ crosshair drawn by the project HUD
- Aim bounds / clamps
- Screen pixel aim position API
- World ray aim API
- Required GameMode, PlayerController and HUD wiring
- Camera look remains independent from crosshair aim
- Vertical gamepad aim direction corrected

Current Aim Defaults:

- `AimMinX = 0.05f`
- `AimMaxX = 0.95f`
- `AimMinY = 0.05f`
- `AimMaxY = 0.95f`
- `MouseAimSensitivity = 0.0025f`
- `GamepadAimSpeed = 0.75f`
- `GamepadAimDeadZone = 0.15f`

Validation Summary:

- Build successful
- PIE visual validation successful
- Mouse aim validated
- Crosshair visible and controllable
- Physical gamepad recognized
- Gamepad left/right aim validated
- Gamepad up/down aim validated after vertical direction fix
- Aim clamps validated
- Camera remains independent from crosshair aim
- No relevant runtime errors reported during manual validation

Known Notes:

- The installed MSVC version is newer than the Unreal Engine preferred toolchain version. The build still succeeds.
- `sky.launch_app` may report Unreal missing modules in this environment; directly opening the `.uproject` works.

Next Milestone:
0.0.4 - Weapon & Hit System

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
