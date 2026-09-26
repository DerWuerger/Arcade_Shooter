# Arcade_Shooter

`Arcade_Shooter` is a modular on-rails arcade shooter built with Unreal Engine 5.

The project is inspired by classic lightgun games and is designed from the ground up for flexible expansion, local co-op, interchangeable visual styles and data-driven gameplay systems.

## Core Goals

* On-rails arcade gameplay
* Unreal Engine 5
* C++ core systems + Blueprints for level design and visual iteration
* Local 1–2 player support
* Future lightgun support
* Mouse and controller support
* Modular character visual styles
* Modular HUD and UI themes
* Family / Arcade / Gore presentation modes
* Data-driven difficulty balancing
* Data-driven weapons, enemies, bosses and pickups
* Progression and economy system
* Unlockable cosmetics, weapons and styles

## Visual Styles

The first planned character style is:

* Comic Stickman

Additional styles are planned, including:

* 90s Arcade Anime
* future interchangeable visual themes

Gameplay logic must remain independent from the selected visual style.

## Modular Architecture

Major systems include:

* Rail System
* Player System
* Combat System
* Weapon System
* Enemy System
* Boss System
* Item / Pickup System
* Progression & Economy System
* Character Visual System
* UI / HUD Theme System
* Presentation System
* Difficulty System
* Input System
* Game Configuration

The project follows the principle:

> Gameplay provides data, state and events. Presentation systems decide how they are displayed and heard.

## Local Co-op

The architecture is designed for local 1–2 player gameplay using one shared rail camera.

Each player can have independent:

* aim position
* crosshair
* weapons
* ammo
* score
* health
* lives
* input device
* statistics
* pickups

Future setups may include two lightguns or Wiimote / DolphinBar input.

## Data-Driven Design

Balancing values should be configurable through Unreal Data Assets or Data Tables whenever practical.

This includes:

* enemy health
* reaction time
* accuracy
* spawn pressure
* weapon damage
* magazine size
* reload speed
* item values
* boss phases
* difficulty modifiers
* shop prices
* unlock requirements
* rewards

The goal is to make balancing possible without rewriting core gameplay code.

## Project Structure

Project root:

`E:\Projekt_Arcade_Shooter`

Unreal Engine project:

`E:\Projekt_Arcade_Shooter\Arcade_Shooter`

Important project documentation:

* `ARCHITECTURE_CHARTER.md`
* `ROADMAP.md`
* `VERSION.md`

## Current Status

**Version:** `0.0.0`

**Status:** Project Architecture / Pre-Prototype

**Next milestone:** `0.0.1 – Core Rail Prototype`

## Version Approval

A version is only considered completed or released after explicit approval by project lead:

**Jens Würger**

Technical completion, successful tests, Git commits, merges or prepared GitHub releases do not count as final approval.

Until approval, milestones remain in development, review or release-candidate status.

## Development Principle

> As modular as necessary, as simple as possible.

New features should extend existing systems instead of unnecessarily replacing or duplicating them.
