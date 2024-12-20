#include "Service.h"

Service::Service(std::string nom) : nom(nom) {}

void Service::ajouterEmploye(const Employe& employe) {
    employes.push_back(employe);
}

const std::vector<Employe>& Service::getEmployes() const {
    return employes;
}

std::string Service::getNom() const {
    return nom;
}

