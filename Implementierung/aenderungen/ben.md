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
entferne LoadRawVideo
<b>Grund:</b> layout �nderung, selber Button wie addVideo;
f�ge methode loadYuvVideo und removeYuvVideo hinzu
<b>Grund:</b> erm�glicht einfacheres undo/redo
f�ge int anaTypShown hinzu
<b>Grund:</b> einfacher einem neuen Video zu sagen welches Analysevideo er zeigen soll.
<hr>
f�ge Model::Project project_ mit setter hinzu
<b>Grund:</b> N�tig f�r Konstructor von ProjectWriter welcher Ergebnisse speichert.
##AnalysisBoxContainer
f�ge addBox(int index, AnaBoxMemento memo) hinzu
<b>Grund:</b> erm�glicht einfaches hinzuf�gen der boxen f�r den Undo/ReDo Befehl.
<hr>
##AddVideo
aendere parameter des constructors zu GUI::AnalysisBox
nur AnalysisBox als Attribut
<b>Grund:</b> alle noetigen Infos kann man aus der Box erhalten. 
<hr>
##RemoveVideo
parameter nun AnaBox, AnaBoxMemento und AnaBoxContainer
<b>Grund:</b>AnaBox um zu entfernende box zu finden, memo um box wiederherzustellen, container zum finden des containers
<hr>
##LoadAnalysisVideo
entferne memento aus Parametern und Attributen
<b>Grund:</b> warum den Zustand speichern wenn man den schritt dorthin kennt
<hr>
##AnalysisTabMemento
f�ge yuvDaten hinzu
<b>Grund:</b>wurde wohl vergessen
<hr>
##FilterTabMemento
f�ge yuvDaten hinzu
<b>Grund:</b>wurde wohl vergessen
<hr>
##VideoSaver
Wurde ins Project hinzugef�gt
<b>Grund:</b>Sonst keine M�glichkeit die Analysevideos zu speichern.
<hr>
