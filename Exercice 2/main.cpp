
#include <iostream>
#include <string>
using namespace std;

// Classe Universite
class Universite {
private:
    string nom;

public:
    // Constructeur
    Universite(string n) {
        nom = n;
    }

    // Afficher le nom de l'universite
    void afficherNom() {
        cout << "Universite : " << nom << endl;
    }

    // Getter pour recuperer le nom
    string getNom() {
        return nom;
    }
};

// Classe Etudiant
class Etudiant {
private:
    string nom;
    int age;
    Universite* universite;

    // Attribut statique partage par tous les etudiants
    static int nbEtudiants;

public:
    // Constructeur
    Etudiant(string n, int a, Universite* u) {
        nom = n;
        age = a;
        universite = u;
        nbEtudiants++;
    }

    // Afficher les informations de l'etudiant
    void afficher() {
        cout << "Nom : " << nom << endl;
        cout << "Age : " << age << endl;

        if (universite != nullptr) {
            universite->afficherNom();
        } else {
            cout << "Universite non definie" << endl;
        }

        cout << "-------------------" << endl;
    }

    // Methode statique
    static void afficherTotal() {
        cout << "Nombre total d'etudiants : "
             << nbEtudiants << endl;
    }
};

// Initialisation de l'attribut statique
int Etudiant::nbEtudiants = 0;

// Fonction principale
int main() {
    Universite u("Universite de Casablanca");

    Etudiant e1("Amine", 20, &u);
    Etudiant e2("Sara", 21, &u);
    Etudiant e3("Youssef", 22, &u);

    e1.afficher();
    e2.afficher();
    e3.afficher();

    Etudiant::afficherTotal();

    return 0;
}
