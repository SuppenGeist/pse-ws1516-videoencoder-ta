## Allgemein
Fuege bei Attributen einen Unterstrich ( _ ) ans Ende der Namen hinzu.
## MainWindow
Aendere Rueckgabetyp von getProject zu pointer.
<br><b>Grund:</b> Es kann auch kein project geladen sein.
<hr>

##filterTab
moveFilter(int old, int new) zu moveFilter(int oldIndex, newIndex) umbenannt
<br><b>Grund:</b> "new" ist kein guter Name f�r einen Parameter.
<hr>

##FilterView
f�ge methode uncheck() hinzu
<br><b>Grund</b> keine m�glichkeit die checkbox von FilterCOntainerTab aus zu erreichen.
<hr>

##AnalyisTab
f�ge ui hinzu
<br><b>Grund</b> Einfacher das interface zu gestalten
�ndere controlpanel zu playerPanel_  
�ndere yuvVideo zu rawVideo
�ndere player und rawVideo zu unique_ptr
<br><b>Grund</b> Gleiche funktion wie im filtertab, leichtere Orientierung
entferne LoadRawVideo
<br><b>Grund:</b> layout �nderung, selber Button wie addVideo;
f�ge methode loadYuvVideo und removeYuvVideo hinzu
<br><b>Grund:</b> erm�glicht einfacheres undo/redo
f�ge int anaTypShown hinzu
<br><b>Grund:</b> einfacher einem neuen Video zu sagen welches Analysevideo er zeigen soll.
f�ge Model::Project project_ mit setter hinzu
<br><b>Grund:</b> N�tig f�r Konstructor von ProjectWriter welcher Ergebnisse speichert.
<hr>
##AnalysisBoxContainer
f�ge addBox(int index, AnaBoxMemento memo) hinzu
<br><b>Grund:</b> erm�glicht einfaches hinzuf�gen der boxen f�r den Undo/ReDo Befehl.
<hr>
##AddVideo
aendere parameter des constructors zu GUI::AnalysisBox
nur AnalysisBox als Attribut
<br><b>Grund:</b> alle noetigen Infos kann man aus der Box erhalten. 
<hr>
##RemoveVideo
parameter nun AnaBox, AnaBoxMemento und AnaBoxContainer
<br><b>Grund:</b>AnaBox um zu entfernende box zu finden, memo um box wiederherzustellen, container zum finden des containers
<hr>
##LoadAnalysisVideo
entferne memento aus Parametern und Attributen
<br><b>Grund:</b> warum den Zustand speichern wenn man den schritt dorthin kennt
<hr>
##AnalysisTabMemento
f�ge yuvDaten hinzu
<br><b>Grund:</b>wurde wohl vergessen
<hr>
##FilterTabMemento
f�ge yuvDaten hinzu
<br><b>Grund:</b>wurde wohl vergessen
<hr>
##VideoSaver
Wurde ins Project hinzugef�gt
<br><b>Grund:</b>Sonst keine M�glichkeit die Analysevideos zu speichern.
<hr>
