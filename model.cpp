#include "model.h"
#include <cstring>
#include <cstdlib>
#include <ctime>

void modelInitJoueur(Joueur *joueur, const char *nom)
{
    strncpy(joueur->nom, nom, 49);
    joueur->nom[49]          = '\0';
    joueur->tentativeCourante = 0;
    joueur->partiesJouees    = 0;
    joueur->partiesGagnees   = 0;
}

void modelSetDifficulte(Joueur *joueur, int niveau)
{
    if (niveau == NIVEAU_FACILE) {
        joueur->difficulte = {1, 50, 10};
    } else if (niveau == NIVEAU_MOYEN) {
        joueur->difficulte = {1, 100, 7};
    } else {
        joueur->difficulte = {1, 500, 5};
    }
}

void modelGenererNombre(Joueur *joueur)
{
    static int seeded = 0;
    if (!seeded) { srand((unsigned int)time(NULL)); seeded = 1; }
    int plage = joueur->difficulte.borneMax - joueur->difficulte.borneMin + 1;
    joueur->nombreSecret      = joueur->difficulte.borneMin + rand() % plage;
    joueur->tentativeCourante = 0;
    joueur->partiesJouees++;
}

int modelVerifierProposition(Joueur *joueur, int proposition)
{
    joueur->tentativeCourante++;
    if (proposition < joueur->nombreSecret)  return -1;
    if (proposition > joueur->nombreSecret)  return  1;
    return 0;
}

int modelEstGagnant(Joueur *joueur, int proposition)
{
    return proposition == joueur->nombreSecret;
}

int modelPlusDeChances(Joueur *joueur)
{
    return joueur->tentativeCourante >= joueur->difficulte.maxTentatives;
}
