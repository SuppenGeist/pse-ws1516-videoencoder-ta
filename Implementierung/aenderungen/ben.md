## Allgemein
Fuege bei Attributen einen Unterstrich ( _ ) ans Ende der Namen hinzu.
## MainWindow
Aendere Rueckgabetyp von getProject zu pointer.
<br><b>Grund:</b> Es kann auch kein project geladen sein.
<hr>

##filterTab
moveFilter(int old, int new) zu moveFilter(int oldIndex, newIndex) umbenannt
<br><b>Grund:</b> "new" ist kein guter Name für einen Parameter.
<hr>

##FilterView
füge methode uncheck() hinzu
<br><b>Grund</b> keine möglichkeit die checkbox von FilterCOntainerTab aus zu erreichen.
<hr>

##AnalyisTab
füge ui hinzu
<br><b>Grund</b> Einfacher das interface zu gestalten
ändere controlpanel zu playerPanel_  
ändere yuvVideo zu rawVideo
ändere player und rawVideo zu unique_ptr
<br><b>Grund</b> Gleiche funktion wie im filtertab, leichtere Orientierung
entferne LoadRawVideo
<br><b>Grund:</b> layout änderung, selber Button wie addVideo;
füge methode loadYuvVideo und removeYuvVideo hinzu
<br><b>Grund:</b> ermöglicht einfacheres undo/redo
füge int anaTypShown hinzu
<br><b>Grund:</b> einfacher einem neuen Video zu sagen welches Analysevideo er zeigen soll.
füge Model::Project project_ mit setter hinzu
<br><b>Grund:</b> Nötig für Konstructor von ProjectWriter welcher Ergebnisse speichert.
<hr>
##AnalysisBoxContainer
füge addBox(int index, AnaBoxMemento memo) hinzu
<br><b>Grund:</b> ermöglicht einfaches hinzufügen der boxen für den Undo/ReDo Befehl.
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
füge yuvDaten hinzu
<br><b>Grund:</b>wurde wohl vergessen
<hr>
##FilterTabMemento
füge yuvDaten hinzu
<br><b>Grund:</b>wurde wohl vergessen
<hr>
##VideoSaver
Wurde ins Project hinzugefügt
<br><b>Grund:</b>Sonst keine Möglichkeit die Analysevideos zu speichern.
<hr>
