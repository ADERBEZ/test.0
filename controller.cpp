#include "controller.h"
#include "model.h"
#include "view.h"

static void jouerPartie(Joueur *joueur)
{
    modelGenererNombre(joueur);
    viewAfficherDebutPartie(joueur);

    while (!modelPlusDeChances(joueur)) {
        int proposition = viewDemanderProposition(joueur);
        int resultat    = modelVerifierProposition(joueur, proposition);

        if (modelEstGagnant(joueur, proposition)) {
            joueur->partiesGagnees++;
            viewAfficherVictoire(joueur);
            return;
        }
        viewAfficherResultatTentative(resultat, joueur);
    }
    viewAfficherDefaite(joueur);
}

static void configurerJoueur(Joueur *joueur)
{
    char nom[50];
    viewDemanderNom(nom, 50);
    modelInitJoueur(joueur, nom);
    viewAfficherMenuDifficulte();
    int niveau = viewDemanderDifficulte();
    modelSetDifficulte(joueur, niveau);
}

void controller()
{
    Joueur joueur;
    viewAfficherBanniere();
    configurerJoueur(&joueur);

    do {
        jouerPartie(&joueur);
        viewAfficherStats(&joueur);
    } while (viewDemanderRejouer(&joueur));
}
