#include "view.h"
#include <cstdio>
#include <cstring>

void viewAfficherBanniere()
{
    printf("\n");
    printf(CYAN BOLD "  ╔══════════════════════════════════╗\n" RESET);
    printf(CYAN BOLD "  ║   " JAUNE "🎯  JUSTE PRIX  v%s" CYAN "           ║\n" RESET, VERSION);
    printf(CYAN BOLD "  ║   " BLANC "BTS CIEL — LaSalle Avignon" CYAN "    ║\n" RESET);
    printf(CYAN BOLD "  ╚══════════════════════════════════╝\n" RESET);
    printf("\n");
}

void viewDemanderNom(char *nom, int taille)
{
    printf(BLANC "Entrez votre nom : " RESET);
    fgets(nom, taille, stdin);
    int len = (int)strlen(nom);
    if (len > 0 && nom[len - 1] == '\n') nom[len - 1] = '\0';
}

void viewAfficherMenuDifficulte()
{
    printf("\n" BOLD "Choisissez un niveau de difficulté :\n" RESET);
    printf(VERT  "  [1] Facile    " RESET "— 1 à 50,  10 tentatives\n");
    printf(JAUNE "  [2] Moyen     " RESET "— 1 à 100,  7 tentatives\n");
    printf(ROUGE "  [3] Difficile " RESET "— 1 à 500,  5 tentatives\n");
}

int viewDemanderDifficulte()
{
    int choix = 0;
    while (choix < 1 || choix > 3) {
        printf(BLANC "Votre choix : " RESET);
        scanf("%d", &choix);
        getchar();
    }
    return choix;
}

void viewAfficherDebutPartie(const Joueur *joueur)
{
    printf("\n" CYAN "──────────────────────────────────────\n" RESET);
    printf(BOLD "  Bonne chance, %s !\n" RESET, joueur->nom);
    printf("  Devinez un nombre entre " VERT "%d" RESET " et " VERT "%d" RESET "\n",
           joueur->difficulte.borneMin, joueur->difficulte.borneMax);
    printf("  Tentatives autorisées : " JAUNE "%d\n" RESET, joueur->difficulte.maxTentatives);
    printf(CYAN "──────────────────────────────────────\n\n" RESET);
}

int viewDemanderProposition(const Joueur *joueur)
{
    int val = -1;
    printf(BLANC "[%s] Tentative %d/%d — Votre proposition : " RESET,
           joueur->nom,
           joueur->tentativeCourante + 1,
           joueur->difficulte.maxTentatives);
    scanf("%d", &val);
    getchar();
    return val;
}

void viewAfficherResultatTentative(int resultat, const Joueur *joueur)
{
    if (resultat == -1)
        printf(ROUGE "  ➜  C'est plus grand !\n\n" RESET);
    else if (resultat == 1)
        printf(BLEU  "  ➜  C'est plus petit !\n\n" RESET);
    (void)joueur;
}

void viewAfficherVictoire(const Joueur *joueur)
{
    printf(VERT BOLD "\n  ✅  Bravo %s ! Vous avez trouvé en %d essai(s) !\n" RESET,
           joueur->nom, joueur->tentativeCourante);
}

void viewAfficherDefaite(const Joueur *joueur)
{
    printf(ROUGE BOLD "\n  ❌  Perdu %s ! Le nombre était %d.\n" RESET,
           joueur->nom, joueur->nombreSecret);
}

void viewAfficherStats(const Joueur *joueur)
{
    printf("\n" CYAN "──────────────────────────────────────\n" RESET);
    printf(BOLD "  Statistiques de %s :\n" RESET, joueur->nom);
    printf("  Parties jouées  : " JAUNE "%d\n" RESET, joueur->partiesJouees);
    printf("  Parties gagnées : " VERT "%d\n" RESET, joueur->partiesGagnees);
    printf(CYAN "──────────────────────────────────────\n" RESET);
}

int viewDemanderRejouer(const Joueur *joueur)
{
    char rep[4];
    printf("\n" BLANC "[%s] Voulez-vous rejouer ? (o/n) : " RESET, joueur->nom);
    fgets(rep, sizeof(rep), stdin);
    return (rep[0] == 'o' || rep[0] == 'O');
}
