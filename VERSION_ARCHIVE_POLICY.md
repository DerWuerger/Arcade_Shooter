# Version Archive Policy

Diese Policy definiert das lokale Versionsarchiv des Projekts `Arcade_Shooter`.

Sie ergänzt `ARCHITECTURE_CHARTER.md`, `ROADMAP.md`, `VERSION.md`, `README.md`, `AGENTS.md` und die vollständige Git-/GitHub-Historie. Bei Konflikten hat `ARCHITECTURE_CHARTER.md` Vorrang.

Policy Status: `Active`

---

## 1. Zweck

Das Versionsarchiv hält für jede offiziell veröffentlichte Version eine unveränderliche lokale Snapshot-Kopie bereit. Es unterstützt die Nachvollziehbarkeit, den Vergleich und die Wiederherstellung früherer freigegebener Projektstände.

Das Archiv ersetzt Git oder GitHub nicht. Git/GitHub bleibt die vollständige technische Historie für Code, Content, Assets, Commits, Zusammenarbeit und die Wiederherstellung vollständiger Projektstände.

---

## 2. Verbindliche Archivierungsregel

Bei jedem zukünftigen offiziellen Versionsabschluss muss automatisch eine lokale Archivkopie der veröffentlichten Version erstellt und validiert werden.

Ein offizieller Versionsabschluss ist ohne erfolgreich erstellte und validierte lokale Archivkopie nicht vollständig.

Diese Regel gilt für alle zukünftigen offiziellen Versionen, zum Beispiel:

* `v0.0.3`
* `v0.0.4`
* `v0.0.5`
* `v0.1.0`

---

## 3. Vollständiger Versionsabschluss

Ein Versionsabschluss gilt erst dann als vollständig, wenn alle folgenden Schritte abgeschlossen sind:

1. Implementierung abgeschlossen.
2. Validierung erfolgreich.
3. Versionsdokumentation aktualisiert.
4. Release-Commit erstellt.
5. `main` erfolgreich nach `origin/main` gepusht.
6. Versions-Tag `v<VERSION>` erstellt.
7. Versions-Tag erfolgreich zu `origin` gepusht.
8. Archivkopie exakt aus diesem veröffentlichten Tag erstellt.
9. Archivkopie validiert.
10. Arbeitsbaum anschließend sauber.

Codex muss diese Archivierung bei jedem zukünftigen offiziellen Versionsabschluss automatisch durchführen, ohne dass dafür eine erneute Einzelanweisung erforderlich ist.

---

## 4. Archivpfad und Benennung

Die lokale Archivwurzel liegt unter:

`D:\Projekt_Arcade_Shooter\Archive`

Jede offizielle Version erhält genau einen eigenen Ordner im Format:

```text
Archive/
├── v0.0.1/
├── v0.0.2/
├── v0.0.3/
└── v0.1.0/
```

Beispiele:

* `D:\Projekt_Arcade_Shooter\Archive\v0.0.3`
* `D:\Projekt_Arcade_Shooter\Archive\v0.0.4`
* `D:\Projekt_Arcade_Shooter\Archive\v0.1.0`

Bestehende Archivversionen dürfen niemals stillschweigend überschrieben oder verändert werden. Falls ein Archiv beschädigt ist oder repariert werden muss, ist dafür eine ausdrückliche Einzelanweisung erforderlich.

---

## 5. Quelle der Archivkopie

Die Archivkopie darf nicht aus dem aktuellen Arbeitsverzeichnis kopiert werden.

Quelle ist ausschließlich der gerade veröffentlichte Git-Tag:

`v<VERSION>`

Die archivierten Dateien müssen exakt dem Git-Stand dieses Tags entsprechen. Der Snapshot soll direkt aus Git erzeugt werden, beispielsweise über `git archive`, damit keine Dateien eines späteren oder bereits weiterentwickelten `main` versehentlich in das Archiv gelangen.

---

## 6. Archivinhalt

Übernommen werden alle Dateien, die im jeweiligen Release-Tag versioniert sind.

Dazu gehören je nach Version insbesondere:

* Unreal-Projektdateien
* `.uproject`
* `Source`
* `Config`
* versionierter `Content`
* `README.md`
* `ROADMAP.md`
* `VERSION.md`
* `VERSION`
* `VERSION_HISTORY.md`
* Architektur-/Design-Dokumentation
* sonstige versionierte Projektdateien

Nicht übernommen werden:

* `.git`
* `.vs`
* `Binaries`
* `DerivedDataCache`
* `Intermediate`
* `Saved`
* temporäre Build-Dateien
* lokale IDE-Dateien
* Cache-Dateien
* sonstige nicht versionierte Entwicklungsartefakte

---

## 7. ARCHIVE_INFO.md

In jedem Versionsarchiv wird zusätzlich eine lokale Datei erstellt:

`ARCHIVE_INFO.md`

Diese Datei muss mindestens enthalten:

* Version
* Versionsname
* Git-Tag
* vollständigen Release-Commit-Hash
* Status: `Completed`
* Archivierungsdatum
* Hinweis, dass dies eine unveränderliche lokale Archivkopie des veröffentlichten Releases ist

Beispiel:

```text
Version: `0.0.3`
Name: `<Versionsname>`
Git-Tag: `v0.0.3`
Release-Commit: `<vollständiger SHA>`
Status: `Completed`
Archive Date: `<YYYY-MM-DD>`

Hinweis: Immutable local archive snapshot of the published release.
```

`ARCHIVE_INFO.md` gehört ausschließlich zum lokalen Archiv. Sie darf keinen bereits veröffentlichten Release-Tag und keinen Release-Commit verändern.

---

## 8. Validierung jedes Archivs

Nach jeder Archivierung muss automatisch geprüft werden:

1. Archivordner existiert.
2. Verwendeter Tag zeigt auf den erwarteten Release-Commit.
3. Snapshot entspricht den versionierten Dateien des Tags.
4. `VERSION` entspricht der archivierten Version.
5. Zentrale Source-Dateien der Version sind vorhanden.
6. Keine Dateien späterer Commits sind enthalten.
7. Keine generierten Unreal-Buildordner sind enthalten.
8. Bestehende ältere Archive wurden nicht verändert.
9. Aktueller Git-Arbeitsbaum bleibt sauber.

Die strengste bevorzugte Prüfung ist ein Vergleich der archivierten Dateiliste und Blob-Inhalte gegen den Git-Tag. Wenn Windows-Zeilenenden eine bytegenaue Prüfung verfälschen würden, muss der Snapshot mit deaktivierter CRLF-Konvertierung erzeugt werden, zum Beispiel über `git -c core.autocrlf=false archive`.

---

## 9. Git-Verhalten des Archive-Ordners

`Archive/` bleibt lokal.

Archivkopien werden nicht committed, nicht gepusht und nicht in Versions-Tags aufgenommen.

`Archive/` soll lokal über `.git/info/exclude` ignoriert werden. Die öffentliche `.gitignore` wird nur geändert, wenn dies ausdrücklich zur bestehenden Projektstrategie passt. Standard ist weiterhin die lokale Ignorierung über `.git/info/exclude`.

---

## 10. Verhältnis zwischen Git und Versionsarchiv

Git/GitHub dient für:

* vollständige Versions-, Code-, Content- und Asset-Historie
* Commits und Zusammenarbeit
* Wiederherstellung vollständiger Projektstände

Das lokale Archiv dient für:

* schnelle lokale Übersicht veröffentlichter Versionen
* lokale Projekt- und Release-Dokumentation
* schnellen Vergleich zentraler Grunddateien
* reproduzierbare lokale Snapshots veröffentlichter Tags

Beide Systeme ergänzen sich. Keines ersetzt das andere.

---

## 11. Wiederherstellung einer alten Version

Zur Untersuchung oder Wiederherstellung einer alten Version:

1. `ARCHIVE_INFO.md` lesen.
2. Den dokumentierten Git-Tag und Release-Commit identifizieren.
3. Die zentralen Grunddateien aus dem Archiv verwenden.
4. Falls weiterer Content oder andere Assets benötigt werden, den dokumentierten Git-Tag beziehungsweise den zugehörigen Git-Stand verwenden.

---

## 12. Aktueller Stand

Aktueller veröffentlichter Projektstand: `0.0.3 - Aiming & Crosshair`.

Bestehende Archive unter `Archive/` bleiben unverändert. Diese Policy führt keine neue Projektversion ein, erhöht keine Versionsnummer und erstellt keinen neuen Versions-Tag.

Für zukünftige offizielle Versionsabschlüsse gilt dauerhaft:

`Future official version releases will automatically create and validate a local Archive\v<VERSION> snapshot from the published Git tag.`
