// Macro ROOT: fit lineare di dati con incertezze
// Formato file: x  y  err_x  err_y
// Caso fisico: pendolo linearizzato  T^2 = (4pi^2/g) * L

void fit_pendolo() {

    // --- 1. Leggi i dati dal file ---
    TGraphErrors* graph = new TGraphErrors("misure_linearizzate.dat");

    // Controlla che il file sia stato letto correttamente
    if (graph->GetN() == 0) {
        cerr << "Errore: file non trovato o vuoto!" << endl;
        return;
    }
    cout << "Punti letti dal file: " << graph->GetN() << endl;

    // --- 2. Etichette degli assi e titolo ---
    graph->SetTitle("Periodo del pendolo;L (m);T^{2} (s^{2})");

    // Stile dei punti: cerchietti pieni, colore blu
    graph->SetMarkerStyle(20);
    graph->SetMarkerColor(kBlue);
    graph->SetLineColor(kBlue);

    // --- 3. Definisci la funzione di fit: retta  y = m*x + q ---
    // Il fit parte dall'intervallo dei dati: x in [0.1, 0.45]
    TF1* retta = new TF1("retta", "[0]*x + [1]", 0.05, 0.50);

    // Nomi dei parametri (compaiono nei risultati)
    retta->SetParName(0, "m");
    retta->SetParName(1, "q");

    // Valori iniziali: stima grezza dalla prima e ultima coppia di punti
    // m ~ DeltaY/DeltaX ~ (1.84-0.393)/(0.45-0.1) ~ 4.1
    retta->SetParameter(0, 4.1);
    retta->SetParameter(1, 0.0);

    // Colore della curva di fit
    retta->SetLineColor(kRed);
    retta->SetLineWidth(2);

    // --- 4. Esegui il fit ---
    // Opzioni:
    //   "R"  = usa l'intervallo definito in TF1
    //   "S"  = salva il risultato (permette di stampare la matrice di covarianza)
    //   "E"  = calcola gli errori con MINOS (più accurato)
    TFitResultPtr risultato = graph->Fit(retta, "RSE");

    // --- 5. Crea la canvas e disegna ---
    TCanvas* canvas = new TCanvas("canvas", "Fit pendolo", 800, 600);
    canvas->SetGrid();                  // griglia di sfondo

    graph->Draw("AP");                  // A = disegna gli assi, P = disegna i punti
    retta->Draw("same");                // sovrapponi la curva di fit

    // --- 6. Stampa i risultati su terminale ---
    cout << "\n===== Risultati del fit =====" << endl;
    cout << "m  = " << retta->GetParameter(0)
         << " +/- " << retta->GetParError(0) << " s^2/m" << endl;
    cout << "q  = " << retta->GetParameter(1)
         << " +/- " << retta->GetParError(1) << " s^2"   << endl;

    // Ricava g dalla pendenza:  m = 4*pi^2/g  =>  g = 4*pi^2/m
    double m    = retta->GetParameter(0);
    double dm   = retta->GetParError(0);
    double g    = 4.0 * TMath::Pi() * TMath::Pi() / m;
    double dg   = g * (dm / m);         // propagazione dell'errore: dg/g = dm/m
    cout << "\ng = 4*pi^2/m = " << g << " +/- " << dg << " m/s^2" << endl;
    cout << "(valore atteso: 9.81 m/s^2)" << endl;

    cout << "\nChi2        = " << retta->GetChisquare() << endl;
    cout << "NDF         = " << retta->GetNDF()        << endl;
    cout << "Chi2/NDF    = " << retta->GetChisquare() / retta->GetNDF() << endl;
    cout << "Probabilita = " << retta->GetProb()       << endl;

    canvas->Update();
}