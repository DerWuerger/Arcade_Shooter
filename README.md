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
- `planned_input_extensions` (future device support declarations, e.g. lightgun)
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

### Schema conventions (required)

- Every `id` value is unique within its section.
- `presentation_asset_path` / `widget_theme_path` values are Unreal asset reference paths and must resolve in content.
- `difficulty_presets`, `weapons`, `enemies`, `bosses`, and `pickups` are arrays; each entry has a unique `id` used for lookup/indexing.
- `progression.levels` is sorted by ascending `level` with non-decreasing `xp_required`.
- Boss `phases` are sorted by descending `trigger_health_percent` (1.0 to 0.0), with each next phase triggering when health drops to or below its threshold.
