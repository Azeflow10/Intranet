#include "../../Intranet/Filiale.h"
#include <iostream>

// Constructeur
Filiale::Filiale(std::string nom, double ca) : nom(nom), ca(ca) {}

// Ajouter un service
void Filiale::ajouterService(const Service& service) {
    services.push_back(service);
}

// Ajouter un employé à un service spécifique
void Filiale::ajouterEmploye(const std::string& serviceNom, const Employe& employe) {
    for (Service& service : services) {
        if (service.getNom() == serviceNom) {
            service.ajouterEmploye(employe);
            return;
        }
    }
    std::cout << "Service non trouvé." << std::endl;
}

// Retourne la liste des services
const std::vector<Service>& Filiale::getServices() const {
    return services;
}

// Accesseurs
std::string Filiale::getNom() const { return nom; }
double Filiale::getCA() const { return ca; }

// Nombre d'employés dans la filiale
int Filiale::getNbEmployes() const {
    int count = 0;
    for (const Service& service : services) {
        count += service.getEmployes().size();
    }
    return count;
}

