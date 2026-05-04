#ifndef MODEL_H
#define MODEL_H

#define VERSION        "1.0"
#define NOM_LOGICIEL   "JustePrix"

#define NIVEAU_FACILE    1
#define NIVEAU_MOYEN     2
#define NIVEAU_DIFFICILE 3

typedef struct {
    int borneMin;
    int borneMax;
    int maxTentatives;
} Difficulte;

typedef struct {
    char nom[50];
    int nombreSecret;
    int tentativeCourante;
    int partiesJouees;
    int partiesGagnees;
    Difficulte difficulte;
} Joueur;

void modelInitJoueur(Joueur *joueur, const char *nom);
void modelSetDifficulte(Joueur *joueur, int niveau);
void modelGenererNombre(Joueur *joueur);
int  modelVerifierProposition(Joueur *joueur, int proposition);
int  modelEstGagnant(Joueur *joueur, int proposition);
int  modelPlusDeChances(Joueur *joueur);

#endif
