# Version Archive Policy

Diese Policy definiert das schlanke lokale Versionsarchiv des Projekts `Arcade_Shooter`.

Sie ergänzt `ARCHITECTURE_CHARTER.md`, `ROADMAP.md`, `VERSION.md` und die vollständige Git-/GitHub-Historie. Bei Konflikten hat `ARCHITECTURE_CHARTER.md` Vorrang.

Policy Status: `Pending Approval by Jens Würger`

---

## 1. Zweck

Das Versionsarchiv hält die zentralen Grunddateien jeder ausdrücklich freigegebenen Version lokal und schnell zugänglich. Es unterstützt die Nachvollziehbarkeit, den Vergleich und die Wiederherstellung früherer freigegebener Projektstände, ohne große Unreal-Assets mehrfach zu kopieren.

Das Versionsarchiv ersetzt Git oder GitHub nicht. Git/GitHub bleibt die vollständige technische Historie für Code, Content, Assets, Commits, Zusammenarbeit und die Wiederherstellung vollständiger Projektstände.

---

## 2. Freigabe als zwingende Voraussetzung

Ein offizielles Versionsarchiv wird ausschließlich erstellt, nachdem die betreffende Version ausdrücklich durch den Projektleiter freigegeben wurde:

**Jens Würger**

Nicht ausreichend sind:

* erfolgreicher Build
* erfolgreicher Runtime-Test
* Release-Candidate-Status
* Commit oder Push
* Merge
* technische Fertigstellung
* Bewertung oder Empfehlung durch Codex

Vor der ausdrücklichen Freigabe darf kein Ordner `Version_Archive/vX.X.X/` für die betreffende Version erzeugt werden.

---

## 3. Archivpfad und Benennung

Das lokale Archiv liegt unter:

`E:\Projekt_Arcade_Shooter\Version_Archive`

Jede freigegebene Version erhält genau einen eigenen Ordner im Format:

```text
Version_Archive/
├── v0.0.1/
├── v0.0.2/
├── v0.0.3/
└── v0.1.0/
```

Der Pfad `Version_Archive/` ist über `.gitignore` von der regulären Git-Historie ausgeschlossen. Der Ordner wird erst angelegt, wenn erstmals eine freigegebene Version archiviert werden muss.

---

## 4. Verpflichtender Archivinhalt

Jede Archivversion enthält mindestens:

```text
Version_Archive/vX.X.X/
├── ARCHITECTURE_CHARTER.md
├── ROADMAP.md
├── VERSION.md
├── README.md
├── VERSION_ARCHIVE_POLICY.md
├── RELEASE_INFO.md
│
└── Arcade_Shooter/
    ├── Arcade_Shooter.uproject
    ├── Config/
    └── Source/
```

Wenn eigene Plugins verwendet werden, werden zusätzlich deren relevante Grunddateien archiviert:

```text
Plugins/
└── CustomPlugin/
    ├── CustomPlugin.uplugin
    ├── Source/
    └── Config/
```

Große Plugin-Content-Assets werden nicht automatisch dupliziert.

---

## 5. Grundsätzlich ausgeschlossene Inhalte

Folgende Verzeichnisse werden nicht in jede Archivversion kopiert:

```text
Arcade_Shooter/Content/
Arcade_Shooter/Binaries/
Arcade_Shooter/DerivedDataCache/
Arcade_Shooter/Intermediate/
Arcade_Shooter/Saved/
```

Ebenfalls ausgeschlossen sind grundsätzlich:

* IDE-Caches
* temporäre Dateien
* Build-Caches
* automatisch erzeugte Dateien
* große Grafiken
* Audio-Dateien
* Animationen
* Texturen
* Meshes
* andere große Content-Assets

Diese Inhalte werden nicht dupliziert, sofern ihr vollständiger Versionsstand über den dokumentierten Git Commit eindeutig reproduzierbar ist.

---

## 6. Verpflichtende RELEASE_INFO.md

Jede Archivversion enthält eine `RELEASE_INFO.md` mit mindestens folgenden Metadaten:

```text
Version:
Approval Status:
Approved By:
Approval Date:

Git Commit:
Git Tag: optional, falls vorhanden

Unreal Engine Version:
Previous Approved Version:
```

Der Eintrag `Git Commit` ist verpflichtend und muss auf den finalen freigegebenen Projektstand zeigen. Ein Git Tag ist optional.

Zusätzlich enthält `RELEASE_INFO.md` einen verständlichen Änderungsbericht mit den jeweils zutreffenden Bereichen:

### Added

Neue Systeme, Gameplay-Funktionen, Klassen, Features und Einstellungen.

### Changed

Änderungen an bestehendem Verhalten, Architektur, Datenstrukturen, Steuerung oder Konfiguration.

### Improved

Verbesserungen an Performance, Stabilität, Bedienbarkeit, Code-Struktur, Modularität oder Balancing.

### Fixed

Behobene Fehler.

### Removed

Tatsächlich entfernte oder ersetzte Bestandteile. Dieser Bereich wird nur verwendet, wenn etwas entfernt wurde.

### Known Issues

Bekannte Fehler und Einschränkungen der freigegebenen Version.

### Technical Notes

Wichtige Migrationen, Abhängigkeiten, Toolchain-Eigenheiten und relevante Architekturentscheidungen.

---

## 7. Tatsächlicher Projektstand als Quelle

Codex darf keine Änderungen oder Testergebnisse erfinden. `RELEASE_INFO.md` wird aus dem tatsächlichen Git-Diff, den Testergebnissen und der Projektdokumentation der freigegebenen Version erstellt.

Nach Möglichkeit wird der Unterschied zur vorherigen freigegebenen Version geprüft, beispielsweise `v0.0.1` zu `v0.0.2`. Der dokumentierte Git Commit muss den vollständigen Content- und Asset-Stand reproduzierbar machen.

---

## 8. Unveränderlichkeit

Ein erstellter und geprüfter Archivordner ist ein unveränderlicher historischer Snapshot.

Ein bestehender Ordner wie `Version_Archive/v0.0.1/` darf später nicht stillschweigend geändert, ergänzt oder überschrieben werden. Nachträgliche Projektänderungen erfordern eine neue Version, beispielsweise `v0.0.2`.

---

## 9. Verhältnis zwischen Git und Versionsarchiv

Git/GitHub dient für:

* vollständige Versions-, Code-, Content- und Asset-Historie
* Commits und Zusammenarbeit
* Wiederherstellung vollständiger Projektstände

Das Versionsarchiv dient für:

* schnelle lokale Übersicht freigegebener Versionen
* Projektdokumentation
* Source und Config
* Projektdefinition
* Release-Informationen
* schnellen Vergleich zentraler Grunddateien

Beide Systeme ergänzen sich. Keines ersetzt das andere.

---

## 10. Verbindliche Reihenfolge beim Versionsabschluss

```text
Entwicklung
↓
Build und Tests
↓
Release Candidate
↓
Review durch Jens Würger
↓
ausdrückliche Freigabe
↓
finalen freigegebenen Commit feststellen
↓
VERSION.md aktualisieren
↓
Versionsarchiv erstellen
↓
RELEASE_INFO.md erstellen
↓
Archiv prüfen
↓
Versionsabschluss dokumentieren
```

Git Tags können später ergänzt werden, sind für die Archivregel aber nicht verpflichtend.

Wenn eine freigegebene Version gemäß dieser Policy archiviert werden muss, ist der technische Versionsabschlussprozess erst vollständig dokumentiert, nachdem das Archiv korrekt erstellt und geprüft wurde. Die Freigabehoheit bleibt davon unberührt ausschließlich bei Jens Würger.

---

## 11. Abschlussprüfung des Archivs

Bei jedem zukünftigen Versionsabschluss ist zu prüfen:

1. Liegt die ausdrückliche Freigabe durch Jens Würger vor?
2. Wurde der richtige Versionsordner erstellt?
3. Sind alle erforderlichen Grunddateien enthalten?
4. Ist `RELEASE_INFO.md` vollständig?
5. Entspricht der Änderungsbericht dem tatsächlichen Projektstand?
6. Ist der korrekte Git Commit Hash dokumentiert?
7. Sind bekannte Fehler und Einschränkungen dokumentiert?
8. Wurden keine Unreal-Generatorverzeichnisse kopiert?
9. Wurden keine unnötigen großen Content-Assets dupliziert?
10. Ist ein bereits bestehender Archivstand unverändert geblieben?

Codex darf eine Freigabe niemals selbst erteilen.

---

## 12. Wiederherstellung einer alten Version

Zur Untersuchung oder Wiederherstellung einer alten Version:

1. `RELEASE_INFO.md` lesen.
2. Den dokumentierten Git Commit identifizieren.
3. Die zentralen Grunddateien aus dem Archiv verwenden.
4. Falls alter Content oder andere Assets benötigt werden, den dokumentierten Git Commit beziehungsweise den zugehörigen Git-Stand verwenden.

Das Archiv ist nicht dafür vorgesehen, sämtliche Assets mehrfach lokal vorzuhalten.

---

## 13. Aktueller Stand

Durch die Einführung dieser Policy wird kein Versionsarchiv erstellt. Insbesondere wird noch kein Ordner `Version_Archive/v0.0.1/` angelegt.

Version `0.0.1` bleibt `In Development` und ist nicht freigegeben. Diese Policy selbst gilt erst nach ausdrücklicher Freigabe durch Jens Würger als verbindlich eingeführt.
