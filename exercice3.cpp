
#include <iostream>
#include <vector>
using namespace std;

class Observateur {
public:
    virtual void mettreAJour(float valeur) = 0;
    virtual ~Observateur() {}
};

class AffichageTemperature : public Observateur {
public:
    void mettreAJour(float valeur) override {
        cout << "Temperature : " << valeur << " C" << endl;
    }
};

class AffichageHumidite : public Observateur {
public:
    void mettreAJour(float valeur) override {
        cout << "Humidite : " << valeur << " %" << endl;
    }
};

class AffichagePression : public Observateur {
public:
    void mettreAJour(float valeur) override {
        cout << "Pression : " << valeur << " hPa" << endl;
    }
};

class StationMeteo {
private:
    float temperature;
    float humidite;
    float pression;

    vector<Observateur*> observateurs;

public:
    void ajouterObservateur(Observateur* o) {
        observateurs.push_back(o);
    }

    void notifierObservateurs() {
        for (auto o : observateurs) {
            o->mettreAJour(temperature);
        }
    }

    void changerDonnees(float t, float h, float p) {
        temperature = t;
        humidite = h;
        pression = p;

        cout << "\nMise a jour des donnees :\n";

        // Notification des observateurs
        notifierObservateurs();
    }
};

int main() {
    StationMeteo station;

    AffichageTemperature temperature;
    AffichageHumidite humidite;
    AffichagePression pression;

    station.ajouterObservateur(&temperature);
    station.ajouterObservateur(&humidite);
    station.ajouterObservateur(&pression);

    station.changerDonnees(25, 60, 1013);

    return 0;
}
