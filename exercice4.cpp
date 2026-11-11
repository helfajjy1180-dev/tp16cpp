
#include <iostream>
#include <vector>
using namespace std;

class Observateur {
public:
    virtual void mettreAJour(float t, float h, float p) = 0;
    virtual ~Observateur() {}
};

class AffichageTemperature : public Observateur {
public:
    void mettreAJour(float t, float h, float p) override {
        cout << "Temperature : " << t << " C" << endl;
    }
};

class AffichageHumidite : public Observateur {
public:
    void mettreAJour(float t, float h, float p) override {
        cout << "Humidite : " << h << " %" << endl;
    }
};

class AffichagePression : public Observateur {
public:
    void mettreAJour(float t, float h, float p) override {
        cout << "Pression : " << p << " hPa" << endl;
    }
};

class StationMeteo {
private:
    float temperature, humidite, pression;
    vector<Observateur*> observateurs;

public:
    void ajouterObservateur(Observateur* o) {
        observateurs.push_back(o);
    }

    void notifierObservateurs() {
        for (auto o : observateurs) {
            o->mettreAJour(temperature, humidite, pression);
        }
    }

    void changerDonnees(float t, float h, float p) {
        temperature = t;
        humidite = h;
        pression = p;
        notifierObservateurs();
    }
};

int main() {
    StationMeteo station;

    AffichageTemperature t;
    AffichageHumidite h;
    AffichagePression p;

    station.ajouterObservateur(&t);
    station.ajouterObservateur(&h);
    station.ajouterObservateur(&p);

    station.changerDonnees(25, 60, 1013);

    return 0;
}
