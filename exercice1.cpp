
#include <iostream>
#include <string>
using namespace std;

class Configuration {
private:
    string cheminFichier;
    string utilisateur;
    string motDePasse;

    // Constructeur prive
    Configuration() {
        cheminFichier = "config.txt";
        utilisateur = "admin";
        motDePasse = "123456";
    }

    // Suppression du constructeur de copie
    Configuration(const Configuration&) = delete;
    Configuration& operator=(const Configuration&) = delete;

public:
    static Configuration& getInstance() {
        static Configuration instance;
        return instance;
    }

    void afficherParametres() {
        cout << "Chemin : " << cheminFichier << endl;
        cout << "Utilisateur : " << utilisateur << endl;
        cout << "Mot de passe : " << motDePasse << endl;
    }
};

int main() {
    Configuration& c1 = Configuration::getInstance();
    Configuration& c2 = Configuration::getInstance();

    c1.afficherParametres();

    cout << "Meme instance : "
         << (&c1 == &c2) << endl;

    return 0;
}
