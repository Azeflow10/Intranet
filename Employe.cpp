#include "Employe.h"

Employe::Employe(std::string nom, std::string prenom, std::string matricule, std::string emploi, int anneeArrivee)
    : nom(nom), prenom(prenom), matricule(matricule), emploi(emploi), anneeArrivee(anneeArrivee) {
}

std::string Employe::getNom() const { return nom; }
std::string Employe::getPrenom() const { return prenom; }
std::string Employe::getMatricule() const { return matricule; }
std::string Employe::getEmploi() const { return emploi; }
int Employe::getAnneeArrivee() const { return anneeArrivee; }

