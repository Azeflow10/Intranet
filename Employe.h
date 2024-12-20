#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <string>

class Employe {
private:
    std::string nom;
    std::string prenom;
    std::string matricule;
    std::string emploi;
    int anneeArrivee;

public:
    Employe(std::string nom, std::string prenom, std::string matricule, std::string emploi, int anneeArrivee);

    std::string getNom() const;
    std::string getPrenom() const;
    std::string getMatricule() const;
    std::string getEmploi() const;
    int getAnneeArrivee() const;
};

#endif

