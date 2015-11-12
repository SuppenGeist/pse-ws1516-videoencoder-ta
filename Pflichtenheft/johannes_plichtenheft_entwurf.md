# Pflichtenheft
## 1. Zielbestimmung
Das Programm soll es ermöglichen, verschiedene Video codecs auf ihre Qualität zu untersuchen.
### 1.1 Musskriterien
* #### Codieren von Videos
    * Auswählen eines eigenen Codierers
    * Codieren von Videos mittels diesem encoder
    * Auswählen von Videos die kürzlich codiert wurden
    * Auswählen von kürzlich verwendeten Encodern


* #### Abspielen von Videos
    * Das synchronisierte Abspielen des codiereten and rohen Videos in seperaten Views
    * Das synchroniesierte Vergleichen bei beliebiger Geschw. des codierten und rohen Videos
    * Das Anzeigen von Unterschieden im rohen und codierten Video
    * Abspielen des Videos bevor es codiert wurde


* #### Unterstützte Videoformate zum encodieren
    * Encoder abhängig


* #### Unterstützte Videoformate zum decodieren
    * ???


* #### Anzeigen von Bewertungskriterien des Codierers
    * PSNR
    * Dateigröße
    * Encodierungsdauer


* #### Verändern des Originalvideos
    * Schwarzweiß-Filter
    * Unschärfe-Filter
    * Rauschen-Filter

### 1.2 Wunschkriterien

* #### Verändern des Originalvideos
   * Artefakte einfügen wie z.B. ein Gitter, Kreise, etc.

## 2. Produkteinsatz
Das Produkt dient zum Vergleichen von vershciedenen Videoencodern.
### 2.1 Anwendungsbereiche
Das Programm soll hauptsächlich von Forschungsprojekten verwendet werden, um eigene Encoder
objektiv mit der Konkurrenz vergleichen zu können.
### 2.2 Zielgruppe
Menschen.
### 2.3 Betriebsbedingungen
* 24/7
* Wartungsfrei


## 3. Produktumgebung
* ### 3.1 Hardware
    * Gewöhnlicher Desktop-PC mit einem x86_64 Prozessor


* ### 3.2 Software
    * Linux 64 bit
    * Qt-Bibliothek

## 4. Funktionale Anforderungen

#### /F10/ Auswählen eines Encoders
Über einen Dateiauswähldialog kann der Nutzer ein ausführbares Programm auswählen, welches
über ein Kommandozeilenargument das Video entgegen nimmt, welches encoded werden soll.
Akzeptierte ausführbare Dateien sind das ELF32 sowie ELF64 Format.

#### /F20/ Auswählen von kürzlich codierten Videos
Der Nutzer hat die Möglichkeit sich die letzten 10 (die konkeret Zahl ist anpassbar, 10 ist
default) codierten Videos anzeigen zu lassen und diese aus dieser Liste zu wählen. Das
Programm prüft natprlich vor dem Anzeigen ob diese Videos tatsächlich noch existieren.

#### /F30/ Auswählen von kürzlich verwendeten Encodern
Der Nutzer hat die Möglichkeit sich die letzten 5 (konkerete Zahl ist anpassbar,5 ist default)
verwendeten Encoder anzeigen zu lassen und aus dieser Liste zu wählen. Das Programm prüft
natürlich vor dem Anzeigen ob die entsprechenden Encoder tatsächlich noch existieren.

#### /F40/ Codieren von Videos
Hat der Nutzer ein Video und einen Encoder gewählt, kann er es codieren lassen.

#### /F50/ Abspielen des codierten und rohen Videos
Nachdem das Video codiert wurde, kann der Nutzer das codierte und das rohe Video nebeneinander
synchron abspielen.

#### /F60/ Abspielen des codierten und rohen Videos auf beliebiger Geschwindigkeit
Neben dem Abspielen auf normaler Geschwindigkeit ist es dem Benutzer möglich, das Video mit
1.25x,1.5x,1.75x,2.0x,0.75x,0.5x,0.25x Geschwindigkeit abzuspielen sowie Frame by Frame.

#### /F70/ Auf das Rohvideo einen Filter legen
Der Nutzer hat die Möglichkeit, vor dem codieren des Videos einen Filter auf das Video zu
legen. Unterstützte Filter sind:
   * Schwarzweiß-Filter
   * Unschärfe-Filter
   * Rauschen-Filter

####  /F80/ Abspielen des Videos vor dem Codiervorgang
Der Nutzer hat die Möglichkeit, vor dem Codieren sich das Video anzugucken, so wie
es codiert wird. D.h. ist ein Filter ausgewählt, wird das Video mit dem entsprechendem
Filter abgespielt.

#### /F90/ Anzeigen von Encoderbewertung
Der Nutzer hat die Möglichkeit, sich verschiedene Bwertungen anzeigen zu lassen.
Die da wären: ...

## 5. Produktdaten

#### /D10/ Kürzlich codierte Videos
   * Der absolute Pfad zu dem Video sowie den Dateinamen

#### /D20/ Kürzlich verwendete Encoder
   * Der absolute Pfad zum Encoder sowie den Dateinamen

## 6. Nichtfunktionale Anforderungen

#### /NF10/
Jede Funktion sollte mit maximal 2 Klicks erreichbar sein.

#### /NF20/
Sollte eine Aktion längere Zeit benötigen, muss der Nutzer angemessen darüber informiert werden,
dass das Programm arbeitet und was es gerade tut.

## 7. Benutzungsoberfläche

## 8. Qualitätsbestimmung

## 9. Globale Testfälle und Szenarien
...Erst möglich, sowie alle Funktionalen Anforderungen stehen.
