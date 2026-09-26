# Arcade_Shooter

`Arcade_Shooter` is structured as a modular Unreal Engine 5 on-rails arcade shooter foundation.

## Core design rules

- Keep **gameplay logic** in reusable C++ core systems.
- Keep **visuals, UI, and presentation** in Blueprint/content layers.
- Keep balance and progression in **data-only configuration** so tuning does not require code rewrites.
- Support local **1–2 player co-op** now and **future lightgun input** through input profile mapping.

## Module boundaries

- **Core Gameplay (C++)**
  - Player state, weapons runtime, enemy runtime, boss runtime, pickups runtime, progression/economy runtime.
  - No direct HUD/theme/mesh/material dependencies.
- **Presentation (Blueprint + Content)**
  - Character meshes/material styles, VFX/SFX, HUD theme widgets, camera polish.
  - Subscribes to core gameplay state/events.
- **Balancing/Data**
  - Data assets/tables for weapon stats, enemy waves, boss phases, pickups, difficulty scaling, progression, and economy.
  - Swappable without touching core runtime logic.

## Data-driven tuning

The repository includes a single configuration template at:

- `Config/ArcadeShooter/gameplay_config.json`

This file defines structured data blocks for:

- `input_profiles`
- `character_styles`
- `hud_themes`
- `difficulty_presets`
- `weapons`
- `enemies`
- `bosses`
- `pickups`
- `progression`
- `economy`

Use this as the canonical contract when wiring UE5 DataAssets/DataTables and Blueprint-level presentation.
