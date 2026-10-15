# Minishell

Minishell est un projet de l’école 42 qui consiste à créer, en C, un interpréteur de commandes inspiré de Bash. Il affiche une invite interactive, lit les commandes saisies, les analyse puis les exécute dans un processus ou une chaîne de processus.

> Ce projet reproduit un sous-ensemble des fonctionnalités d’un shell : il ne vise pas à remplacer Bash ni à en reproduire toute la grammaire.

## Fonctionnalités

- Invite interactive avec historique des commandes grâce à GNU Readline.
- Analyse de la ligne de commande : vérification des erreurs de syntaxe, tokenisation et prise en compte des guillemets simples et doubles.
- Exécution de commandes et enchaînement par pipes (`|`).
- Redirections d’entrée (`<`), de sortie (`>`), d’ajout (`>>`) et document here-doc (`<<`).
- Expansion des variables d’environnement (`$NOM`) et du code de retour précédent (`$?`).
- Commandes intégrées : `echo`, `cd`, `pwd`, `env`, `export`, `unset` et `exit`.
- Gestion des signaux clavier, notamment `Ctrl-C` et `Ctrl-\`, avec un traitement particulier pendant la saisie d’un here-doc.

## Prérequis

- Un environnement Unix/Linux avec un compilateur C (`cc`) et `make`.
- GNU Readline et ses fichiers de développement (par exemple `libreadline-dev` sur Debian ou Ubuntu).

La bibliothèque utilitaire `pedro_lib` est incluse dans le dépôt et construite par le Makefile.

## Compilation et lancement

Depuis la racine du dépôt :

```sh
make
./bin/minishell
```

Le programme s’utilise de manière interactive. Il n’accepte pas d’arguments au lancement.

Exemples de commandes à essayer :

```sh
echo "Bonjour $USER"
pwd
cat README.md | grep Minishell
cat < README.md
echo "sortie" >> sortie.txt
cat << FIN
Texte à saisir
FIN
```

## Commandes Makefile

| Commande | Action |
| --- | --- |
| `make` ou `make all` | Compile le projet et produit `bin/minishell`. |
| `make clean` | Supprime les fichiers objets. |
| `make fclean` | Supprime les fichiers objets et l’exécutable généré. |
| `make re` | Nettoie puis recompile le projet. |

## Organisation du projet

```text
.
├── Includes/                 # En-tête principal et déclarations
├── Libraries/pedro_lib/      # Bibliothèque utilitaire du projet
├── srcs_mandatory/
│   ├── Builtins/             # Commandes intégrées
│   ├── Environnement/        # Initialisation et gestion de l’environnement
│   ├── Exec/
│   │   ├── the_exec/         # Processus, commandes et redirections
│   │   └── the_parsing/      # Préparation des commandes et redirections
│   ├── Expands/              # Expansion des variables et traitement des mots
│   ├── Here_doc/             # Gestion des here-docs
│   ├── Lexer/                # Découpage en tokens
│   ├── Pre_parser/           # Vérifications syntaxiques préalables
│   ├── Signals/              # Gestion des signaux
│   └── Zmain_functions/      # Initialisation et boucle principale
└── Makefile                  # Compilation et nettoyage
```

## Parcours d’une commande

Le traitement suit plusieurs étapes : vérification de la saisie, analyse lexicale, expansion des variables, préparation des commandes et des redirections, puis exécution. Les commandes reliées par des pipes sont lancées avec les flux correspondants ; les commandes intégrées sont traitées par le shell.

## À propos

Projet pédagogique réalisé dans le cadre du cursus 42, autour de la programmation système en C : processus, descripteurs de fichiers, signaux, environnement et analyse de commandes.
