#ifndef VIEW_H
#define VIEW_H

#include "model.h"

// Couleurs ANSI
#define RESET   "\x1b[0m"
#define BOLD    "\x1b[1m"
#define ROUGE   "\x1b[31m"
#define VERT    "\x1b[32m"
#define JAUNE   "\x1b[33m"
#define BLEU    "\x1b[34m"
#define CYAN    "\x1b[36m"
#define BLANC   "\x1b[37m"

void viewAfficherBanniere();
void viewDemanderNom(char *nom, int taille);
void viewAfficherMenuDifficulte();
int  viewDemanderDifficulte();
void viewAfficherDebutPartie(const Joueur *joueur);
int  viewDemanderProposition(const Joueur *joueur);
void viewAfficherResultatTentative(int resultat, const Joueur *joueur);
void viewAfficherVictoire(const Joueur *joueur);
void viewAfficherDefaite(const Joueur *joueur);
void viewAfficherStats(const Joueur *joueur);
int  viewDemanderRejouer(const Joueur *joueur);

#endif
