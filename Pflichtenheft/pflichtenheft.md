# Pflichtenheft zu Vive

Carina Weber, Jan Bendeikt Schwarz, Johannes Werner, Noel Schuhmacher, Sasha Rapp, Simon
Grafenhorst

## 0. Einleitung
Vive (lang: Video veritatem) ist ein Programm zum Testen verschiedener Videoencoder. Man hat die Möglichkeit ein
Video (mit Filtern) zu bearbeiten welches dann von einem externen Encoder encodiert wird.
Dieses encodierte Video kann dann wieder in Vive geladen werden, wo so komfortabel
mit graphischen Visualisierungen entschieden werden kann, wie gut der Encoder das Video
encodiert hat.

## 1. Zielbestimmung
Vive ist ein Multimedia-Framework zur Evaluation von Videoencodern.

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
Vive soll es Forschungseinrichtungen und Firmen ermöglichen Videoencoder einfach
miteinander zu vergleichen. So kann schnell ein optimaler Encoder für den jeweiligen Zweck
gefunden oder die Qualität eines vorhandenen geprüft werden. Aber auch Privatpersonen können
mit diesem Produkt die Funktionsweise eines Encoders kennenlernen oder einen Encoder für ein
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
* Laufzeiten von bis zu 8h pro Tag sind zu erwarten


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
* YUV

##### /F0020/ Akzeptierte encodede Dateitypen
* GStreamer kompatible Dateitypen

##### /F0030/ Anzeigen von Aktionen in Statusleiste
Folgende Aktionen werden in der Statusleiste angezeigt, falls sie aktiv sind:
* Anwenden von Filtern/Artefakten
* Speichern des veränderten Videos
* Laden der encodierten Videos (also Berrechnung von PSNR,etc.)
* Speichern des Zustandes des Programms
* Laden des Zustandes des Programms


#### 4.1.1 Rohvideo auswählen und bearbeiten
##### /F0100/ Auswahl mit Dateiauswaldialog
Auswahl eines Videos mit einem Dateiauswahldialog. Erlaubte Dateitypen wie in /F0010/.
##### /F0110/ Auswahl kürzlich ausgewählter Videos
Auswahl aus einer Liste mit den 10 zuletzt ausgewählten
Videos.
##### /F0120/ Auswahl von Filtern
Auswahl von einem oder mehreren Filtern, die auf das Video gelegt werden.
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
Ein Kontrastfilter mit den folgenden einstelbaren Eigenschaften:
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
Ein neu ausgewählter Filter/Artefakte wird ans Ende der Anwendungsreihenfolge angehängt.

##### /F0150/ Ändern der Anwendungsreihenfolge
Die Anwendungsreihenfolge der Filter/Artefakte kann beliebig geändert werden.

##### /F0160/ Entfernen ausgewählter Filter/Artefakte
Ausgewählte Filter/Artefakte können wieder entfernt werden.

##### /F0170/ Abspeichern einer Filter/Artefakte Konfiguration
Abspeichern der Konfiguration von Filtern/Artefakten. Abgespeichert wird:
* welche Filter/Artefakte ausgewählt wurden
* die Reihenfolge in der die Filter/Artefakte angewendet werden sollen
* der jeweilige Zustand, der einstellbaren Eigenschaften der Filter/Artefakte

##### /F0180/ Anzeigen einer Vorschau
Die Vorschau des ausgewählten Videos mit den ausgewählten Filtern und Artefakten besteht aus zwei Stufen:
##### /F0181/ 5 Frame Vorschau
Jedes mal, wenn der Benutzer etwas an den Artefakten/Filtern ändert, werden 5 Frames aus dem Video sofort gerendert.
##### /F0182/ Komplette Vorschau
Nachdem der Nutzer auf einen entsprechenden Button geklickt hat, kann er das ausgewählte Video mit allen ausgewählten Filtern und Artefakten angeschauen. Steuerelemente wie in /F0000/.

##### /F0190/ Speichern des Videos
Das veränderte Video kann abgespeichert werden. Das Dateiformat ist dasselbe wie das des Inputvideos.

##### /F01100/ Laden einer Filter/Artefakte Konfiguration
Gespeicherte Konfigurationen können wieder geladen werden.
##### /F01110/ Alles zurücksetzen
Ausgewählte Filter und Artefakte können alle auf einmal entfernt werden.

#### 4.1.2 Encodede Videos bewerten
##### /F0200/ Encodierte Videos laden
Laden von mehreren enodierten Videos. Akzeptierte Dteitypen wie in /F0020/.
##### /F0210/ Anzeigen der encodierten Videos
Die geladenen Videos können angeschaut werden.
##### /F0220/ Anzeigen des Rohvideos
Das Rohvideo kann angeschaut werden.
##### /F0230/ Steuerelemente
Alle Videos aus /F0210/ und /F0220/ teilen sich einen Satz Steuerelemente. Steuerlemente wie in /F0000/.
##### /F0240/ Anzeigen von Dateiattributen
Folgende Dateiattribute der Videodateien werden angezeigt:
* Dateiname
* Dateigröße

##### /F0250/ Anzeigen eines RGB-Histogramms
Für jedes Video wird ein RGB-Histogramm angezeigt.
##### /F0260/ Anzeigen eines PSNR-Graphen
Für jedes Video wird ein PSNR-Graph angezeigt.
##### /F0270/ PSNR-Graph als Timeline
Durch klicken auf den PSNR-Graph wird zu der dazugehörigen Stelle im Video gesprungen (bei allen geladenen Videos wird zu dieser Stelle gesprungen).
##### /F0280/ Farbunterschied zwischen Roh- und encodiertem Video anzeigen
Anzeigen der Farbdifferenz der einzelnen Farbkanäle zwischen dem Roh- und encodiertem Video.
##### /F0290/ Anzeigen von Makroblöcken
Falls der Encoder Makroblöcke zum komprimieren verwendet hat, können diese angezeigt werden.
##### /F02100/ Speichern des Zustands
Der Zustand des Programms  kann gespeichert werden. Gespeichert wird dabei folgendes:
* Absoluter Pfad zum Rohvideo
* Absoluter Pfad zu allen geladenen encodierten Videos
* Aktuelle Abspielstelle in den Videos

##### /F02110/ Laden eines Zustandes
Gespeicherte Zustände können wieder gelden werden.

### 4.2 Wunschkriterien
#### 4.2.1 Encoder integrieren
##### /F1100/ Laden eines Encoders
Der Encoder, der verwendet werden soll, kann mit einem Dateiauswahldialog ausgewählt werden.
##### /F1110/ Akzeptierte Dateitypen für Encoder
Akzeptiert werden ELF32,ELF64 Dateien.
##### /F1120/ Encoder interface
Der Encoder mussüber eine Konsole aufgerufen werden können mit dem Dateinamen zum zu encodierendem Video und verschiedene Encodierungsmodi als Parameter.
##### /F1200/ Spezifizieren von Parametern
Man kann Parameter angeben, die dem Encoder übergeben werden.
##### /F1210/ Parameterliste
Mehrere verschiedene Parameter werden in einer Liste zusammengefasst.
##### /F1220/ Mehrfaches aufrufen des Encoders
Für jeden Eintrag in der Liste aus /F1210/ wird der Encoder aufgerufen.
##### /F1300/ Gewährleistung
Wenn der Encoder nicht korrekt arbeitet (z.B. nicht terminiert), kann die Korrektheit von Vive nicht grantiert werden.
##### /F1400/ Laden der encodierten Videos
Wenn alle encodierten Videos erzeugt wurden, werden sie automatisch geladen.

#### 4.2.2 Manuelles Bewertungssystem
##### /F2100/ Bewerten der encodierten Videos
Die Qualität eines encodierten Videos kann mit einem 5-Sterne Bewertungssystem bewertet werden.
##### /F2200/ Speichern des Zustandes
Zusätzlich zu den in /F02100/ spezifizierten Attributen wird die 5-Sterne Bewertung gespeichert.
##### /F2300/ Laden eines Zustandes
Beim Laden eines Zustandes wie in /F02100/ wird auch die 5-Sterne Bewertung geladen.

#### 4.2.3 Pluginsystem für Filter und Artefakte
##### /F3100/ Dynamisches Laden von Plugins
Beim Programmstart werden Filter und Artefakte dynamisch geladen.


## 5. Produktdaten
### 5.1 Musskriterien
##### /D010/ Filter/Artefakt Konfiguration
Wie in /F0170/ spezifiert:
* Ausgewählte Filter/Artefakte
* Reihenfolge der Filter/Artefakte
* Zustand der einstellbaren Eigenschaften der Filter/Artefakte

##### /D020/ Zustand
Wie in /F02100/ spezifiert:
* Absoluter Pfad zum Rohvideo
* Absolute Pfade zu den encodierten Videos
* Abspielposition der Videos

##### /D030/ Zuletzt ausgewählte Videos
Wie in /F0110/ spezifiert:
* Absoute Pfade zu den 10 zuletzt ausgewählten Videos

### 5.2 Wunschkriterien
#### 5.2.1 Manuelles Bewertungssystem
##### /D110/ 5-Sterne Bewertung
Wie in /F2200/ spezifiert.
## 6. Nichtfunktionale Anforderungen
##### /L010/ Responsive GUI
Auch bei rechenintensiven Hintergrundaktionen bleibt die GUI responsive.
##### /L020/ Fehlerrobust
Bei Fehlerhaften Videodateien oder Nutzereingaben soll das Programm nicht abstürzen.
## 7. Benutzeroberfläche

## 8. Qualitätsbestimmung
Kann aus PDF übernommen werden.

## 9. Globale Testfälle und Szenarien

## 10. Glossar
#### Benutzer
Weibliche oder männliche Person, die das Programm benutzt.

#### Artefakt
Eine Struktur, die über das Video gelegt wird, wie zum Beipspiel ein Kreis oder eine Linie.

#### Encoder
Ein Programm zum komprimieren von Videodateien.

#### Filter
Ein Algorithmus, der Farbwerte nach einem bestimmten Muster verändert.

#### RGB-Histogramm
Ein Graph, der die Farbverteilung eines Videos anzeigt.
#### PSNR-Graph
Ein Graph der auf der x-Achse Zeitwerte(Framenummer) enthält und auf der y-Achse den dazugehörigen PSNR-Wert
#### 5-Sterne Bewertungssystem
5 Sterne zur Bewertung, wobei 1 Stern die niedrigste Bewertung ist und 5 Sterne die höchste.
