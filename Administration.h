#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#include <string>
#include "Filiale.h"

class Administration {
private:
    std::string motDePasse;

public:
    Administration(std::string mdp);
    bool authentifier(const std::string& mdp);

    void ajouterService(Filiale& filiale);
    void ajouterEmploye(Filiale& filiale);
    void ajouterPoste(Filiale& filiale);
    double calculerCA(const std::vector<Filiale>& filiales);
    void listerEmployesArrivesCetteAnnee(const std::vector<Filiale>& filiales, int annee);
};

#endif


