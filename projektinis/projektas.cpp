#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

// Vartotojo sukurta struktūra automobilio duomenims saugoti
struct Automobilis {
    int id;
    string marke;
    string modelis;
    int gamybosMetai;
    double kaina;
    string kuroTipas;
};

// Funkcijų prototipai (deklaracijos)
bool nuskaitytiDuomenis(const string& failoVardas, vector<Automobilis>& sarasas);
void issaugotiDuomenis(const string& failoVardas, const vector<Automobilis>& sarasas);
void rodytiVisus(const vector<Automobilis>& sarasas);
void rodytiViena(const vector<Automobilis>& sarasas);
void pridetiAutomobili(vector<Automobilis>& sarasas);
void redaguotiAutomobili(vector<Automobilis>& sarasas);
void trintiAutomobili(vector<Automobilis>& sarasas);
void filtruotiPagalMarke(const vector<Automobilis>& sarasas);
void generuotiAtaskaita(const vector<Automobilis>& sarasas);

int main() {
    vector<Automobilis> autoSarasas;
    string failoVardas = "automobiliai.txt";

    // Pradinių duomenų nuskaitymas programos pradžioje
    if (!nuskaitytiDuomenis(failoVardas, autoSarasas)) {
        cout << "Klaida: Nepavyko nuskaityti pradinio failo " << failoVardas << endl;
        cout << "Sukuriamas naujas, tuscias sarasas." << endl;
    }

    int pasirinkimas;

    // Ciklas do-while skirtas konsoliniam meniu palaikyti
    do {
        cout << "\n=========================================" << endl;
        cout << "   AUTOMOBILIU DUOMENU VALDYMO SISTEMA   " << endl;
        cout << "=========================================" << endl;
        cout << "1. Perziureti visus automobilius (Read)" << endl;
        cout << "2. Perziureti viena automobilio irasa (Read)" << endl;
        cout << "3. Prideti nauja automobilia (Create)" << endl;
        cout << "4. Redaguoti automobilio duomenis (Update)" << endl;
        cout << "5. Pasalinti automobilia is saraso (Delete)" << endl;
        cout << "6. Filtruoti automobilius pagal marke (Papildoma)" << endl;
        cout << "7. Generuoti statistine ataskaita i faila (Papildoma)" << endl;
        cout << "0. Iseiti ir issaugoti pakeitimus" << endl;
        cout << "Pasirinkite veiksma: ";
        cin >> pasirinkimas;

        // Sąlygos sakinys switch vartotojo pasirinkimui apdoroti
        switch (pasirinkimas) {
        case 1:
            rodytiVisus(autoSarasas);
            break;
        case 2:
            rodytiViena(autoSarasas);
            break;
        case 3:
            pridetiAutomobili(autoSarasas);
            break;
        case 4:
            redaguotiAutomobili(autoSarasas);
            break;
        case 5:
            trintiAutomobili(autoSarasas);
            break;
        case 6:
            filtruotiPagalMarke(autoSarasas);
            break;
        case 7:
            generuotiAtaskaita(autoSarasas);
            break;
        case 0:
            // Duomenų įrašymas į failą prieš baigiant darbą
            issaugotiDuomenis(failoVardas, autoSarasas);
            cout << "Duomenys sekmingai issaugoti. Viso gero!" << endl;
            break;
        default:
            cout << "Neteisingas pasirinkimas! Bandykite dar karta." << endl;
        }
    } while (pasirinkimas != 0);

    return 0;
}

// Funkcija, kuri nuskaito duomenis iš struktūruoto tekstinio failo
bool nuskaitytiDuomenis(const string& failoVardas, vector<Automobilis>& sarasas) {
    ifstream failas(failoVardas);
    if (!failas.is_open()) {
        return false;
    }

    sarasas.clear();
    string eilute;

    // Ciklas while skaito failą eilutė po eilutės
    while (getline(failas, eilute)) {
        if (eilute.empty()) continue; // Praleidžiame tuščias eilutes

        stringstream ss(eilute);
        Automobilis autoObj;
        string laukas;

        // Skaidome eilutę naudodami skyriklį ';'
        getline(ss, laukas, ';'); autoObj.id = stoi(laukas);
        getline(ss, autoObj.marke, ';');
        getline(ss, autoObj.modelis, ';');
        getline(ss, laukas, ';'); autoObj.gamybosMetai = stoi(laukas);
        getline(ss, laukas, ';'); autoObj.kaina = stod(laukas);
        getline(ss, autoObj.kuroTipas, ';');

        sarasas.push_back(autoObj); // Įtraukiame į vector kolekciją
    }

    failas.close();
    return true;
}

// Funkcija, kuri įrašo visus kolekcijos duomenis atgal į failą
void issaugotiDuomenis(const string& failoVardas, const vector<Automobilis>& sarasas) {
    ofstream failas(failoVardas);

    // Ciklas for peržiūri kiekvieną elementą
    for (size_t i = 0; i < sarasas.size(); i++) {
        failas << sarasas[i].id << ";"
            << sarasas[i].marke << ";"
            << sarasas[i].modelis << ";"
            << sarasas[i].gamybosMetai << ";"
            << fixed << setprecision(2) << sarasas[i].kaina << ";"
            << sarasas[i].kuroTipas << "\n";
    }
    failas.close();
}

// Funkcija (READ): parodo visą automobilių sąrašą tvarkingoje lentelėje
void rodytiVisus(const vector<Automobilis>& sarasas) {
    if (sarasas.empty()) {
        cout << "\nSarasas yra tuscias!" << endl;
        return;
    }

    cout << "\n" << string(75, '-') << endl;
    cout << left << setw(5) << "ID" << setw(15) << "Marke" << setw(15) << "Modelis"
        << setw(10) << "Metai" << setw(15) << "Kaina (EUR)" << setw(15) << "Kuras" << endl;
    cout << string(75, '-') << endl;

    for (size_t i = 0; i < sarasas.size(); i++) {
        cout << left << setw(5) << sarasas[i].id
            << setw(15) << sarasas[i].marke
            << setw(15) << sarasas[i].modelis
            << setw(10) << sarasas[i].gamybosMetai
            << setw(15) << fixed << setprecision(2) << sarasas[i].kaina
            << setw(15) << sarasas[i].kuroTipas << endl;
    }
    cout << string(75, '-') << endl;
}

// Funkcija (READ): parodo tik vieno automobilio duomenis pagal vartotojo įvestą ID
void rodytiViena(const vector<Automobilis>& sarasas) {
    int ieskomasId;
    cout << "Iveskite automobilio ID, kuri norite perziureti: ";
    cin >> ieskomasId;

    for (size_t i = 0; i < sarasas.size(); i++) {
        if (sarasas[i].id == ieskomasId) {
            cout << "\n--- RASTAS AUTOMOBILIS ---" << endl;
            cout << "ID: " << sarasas[i].id << endl;
            cout << "Marke: " << sarasas[i].marke << endl;
            cout << "Modelis: " << sarasas[i].modelis << endl;
            cout << "Gamybos metai: " << sarasas[i].gamybosMetai << endl;
            cout << "Kaina: " << fixed << setprecision(2) << sarasas[i].kaina << " EUR" << endl;
            cout << "Kuro tipas: " << sarasas[i].kuroTipas << endl;
            return; // Baigiame funkciją, nes radome įrašą
        }
    }
    cout << "Automobilis su ID " << ieskomasId << " nerastas." << endl;
}

// Funkcija (CREATE): sukuria naują įrašą ir automatiškai suteikia jam unikalų ID
void pridetiAutomobili(vector<Automobilis>& sarasas) {
    Automobilis naujas;

    // Automatinis ID generavimas (surandamas didžiausias esamas ID ir pridedamas 1)
    int maxId = 0;
    for (size_t i = 0; i < sarasas.size(); i++) {
        if (sarasas[i].id > maxId) {
            maxId = sarasas[i].id;
        }
    }
    naujas.id = maxId + 1;

    cout << "Iveskite marke: ";
    cin >> naujas.marke;
    cout << "Iveskite modeli: ";
    cin >> naujas.modelis;
    cout << "Iveskite gamybos metus: ";
    cin >> naujas.gamybosMetai;
    cout << "Iveskite kaina: ";
    cin >> naujas.kaina;
    cout << "Iveskite kuro tipa (Benzinas/Dyzelinas/Dujos/Hibridas): ";
    cin >> naujas.kuroTipas;

    sarasas.push_back(naujas);
    cout << "\nAutomobilis sekmingai pridetas! Suteiktas ID: " << naujas.id << endl;
}

// Funkcija (UPDATE): redaguoja jau egzistuojantį automobilio įrašą pagal ID
void redaguotiAutomobili(vector<Automobilis>& sarasas) {
    int redaguojamasId;
    cout << "Iveskite automobilio ID, kuri norite redaguoti: ";
    cin >> redaguojamasId;

    for (size_t i = 0; i < sarasas.size(); i++) {
        if (sarasas[i].id == redaguojamasId) {
            cout << "\n--- Iveskite naujus duomenis (buvusi reikšme skliausteliuose) ---" << endl;

            cout << "Nauja marke (" << sarasas[i].marke << "): ";
            cin >> sarasas[i].marke;

            cout << "Naujas modelis (" << sarasas[i].modelis << "): ";
            cin >> sarasas[i].modelis;

            cout << "Nauji gamybos metai (" << sarasas[i].gamybosMetai << "): ";
            cin >> sarasas[i].gamybosMetai;

            cout << "Nauja kaina (" << sarasas[i].kaina << "): ";
            cin >> sarasas[i].kaina;

            cout << "Naujas kuro tipas (" << sarasas[i].kuroTipas << "): ";
            cin >> sarasas[i].kuroTipas;

            cout << "\nDuomenys sekmingai atnaujinti!" << endl;
            return;
        }
    }
    cout << "Automobilis su ID " << redaguojamasId << " nerastas." << endl;
}
// Funkcija (CREATE): sukuria naują įrašą ir automatiškai suteikia jam unikalų ID
void pridetiAutomobili(vector<Automobilis>& sarasas) {
    Automobilis naujas;

    // Automatinis ID generavimas (surandamas didžiausias esamas ID ir pridedamas 1)
    int maxId = 0;
    for (size_t i = 0; i < sarasas.size(); i++) {
        if (sarasas[i].id > maxId) {
            maxId = sarasas[i].id;
        }
    }
    naujas.id = maxId + 1;

    cout << "Iveskite marke: ";
    cin >> naujas.marke;
    cout << "Iveskite modeli: ";
    cin >> naujas.modelis;
    cout << "Iveskite gamybos metus: ";
    cin >> naujas.gamybosMetai;
    cout << "Iveskite kaina: ";
    cin >> naujas.kaina;
    cout << "Iveskite kuro tipa (Benzinas/Dyzelinas/Dujos/Hibridas): ";
    cin >> naujas.kuroTipas;

    sarasas.push_back(naujas);
    cout << "\nAutomobilis sekmingai pridetas! Suteiktas ID: " << naujas.id << endl;
}

// Funkcija (UPDATE): redaguoja jau egzistuojantį automobilio įrašą pagal ID
void redaguotiAutomobili(vector<Automobilis>& sarasas) {
    int redaguojamasId;
    cout << "Iveskite automobilio ID, kuri norite redaguoti: ";
    cin >> redaguojamasId;

    for (size_t i = 0; i < sarasas.size(); i++) {
        if (sarasas[i].id == redaguojamasId) {
            cout << "\n--- Iveskite naujus duomenis (buvusi reikšme skliausteliuose) ---" << endl;

            cout << "Nauja marke (" << sarasas[i].marke << "): ";
            cin >> sarasas[i].marke;

            cout << "Naujas modelis (" << sarasas[i].modelis << "): ";
            cin >> sarasas[i].modelis;

            cout << "Nauji gamybos metai (" << sarasas[i].gamybosMetai << "): ";
            cin >> sarasas[i].gamybosMetai;

            cout << "Nauja kaina (" << sarasas[i].kaina << "): ";
            cin >> sarasas[i].kaina;

            cout << "Naujas kuro tipas (" << sarasas[i].kuroTipas << "): ";
            cin >> sarasas[i].kuroTipas;

            cout << "\nDuomenys sekmingai atnaujinti!" << endl;
            return;
        }
    }
    cout << "Automobilis su ID " << redaguojamasId << " nerastas." << endl;
}

// Funkcija (DELETE): pašalina įrašą iš vektoriaus pagal nurodytą ID
void trintiAutomobili(vector<Automobilis>& sarasas) {
    int trunamasId;
    cout << "Iveskite automobilio ID, kuri norite pasalinti: ";
    cin >> trunamasId;

    // Naudojame iteratorius elemento trynimui iš vector struktūros
    for (auto it = sarasas.begin(); it != sarasas.end(); ++it) {
        if (it->id == trunamasId) {
            sarasas.erase(it); // Pašalina elementą ir pastumia likusius
            cout << "\nAutomobilis sekmingai pasalintas iš sistemos." << endl;
            return;
        }
    }
    cout << "Automobilis su ID " << trunamasId << " nerastas." << endl;
}

// 1 PAPILDOMA FUNKCIJA: Duomenų filtravimas pagal markę
void filtruotiPagalMarke(const vector<Automobilis>& sarasas) {
    string ieskomaMarke;
    cout << "Iveskite marke, pagal kuria norite filtruoti (pvz., Audi): ";
    cin >> ieskomaMarke;

    bool rasta = false;
    cout << "\n" << string(75, '-') << endl;
    cout << left << setw(5) << "ID" << setw(15) << "Marke" << setw(15) << "Modelis"
        << setw(10) << "Metai" << setw(15) << "Kaina (EUR)" << setw(15) << "Kuras" << endl;
    cout << string(75, '-') << endl;

    for (size_t i = 0; i < sarasas.size(); i++) {
        if (sarasas[i].marke == ieskomaMarke) {
            cout << left << setw(5) << sarasas[i].id
                << setw(15) << sarasas[i].marke
                << setw(15) << sarasas[i].modelis
                << setw(10) << sarasas[i].gamybosMetai
                << setw(15) << fixed << setprecision(2) << sarasas[i].kaina
                << setw(15) << sarasas[i].kuroTipas << endl;
            rasta = true;
        }
    }
    cout << string(75, '-') << endl;

    if (!rasta) {
        cout << "Automobiliu su marke '" << ieskomaMarke << "' nerasta." << endl;
    }
}

// 2 PAPILDOMA FUNKCIJA: Ataskaitos generavimas i tekstinį failą
void generuotiAtaskaita(const vector<Automobilis>& sarasas) {
    if (sarasas.empty()) {
        cout << "Sarasas tuscias, ataskaitos generuoti negalima." << endl;
        return;
    }

    double bendraKaina = 0;
    int naujausiMetai = sarasas[0].gamybosMetai;
    Automobilis brangiausias = sarasas[0];

    // Algoritmas statistiniams rodikliams skaičiuoti (Ciklas per visus įrašus)
    for (size_t i = 0; i < sarasas.size(); i++) {
        bendraKaina += sarasas[i].kaina;

        if (sarasas[i].gamybosMetai > naujausiMetai) {
            naujausiMetai = sarasas[i].gamybosMetai;
        }

        if (sarasas[i].kaina > brangiausias.kaina) {
            brangiausias = sarasas[i];
        }
    }

    double vidutineKaina = bendraKaina / sarasas.size();

    // Ataskaitos failo kūrimas ir įrašymas
    ofstream fAtaskaita("ataskaita.txt");
    fAtaskaita << "=========================================\n";
    fAtaskaita << "        AUTOMOBILIU DUOMENU ATASKAITA    \n";
    fAtaskaita << "=========================================\n";
    fAtaskaita << "Is viso automobiliu bazėje: " << sarasas.size() << " vnt.\n";
    fAtaskaita << "Vidutine automobilio kaina: " << fixed << setprecision(2) << vidutineKaina << " EUR\n";
    fAtaskaita << "Naujausi gamybos metai sarase: " << naujausiMetai << " m.\n";
    fAtaskaita << "Brangiausias automobilis: " << brangiausias.marke << " " << brangiausias.modelis
        << " (Kaina: " << brangiausias.kaina << " EUR)\n";
    fAtaskaita << "=========================================\n";
    fAtaskaita.close();

    cout << "\nStatistine ataskaita sekmingai sugeneruota ir irasyta i faila 'ataskaita.txt'!" << endl;
}

// Kodo pabaiga