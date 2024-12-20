#include "Administration.h"
#include <iostream>

Administration::Administration(std::string mdp) : motDePasse(mdp) {}

bool Administration::authentifier(const std::string& mdp) {
    return mdp == motDePasse;
}

void Administration::ajouterService(Filiale& filiale) {
    std::string serviceNom;
    std::cout << "Nom du service e ajouter: ";
    std::cin >> serviceNom;
    Service service(serviceNom);
    filiale.ajouterService(service);
}

void Administration::ajouterEmploye(Filiale& filiale) {
    std::string serviceNom;
    std::cout << "Nom du service pour l'employé: ";
    std::cin >> serviceNom;
    std::string nom, prenom, matricule, emploi;
    int anneeArrivee;
    std::cout << "Nom: ";
    std::cin >> nom;
    std::cout << "Prenom: ";
    std::cin >> prenom;
    std::cout << "Matricule: ";
    std::cin >> matricule;
    std::cout << "Emploi: ";
    std::cin >> emploi;
    std::cout << "Annee d'arrivee: ";
    std::cin >> anneeArrivee;
    Employe employe(nom, prenom, matricule, emploi, anneeArrivee);
    filiale.ajouterEmploye(serviceNom, employe);
}

double Administration::calculerCA(const std::vector<Filiale>& filiales) {
    double totalCA = 0;
    for (const Filiale& filiale : filiales) {
        totalCA += filiale.getCA();
    }
    return totalCA;
}

void Administration::listerEmployesArrivesCetteAnnee(const std::vector<Filiale>& filiales, int annee) {
    for (const Filiale& filiale : filiales) {
        for (const Service& service : filiale.getServices()) {
            for (const Employe& employe : service.getEmployes()) {
                if (employe.getAnneeArrivee() == annee) {
                    std::cout << employe.getNom() << " " << employe.getPrenom() << " est arrivé cette annee." << std::endl;
                }
            }
        }
    }
}
