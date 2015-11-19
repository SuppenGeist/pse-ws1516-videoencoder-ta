### (Name änderbar)
# Pflichtenheft zu Vive

Carina Weber, Jan Bendeikt Schwarz, Johannes Werner, Noel Schuhmacher, Sasha Rapp, Simon
Grafenhorst

## 0. Einleitung
Aletheia ist ein Programm zum Testen verschiedener Videoencoder. Man hat die Moeglichkeit ein
Video (mit Filtern) zu bearbeiten welches dann von einem externen Encoder encodiert wird.
Dieses encodierte Video kann dann wieder in Aletheia geladen werden, und so komfortabel
mit graphischen Visualisierungen entschieden werden kann, wie gut der Encoder das Video
encodiert hat.

## 1. Zielbestimmung
Aletheia ist ein Multimedia-Framework zur Evaluation von Videoencodern.

### 1.1 Musskriterien
#### 1.1.1 Rohvideo auswählen und bearbeiten
* Video laden
* Aus einer List von Filtern mehrere Filter auswählen
* Aus einer List von Artefakten mehrere Artefakte auswählen
* Filter/Artefakte anpassen
* Zuvor verwendete Konfigurationen (Filter/Artefakte) auswählen
* Anzeigen einer Vorschau mit den angewandten Filtern/Artefakten
* Video abspeichern

#### 1.1.2 Bewerten des Encoders
* Mehrere encodierte Videos laden
* Bewertungskriterien berrechnen
* Unterschiede zwischen Roh- und encodiertem Video visualisieren
* Bewertungskriterien/Videoeigenschaften/Metadaten visualisieren
* Roh- und encodierte(s) Video(s) nebeneinander synchron abspielen

#### 1.1.3 Sonstiges
* Zustand des Programms als Projekt speichern
* Projekt laden

### 1.2 Wunschkriterien
* Encoder integrieren
* Manuelles Bewertungssystem
* Pluginsystem für Filter und Artefakte

### 1.3 Abgrenzungskriterien
* Audio wird nicht beachtet
* Die Software ist ausschließlich in deutscher Sprache verfügbar

## 2. Produkteinsatz
Aletheia soll es Forschunkghseinrichtungen und Firmen ermöglichen Videoencoder einfach
miteinander zu vergleichen. So kann schnell ein optimaler Encoder für den jeweiligen Zweck
gefunden oder die Qualität eines vorhandenen geprüft werden. Aber auch Privatpersonen können
mit diesem Produkt die Funktionsweise eines Encoders kennenlernen oder ein Encoder für ein
Privatprojekt auswählen.

### 2.1 Anwendungsbereiche
* Forschungsprojekte
* Kommerzielle Softwarentwicklung
* Privatprojekte

### 2.2 Zielgruppe
* Forscher im Bereich Multimedia
* Videoplattformbetreiber
* Videobearbeiter
* Privatanwender

### 2.3 Betriebsbedingungen
Die Betriebsbedingungen unterscheiden sich im wesentlichen nicht zu denen normaler Software:
* Büroumgebung
* Laufzeit von bis zu 8h pro Tag ist zu erwarten


## 3. Produktumgebung
### 3.1 Hardware
* AMD64 Prozessorarchitektur
* Intel: Pentium 4 oder neuer
* AMD: Athlon II, Phenom II oder neuer
* Mindestens 50 MB freier Festplattenspeicher
* Mindestens 4 GB Arbeitsspeicher

### 3.2 Software
* Linux 64 bit (getestet auf Ubuntu)
* Qt Bibliothek 5.5.1

## 4. Funktionale Anforderungen
### 4.1 Musskriterien
#### 4.1.0 Allgemein
##### /F0000/ Steuerlemente für Videos
Videos können mit folgenden Steuerelementen angeschaut werden:
* Start/Pause-Button
* Stop-Button
* Timeline
* Geschwindigkeitsauswahl:
    * Frame by Frame
    * 0.25x
    * 0.5x
    * 0.75x
    * 1.0x
    * 1.25x
    * 1.5x
    * 1.75x
    * 2.0x

##### /F0010/ Akzeptierte nicht encodede Dateitypen
* YUF

##### /F0020/ Akzeptierte encodierte Dateitypen
* kommt noch

#### 4.1.1 Rohvideo auswählen und bearbeiten
##### /F0100/ Auswahl mit Dateiauswaldialog
Auswahl eines Videos mit einem Dateiauswahldialog. Erlaubte Dateitypen wie in /F0010/.
##### /F0110/ Auswahl kürzlich ausgewählter Videos
Auswahl aus einer Liste mit den 10 zuletzt ausgewählten
Videos.
##### /F0120/ Auswahl von Filtern
Auswahl von einem oder mehreren Filter, die auf das Video gelegt werden.
##### /F0121/ Filter: Schwarzweiß
Ein Schwarzweißfilter mit einstellbaren Eigenschaften:
* Helligkeit

##### /F0122/ Filter: Unschärfe
Ein Unschärfefilter mit folgenden einstellbaren Egenschaften:
* Helligkeit
* Grad der Unschärfe

##### /F0123/ Filter: Farbe
Ein Farbfilter mit folgenden einstellbaren Eigenschaften:
* Helligkeit
* Farbe(n) die herausegefiltert werden sollen
* Intensität der einzelnen Farben

##### /F0124/ Fiter: Kontrast
Ein Kontrastfilter mit den folgenden einstelbaren Eigenschften:
* Helligkeit
* Stärke des Kontrastes

##### /F0130/ Auswahl von Artefakten
Auswahl von einem oder mehreren Artefakten, die auf das Video gelegt werden.

##### /F0131/ Artefakt: Gittermuster
Ein Gittermuster mit den folgenden einstellbaren Eigenschaften:
* Anzahl der vertikalen und horizontalen Linien
* Farbe
* Helligkeit
* Dicke der Linien

##### /F0132/ Artefakt: Schriftzug
Ein Schriftzug mit fixer Position und folgenden Eigenschaften:
* Schriftgröße
* Farbe
* Text

##### /F0140/ Anwendugsreihenfolge von Filtern/Artefakten
Filter und Artefakte werden in der Reihenfolge angewendet, in der sie ausgewählt wurden.

##### /F0150/ Ändern der Anwendungsreihenfolge
Die Anwendungsreihenfolge der Filter/Artefakte kann beliebig geändert werden.

##### /F0160/ Entfernen ausgewählter Filter/Artefakte
Ausgewählte Filter/Artefakte können wieder entfernt werden.

##### /F0170/ Abspeichern einer Filter/Artefakte Konfiguration
Abspeichern der Konfiguration von Filtern/Artefakten. Abgespeichert wird:
* Welche Filter/Artefakte ausgewählt wurden
* Reihenfolge in der die Filter/Artefakte angewendet werden sollen
* Jeweiligen Zustand der einstellbaren Eigenschaften der Filter/Artefakte

##### /F0180/ Anzeigen einer Vorschau
Die Vorschau des ausgewählten Videos mit den ausgewählten Filtern und Artefakten besteht aus zwei Stufen:
##### /F0181/ 5 Frame Vorschau
Jedes mal, wenn der Benutzer etwas an den Artefakten/Filtern ändert, werden 5 Frames aus dem Video sofort gerendert.
##### /F0182/ Komplette Vorschau
Nachdem der Nutzer auf ein entsprechenden Button geklickt hat, kann er das ausgewählte Video mit allen ausgewählten Filtern und Artefakten angeschauen. Steuerelemente wie in /F0000/.

##### /F0190/ Speichern des Videos
Das veränderte Video kann abgespeichert werden. Das Dateiformat ist dasselbe wie das des Inputvideos.

## 5. Produktdaten

## 6. Nichtfunktionale Anforderungen

## 7. Benutzeroberflaeche

## 8. Qualitaetsbestimmung

## 9. Globale Testfaelle und Szenarien

## 10. Glossar

### Artefakt
Eine Struktur, die über das Video gelegt wird, um den Encoder zu verwirren.

### Encoder
Ein Programm zum komprimieren von Video Dateien.

### Filter
Ein Algorithmus, der Farbwerte nach einem bestimmten Muster verändert.
