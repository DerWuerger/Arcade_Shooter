# ROADMAP.md

Diese Roadmap beschreibt die geplanten technischen Meilensteine fuer das Projekt `Arcade_Shooter` bis einschliesslich `v0.1.0`.

Sie ist mit `ARCHITECTURE_CHARTER.md` abzugleichen. Keine Roadmap-Entscheidung darf die Architecture Charter umgehen. Versionen gelten erst nach ausdruecklicher Freigabe durch Jens Wuerger als abgeschlossen.

Die Roadmap ist nicht starr. Falls waehrend der Entwicklung ein System groesser oder komplexer wird, duerfen Zwischenversionen oder zusaetzliche Entwicklungsschritte ergaenzt werden.

Innerhalb einer Version koennen intern Teilabschnitte verwendet werden, zum Beispiel `0.0.2-A`, `0.0.2-B` oder `0.0.2-C`. Diese muessen nicht als eigene Git-Releases veroeffentlicht werden.

Ein offizieller Git-Tag wird erst erstellt, wenn die jeweilige Hauptversion vollstaendig validiert wurde.

---

## Completed

### Version 0.0.1 - Rail Foundation

Status: Completed and published

Enthalten:

* `AArcadeRailPath`
* editierbare Spline
* `AArcadeRailMover`
* Bewegung entlang der Rail
* Stop am Spline-Ende
* erfolgreicher PIE-Test

---

### Version 0.0.2 - Player & Camera Foundation

Status: Completed and published

Enthalten:

* `AArcadeRailPlayerPawn`
* Player-/Camera-Grundarchitektur
* Kamera folgt der Rail-Bewegung
* stabile Rail-Grundrotation ohne unerwuenschten Camera Roll
* freie Blicksteuerung relativ zur Rail-Grundrichtung
* Mouse Yaw und Mouse Pitch
* Gamepad-Look implementiert
* Yaw- und Pitch-Limits
* Trennung von Look-Richtung und Rail-Bewegung
* Stop am Spline-Ende

Hinweis:

* Gamepad input implemented; physical controller validation pending.

---

### Version 0.0.3 - Aiming & Crosshair

Status: Completed and published

Enthalten:

* sichtbares Fadenkreuz
* normalisierte Screen-Space-Aim-Position
* Zielbewegung per Maus
* Zielbewegung per Gamepad
* definierte Aim-Clamps
* technische C++-Crosshair-Darstellung
* Screen-Pixelposition-API
* World-Ray-API
* GameMode-, PlayerController- und HUD-Verkabelung
* Kamera bleibt vom Crosshair-Aim getrennt
* vertikale Gamepad-Y-Richtung korrigiert

Validierung:

* Build erfolgreich
* PIE visuell geprueft
* Mouse Aim geprueft
* Crosshair geprueft
* physischer Gamepad-Test erfolgreich
* horizontale und vertikale Gamepad-Steuerung erfolgreich

---

## Planned

### Version 0.0.4 - Weapon & Hit System

Ziele:

* erste Waffenlogik
* Schiessen
* Hitscan/Line Trace
* Treffererkennung
* Feuerrate
* grundlegende Reload-Struktur
* noch keine komplexe Gegner-KI

---

### Version 0.0.5 - Enemy Foundation

Ziele:

* erster grundlegender Gegnertyp
* Health
* Damage
* Death
* einfache Zustands-/Animationsstruktur
* Spawnfaehigkeit

---

### Version 0.0.6 - Combat Encounters

Ziele:

* definierte Combat Stops entlang der Rail
* Rail-Bewegung kann fuer Kaempfe anhalten
* Gegner koennen Encounter-gebunden erscheinen
* Weiterfahrt nach erfuellter Encounter-Bedingung
* Trigger-/Encounter-Grundsystem

---

### Version 0.0.7 - Arcade Game Loop

Ziele:

* Player Health/Lives
* Score
* Trefferquote
* Game Over
* Restart
* grundlegende HUD-Anzeigen

---

### Version 0.0.8 - Endless / Horde Mode

Ziele:

* kleine spielbare Karte
* fortlaufender Arcade-Gameplay-Loop
* wiederkehrende bzw. aufeinanderfolgende Encounter
* steigende Gegnerwellen oder Schwierigkeitssteigerung
* Fokus auf Endless/Horde statt Story-Modus

---

### Version 0.0.9 - Presentation & Polish

Ziele:

* Trefferfeedback
* einfache VFX
* Muzzle Flash
* Sounds
* Kameraeffekte
* UI-Polish
* Balancing
* Bugfixes

---

### Version 0.1.0 - First Playable

Ziel:

Ein vollstaendiger erster spielbarer Arcade-Shooter-Loop.

Der Spieler soll:

* auf der Rail bewegt werden
* zielen koennen
* schiessen koennen
* Gegner bekaempfen
* Combat Stops absolvieren
* Score/Leben besitzen
* nach einem Game Over neu starten koennen
* einen funktionierenden Endless-/Horde-Loop erleben koennen

`0.1.0` ist noch kein fertiges Spiel und benoetigt ausdruecklich noch keinen Story-Modus.

---

## Future / Post-0.1.0

Noch keiner festen Version zuordnen:

* Story-Modus
* weitere Level
* erweiterte Gegner-KI
* Boss Encounters
* Local Two Player
* weitere Waffen
* Pickups und Power-Ups
* Character Style Selection
* HUD Theme Selection
* echte Lightgun-Unterstuetzung
* Wiimote / DolphinBar
* Highscores
* lokale Bestenlisten
