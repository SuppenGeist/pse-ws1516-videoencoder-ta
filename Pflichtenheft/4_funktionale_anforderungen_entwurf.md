# 4. Nichtfunktionale Anforderungen
## 4.1 Encoder auswählen
#### /F010/ Encoder auswählen
Der Benutzer kann mittels eines Dateiauswahldialogs eine ausführbare Datei (ELF32,ELF64) auswählen.
Das Programm muss ein über das Terminal gestartet werden können und das zu encodende Video als
Argument übernehmen.

#### /F020/ Encoder aus Liste wählen
Der Benutzer hat die Möglichkeit einen Encoder aus einer Liste zu wählen, in der die letzten 5 zuvor
verwendeten Encoder stehen. Das Programm prüft vor dem Anzeigen der Encoder ob diese noch existieren.

## 4.2 Video auswählen
#### /F110/ Video wählen
Der Benutzer kann mittels eines Dateiauswahldialogs ein Video (Dateityp:???) auszuwählen. Dieses
Video wird später encodiert werden.

#### /F120/ Video aus Liste wählen
Der Benutzer hat die Möglichkeit ein Video aus einer Liste zu wählen, die die letzten 10 encodierten
Videos enthält. Das Programm prüft vor dem Anzeigen der Videos, ob diese noch existieren.

#### /F130/ Filter auswählen
Der Benutzer hat die Möglichkeit einen einzigen Filter aus einer Liste vorgefertigter Filter
auszuwählen. Vorhandene Filter:
   * Schwarzweiß-Filter
   * Unschärfe-Filter
   * ???

Natürlich besteht auch die Möglichkeit die Selektion wieder aufzuheben.

#### /F140/ Artefakt auswählen
Der Benutzer hat die Möglichkeit ein einziges Artefakt/Muster aus einer Liste vorgefertigter
Artefakte/Muster auszuwählen. Diese Liste enthält folgende:
   * Gitter-Muster
   * ???

Natürlich besteht auch die Möglichkeit die Selektion wieder aufzuheben.

#### /F150/ Vorschau anzeigen
Der Benutzer hat die Möglichkeit, wenn er ein Artefakt oder ein Muster ausgewählt hat, sich eine
Vorschau anzeigen zu lassen. Diese Vorschau besteht aus 5 Frames. Diese Frames sind jeweils bei
1/5,2/5,... der gesamten Frameanzahl entnommen. Auf diese Frames wird der Filter bzw. Artefakt
angewendet. Der Benutzer kann durch alle 5 Frames durchschalten. Wurde ein Artefakt und ein Filter
gleichzeitig ausgewählt, wird erst das Artefakt angewendet, dann der Filter und wird die
Vorschau angezeigt.

#### /F160/ Filter/Artefakt anwenden
Der Benutzer muss den Filter/Artefakt erst anwenden, bevor das Video damit encodiert wird. Tut er
das nicht, wird einfach das Originalvideo codiert. Wenn er es tut, wird eine neue Videodatei mit
dem Filter/Artefakt erzeugt. Ändert er Filter/Artefakt und wendet erneut an, wird wieder eine neue
Datei erstellt, allerdings die vorherige wieder gelöscht.

#### /F170/ Vorschau des kompletten Videos
Hat der Benutzer den Filter/Artefakt angewandt, hat er die Möglichkeit, sich das komplette neue
Video anzuschauen. Steuerelemente für das Video sind dabei lediglich Start/Pause/Restart Buttons.

## 4.3 Video encodieren
#### /F210/ Video encodieren
Der Benutzer kann, wenn er ein Video und Encoder ausgewählt hat, das ausgewählte Video mit dem
ausgewählten Encoder codieren.

## 4.4 Bewertung des Encoders
#### /F310/ Anschauen des codierten und rohen Videos
Der Benutzer kann das Rohvideo sowie das codierte anschauen. Dabei sind beide Videos gleichzeitig
zu sehen. Steuerelemente sind Start/Pause/Stop sowie eine Timeline. Es gibt nur einen Satz
Steuerelemente für beide Videos. D.h. die Videos können nur synchron angeschaut werden.

#### /F320/ Einstellen der Abspielgeschwindigkeit
Der Benutzer kann die Videos aus /F310/ in verschiedenen Geschwindigkeiten abspielen. Zugelassen
sind:
   * Frame by Frame
   * 0.25
   * 0.5
   * 0.75
   * 1.0
   * 1.25
   * 1.5
   * 1.75
   * 2.0

#### /F330/ Bewertungskriterien anzeigen
Bewertungskriterien zum Encoder und Video werden angezeigt. Folgende Kriterien/Gegenüberstellungen
gibt es:
   * PSNR
   * Dateigröße
   * Encodierungsdauer
   * ???

#### /F340/ Unterschied zwischen Roh- und encodiertem Video anzeigen
Der Benutzer kann sich die Farbabweichungen jeweils von RGB vom Roh- und encodiertem Video
anzeigen lassen.

#### /F350/ Interressante Eigenschaften des encodierten Videos anzeigen
Der Benutzer kann sich interressante Eigenschaften im encdierten Video anzeigen:
   * Makroblöcke
   * ???
