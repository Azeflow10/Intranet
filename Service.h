#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include <vector>
#include "Employe.h"

class Service {
private:
    std::string nom;
    std::vector<Employe> employes;

public:
    Service(std::string nom);
    void ajouterEmploye(const Employe& employe);
    const std::vector<Employe>& getEmployes() const;
    std::string getNom() const;
};

#endif
