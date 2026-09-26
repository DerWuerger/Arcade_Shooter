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
- `ai_profiles`
- `attack_profiles`
- `enemies`
- `bosses`
- `pickups`
- `progression`
- `economy`

Use this as the canonical contract when wiring UE5 DataAssets/DataTables and Blueprint-level presentation.
Future lightgun support is added by introducing `input_profiles` entries with `device_type: "lightgun"` once runtime input handling is implemented.
The checked-in `gameplay_config.json` is a **template/sample payload**; `/Game/TEMPLATE/...` entries are placeholders and are expected to be replaced with resolving content paths in production.

### Schema conventions (required)

- Every `id` value is unique within its section.
- Current asset-path fields in this contract are `character_styles[].presentation_asset_path`, `hud_themes[].widget_theme_path`, and `pickups[].presentation_asset_path`; each uses Unreal object path format (`/Game/Folder/Asset.Asset`). Template/sample values can be placeholders, but production values must resolve in content. If new path-based fields are added, extend this list and apply the same rule.
- `input_profiles[].device_type` identifies control schemes (current: `gamepad`; future-extensible for `lightgun`).
- `input_profiles[].bindings` values use canonical Unreal key identifiers (example: `Gamepad_RightTrigger`) rather than platform-specific shorthand.
- Non-path references use `id` lookups into registry sections (for example `enemies[].ai_profile -> ai_profiles[].id`, `bosses[].phases[].attack_profile -> attack_profiles[].id`).
- `pickups` use typed `effects` payloads (for example `health_delta`, `credits_delta`) instead of a single polymorphic numeric field.
- `pickups[].type` is a category discriminator and must match allowed effect keys (`health -> health_delta`, `currency -> credits_delta`) to keep one consistent interpretation.
- `economy.weapon_upgrade_scalars` is a map keyed by upgrade level to keep tuning explicit and stable.
- Only `character_styles`, `hud_themes`, and `pickups` carry presentation asset-path fields in this contract by design; enemy/boss presentation remains in Blueprint/content composition outside this gameplay payload.
- `difficulty_presets`, `weapons`, `enemies`, `bosses`, and `pickups` are arrays; each entry has a unique `id` used for lookup/indexing.
- `progression.levels` is sorted by ascending `level` with non-decreasing `xp_required`.
- Boss `phases` are sorted by descending `trigger_health_percent` (1.0 to 0.0), with each next phase triggering when health drops to or below its threshold.
