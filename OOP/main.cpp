#include <iostream>
#include <string>

using namespace std;


//Přetížený konstruktor
//Třídní proměnná (static) a metody
//Rozšíření (dat i metod), změna chování s využitou pozdní vazbou
//Protected atribut
//Ryze abstraktní třída
class Pokoj {
protected:
    int cisloPokoje;
    bool jeLuxusni;
    static int pocetPokoji;

public:
    Pokoj(int cislo);
    virtual ~Pokoj() {}
    virtual void getInfo() const = 0;
    virtual void nastavLuxusni(bool luxusni);

    static int getPocetPokoji() { return pocetPokoji; }
};

int Pokoj::pocetPokoji = 0;

class JednoluzkovyPokoj : public Pokoj {
public:
    JednoluzkovyPokoj(int cislo);
    void getInfo() const override;
};

class DvouluzkovyPokoj : public Pokoj {
public:
    DvouluzkovyPokoj(int cislo);
    void getInfo() const override;
};

class Apartman : public Pokoj {
public:
    Apartman(int cislo);
    void getInfo() const override;
};

class Personal {
public:
    virtual ~Personal() {}
    virtual void getInfo() const = 0;
};

class Manazer : public Personal {
public:
    void getInfo() const override;
};

class UklidovyPersonal : public Personal {
public:
    void getInfo() const override;
};

class Kuchar : public Personal {
public:
    void getInfo() const override;
};

class ObsluhaRestaurace : public Personal {
public:
    void getInfo() const override;
};

class Rezervace {
public:
    virtual ~Rezervace() {}
    virtual void getInfo() const = 0;
};

class OnlineRezervace : public Rezervace {
public:
    void getInfo() const override;
};

class TelefonickaRezervace : public Rezervace {
public:
    void getInfo() const override;
};

class Recepce {
public:
    virtual ~Recepce() {}
    virtual void getInfo() const = 0;
};


class RecepceProHosty : public Recepce {
public:
    void getInfo() const override;
};

class RecepceProPersonal : public Recepce {
public:
    void getInfo() const override;
};

class Hotel {
public:
    virtual ~Hotel() {}
    virtual void getInfo() const = 0;
    static int getPocetPokoji();
};

class BoutiqueHotel : public Hotel {
public:
    void getInfo() const override;
};

class Resort : public Hotel {
public:
    void getInfo() const override;
};

//Dynamické pole ukazatelů na objekty jiné třídy
//Metody pro přidání a mazání prvků pole
class HotelovaRecepce {
private:
    static const int MAX_RECEPCNI = 5;
    Recepce* recepcni[MAX_RECEPCNI];
    int pocetRecepcnich;

public:
    HotelovaRecepce();
    void pridejRecepcniho(Recepce* recepcniOsoba);
    void vypisRecepcni() const;
};

class LuxusniPokoj : public Pokoj {
public:
    LuxusniPokoj(int cislo);
    void getInfo() const override;
    void nastavLuxusni(bool luxusni) override;
};

class HotelovaRecepceProHosty : public RecepceProHosty {
public:
    void getInfo() const override;
};

int Hotel::getPocetPokoji() {
    return Pokoj::getPocetPokoji();
}

Pokoj::Pokoj(int cislo) : cisloPokoje(cislo), jeLuxusni(false) {
    pocetPokoji++;
}

void Pokoj::nastavLuxusni(bool luxusni) {
    jeLuxusni = luxusni;
}

JednoluzkovyPokoj::JednoluzkovyPokoj(int cislo) : Pokoj(cislo) {}

//Změna chování překrytím
void JednoluzkovyPokoj::getInfo() const {
    cout << "Jednoluzkovy pokoj c. " << cisloPokoje;
    if (jeLuxusni) {
        cout << " - Luxusni vybaveni";
    }
    cout << endl;
}

DvouluzkovyPokoj::DvouluzkovyPokoj(int cislo) : Pokoj(cislo) {}

void DvouluzkovyPokoj::getInfo() const {
    cout << "Dvouluzkovy pokoj c. " << cisloPokoje;
    if (jeLuxusni) {
        cout << " - Luxusni vybaveni";
    }
    cout << endl;
}

Apartman::Apartman(int cislo) : Pokoj(cislo) {}

void Apartman::getInfo() const {
    cout << "Apartman c. " << cisloPokoje;
    if (jeLuxusni) {
        cout << " - Luxusni vybaveni";
    }
    cout << endl;
}

void Manazer::getInfo() const {
    cout << "Manazer" << endl;
}

void UklidovyPersonal::getInfo() const {
    cout << "Uklidovy personal" << endl;
}

void Kuchar::getInfo() const {
    cout << "Kuchar" << endl;
}

void ObsluhaRestaurace::getInfo() const {
    cout << "Obsluha restaurace" << endl;
}

void OnlineRezervace::getInfo() const {
    cout << "Online rezervace" << endl;
}

void TelefonickaRezervace::getInfo() const {
    cout << "Telefonicka rezervace" << endl;
}

void RecepceProHosty::getInfo() const {
    cout << "Recepce pro hosty" << endl;
}

void RecepceProPersonal::getInfo() const {
    cout << "Recepce pro personal" << endl;
}

void BoutiqueHotel::getInfo() const {
    cout << "Boutique hotel" << endl;
}

void Resort::getInfo() const {
    cout << "Resort" << endl;
}

HotelovaRecepce::HotelovaRecepce() : pocetRecepcnich(0) {}

//Metody pro přidání a mazání prvků pole
void HotelovaRecepce::pridejRecepcniho(Recepce* recepcniOsoba) {
    if (pocetRecepcnich < MAX_RECEPCNI) {
        recepcni[pocetRecepcnich++] = recepcniOsoba;
    } else {
        cout << "Nelze pridat dalsiho recepcniho, limit byl dosazen." << endl;
    }
}

void HotelovaRecepce::vypisRecepcni() const {
    cout << "Recepcni na sluzbe: " << endl;
    for (int i = 0; i < pocetRecepcnich; ++i) {
        recepcni[i]->getInfo();
    }
}

LuxusniPokoj::LuxusniPokoj(int cislo) : Pokoj(cislo) {}

void LuxusniPokoj::getInfo() const {
    cout << "Luxusni pokoj c. " << cisloPokoje;
    if (jeLuxusni) {
        cout << " - Luxusni vybaveni";
    }
    cout << endl;
}

void LuxusniPokoj::nastavLuxusni(bool luxusni) {
    jeLuxusni = luxusni;
}

void HotelovaRecepceProHosty::getInfo() const {
    cout << "Vitejte v nasi exkluzivni recepci pro hosty!" << endl;
}

#include <iostream>

#include <iostream>

int main() {
    cout << "***** Hotelovy Management *****" << endl << endl;

    // Vytvoreni pokoju
    cout << "=== Pokoje ===" << endl;
    Pokoj* pokoj1 = new JednoluzkovyPokoj(101);
    Pokoj* pokoj2 = new DvouluzkovyPokoj(201);
    Pokoj* pokoj3 = new Apartman(301);
    Pokoj* pokoj4 = new LuxusniPokoj(401);

    pokoj1->getInfo();
    pokoj2->getInfo();
    pokoj3->getInfo();
    pokoj4->getInfo();

    cout << endl;

    // Vytvoreni personalu
    cout << "=== Personal ===" << endl;
    Personal* personal1 = new Manazer();
    Personal* personal2 = new UklidovyPersonal();
    Personal* personal3 = new Kuchar();
    Personal* personal4 = new ObsluhaRestaurace();

    personal1->getInfo();
    personal2->getInfo();
    personal3->getInfo();
    personal4->getInfo();

    cout << endl;

    // Vytvoreni rezervaci
    cout << "=== Rezervace ===" << endl;
    Rezervace* rezervace1 = new OnlineRezervace();
    Rezervace* rezervace2 = new TelefonickaRezervace();

    rezervace1->getInfo();
    rezervace2->getInfo();

    cout << endl;

    // Vytvoreni recepci
    cout << "=== Recepce ===" << endl;
    Recepce* recepce1 = new RecepceProHosty();
    Recepce* recepce2 = new RecepceProPersonal();

    recepce1->getInfo();
    recepce2->getInfo();

    cout << endl;

    // Vytvoreni hotelu
    cout << "=== Hotely ===" << endl;
    Hotel* hotel1 = new BoutiqueHotel();
    Hotel* hotel2 = new Resort();

    hotel1->getInfo();
    hotel2->getInfo();

    cout << endl;

    // Pocet pokoju v hotelu
    cout << "Celkovy pocet pokoju v hotelu: " << Hotel::getPocetPokoji() << endl;

    cout << endl;

    // Vypis recepcnich hotelu
    cout << "=== Recepcni hotelu ===" << endl;
    //Polymorfismus
    HotelovaRecepce recepceHotelu;
    recepceHotelu.pridejRecepcniho(new HotelovaRecepceProHosty());
    recepceHotelu.pridejRecepcniho(new RecepceProHosty());
    recepceHotelu.pridejRecepcniho(new RecepceProPersonal());

    recepceHotelu.vypisRecepcni();

    cout << endl;

    // Uvolneni pameti
    delete pokoj1;
    delete pokoj2;
    delete pokoj3;
    delete pokoj4;

    delete personal1;
    delete personal2;
    delete personal3;
    delete personal4;

    delete rezervace1;
    delete rezervace2;

    delete recepce1;
    delete recepce2;

    delete hotel1;
    delete hotel2;

    return 0;
}


