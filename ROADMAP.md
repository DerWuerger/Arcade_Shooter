# ROADMAP.md

Diese Roadmap beschreibt die geplanten technischen Meilensteine fuer das Projekt On-Rails Arcade Shooter.

Sie ist mit ARCHITECTURE_CHARTER.md abzugleichen. Keine Roadmap-Entscheidung darf die Architecture Charter umgehen. Versionen gelten erst nach ausdruecklicher Freigabe durch Jens Würger als abgeschlossen.

---

## Version 0.0.1 – Core Rail Prototype

Ziel:

Minimal funktionierender technischer On-Rails-Prototyp.

Geplanter Umfang:

* Unreal-Projektbasis
* grundlegende Projektstruktur
* Rail System
* Spline Path
* automatische Kamerafahrt
* Combat Stop
* Weiterfahrt nach abgeschlossenem Combat Stop
* Mouse Aim
* Fire Input
* einfacher Hit Test
* einfache Platzhaltergegner
* Debug-Ausgaben
* Core-Strukturen bereits so planen, dass Player Ownership nicht hart auf einen Spieler beschränkt wird

Nicht enthalten:

* finales Character Design
* Gore
* fertiges Difficulty-Menü
* Lightgun-Support
* finales HUD
* Boss
* komplettes Pickup-System
* finaler Two-Player Gameplay Mode

Status nach technischer Fertigstellung:

`Awaiting Approval by Jens Würger`

Version 0.0.1 gilt erst nach ausdrücklicher Freigabe als abgeschlossen.

---

## Version 0.0.2 – Combat Foundation

* Weapon Base
* Fire
* Magazine
* Reserve Ammo
* Reload
* Hit Detection
* Hit Zones
* Health
* Enemy Defeat State
* Score-Basis
* mehrere Gegner pro Combat Stop

---

## Version 0.0.3 – Enemy Architecture

* Enemy Base
* Enemy Archetypes
* Enemy Behaviour
* Spawn Points
* Enemy Waves
* Reaction Time
* Attack Timing
* datengetriebene Basiswerte

---

## Version 0.0.4 – Modular Character Visuals

* Shared Skeleton
* Shared Animations
* Character Visual Abstraction
* Comic Stickman als erster Style
* Visual Style ohne Gameplay-Änderung austauschbar
* Vorbereitung für 90s Arcade Anime

---

## Version 0.0.5 – Modular HUD Theme System

* HUD Theme Abstraction
* Fonts
* Score Theme
* Ammo Theme
* Reload Theme
* Health/Energy Theme
* Crosshair Theme
* UI Animation Theme
* UI Sound Theme
* Vorbereitung für unterschiedliche 1P-/2P-HUD-Layouts

---

## Version 0.0.6 – Presentation Modes

* Family Mode
* Arcade Mode
* Gore Mode
* einheitliche Damage Events
* Presentation ausschließlich als Darstellungsebene

---

## Version 0.0.7 – Difficulty System

* Easy
* Normal
* Hard
* optional Arcade
* Enemy Count
* Reaction Time
* Accuracy
* Health Modifier
* Spawn Pressure
* Special Enemy Frequency
* Boss Scaling Vorbereitung
* Difficulty Data Assets

---

## Version 0.0.8 – Item / Pickup Foundation

* Item Base
* Ammo Pickup
* Health / Energy Pickup
* Score Pickup
* playerbezogene Pickup-Zuordnung
* Item Data Assets
* Style-unabhängige Item-Funktion
* Vorbereitung auf Weapon Pickups und Power-Ups

---

## Version 0.0.9 – Local Two Player Foundation

* Player 2 aktivierbar
* getrennte Aim Positions
* zwei Crosshairs
* getrennte Scores
* getrennte Weapon-/Ammo-States
* Input Device Assignment
* gemeinsame Rail-Kamera
* 2P HUD Layout
* Player Ownership bei Hits und Items

---

## Version 0.0.10 – Boss Foundation

* Boss Base
* Boss Configuration
* Boss Health
* Weak Points
* mehrere Phasen
* datengetriebene Phase Transitions
* Boss HUD Data
* Difficulty Scaling
* Style-unabhängige Boss Visuals

Ein echter Boss muss noch nicht zwingend Bestandteil des ersten finalen Levels sein.

---

## Version 0.0.11 – Arcade Game Loop

* Start
* Level Begin
* Rail Sections
* Combat Stops
* Score
* Accuracy
* Combo-Basis
* Lives / Continues
* Level Complete
* Result Screen

---

## Version 0.0.12 – Level 1

Vorläufiges Szenario:

`Industrial / Warehouse / Docks`

Geplant:

* vollständiger Rail Path
* mehrere Combat Stops
* Enemy Waves
* unterschiedliche Spawn-Situationen
* Pickups
* mindestens ein Special Enemy
* Civilians / Non-Targets
* Level Ending

---

## Version 0.0.13 – Input Expansion

* Mouse
* Controller
* abstraktes Aim Interface
* Fire Interface
* Reload Interface
* saubere Player/Input-Zuordnung
* Lightgun-Vorbereitung

---

## Version 0.1.0 – First Playable Arcade Release Candidate

Ziel:

Erster vollständiger intern spielbarer Release Candidate.

Geplant:

* vollständiges Level
* Comic Stickman Style
* mehrere Enemy Archetypes
* Difficulty Selection
* Family / Arcade / Gore
* Score
* Accuracy
* Reload
* Lives / Continues
* Item System
* 1–2 Player Support
* Mouse / Controller
* modulares HUD
* modulare Grundlage für 90s Arcade Anime
* Boss-System technisch vorbereitet

Wichtig:

`0.1.0` gilt nicht automatisch als Release.

Nach technischer Fertigstellung:

`0.1.0 Release Candidate – Awaiting Approval by Jens Würger`

Erst nach ausdrücklicher Freigabe darf der Status auf Released / Completed gesetzt werden.

---

## Future / Post-0.1

Noch keiner festen Version zuordnen:

* 90s Arcade Anime Visual Style
* weitere Visual Styles
* weitere HUD Themes
* echte Lightgun-Unterstützung
* Wiimote / DolphinBar
* mehrere Waffen
* mehr Power-Ups
* mehr Items
* mehrere Level
* zusätzliche Bosses
* Character Style Selection
* HUD Theme Selection
* Audio Theme Selection
* erweiterte Zwei-Spieler-Regeln
* Highscores
* lokale Bestenlisten
* Arcade Cabinet UI
* weitere Difficulty Modes

---
