## Allgemein
Fuege bei Attributen einen Unterstrich ( _ ) ans Ende der Namen hinzu.
## FrameView
Benenne "repaintEvent" zu "paintEvent" um.<br>
<b>Grund:</b> paintEvent ist der korrekte Name fuer die event-Methode.
<hr>
## Video
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
Entferne Methode createActions.
<br><b>Grund:</b> Es gibt keine Actions mehr die erzeugt werden muessen.
<hr>
Fuege Membervariable button_pause hinzu.
<br><b>Grund:</b> Wurde im Entwurf vergessen reinzumachen.
<hr>
## Timer
Lasse Timer von QObject erben.
<br><b>Grund:</b> Sonst lassen sich slots nicht realisieren.
<hr>
## PreviewControlPanel
Entferne Methode createActions.
<br><b>Grund:</b> Es gibt keine Actions mehr die erzeugt werden muessen.
<hr>
Entferne Methode updateLabel.
<br><b>Grund:</b> Die Methode macht dasselbe wie updateUi.
<hr>
## YuvFileOpenDialog
Aendere Datentyp von model_recentlyUsed QListViewModel->QStringListModel.
<br><b>Grund:</b> QListViewModel gibt es garnicht.
<hr>
Aendere Datentyp von button_chooseFile Qbutton->QPushButton
<br><b>Grund:</b> QButton gibt es garnicht.
<hr>
Fuege slot chooseFile() fuer button_selectFile hinzu.
<br><b>Grund:</b> Wurde vergessen.
<hr>
Fuege slot selectionChanged(QItemSelection) fuer listView_recenltyUsed hinzu.
<br><b>Grund:</b> Wurde vergessen.
<hr>
Aendere Methode loadRecentlyUsed zu getListModel.
<br><b>Grund:</b> Bessere Kontrolle ueber das statische Model.
<hr>
Entferne Methode show.
<br><b>Grund:</b> Die Methode ist ueberfluessig, da es schon exec gibt.
<hr>
Fuege Methode saveListModel hinzu.
<br><b>Grund:</b> Das Model muss auch gespeichert werden.
<hr>
Fuege static attribute MAX_SAVED_ENTRIES hinzu.
<br><b>Grund:</b> Mehr dynamik beim recently used kram.
<hr>
Fuege static attribute SAVE_FILENAME hinzu.
<br><b>Grund:</b> Mehr dynamik beim recently used kram.
<hr>
Entferne Attribut wasSuccessful und Methode wasSuccessful.
<br><b>Grund:</b> Funktionalitaet wird von QDialog uebernommen.
<hr>
Fuege Methode hasFinished hinzu.
<br><b>Grund:</b> Wird benoetigt um recentlyUsed zu speichern.
<hr>
## PixelSheme
Remove this class. Change classes that used this class so that they now use YuvType.
<br><b>Grund:</b> Klasse ist redundant mit YuvType.
<hr>
## YuvInfoFialog
Aendere Typ QWidget zu QLabel von allen Atrributen diemit label_ beginnen.
<br><b>Grund:</b> Sollte QLabel von anfang an sein.
<hr>
Entferne Methode show.
<br><b>Grund:</b> Die Methode ist ueberfluessig, da es schon exec gibt.
<hr>
Fuege slot pixelShemeSelectionChanged() fuer comboBox_pixelSheme hinzu.
<br><b>Grund:</b> Wenn Yuv 420 ausgewaehlt is, gibt es keine compression. Darauf muss reagiert
werden.
<hr>
Fuege Attribut wasSuccessful hinzu.
<br><b>Grund:</b> Wurde im Entwurf vergessen. Sollt von anfang an dabei sein.
<hr>
Fuege Attribut compressionList_ hinzu.
<br><b>Grund:</b> Magic numbers im code vermeiden.
<hr>
Fuege Attribut pixelShemeList_ hinzu.
<br><b>Grund:</b> Magic numbers im code vermeiden.
<hr>
Entferne Attribut wasSuccessful und Methode wasSuccessful.
<br><b>Grund:</b> Funktionalitaet wird von QDialog uebernommen.
<hr>
## Graph
Benenne Methode addValue zu setValue um.
<br><b>Grund:</b> Besserer name.
<hr>
Aendere parameter x von der Methode setValue vom typ int->std::size_t.
<br><b>Grund:</b> Ueberlauf verhindern.
<hr>
Aendere parameter von der Methode cut vom typ int->std::size_t.
<br><b>Grund:</b> Ueberlauf verhindern.
<hr>
Aendere parameter von der Methode getValue vom typ int->std::size_t.
<br><b>Grund:</b> Ueberlauf verhindern.
<hr>
Aendere parameter von der Methode removeValue vom typ int->std::size_t.
<br><b>Grund:</b> Ueberlauf verhindern.
<hr>
Fuege Methode getBiggestValue hinzu.
<br><b>Grund:</b> GraphWidget braucht diese Methode um den Graphen korrekt zeichnen zu
koennen.
<hr>
Bennene Methode getLength zu getSize um.
<br><b>Grund:</b> Besserer name.
<hr>
Aendere Rueckgabetyp von der Methode getSize vom typ int->std::size_t.
<br><b>Grund:</b> Ueberlauf verhindern.
<hr>
## GraphWidget
Fuege resizeEvent methode hinzu.
<br><b>Grund:</b> Wird benoetigt um auf Aenderung der Groese reagieren zu koennen.
<hr>
Fuege Attribut isFilled_ mit setter hinzu.
<br><b>Grund:</b> Mehr kontroll fue der user.
<hr>
Fuege Konstruktorparameter parent hinzu.
<br><b>Grund:</b> Wird gebraucht fuer qts memory management.
<hr>
Fuege buildScene methode hinzu.
<br><b>Grund:</b> Kapsele das bauen der Szene.
<hr>
Fuege Attribut scene_ hizu.
<br><b>Grund:</b> Die Szene die monentan gezeichnet wird.
<hr>
Aendere Parameter von setControlPanel von pointer zu referenz.
<br><b>Grund:</b> Es soll kein nullptr uebergebenw erden.
<hr>
Entferne parameter isFilled von drawGraph.
<br><b>Grund:</b> Ein einheitlicheres interface.
<hr>
Entferne Methode setLineColor
<br><b>Grund:</b> Wurde ersetzt.
<hr>
Entferne Methode setFillColor
<br><b>Grund:</b> Wurde ersetzt.
<hr>
Fuege Methode setLinePen und attribut linePen_ hinzu
<br><b>Grund:</b> Mehr Kontrolle fuer den user.
<hr>
Fuege Methode setFillPen und attribut fillPen_ hinzu
<br><b>Grund:</b> Mehr Kontrolle fuer den user.
<hr>
Fuege Methode setFillBrush und attribut fillBrush_ hinzu
<br><b>Grund:</b> Mehr Kontrolle fuer den user.
<hr>
Fuege Methode setAxisLabels und attribute xLabel_ und yLabel_ sowie
xLabelHeight_ und xLabelWidth_ hinzu.
<br><b>Grund:</b> Mehr Kontrolle fuer den user.
<hr>
Fuege Methode setMargin und attribute marginWidth_ und marginHeight_ hinzu.
<br><b>Grund:</b> Mehr Kontrolle fuer den user.
<hr>
Fuege Methode setShowLabels und Attribut showLabels_ hinzu.
<br><b>Grund:</b> Mehr Kontrolle fuer den user.
<hr>
Fuege Methode setMarkLength und attribute markLenX_ und markLenY_ hinzu.
<br><b>Grund:</b> Mehr Kontrolle fuer den user.
<hr>
Fuege Methode setBackgroundColor hinzu.
<br><b>Grund:</b> Mehr Kontrolle fuer den user.
<hr>
Fuege Methode clamp hinzu
<br><b>Grund:</b> Wird fue berrehnungen beim zeichnen benoetigt.
<hr>
Aendere Parameter von Methode drawGraph zu referenz und mache attribut graph zu pointer.
<br><b>Grund:</b> Unnoetiges kopieren verhindenrn,
<hr>
Fuege Methode setMarkDistance und attribute markDistanceX_ und marDistanceY_ hinzu.
<br><b>Grund:</b> Mehr Kontrolle fuer den user.
<hr>
Fuege Methode updateLabelSize.
<br><b>Grund:</b> Codedopplung vermeiden.
<hr>
Fuege Methode setLabelFont und attribut labelFont_ hinzu..
<br><b>Grund:</b> Mehr Kontrolle fuer den user.
<hr>
Fuege Methode setMarkFont und attribut markFont_ hinzu..
<br><b>Grund:</b> Mehr Kontrolle fuer den user.
<hr>
