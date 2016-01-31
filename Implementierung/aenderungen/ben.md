## Allgemein
Fuege bei Attributen einen Unterstrich ( _ ) ans Ende der Namen hinzu.
## MainWindow
Aendere Rueckgabetyp von getProject zu pointer.
<br><b>Grund:</b> Es kann auch kein project geladen sein.
<hr>

##filterTab
moveFilter(int old, int new) zu moveFilter(int oldIndex, newIndex) umbenannt
<b>Grund:</b> "new" ist kein guter Name für einen Parameter.
<hr>

##FilterView
füge methode uncheck() hinzu
<b>Grund</b> keine möglichkeit die checkbox von FilterCOntainerTab aus zu erreichen.
<hr>