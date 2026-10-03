# Roadmap

This roadmap describes the planned development path for `Arcade_Shooter` through `v0.1.0`.

The roadmap is flexible. If a system becomes larger or more complex during development, additional intermediate versions or internal development steps may be added.

Internal sub-steps such as `0.0.2-A`, `0.0.2-B`, or `0.0.2-C` may be used during development. They do not need to be published as separate Git releases.

Official Git tags are created only after the related main version has been fully implemented and validated.

## Completed

### 0.0.1 - Rail Foundation

Status: Completed and published

Included:

- `AArcadeRailPath`
- editable spline
- `AArcadeRailMover`
- movement along the assigned rail
- stop at the spline end
- successful PIE validation

### 0.0.2 - Player & Camera Foundation

Status: Completed and published

Included:

- `AArcadeRailPlayerPawn`
- player and camera foundation architecture
- camera follows rail movement
- stable rail base orientation without unwanted camera roll
- free look relative to the rail base direction
- mouse yaw and pitch
- gamepad look implemented
- yaw and pitch limits
- movement and look direction kept logically separated
- stop at the spline end

Note:

- Gamepad input implemented; physical controller validation pending.

## Planned

### 0.0.3 - Aiming & Crosshair

Status: In Progress

Goals:

- visible crosshair
- aim movement with mouse and controller
- defined aim/look bounds
- clean screen/world aiming foundation
- preparation for hit calculation

Current implementation direction:

- normalized screen-space aim position in `AArcadeRailPlayerPawn`
- mouse aim as the primary mouse input for crosshair movement
- gamepad aim through the right stick with deadzone and framerate-independent movement
- technical C++ crosshair drawn by the project HUD
- public aim API for normalized position, pixel position, and world ray preparation

### 0.0.4 - Weapon & Hit System

Goals:

- first weapon logic
- shooting
- hitscan/line trace
- hit detection
- fire rate
- basic reload structure
- no complex enemy AI yet

### 0.0.5 - Enemy Foundation

Goals:

- first basic enemy type
- health
- damage
- death
- simple state/animation structure
- spawn capability

### 0.0.6 - Combat Encounters

Goals:

- defined combat stops along the rail
- rail movement can stop for combat
- enemies can appear as part of encounters
- rail movement resumes after encounter completion
- trigger/encounter foundation system

### 0.0.7 - Arcade Game Loop

Goals:

- player health/lives
- score
- accuracy
- game over
- restart
- basic HUD displays

### 0.0.8 - Endless / Horde Mode

Goals:

- small playable map
- continuous arcade gameplay loop
- recurring or consecutive encounters
- increasing enemy waves or difficulty scaling
- focus on Endless/Horde mode instead of story mode

### 0.0.9 - Presentation & Polish

Goals:

- hit feedback
- simple VFX
- muzzle flash
- sounds
- camera effects
- UI polish
- balancing
- bugfixes

### 0.1.0 - First Playable

Goal:

A complete first playable arcade shooter loop.

The player should be able to:

- move along the rail
- aim
- shoot
- fight enemies
- complete combat stops
- have score and lives
- restart after game over
- experience a functional Endless/Horde loop

`0.1.0` is not a finished game and does not require a story mode.

## Future / Post-0.1.0

Not assigned to a fixed version yet:

- story mode
- additional levels
- advanced enemy AI
- boss encounters
- local two-player support
- additional weapons
- pickups and power-ups
- visual style selection
- HUD theme selection
- lightgun support
- Wiimote / DolphinBar support
- high score tables
