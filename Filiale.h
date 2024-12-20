#ifndef FILIALE_H
#define FILIALE_H

#include <string>
#include <vector>
#include "Service.h"

class Filiale {
private:
    std::string nom;
    double ca;  // Chiffre d'affaires
    std::vector<Service> services;

public:
    Filiale(std::string nom, double ca);

    void ajouterService(const Service& service);
    void ajouterEmploye(const std::string& serviceNom, const Employe& employe);

    const std::vector<Service>& getServices() const;
    std::string getNom() const;
    double getCA() const;
    int getNbEmployes() const;
};

#endif




