# 🎯 JustePrix

> Mini-projet BTS CIEL — Développement collaboratif en C++

![Version](https://img.shields.io/badge/version-3.0-blue)
![Language](https://img.shields.io/badge/langage-C%2B%2B-orange)
![Architecture](https://img.shields.io/badge/architecture-MVC-green)
![Interface](https://img.shields.io/badge/interface-CLI-lightgrey)

---

## 📖 Description

**JustePrix** est un jeu en ligne de commande inspiré de l'émission télévisée du même nom.  
Un nombre est tiré aléatoirement entre deux bornes, et le joueur doit le deviner en un **minimum d'essais**.  
À chaque tentative, le jeu indique si le nombre recherché est **supérieur** ou **inférieur** à la proposition du joueur.

Ce projet a été réalisé dans le cadre d'un mini-projet BTS avec pour objectif de mettre en œuvre les **méthodes de développement collaboratif** (Kanban, Gitflow, architecture MVC).

---

## 🗂️ Structure du projet

```
src/
├── controller.cpp   # Logique et gestion des événements
├── controller.h
├── justeprix.cpp    # Point d'entrée (main)
├── model.cpp        # Données métier
├── model.h
├── view.cpp         # Interface utilisateur (CLI)
└── view.h
Makefile             # Compilation du projet
README.md
```

---

## 🚀 Versions

### Version 1.0 — Base du jeu
- Saisie du nom du joueur
- Jouer une ou plusieurs parties
- Gestion du niveau de difficulté (bornes min/max, nombre de tentatives autorisées)
- Affichage du nom du logiciel et de sa version au lancement

### Version 2.0 — Scores & Historique
- Affichage de l'historique des parties jouées (avec les coups joués)
- Sauvegarde des résultats dans un fichier des meilleurs scores
- Affichage du classement général des meilleurs scores
- Affichage de la position du joueur dans le classement

### Version 3.0 — Chronomètre
- Chronométrage de chaque partie
- (fonctionnalités additionnelles à venir...)

---

## ⚙️ Prérequis

- Compilateur **C++** (g++ recommandé)
- Système **Linux / macOS** (ou terminal compatible ANSI sous Windows)
- **Make** pour la compilation

---

## 🛠️ Installation & Compilation

**1. Cloner le dépôt :**
```bash
git clone https://github.com/<votre-organisation>/justeprix.git
cd justeprix
```

**2. Compiler le projet :**
```bash
make
```

**3. Lancer le jeu :**
```bash
./justeprix
```

---

## 🕹️ Manuel d'utilisation

### Démarrage

Au lancement, le jeu affiche son nom et sa version, puis demande le nom du joueur :

```
===========================
    JUSTE PRIX  v3.0
===========================
Entrez votre nom : Alice
```

### Choisir la difficulté

Le joueur sélectionne un niveau de difficulté qui définit les bornes et le nombre de tentatives :

```
Choisissez un niveau de difficulté :
  [1] Facile    (1 - 50,   10 tentatives)
  [2] Moyen     (1 - 100,  7 tentatives)
  [3] Difficile (1 - 500,  5 tentatives)
Votre choix : 2
```

### Jouer une partie

Le jeu génère un nombre aléatoire. Le joueur propose une valeur à chaque tour :

```
[Alice] Tentative 1/7 — Votre proposition : 42
  ➜ C'est plus grand !

[Alice] Tentative 2/7 — Votre proposition : 75
  ➜ C'est plus petit !

[Alice] Tentative 3/7 — Votre proposition : 63
  ✅ Bravo Alice ! Vous avez trouvé en 3 essais !
```

### Rejouer ou quitter

```
Voulez-vous rejouer ? (o/n) : o
```

### Classement (v2.0+)

À la fin d'une partie, le score est sauvegardé et le classement s'affiche :

```
╔══════════════════════════════╗
║        MEILLEURS SCORES      ║
╠══════════════════════════════╣
║  1. Alice       3 essais     ║
║  2. Bob         5 essais     ║
║  3. Charlie     7 essais     ║
╚══════════════════════════════╝
Votre position : 1er 🏆
```

### Chronomètre (v3.0+)

Le temps de chaque partie est affiché à la fin :

```
⏱️  Temps de la partie : 00:45
```

---

## 🏗️ Architecture MVC

Le projet suit le patron de conception **Modèle-Vue-Contrôleur** :

| Composant | Fichier | Rôle |
|---|---|---|
| **Modèle** | `model.cpp / .h` | Données métier : nombre à deviner, scores, historique |
| **Vue** | `view.cpp / .h` | Affichage CLI, saisies utilisateur, couleurs ANSI |
| **Contrôleur** | `controller.cpp / .h` | Logique du jeu, synchronisation modèle ↔ vue |

La fonction `main()` se contente de démarrer le contrôleur :
```cpp
int main() {
    controller();
    return 0;
}
```

---

## 🎨 Couleurs ANSI

L'interface utilise les séquences d'échappement ANSI pour coloriser le terminal :

```cpp
// Exemple : afficher du texte en rouge
std::cout << "\033[31m" << "C'est plus grand !" << "\x1b[0m" << std::endl;
```

---

## 📋 Méthodologie de développement

- **Kanban** : gestion des tâches via GitHub Projects
- **Gitflow** : branches `main`, `develop`, branches de fonctionnalités et de correctifs
- **Cycle itératif et incrémental** : livraison par versions (1.0 → 2.0 → 3.0)
- Chaque version livrée est signalée au client par mail avec une **release sur `main`**

---

## 👥 Auteurs

| Nom | Rôle |
|-----|------|
| *(Prénom NOM)* | Développeur |
| *(Prénom NOM)* | Développeur |

*BTS CIEL — LaSalle Avignon — 2026*

---

## 📄 Licence

Projet réalisé dans un cadre pédagogique — BTS CIEL, LaSalle Avignon.
