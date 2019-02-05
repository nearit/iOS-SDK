# Come sviluppare NearITSDK iOS

## Info sul progetto

NearITSDK si compone di due framework:

* framework per Obj-C
* framework per Swift

C'è un extra che è il Near Sample, è l'app usata per fare le varie prove del SDK, non è pubblica.
Gli altri extra è la docs e un sample pubblico che finirà su github.

All'interno della cartella di sviluppo c'è anche uno script per distribuire il framework, docs e sample (distribution.sh)

## Distribuzione del framework

Il progetto viene principalmente distribuito tramite pod di Cocoapods, ci sono anche altre varianti tra cui la libreria statica che viene esclusivamente usata per il binding React Native.

Esiste un altro repository che viene usato da Cocoapods per distribuire il framework, questo è il link: https://github.com/nearit/iOS-SDK

Il repository su GitHub oltre che a contenere i file del framework (Obj-C e Swift), contiene anche la documentazione, un sample e i file .podspec per la distribuzione su Cocoapods.

Passi preliminari per la distribuzione del framework, da eseguire nella cartella del progetto NearITSDK, dovrebbero essere necessari solo la prima volta che si distribuisce il framework:

* Definire un file "distribution_config.private" contenente la variabile DISTRIBUTION_PATH, questa deve puntare alla cartella che rappresenta il repo su GitHub (es. DISTRIBUTION_PATH="/Users/francesco.leoni/Documents/projects/NearITSDK")
* Registrarsi al trunk di Cocoapods https://guides.cocoapods.org/making/getting-setup-with-trunk.html
* Essere aggiunti come owners al trunk

I passi per distribuire il framework sono i seguenti:

* Andare nel repository del progetto NearITSDK e lanciare il comando "distribution.sh"
* Attendere le operazioni dello script che genererà i file .framework e copierà docs e sample nella cartella del repo di GitHub
* Andare nella cartella del repo di GitHub e aggiornare i file .podspec, bisogna aprirli e editarli a mano, praticamente quasi sempre sarà necessario solo aggiornare il numero di versione e la dipendenza del framework Swift da quello Obj-C
* Committare le modifiche e taggare con il corretto numero di versione (altrimenti se non c'è il tag, Cocoapods non funziona)
* Eseguire il comando: ```pod trunk push NearITSDK.podspec --allow-warnings```
* Eseguire il comando: ```pod repo update```
* Eseguire il comando: ```pod trunk push NearITSDKSwift.podspec --allow-warnings```

## Build della SDK statica universale

La versione statica produce dei file locali che solitamente vengono utilizzati per alcuni framework ibridi (Xamarin, React-Native).

* Aprire workspace in XCode
* Selezionare il target `UniversalLib` (icona bersaglio)
* Buildare contro `Generic iOS device`
* Prelevare il file `libNearIT.a` e la cartella `include` che contiene i file header .h nel seguente path: `/Library/Developer/Xcode/DerivedData/NearITSDK<alphanumerici>/Build/Products/Debug-universal`

### Risorse per test device: 
* Selezionare il target `NearITResources` (icona mattoncino)
* Buildare contro un device fisico
* Prelevare il file `NearITResources.bundle` nel seguente path: `/Library/Developer/Xcode/DerivedData/NearITSDK<alphanumerici>/Build/Products/Debug-iphoneos`
