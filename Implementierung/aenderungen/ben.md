## Allgemein
Fuege bei Attributen einen Unterstrich ( _ ) ans Ende der Namen hinzu.
## MainWindow
Aendere Rueckgabetyp von getProject zu pointer.
<br><b>Grund:</b> Es kann auch kein project geladen sein.
<hr>

##filterTab
moveFilter(int old, int new) zu moveFilter(int oldIndex, newIndex) umbenannt
<b>Grund:</b> "new" ist kein guter Name f�r einen Parameter.
<hr>

##FilterView
f�ge methode uncheck() hinzu
<b>Grund</b> keine m�glichkeit die checkbox von FilterCOntainerTab aus zu erreichen.
<hr>

##AnalyisTab
f�ge ui hinzu
<b>Grund</b> Einfacher das interface zu gestalten
�ndere controlpanel zu playerPanel_  
�ndere yuvVideo zu rawVideo
�ndere player und rawVideo zu unique_ptr
<b>Grund</b> Gleiche funktion wie im filtertab, leichtere Orientierung

