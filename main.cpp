#include <iostream>
#include <vector>
#include "Filiale.h"
#include "Service.h"
#include "Employe.h"
#include "Administration.h"

using namespace std;

int main() {
    // Création des filiales
    Filiale f1("Lyon", 10000);
    Filiale f2("Paris", 500000);

    // CAdmin avec mdp
    Administration admin("admin123");

    // Services et employes
    Service service1("INFORMATIQUE");
    Service service2("RH");
    Service service3("MARKETING");
    Service service4("LOGISTIQUE");

    f1.ajouterService(service1);
    f1.ajouterService(service2);
    f2.ajouterService(service3);
    f2.ajouterService(service4);

    Employe employe1("Dupont", "Jean", "AGR123", "Developpeur", 2024);
    Employe employe2("Martin", "Bernard", "AGR124", "Administrateur réseau", 2023);
    Employe employe3("Legrand", "Julie", "AGR125", "Chargé de marketing", 2024);
    Employe employe4("Durand", "Paul", "AGR126", "Logisticien", 2022);

    f1.ajouterEmploye("INFORMATIQUE", employe1);
    f1.ajouterEmploye("RH", employe2);
    f2.ajouterEmploye("MARKETING", employe3);
    f2.ajouterEmploye("LOGISTIQUE", employe4);

    // Menu 
    int choixPrincipal;
    do {
        cout << "\nMenu Principal:" << endl;
        cout << "1. Afficher les informations des filiales et leurs services" << endl;
        cout << "2. Afficher les emplois par filiale et service" << endl;
        cout << "3. Acceder a l'interface d'administration" << endl;
        cout << "4. Quitter" << endl;
        cout << "Votre choix: ";
        cin >> choixPrincipal;

        switch (choixPrincipal) {
        case 1: {
            // Affichage des informations des filiales et services
            cout << "\nInformations des filiales:" << endl;
            for (const Filiale& filiale : { f1, f2 }) {
                cout << "Filiale: " << filiale.getNom() << " - Chiffre d'affaire: " << filiale.getCA() << " EUR" << endl;
                cout << "Services:" << endl;
                for (const Service& service : filiale.getServices()) {
                    cout << "- " << service.getNom() << endl;
                }
            }
            break;
        }
        case 2: {
            // Affichage des emplois par filiale et service
            cout << "\nEmplois par filiale et service:" << endl;
            for (const Filiale& filiale : { f1, f2 }) {
                cout << "Filiale: " << filiale.getNom() << endl;
                for (const Service& service : filiale.getServices()) {
                    cout << "  Service: " << service.getNom() << endl;
                    for (const Employe& employe : service.getEmployes()) {
                        cout << "    - " << employe.getNom() << " " << employe.getPrenom() << " (" << employe.getEmploi() << ")" << endl;
                    }
                }
            }
            break;
        }
        case 3: {
            // Interface d'administration
            string mdpAdmin;
            cout << "Entrer le mot de passe d'administration: ";
            cin >> mdpAdmin;
            if (admin.authentifier(mdpAdmin)) {
                int choixAdmin;
                do {
                    cout << "\nMenu d'administration:" << endl;
                    cout << "1. Ajouter un service" << endl;
                    cout << "2. Ajouter un employé" << endl;
                    cout << "3. Calculer le chiffre d'affaire total" << endl;
                    cout << "4. Lister les employés arrivés cette année" << endl;
                    cout << "5. Retour" << endl;
                    cout << "Votre choix: ";
                    cin >> choixAdmin;

                    switch (choixAdmin) {
                    case 1:
                        admin.ajouterService(f1);
                        break;
                    case 2:
                        admin.ajouterEmploye(f1);
                        break;
                    case 3:
                        cout << "Chiffre d'affaire total des filiales: " << admin.calculerCA({ f1, f2 }) << endl;
                        break;
                    case 4:
                        admin.listerEmployesArrivesCetteAnnee({ f1, f2 }, 2024);
                        break;
                    default:
                        break;
                    }
                } while (choixAdmin != 5);
            }
            else {
                cout << "Mot de passe incorrect." << endl;
            }
            break;
        }
        case 4:
            cout << "Au revoir!" << endl;
            break;
        default:
            cout << "Choix invalide." << endl;
            break;
        }
    } while (choixPrincipal != 4);

    return 0;
}
