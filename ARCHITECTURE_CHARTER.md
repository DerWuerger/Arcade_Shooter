# ARCHITECTURE_CHARTER.md

Diese Datei ist die verbindliche technische Leitlinie des gesamten Projekts On-Rails Arcade Shooter.

Sie stellt sicher, dass das Projekt langfristig modular, datengetrieben, erweiterbar, gut balancierbar, visuell austauschbar, UI-seitig austauschbar, fuer mehrere Eingabegeraete geeignet, fuer lokalen Zwei-Spieler-Betrieb vorbereitet und GitHub-kompatibel dokumentiert bleibt.

---

# 1. Grundprinzip

Das gesamte Spiel wird modular aufgebaut.

Folgende Systeme müssen grundsätzlich voneinander getrennt bleiben:

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
* Audio Presentation
* Level Content
* Game Configuration

Kein System darf unnötig fest an einen bestimmten:

* Grafikstil
* Character Style
* HUD Theme
* Font
* Presentation Mode
* Difficulty Mode
* Spieler
* Weapon
* Boss
* Item
* Progression
* Economy
* Shop
* Unlock State
* Input Device
* Level

gekoppelt sein.

Zentraler Entwicklungs-Leitsatz:

> Das Spiel soll sich verändern und erweitern können, ohne dass seine grundlegenden Systeme neu gebaut werden müssen.

Zusätzlich gilt:

> Gameplay liefert Daten, Zustände und Events. Darstellungssysteme entscheiden, wie diese Informationen sichtbar und hörbar präsentiert werden.

Und:

> So modular wie nötig, so einfach wie möglich.

Unnötige Überarchitektur ist zu vermeiden.

---

# 2. Zentrale Systemarchitektur

Dokumentiere folgende Architektur:

```text
Game
├── Rail System
│   ├── Spline Path
│   ├── Camera Movement
│   ├── Rail Speed
│   ├── Combat Stops
│   └── Rail Events
│
├── Player System
│   ├── Player Base
│   ├── Player State
│   ├── Player 1
│   ├── Player 2
│   ├── Lives / Continues
│   ├── Health / Energy
│   ├── Score Ownership
│   └── Player Join / Leave
│
├── Combat System
│   ├── Aim
│   ├── Fire
│   ├── Reload
│   ├── Hit Detection
│   ├── Damage
│   ├── Score
│   └── Combo
│
├── Weapon System
│   ├── Weapon Base
│   ├── Primary Weapon
│   ├── Secondary Weapon
│   ├── Special Weapon
│   ├── Ammo Types
│   ├── Magazine
│   ├── Reserve Ammo
│   ├── Reload
│   └── Weapon Configuration
│
├── Enemy System
│   ├── Enemy Base
│   ├── Health
│   ├── Hit Zones
│   ├── Enemy Behaviour
│   ├── Enemy Archetypes
│   ├── Spawn Logic
│   └── Wave Logic
│
├── Boss System
│   ├── Boss Base
│   ├── Boss Configuration
│   ├── Boss Phases
│   ├── Attack Patterns
│   ├── Weak Points
│   ├── Phase Transitions
│   ├── Special States
│   ├── Add Spawning
│   └── Boss Events
│
├── Item / Pickup System
│   ├── Ammo Pickups
│   ├── Health / Energy Pickups
│   ├── Score Pickups
│   ├── Weapon Pickups
│   ├── Power-Ups
│   ├── Extra Lives / Continues
│   ├── Objective Items
│   └── Special Arcade Items
│
├── Progression & Economy System
│   ├── Player Progression
│   ├── Unlock System
│   ├── Arcade Currency
│   ├── Shop System
│   ├── Cosmetic Unlocks
│   ├── Weapon Unlocks
│   ├── Challenge Rewards
│   ├── Level Completion Rewards
│   ├── Difficulty Rewards
│   ├── Achievement Rewards
│   ├── Ownership Data
│   ├── Equipped Loadout
│   └── Save / Profile Integration
│
├── Character Visual System
│   ├── Shared Skeleton
│   ├── Shared Animations
│   ├── Stickman Visual
│   ├── 90s Arcade Anime Visual
│   └── Future Visual Styles
│
├── UI / HUD Theme System
│   ├── Font Set
│   ├── Player HUD
│   ├── Score Display
│   ├── Ammo Display
│   ├── Reload Indicator
│   ├── Health / Energy Display
│   ├── Lives / Continues
│   ├── Crosshair
│   ├── Combo Display
│   ├── Hit Feedback
│   ├── Boss Health
│   ├── Warning Messages
│   ├── Item Notifications
│   ├── Result Screen
│   ├── UI Animation Set
│   └── UI Sound Set
│
├── Presentation System
│   ├── Family Mode
│   ├── Arcade Mode
│   └── Gore Mode
│
├── Difficulty System
│   ├── Enemy Health Multiplier
│   ├── Enemy Count
│   ├── Spawn Pattern
│   ├── Reaction Time
│   ├── Accuracy
│   ├── Attack Frequency
│   ├── Spawn Pressure
│   ├── Special Enemy Frequency
│   └── Boss Scaling
│
├── Input System
│   ├── Player Input Mapping
│   ├── Mouse
│   ├── Controller
│   ├── Lightgun
│   ├── Wiimote / DolphinBar
│   └── Future Input Devices
│
└── Game Configuration
    ├── Character Style
    ├── HUD Theme
    ├── Presentation Mode
    ├── Difficulty
    ├── Player Count
    ├── Player Input Profiles
    ├── Selected Character Style
    ├── Selected HUD Theme
    ├── Selected Loadout
    ├── Selected Cosmetics
    ├── Selected Crosshair
    └── Selected Audio Theme
```

---

# 3. Zwei-Spieler-Unterstützung ist Teil der Grundarchitektur

Das Projekt muss von Beginn an architektonisch für mindestens zwei lokale Spieler geeignet sein.

Auch wenn frühe Prototypen zunächst nur Player 1 verwenden, dürfen Core-Systeme keine unnötigen Single-Player-Annahmen enthalten.

Nicht fest verdrahten:

```text
SingleCrosshair
SingleScore
SingleWeapon
SinglePlayer
```

Stattdessen spielerbezogene Daten verwenden:

```text
PlayerId
PlayerState
PlayerWeaponState
PlayerScore
PlayerCrosshair
PlayerInputProfile
```

---

# 4. Player 1 und Player 2 verwenden dieselben Basissysteme

Keine getrennten Systeme wie:

```text
Player1WeaponSystem
Player2WeaponSystem
```

Bevorzugt:

```text
PlayerBase
├── Player 1 Instance
└── Player 2 Instance
```

Unterschiede sind instanz- oder datenbasiert.

---

# 5. Folgende Daten müssen pro Spieler getrennt verwaltet werden können

* Score
* Combo
* Weapon
* Magazine Ammo
* Reserve Ammo
* Health / Energy
* Lives
* Continues
* Aim Position
* Crosshair
* Input Device
* Hit Feedback
* Player HUD Accent
* Statistics
* Accuracy
* Shots Fired
* Hits
* Items Collected

Optional sollen später auch gemeinsame Werte möglich sein:

* Team Score
* Shared Continue Pool
* Shared Objective Progress

Diese Regeln dürfen nicht hart im Core-Code vorausgesetzt werden.

---

# 6. Zwei-Spieler-Lightgun-Konzept berücksichtigen

Perspektivisch muss Folgendes möglich sein:

```text
Lightgun 1
→ Player 1

Lightgun 2
→ Player 2
```

oder andere Kombinationen:

```text
Player 1 = Mouse
Player 2 = Controller
```

```text
Player 1 = Wiimote
Player 2 = Wiimote
```

Input Devices müssen eindeutig einem Player zugeordnet werden können.

---

# 7. Gemeinsame Rail-Kamera

Der klassische lokale Zwei-Spieler-Lightgun-Modus verwendet grundsätzlich:

* dieselbe Rail-Kamera
* dasselbe Level
* denselben Encounter

aber getrennte:

* Crosshairs
* Aim Positions
* Scores
* Weapons
* Ammo States
* Player States

Split-Screen ist für den Hauptmodus zunächst nicht vorgesehen.

---

# 8. Gameplay und Character Look bleiben getrennt

Ein Enemy bleibt gameplaytechnisch derselbe Enemy.

Beispiel:

```text
Enemy_Grunt
```

Gameplay-Daten können enthalten:

* Base Health
* Behaviour
* Weapon
* Reaction Time
* Accuracy
* Hit Zones
* Movement Pattern
* Spawn Rules
* Score Value

Darstellung separat:

```text
Enemy_Grunt
├── Stickman Visual
├── 90s Arcade Anime Visual
└── Future Visual Styles
```

Ein Visual-Style-Wechsel darf keine Gameplay-Änderung erfordern.

---

# 9. Shared Skeleton / Shared Animation System

Kompatible humanoide Visual Styles sollen möglichst dieselbe grundlegende Skeleton-Struktur verwenden.

```text
Shared Skeleton
      ↓
Shared Animation Set
      ↓
Stickman
90s Arcade Anime
Future Styles
```

Gemeinsame Animationen sollen unter anderem ermöglichen:

* Idle
* Aim
* Shoot
* Reload
* Walk
* Run
* Cover
* Hit Reaction
* Defeat
* Special Reactions

Ein neuer Look darf zusätzliche Animationen hinzufügen, soll das gemeinsame Basissystem aber nicht unnötig ersetzen.

---

# 10. Erster Visual Style

Der erste Character Style ist:

`Comic Stickman`

Dieser Style ist ausschließlich der erste Visual Layer.

Gameplay darf niemals Stickman-spezifisch aufgebaut werden.

---

# 11. Geplanter zweiter Visual Style

Geplant:

`90s Arcade Anime`

Dieser soll soweit sinnvoll verwenden:

* Shared Skeleton
* Shared Animations
* gleiche Hit Zones
* gleiche Enemy Logic
* gleiche Weapons
* gleiche Levels
* gleiche Boss Logic
* gleiche Item Logic

---

# 12. Character Style und HUD Theme sind unabhängig

Folgende Kombinationen sollen möglich sein:

```text
Stickman + Comic HUD
Stickman + 90s Arcade HUD
90s Anime + Comic HUD
90s Anime + Minimal HUD
```

HUD und Character Style dürfen technisch nicht fest miteinander gekoppelt sein.

---

# 13. UI / HUD Theme System

Das vollständige HUD muss austauschbar sein.

Modular bleiben müssen insbesondere:

* Fonts
* Score Display
* Score Animations
* Ammo Display
* Reserve Ammo
* Reload Indicator
* Health / Energy Display
* Lives
* Continues
* Crosshair
* Hit Marker
* Combo Display
* Timer
* Accuracy
* Boss Health
* Warning Messages
* Mission Messages
* Item Notifications
* Player Labels
* Result Screen
* Icons
* UI Panels
* UI Materials
* UI Animations
* UI Sounds

---

# 14. Gameplay liefert nur Daten und Events

Beispiel:

```text
PlayerScore = 14850
```

Das Score-System kennt nicht:

* Font
* Position
* Farbe
* Widget Layout
* Animation
* Sounds

Das HUD Theme übernimmt die Darstellung.

---

# 15. Reload bleibt modular

Weapon System:

```text
AmmoInMagazine = 0
ReloadRequired = true
```

HUD Theme entscheidet über:

* Text
* Symbol
* Animation
* Sound
* Position
* Blinkverhalten
* Größe

Kein Gameplay-System darf ein bestimmtes `RELOAD!` Widget voraussetzen.

---

# 16. Health / Energy Display bleibt modular

Gameplay liefert beispielsweise:

```text
CurrentHealth = 73
MaxHealth = 100
```

Ein HUD Theme kann dies darstellen als:

```text
LIFE 73%
```

oder:

```text
ENERGY ███████░░░
```

oder:

```text
♥ ♥ ♥
```

Das Gameplay bleibt identisch.

---

# 17. Fonts gehören zum HUD Theme

Fonts dürfen nicht unkontrolliert direkt in einzelnen Widgets fest verdrahtet werden.

Themes können beispielsweise enthalten:

```text
PrimaryFont
SecondaryFont
ScoreFont
WarningFont
ResultFont
```

Geplante Beispiele:

```text
DA_UITheme_StickmanComic
DA_UITheme_90sArcade
DA_UITheme_Minimal
```

---

# 18. UI Sounds und Animationen bleiben modular

Themes können eigene:

* Reload Sounds
* Score Sounds
* Combo Sounds
* Warning Sounds
* Item Sounds
* Hit Confirmation Sounds
* UI Transition Sounds

und eigene Animationen besitzen.

Diese verändern niemals das eigentliche Gameplay.

---

# 19. Weapon System

Waffen bleiben eigenständig und datengetrieben.

Eine Weapon Configuration kann unter anderem enthalten:

```text
WeaponId
AmmoType
MagazineSize
ReserveAmmoMax
Damage
FireRate
ReloadTime
WeaponBehaviour
ScoreModifier
```

Visuals und Sounds sollen getrennt referenziert werden.

---

# 20. Mehrere Weapon Slots

Das System muss perspektivisch mehrere Slots unterstützen können:

```text
Primary Weapon
Secondary Weapon
Special Weapon
```

Nicht jede Waffe besitzt unendlich Munition.

Magazine und Reserve Ammo müssen getrennt modellierbar sein.

---

# 21. Item / Pickup System

Items werden als eigenes datengetriebenes Hauptsystem aufgebaut.

Geplante Kategorien:

* Ammo Pickup
* Health Pickup
* Score Pickup
* Weapon Pickup
* Power-Up
* Extra Life
* Continue
* Objective Item
* Special Arcade Item

---

# 22. Ammo Pickups

Ein Ammo Pickup soll möglichst über abstrakte Zuordnungen funktionieren:

```text
PickupType = Ammo
AmmoType = Secondary
Amount = 12
```

Keine unnötige harte Kopplung an eine konkrete Weapon-Klasse.

Geeignete Konzepte:

* Gameplay Tags
* Ammo Type IDs
* Interfaces
* Data Assets

---

# 23. Player Ownership bei Items

Im Zwei-Spieler-Modus muss eindeutig bestimmt werden können, welcher Spieler ein Pickup erhält.

Beispiel:

```text
Player 1 shoots pickup
→ Player 1 receives ammo
```

Optional können später Team-Pickups existieren.

---

# 24. Item Visuals bleiben austauschbar

Dasselbe Gameplay-Item kann abhängig vom Character-/Presentation-/Art-Style anders aussehen.

Beispiel:

```text
Secondary Ammo Pickup
```

Darstellung:

```text
Stickman Magazine
90s Arcade Ammo Box
Floating Arcade Icon
```

Gameplay-Wirkung bleibt identisch.

---

# 25. Item Balancing bleibt datengetrieben

Mögliche Parameter:

```text
Amount
Duration
SpawnChance
Lifetime
ScoreValue
DifficultyModifier
RespawnRules
```

Neue Items sollen möglichst ohne Änderungen am Core-System erstellt werden können.

---

# 26. Boss System

Bosses erhalten ein eigenes datengetriebenes Hauptsystem.

Ein Boss ist nicht lediglich ein Enemy mit sehr vielen Lebenspunkten.

Das Boss System muss perspektivisch unterstützen:

* Boss Base
* Boss Configuration
* mehrere Boss Phases
* Attack Patterns
* Movement Patterns
* Weak Points
* Phase Transitions
* Special States
* Add Spawning
* Scripted Events
* Boss Score
* Boss Events

---

# 27. Boss-Konfiguration bleibt datengetrieben

Beispiel:

```text
BossId = Helicopter
BaseHealth = 5000
PhaseCount = 3
WeakPointMultiplier = 2.0

Phase2Threshold = 65%
Phase3Threshold = 30%

AttackPattern = Helicopter_A
AddPattern = Soldiers_B
ScoreValue = 50000
```

Diese Werte sollen nicht unnötig hart im Code stehen.

---

# 28. Boss Phases bleiben modular

Eine Phase kann unter anderem konfigurieren:

* Attack Pattern
* Movement Pattern
* Weak Points
* Spawned Enemies
* Attack Frequency
* Vulnerability Windows
* Phase Events

---

# 29. Boss Difficulty Scaling

Difficulty darf Boss-Daten modifizieren.

Beispiele:

```text
Health Multiplier
Attack Frequency
Add Count
Weak Point Window
Damage
Phase Timing
```

Keine separaten Gameplay-Klassen nur aufgrund von:

```text
Boss_Easy
Boss_Normal
Boss_Hard
```

erstellen.

---

# 30. Boss Visuals bleiben austauschbar

```text
Boss Gameplay
      ↓
Visual Style
├── Stickman Version
├── 90s Arcade Anime Version
└── Future Version
```

Boss Gameplay, Phasen und Balancing bleiben unabhängig vom Look.

---

# 31. Boss HUD bleibt Theme-gesteuert

Boss-System liefert ausschließlich Daten wie:

```text
CurrentBossHealth
MaxBossHealth
BossName
CurrentPhase
```

HUD Theme entscheidet über:

* Boss Health Bar
* Font
* Name Display
* Icons
* Animation
* Warnings

---

# 32. Presentation System

Presentation bleibt getrennt vom Damage-System.

Vorgesehene Modi:

## Family Mode

* keine Blutdarstellung
* keine Körperteilabtrennung
* neutrale Trefferreaktionen

## Arcade Mode

* stärkere stilisierte Trefferreaktionen
* Comic-artige Effekte
* moderate Darstellung

## Gore Mode

* optionale stilisierte Bluteffekte
* optionale Körperteilabtrennung
* deutlichere Trefferreaktionen
* zusätzliche Effekte

Grundprinzip:

```text
Hit Detection
      ↓
Damage Result
      ↓
Presentation Mode
      ↓
Visual / Audio Result
```

Presentation darf das eigentliche Damage-Ergebnis nicht verändern.

---

# 33. Difficulty System

Difficulty bleibt vollständig datengetrieben.

Mögliche Parameter:

```text
EnemyHealthMultiplier
EnemyCountMultiplier
ReactionTimeMultiplier
AccuracyMultiplier
AttackFrequencyMultiplier
SpawnPressure
SpecialEnemyChance
BossScaling
ItemFrequency
```

---

# 34. Keine reinen HP-Sponges

Schwierigkeit soll vorzugsweise entstehen durch:

* mehr Gegner
* schnellere Reaktion
* höhere Accuracy
* aggressivere Spawn Patterns
* kürzere Zeitfenster
* höheren Spawn Pressure
* mehr Special Enemies
* anspruchsvollere Boss Patterns

Health Scaling darf verwendet werden, aber nicht als einziges Mittel.

---

# 35. Co-op Difficulty

Das Difficulty-/Encounter-System soll später berücksichtigen können:

```text
1 Player
2 Players
```

Mögliche Skalierungen:

* Enemy Count
* Spawn Pressure
* Boss Health
* Boss Attacks
* Item Frequency
* Special Enemy Count

Diese Werte bleiben datengetrieben.

---

# 36. Keine unnötigen Hardcodes

Balancing-relevante Werte sollen möglichst nicht fest im Code stehen.

Dazu gehören:

* Health
* Ammo
* Magazine Size
* Reserve Ammo
* Weapon Damage
* Reload Time
* Fire Rate
* Enemy Count
* Reaction Time
* Accuracy
* Spawn Timing
* Spawn Pattern
* Score
* Combo
* Item Values
* Boss Values
* Difficulty Multipliers
* Rail Speed
* Combat Stop Timing

---

# 37. Data Assets / Data Tables

Konfiguration und Balancing sollen bevorzugt datengetrieben erfolgen.

Beispiele:

```text
DA_Difficulty_Easy
DA_Difficulty_Normal
DA_Difficulty_Hard
DA_Difficulty_Arcade

DA_Look_Stickman
DA_Look_90sArcadeAnime

DA_UITheme_StickmanComic
DA_UITheme_90sArcade
DA_UITheme_Minimal

DA_Presentation_Family
DA_Presentation_Arcade
DA_Presentation_Gore

DA_Weapon_Pistol
DA_Weapon_Secondary

DA_Item_SecondaryAmmo

DA_Currency_ArcadeTokens
DA_Unlock_Magnum
DA_Cosmetic_Shirt_Red
DA_Cosmetic_Shirt_Blue
DA_Challenge_Level1_Hard
DA_Challenge_Accuracy85
DA_Reward_Level1Complete
DA_ShopCategory_Weapons
DA_ShopCategory_Cosmetics

DA_Boss_Helicopter
```

---

# 37a. Progression & Economy System

Das Progression & Economy System ist ein eigenes offizielles Hauptsystem des Projekts.

Es bleibt modular, datengetrieben und unabhängig vom eigentlichen Combat-System.

Das System umfasst perspektivisch mindestens:

```text
Progression & Economy System
├── Player Progression
├── Unlock System
├── Arcade Currency
├── Shop System
├── Cosmetic Unlocks
├── Weapon Unlocks
├── Challenge Rewards
├── Level Completion Rewards
├── Difficulty Rewards
├── Achievement Rewards
├── Ownership Data
├── Equipped Loadout
└── Save / Profile Integration
```

Progression darf Gameplay-Systeme nicht direkt manipulieren. Das Progression System darf beispielsweise bereitstellen:

```text
Weapon Magnum is owned
```

Das Weapon System entscheidet danach, wie diese Waffe gameplaytechnisch funktioniert.

Das Economy-System darf nicht direkt:

* Damage berechnen
* Enemy Health verändern
* Treffer auswerten
* Rail Movement steuern
* Hit Detection durchführen
* Ammo-Verbrauch berechnen
* Difficulty verändern

---

## 37a.1 Permanent Progression und Run / Level Items

Permanent Progression und Run / Level Items müssen technisch getrennt bleiben.

### Permanent Progression

Beispiele:

```text
Weapons
Character Cosmetics
T-Shirts
Colors
Accessories
Weapon Skins
Crosshair Styles
HUD Themes
Audio Themes
Character Visual Styles
Permanent Unlocks
```

Diese Inhalte können dauerhaft freigeschaltet bzw. gekauft werden.

### Run / Level Items

Beispiele:

```text
Ammo
Health / Energy
Temporary Power-Ups
Temporary Bonus Weapons
Score Items
Mission-specific Items
```

Diese Gegenstände gelten grundsätzlich nur für den aktuellen Run bzw. das aktuelle Level, sofern ihre Konfiguration nichts anderes vorsieht.

Permanent Progression und Run Items dürfen technisch nicht dasselbe Ownership-System voraussetzen.

---

## 37a.2 Unlock, Ownership und Equipped State

Das System muss zwischen folgenden Zuständen unterscheiden können:

```text
Locked
Unlocked
Owned
Equipped
```

Eine Freischaltung bedeutet nicht automatisch Besitz. Besitz und aktuell ausgewählte Ausstattung bleiben getrennt.

Beispiel:

```text
Weapon: Magnum

Unlock Requirement:
Complete Level 2

Shop Price:
2500 Arcade Tokens

Unlocked:
true

Owned:
false
```

Inhalte sollen je nach Data-Konfiguration beispielsweise:

* standardmäßig verfügbar sein
* direkt als Reward vergeben werden
* durch Level Completion freigeschaltet werden
* durch Difficulty Completion freigeschaltet werden
* durch Challenges freigeschaltet werden
* nach Freischaltung im Shop kaufbar werden
* ausschließlich als Challenge Reward erhältlich sein

Keine einzelne Methode darf im Core-System fest vorausgesetzt werden.

Beispiel:

```text
Owned:
Shirt_Red
Shirt_Blue
Shirt_Black

Equipped:
Shirt_Blue
```

Dasselbe gilt für Weapons, Cosmetics, Crosshairs, HUD Themes, Audio Themes und Character Visual Styles.

---

## 37a.3 Arcade Currency

Die erste vorgesehene Economy basiert auf erspielbarer Ingame-Währung.

Vorläufiger Arbeitsbegriff:

```text
Arcade Tokens
```

Die Currency muss datengetrieben bleiben. Mögliche Quellen sind Level Completion, Score, Accuracy, Challenges, Difficulty Bonuses, Boss Rewards, Achievements und Special Objectives.

Keine Currency-Belohnungen hart im Gameplay-Code verteilen, wenn sie datengetrieben konfigurierbar sein können.

Die initiale Economy wird vollständig als erspielbares Ingame-System entwickelt. Das Core-System darf keine Echtgeldtransaktionen voraussetzen.

---

## 37a.4 Shop System

Der Shop soll perspektivisch unterschiedliche Kategorien unterstützen können: Weapons, Character Cosmetics, T-Shirts, Colors, Accessories, Weapon Skins, Crosshair Styles, HUD Themes, Audio Themes und Special Unlocks.

Das Shop-System darf nicht direkt wissen, wie ein gekaufter Gegenstand dargestellt wird.

Es verwaltet primär Item ID, Category, Unlock State, Ownership State, Price, Currency Type, Requirements, Availability und Purchase Rules.

Es darf nicht selbst Weapon Damage, Enemy Stats oder vergleichbare Gameplay-Werte berechnen.

Shop-Preise, Anforderungen und Verfügbarkeit bleiben datengetrieben.

---

## 37a.5 Cosmetics und Visual Styles

Kosmetische Unlocks dürfen nicht unnötig an den Stickman-Look gekoppelt sein.

Die gleiche logische Freischaltung kann je Visual Style auf unterschiedliche Assets zeigen. Der Besitz des Gegenstands bleibt derselbe. Nur die Darstellung wechselt.

Cosmetics und andere visuelle Inhalte sollen angeben können, welche Character Styles sie unterstützen.

```text
SupportedVisualStyles:
- Stickman
- 90sArcadeAnime
```

Nicht unterstützte Kombinationen dürfen nicht zu kaputten Referenzen oder Gameplay-Fehlern führen. Das System muss einen sauberen Fallback bzw. Nicht-Verfügbarkeitsstatus ermöglichen.

---

## 37a.6 Weapon Unlocks und Weapon Ownership

Waffen müssen in das Progression-System integrierbar sein.

Dabei bleiben Weapon Gameplay Data, Weapon Visual Data, Unlock Requirement, Purchase Requirement, Ownership State und Equipped Loadout getrennt.

Beispiel:

```text
WeaponId = Magnum

UnlockRequirement = CompleteLevel2
PurchasePrice = 2500 ArcadeTokens
Owned = false
```

Weapon Damage, Fire Rate, Magazine Size und andere Waffenwerte bleiben Bestandteil des Weapon Systems und dürfen nicht in das Shop-System verschoben werden.

Die Architecture Charter legt nicht fest, dass jede starke Waffe gekauft werden muss. Progression darf Skill-based Unlock, Level Completion, Challenge Completion, Difficulty Completion, Shop Purchase und Reward Grant flexibel kombinieren.

---

## 37a.7 Challenges und Rewards

Das Progression-System soll spätere Challenges unterstützen können, etwa Level Completion, Hard-Mode-Abschluss, Accuracy-Ziele, Score-Ziele, No-Life-Lost-Abschlüsse, Boss-Bedingungen, versteckte Ziele und Co-op-Challenges.

Challenge Conditions und Rewards sollen möglichst datengetrieben bleiben.

Ein Reward soll verschiedene Reward Types unterstützen können: Arcade Currency, Weapon Unlock, Cosmetic Unlock, HUD Theme Unlock, Crosshair Unlock, Audio Theme Unlock, Character Style Unlock und Achievement.

Gameplay oder Challenge-System melden lediglich, dass eine Bedingung erfüllt wurde. Das Reward-System übernimmt die Vergabe.

---

## 37a.8 Player Profile / Ownership Data

Das Progression-System benötigt eine klare Trennung zwischen Definition Data und Player/Profile State.

Definition Data beschreibt beispielsweise Item Definition, Price, Unlock Condition, Category, Supported Styles und Reward Definition.

Player/Profile State beschreibt beispielsweise Unlocked, Owned, Equipped, Currency Balance, Completed Challenges, Achievements und Progression Status.

Diese Daten dürfen nicht miteinander vermischt werden.

Das Progression-&-Economy-System darf nicht davon ausgehen, dass automatisch alles Player 1 gehört.

Die Architektur muss sowohl ein gemeinsames lokales Profil mit Shared Unlocks, Shared Arcade Tokens, Shared Cosmetics und Shared Weapons als auch getrennte Profile für Player 1 und Player 2 ermöglichen.

Welche Variante später Standard wird, ist offen.

---

## 37a.9 UI- und Shop-Darstellung

Das Progression-System liefert Daten wie:

```text
ArcadeTokens = 2750
Owned = true
Price = 750
```

Das HUD-/Menu-Theme entscheidet über Font, Layout, Icons, Farben, Animationen, Sounds und Darstellung von Locked / Owned / Equipped.

Auch der spätere Shop muss die modulare UI-/HUD-Architektur respektieren.

---

## 37a.10 Save / Profile Integration

Permanent Progression muss später persistent gespeichert werden können.

Dazu zählen beispielsweise Currency, Unlocks, Ownership, Equipped Items, Challenges, Achievements und Progression Status.

Das konkrete Save-System wird später implementiert. Die Architektur darf jedoch nicht voraussetzen, dass solche Daten nur während einer laufenden Spielsitzung existieren.

---

# 38. Input-Abstraktion

Zentrale Gameplay-Aktionen:

```text
Aim
Fire
Reload
Pause
WeaponSwitch
SpecialAction
```

Mögliche Inputs:

```text
Mouse
Controller
Lightgun
Wiimote / DolphinBar
Future Devices
```

Gameplay darf das konkrete physische Eingabegerät nicht kennen müssen.

---

# 39. Lightgun von Anfang an berücksichtigen

Prinzip:

```text
Physical Input Device
        ↓
Player Input Profile
        ↓
Aim Position / Actions
        ↓
Combat System
```

Spätere Lightgun-Unterstützung darf keinen Umbau des Combat Systems erfordern.

---

# 40. Rail System bleibt eigenständig

Rail System kontrolliert:

* Spline Path
* Camera Movement
* Rail Speed
* Combat Stops
* Rail Events
* Übergänge

Rail System kontrolliert nicht:

* Enemy Health
* Weapon Damage
* Ammo
* Character Style
* HUD Theme
* Difficulty
* Presentation Mode

---

# 41. Combat Stops

Combat Stops sind wiederverwendbare Module.

```text
Rail Movement
      ↓
Combat Stop
      ↓
Encounter
      ↓
Encounter Complete
      ↓
Rail Movement Continues
```

Ein Combat Stop kann später konfigurieren:

* Single Wave
* Multiple Waves
* Ambush
* Civilian Event
* Pickup Situation
* Special Enemy
* Mini-Boss
* Boss
* Scripted Sequence

---

# 42. Level und Core Gameplay bleiben getrennt

Level enthalten hauptsächlich:

* Environment
* Rail Splines
* Combat Stops
* Spawn Points
* Item Spawn Points
* Boss Areas
* Camera Markers
* Triggers
* Level-specific Visuals

Core Gameplay bleibt möglichst levelunabhängig.

---

# 43. Saubere Kommunikation zwischen Systemen

Vermeide direkte Abhängigkeitsketten wie:

```text
Enemy
→ HUD
→ Rail Camera
→ Difficulty
```

Bevorzugt:

* Interfaces
* Components
* Events
* Event Dispatchers
* Gameplay Tags
* Data Assets
* konfigurationsbasierte Kommunikation

abhängig vom konkreten Anwendungsfall.

---

# 44. C++ / Blueprint-Aufgabentrennung

## C++

Bevorzugt für:

* Core Gameplay
* Base Classes
* Interfaces
* Components
* Player System
* Weapon System
* Item System
* Boss Core
* Difficulty
* Damage
* Score
* Input Abstraction
* Game Configuration
* wiederverwendbare Event-Systeme

## Blueprints / Unreal Editor

Bevorzugt für:

* Level Design
* Rail Splines
* Combat Stops
* Spawn Placement
* Item Placement
* Boss Arena Setup
* Animation Setup
* Materials
* Niagara / VFX
* HUD Layout
* HUD Theme Assembly
* Visual Tuning
* schnelle Iteration

Blueprints dürfen C++ erweitern.

Core-Systeme sollen nicht unnötig ausschließlich aus stark voneinander abhängigen Blueprints bestehen.

---

# 45. Erst Funktion, dann Grafik

Neue Features grundsätzlich:

```text
Prototype
   ↓
Functionality Test
   ↓
Modularization
   ↓
Visual Implementation
   ↓
Polish
```

---

# 46. Freie Kombination der Systeme

Langfristig sollen beispielsweise folgende Kombinationen möglich sein:

```text
Stickman
+ Comic HUD
+ Family
+ Easy
+ 1 Player
```

```text
Stickman
+ 90s Arcade HUD
+ Gore
+ Hard
+ 2 Players
```

```text
90s Arcade Anime
+ Minimal HUD
+ Arcade Presentation
+ Normal
+ 2 Lightguns
```

Character Style, HUD Theme, Presentation Mode, Difficulty und Input dürfen nicht fest aneinander gekoppelt werden.

---

# 47. Audio Presentation

Auch UI- und Presentation-Audio soll möglichst modular bleiben.

Mögliche spätere Audio Themes:

```text
Comic Audio
90s Arcade Audio
Minimal Audio
```

Gameplay löst Events aus.

Audio Presentation entscheidet über konkrete Sounds.

---

# 48. Architekturänderungen dokumentieren

Grundlegende Architekturentscheidungen dürfen nicht stillschweigend geändert werden.

Bei Änderungen:

1. Grund dokumentieren
2. Auswirkungen prüfen
3. Entscheidung festhalten
4. betroffene Systeme identifizieren
5. gegebenenfalls Migration planen

Spätere ADR-Beispiele:

```text
ADR-0001 Shared Character Skeleton
ADR-0002 Data Driven Difficulty
ADR-0003 Presentation Layer
ADR-0004 Input Abstraction
ADR-0005 Modular HUD Theme System
ADR-0006 Gameplay/UI Separation
ADR-0007 Multiplayer Player Ownership
ADR-0008 Data Driven Item System
ADR-0009 Data Driven Boss System
ADR-0010 Data Driven Progression
ADR-0011 Unlock vs Ownership Separation
ADR-0012 Local Profile Progression
ADR-0013 Modular Shop and Economy
```

---

# 49. Verbindliche Regeln für Codex

Codex muss bei allen zukünftigen Implementierungen prüfen:

* Ist `ARCHITECTURE_CHARTER.md` berücksichtigt worden?
* Ist das Feature modular?
* Ist es für 1–2 Spieler geeignet, sofern relevant?
* Wird Player Ownership korrekt behandelt?
* Werden unnötige Single-Player-Annahmen vermieden?
* Werden unnötige Hardcodes vermieden?
* Sind Balancing-Werte datengetrieben?
* Ist Gameplay vom Character Look getrennt?
* Ist Gameplay vom HUD getrennt?
* Ist Difficulty von Enemy- und Boss-Klassen getrennt?
* Ist Presentation vom Damage-System getrennt?
* Ist Input vom Combat-System abstrahiert?
* Sind Items datengetrieben?
* Sind Bosses datengetrieben?
* Sind Weapons datengetrieben?
* Können Character Styles später ausgetauscht werden?
* Können HUD Themes später ausgetauscht werden?
* Ist Permanent Progression von Run Items getrennt?
* Sind Unlock und Ownership getrennt?
* Ist Ownership vom Equipped State getrennt?
* Ist Currency datengetrieben?
* Sind Shop-Preise datengetrieben?
* Sind Unlock Conditions datengetrieben?
* Sind Rewards datengetrieben?
* Ist Progression unabhängig vom Character Visual Style?
* Ist Progression unabhängig vom HUD Theme?
* Berücksichtigt Progression die geplante Zwei-Spieler-Architektur?
* Werden Player/Profile Ownership sauber behandelt?
* Ist keine Echtgeld-Economy für das Core-System erforderlich?
* Kann Progression später persistent gespeichert werden?
* Werden vorhandene Interfaces und Basissysteme wiederverwendet?
* Entsteht unnötige technische Schuld?
* Wurde bei einem Versionsabschluss das vorgeschriebene Versionsarchiv erstellt?
* Ist `RELEASE_INFO.md` vollständig und entspricht dem tatsächlichen Projektstand?
* Ist der freigegebene Git Commit korrekt im Archiv dokumentiert?
* Wurden unnötige Kopien großer Assets vermieden?
* Ist der archivierte Versionsstand unverändert?
* Liegt die ausdrückliche Freigabe durch Jens Würger vor?

Wenn ein zukünftiger Auftrag im Widerspruch zur Charter steht, soll Codex den Konflikt ausdrücklich nennen und nach Möglichkeit eine charter-konforme Lösung verwenden.

---

# 50. Aktuell fest beschlossen

* Unreal Engine 5
* C++ + Blueprints
* On-Rails Arcade Shooter
* lokaler 1–2-Spieler-Unterbau
* gemeinsame Rail-Kamera
* getrennte Crosshairs
* getrennte Scores
* getrennte Weapon-/Ammo-Zustände
* Lightgun-Co-op später vorgesehen
* Spline-basierte Kamerafahrt
* Combat Stops
* Comic Stickman als erster Character Style
* 90s Arcade Anime als weiterer geplanter Style
* Shared Skeleton / Shared Animations soweit sinnvoll
* modulares Character Visual System
* modulares HUD Theme System
* modulare Fonts
* modulare Score-Anzeige
* modulare Reload-Anzeige
* modulare Health-/Energy-Anzeige
* modulare Crosshairs
* modulare UI Animationen
* modulare UI Sounds
* Family / Arcade / Gore Presentation
* datengetriebene Difficulty
* datengetriebene Weapons
* datengetriebene Items
* datengetriebene Bosses
* Progression & Economy System ist offizielles Hauptsystem
* Arcade Currency ist vorgesehen
* Currency wird zunächst ausschließlich erspielt
* Shop-System ist vorgesehen
* Cosmetic Unlocks sind vorgesehen
* Weapon Unlocks sind vorgesehen
* Unlock und Purchase können getrennt sein
* Permanent Progression und Level Pickups bleiben getrennt
* Ownership und Equipped State bleiben getrennt
* Cosmetics sollen Visual-Style-unabhängig definierbar sein
* Progression wird später persistent gespeichert
* Zwei-Spieler-/Profil-Frage bleibt modular
* Echtgeld ist keine Core-Voraussetzung
* Maus und Controller zuerst
* Lightgun später
* Wiimote / DolphinBar optional
* Data Assets / Data Tables für Balancing
* strikte Trennung von Gameplay und Darstellung
* schlankes lokales Versionsarchiv für jede freigegebene Version
* Archivpfad `Version_Archive`
* `RELEASE_INFO.md` und Änderungsprotokoll pro Archivversion
* Archivierung von Projektdokumentation, `.uproject`, Config und Source
* keine unnötige Duplizierung großer Content-Assets pro Version
* vollständige Assets bleiben über den dokumentierten Git-Stand reproduzierbar
* Git Commit Hash ist für jede Archivversion verpflichtend

---

# 51. Noch offen

Noch nicht endgültig festlegen:

* finaler Spielname
* genaue Difficulty-Namen
* Weapon Roster
* Anzahl Weapon Slots
* genaue Ammo-Regeln
* genaue Score Formula
* Combo Rules
* Lives / Continue Regeln
* Team-/Einzel-Score-Regeln
* Shared oder getrennte Continues
* Enemy Archetypes
* konkrete Pickup-Liste
* Power-Ups
* Boss-Typen
* finales Level 1 Design
* genaue Gore-Regeln
* konkrete Lightgun Hardware
* Join-In-Regeln für Player 2
* Friendly Fire
* finale HUD Themes
* Highscore System
* endgültiger Name der Ingame-Währung
* genaue Token-Belohnungen
* Shop-Preise
* genaue Unlock-Bedingungen
* konkrete Cosmetics
* konkrete Weapon Unlocks
* Challenge-Katalog
* Achievement-System
* Shared oder getrennte Progression im Zwei-Spieler-Modus
* konkrete Save-Game-Struktur
* Umfang des Shops
* genaue Loadout-Regeln

---

# 52. Freigabehoheit

Die endgültige Freigabe jeder Version, jedes Meilensteins und jedes offiziellen Releases liegt ausschließlich bei:

**Jens Würger**

Codex darf:

* technische Fertigstellung melden
* Tests durchführen
* Testergebnisse dokumentieren
* eine Version als Release Candidate vorbereiten
* offene Punkte dokumentieren
* einen Stand zur Freigabe vorlegen
* Commits vorbereiten oder durchführen, wenn dies Teil eines späteren Auftrags ist

Codex darf ohne ausdrückliche Freigabe durch Jens Würger jedoch nicht selbst erklären, dass eine Version:

* abgeschlossen
* freigegeben
* final
* released
* approved
* production ready

ist.

---

# 53. Versionsabschlussregel

Eine Version gilt erst dann als abgeschlossen, wenn Jens Würger sie ausdrücklich freigegeben hat.

Das gilt auch dann, wenn:

* alle geplanten Features implementiert sind
* sämtliche Tests erfolgreich sind
* Codex die technische Arbeit abgeschlossen hat
* Commits vorhanden sind
* ein Git Branch gemerged wurde
* eine Versionsnummer bereits vorbereitet wurde
* ein GitHub Release vorbereitet wurde

Technische Fertigstellung ist nicht gleich Freigabe.

Vor Freigabe müssen Statusbezeichnungen verwendet werden wie:

```text
In Development
Pending Review
Awaiting Approval
Release Candidate
```

Vor Freigabe nicht verwenden:

```text
Completed
Released
Final
Approved
Production Ready
```

---

# 54. GitHub- und Release-Regel

Das Projekt wird in Verbindung mit GitHub geführt.

Ein Commit oder Merge stellt ausdrücklich keine Versionsfreigabe dar.

Vor einer offiziellen Versionsfreigabe sollen mindestens folgende Schritte stattfinden:

1. Implementierung des vorgesehenen Umfangs
2. relevante Tests
3. Dokumentation bekannter Fehler
4. Dokumentation bekannter Einschränkungen
5. Dokumentation offener Punkte
6. Abgleich mit `ARCHITECTURE_CHARTER.md`
7. Abgleich mit `ROADMAP.md`
8. Version zur Prüfung vorlegen
9. ausdrückliche Freigabe durch Jens Würger
10. erst danach darf die Version als abgeschlossen / released geführt werden

Ein GitHub Release soll nicht endgültig veröffentlicht oder als final behandelt werden, solange keine ausdrückliche Freigabe erfolgt ist.

---

# 55. Abschlussbericht vor Freigabe

Nach technischer Fertigstellung eines Meilensteins soll Codex einen kompakten Freigabebericht erstellen mit:

* Versionsnummer
* implementierten Funktionen
* geänderten Dateien
* durchgeführten Tests
* Testergebnissen
* bekannten Bugs
* bekannten Einschränkungen
* offenen Punkten
* Architekturabweichungen, falls vorhanden
* vorgeschlagenem Status

Der Status muss ohne Freigabe beispielsweise lauten:

`Awaiting Approval by Jens Würger`

---

# 56. Verbindliche Abschlussregel der Architecture Charter

`ARCHITECTURE_CHARTER.md` ist die verbindliche technische Leitlinie dieses Projekts. Bei zukünftigen Implementierungen muss Codex diese Datei zuerst berücksichtigen. Neue Features sollen bestehende Systeme erweitern und nicht unnötig ersetzen oder duplizieren. Neue Systeme müssen, sofern relevant, von Anfang an die geplante lokale Zwei-Spieler-Unterstützung berücksichtigen.

Eine Version gilt ausschließlich nach ausdrücklicher Freigabe durch die Projektleitung Jens Würger als abgeschlossen. Technische Fertigstellung, erfolgreiche Tests, Commits, Merges oder vorbereitete GitHub Releases ersetzen diese Freigabe nicht. Bis zur ausdrücklichen Freigabe bleibt der jeweilige Stand ein Entwicklungsstand oder Release Candidate.

---

# 57. Freigabeprotokoll

## 2026-09-26 – Architecture Charter Update

Die Ergänzung des `Progression & Economy System` wurde durch die Projektleitung Jens Würger ausdrücklich freigegeben.

Diese Freigabe bestätigt die Architekturänderung, stellt jedoch keine Versionsfreigabe, keinen Release und keinen Start von `0.0.1 – Core Rail Prototype` dar.

---

# 58. Version Archive Policy

Jede ausdrücklich durch Jens Würger freigegebene Version erhält ein schlankes lokales Versionsarchiv unter `Version_Archive/vX.X.X/`.

Ein offizieller Archivordner darf erst nach der ausdrücklichen Versionsfreigabe erstellt werden. Technische Fertigstellung, Tests, Release-Candidate-Status, Commits, Pushes oder Merges ersetzen diese Freigabe nicht.

Das Archiv enthält mindestens:

* Projektdokumentation
* `Arcade_Shooter.uproject`
* `Arcade_Shooter/Config/`
* `Arcade_Shooter/Source/`
* relevante Grunddateien eigener Plugins, sofern vorhanden
* eine verpflichtende `RELEASE_INFO.md`

`RELEASE_INFO.md` dokumentiert mindestens die Version, Freigabe, Freigabedatum, Unreal-Engine-Version und den exakten Git Commit Hash. Große Content-Assets und Unreal-Generatorverzeichnisse werden nicht unnötig pro Version dupliziert; ihr vollständiger Stand bleibt über Git und den dokumentierten Commit reproduzierbar.

Ein einmal erstellter Archivstand ist ein unveränderlicher historischer Snapshot. Nachträgliche Änderungen erfordern eine neue Version und dürfen nicht stillschweigend in einen bestehenden Archivordner geschrieben werden.

Git/GitHub bleibt die vollständige technische Historie. Das lokale Versionsarchiv ergänzt diese Historie um eine schnell zugängliche Sammlung zentraler Grunddateien freigegebener Versionen und ersetzt Git nicht.

Die verbindlichen Details, Ausschlüsse, Prüfregeln, Wiederherstellungsschritte und die Struktur von `RELEASE_INFO.md` stehen in `VERSION_ARCHIVE_POLICY.md`. Diese Policy wird erst nach ausdrücklicher Freigabe durch Jens Würger verbindlich wirksam.
