## Allgemein
Fuege bei Attributen einen Unterstrich ( _ ) ans Ende der Namen hinzu.
## FrameView
Benenne "repaintEvent" zu "paintEvent" um.<br>
<b>Grund:</b> paintEvent ist der korrekte Name fuer die event-Methode.
<hr>
## Video
Speichere QImages nicht mehr in unique_ptr und aendere auch entsprechend
die Methoden-Parameter.<br><b>Grund:</b> Einfachere Handhabung.
<hr>
Tausche Parameter der insertFrame Methode.
<br><b>Grund:</b> Default argument ist sonst nicht machbar.
<hr>
Tausche Parameter der insertFrames Methode.
<br><b>Grund:</b> Default argument ist sonst nicht machbar.
<hr>
Aendere Parametertyp von getFrame int->std::size_t.
<br><b>Grund:</b> Ueberlauf verhindern.
<hr>
Fuege Methode appendFrame hinzu.
<br><b>Grund:</b> Da default value von insertFrame(s) entfernt wurde, gab es keinen bequemen
Weg mehr, Frames ans Ende anzufuegen.
<hr>
Aendere Parametertyp von insertFrames int->std::size_t. Entferne default value.
<br><b>Grund:</b> Ueberlauf verhindern.
<hr>
Aendere Parametertyp von insertFrame int->std::size_t. Entferne default value.
<br><b>Grund:</b> Ueberlauf verhindern.
<hr>
Aendere Parametertyp von removeFrame int->std::size_t.
<br><b>Grund:</b> Ueberlauf verhindern.
<hr>
Aendere Rueckgabetyp von getNumberOfFrames int->std::size_t.
<br><b>Grund:</b> Ueberlauf verhindern.
<hr>
## Player
Aendere Rueckgabetyp von getPosition int->std::size_t.
<br><b>Grund:</b> Ueberlauf verhindern.
<hr>
Aendere Parametertyp von setPosition int->std::size_t.
<br><b>Grund:</b> Ueberlauf verhindern.
<hr>
Fuege Methode getNumberOfFrames hinzu.
<br><b>Grund:</b> Der PLayerControlPanel braucht die Methode um den Slider richtig zu updaten.
<hr>
## VideoPlayer
Aendere Typ der Membervariable position_ int->std::size_t.
<br><b>Grund:</b> Ueberlauf verhindern.
<hr>
## Forward Player
Entferne Membervariable controlPanel.
<br><b>Grund:</b> Wurde vergessen aus dem Entwurf zu entfernen.
<hr>
Mache Parameter von setForwardControlPaenl zu einem Pointer.
<br><b>Grund:</b> Fehler im Entwurf. Sollte von Anfang an ein Pointer sein.
<hr>
## GlobalControlPanel
Fuege Methode setSpeed hizu.
<br><b>Grund:</b> Die Methode wird benoetigt, um eine Aenderung der Geschwindigkeit
weiterleiten zu koennen.
<hr>
## ControlPanel
Mache masterPlayer protected
<br><b>Grund:</b> Erbende Klassen koennen sonst nicht auf den MasterPlayer zugreifen.
<hr>
## PlayerControlPanel
Entferne Methhode createActions.
<br><b>Grund:</b> Es gibt keine Actions mehr die erzeugt werden muessen.
<hr>
Fuege Membervariable button_pause hinzu.
<br><b>Grund:</b> Wurde im Entwurf vergessen reinzumachen.
<hr>
