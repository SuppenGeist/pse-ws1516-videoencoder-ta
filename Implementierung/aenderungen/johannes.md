## Allgemein
Fuege bei Attributen ein Unterstrich ( _ ) ans Ende der Namen hinzu.
## FrameView
Benenne "repaintEvent" zu "paintEvent" um.<br>
<b>Grund:</b> paintEvent ist der korrekte Name fuer die event-Methode.
## Video
Speichere QImages nicht mehr in unique_ptr und aendere auch entsprechend
die Methoden-Parameter.<br><b>Grund:</b> Einfachere Handhabung.
<hr>
Tausche Paramter der insertFrame Methode.
<br><b>Grund:</b> Default argument ist sonst nicht machbar.
<hr>
Tausche Paramter der insertFrames Methode.
<br><b>Grund:</b> Default argument ist sonst nicht machbar.
<hr>
Aendere Parametertyp von getFrame int->std::size_t. Entferne default value.
<br><b>Grund:</b> Ueberlauf verhindern.
<hr>
Fuege Methode appendFrame hinzu.
<br><b>Grund:</b> Da default value von insertFrame(s) entfernt wurde, gab es keinen bequemen
Weg mehr, Frames ans Ende anzufuegen.
<hr>
Aendere Parametertyp von getFrames int->std::size_t. Entferne default value.
<br><b>Grund:</b> Ueberlauf verhindern.
<hr>
Aendere Parametertyp von removeFrame int->std::size_t. Entferne default value.
<br><b>Grund:</b> Ueberlauf verhindern.
<hr>
Aendere Rueckgabewert von getNumberOfFrames int->std::size_t. Entferne default value.
<br><b>Grund:</b> Ueberlauf verhindern.
<hr>
