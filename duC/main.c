#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define TAILLE_MAX 9
#define TAILLE_DECK 20

typedef struct {
    int cartes[TAILLE_DECK];
    int taille;
} Paquet;


typedef struct {
    int id;
    int points;
    int cases_trouves[2];
    int nb_tentatives;
    int echecs;
} Joueur;

///-------------------------------------------------------------------------------------------------------------------------------------------------------PROTOTYPES
void init_paquet(Paquet *paquet);
void melanger_paquet(Paquet *paquet);
void generer_tableau(int tableau[TAILLE_MAX][TAILLE_MAX], int l, int c, Paquet *paquet1, Paquet *paquet2);
void afficher_tableau(int tableau[TAILLE_MAX][TAILLE_MAX], int l, int c);
void afficher_tableau_cachee(int tableau[TAILLE_MAX][TAILLE_MAX], int l, int c);
void afficher_tableau_cachee_avec_numero(int tableau[TAILLE_MAX][TAILLE_MAX], int l, int c, int numero);
void effacement_3 ();
void effacement_5 ();
void effacement_7 ();
void une_manche_2(int tableau[TAILLE_MAX][TAILLE_MAX],int l, int c, int nbJoueurs, int ordi,int nombre, int nb_tentatives);
int init_partie();

//-------------------------------------------------------------------------------------------------------------------------------------------------------MAIN
int main() {
    int nombre;
    printf("☆꧁✬◦°˚°◦. Bienvenue .◦°˚°◦✬꧂☆ \n\n Nous allons jouer à ☆꧁✬◦°˚°◦. Mémorix .◦°˚°◦✬꧂☆ . \n\n Voulez-vous les règles du jeu ? (0: oui / 1: non)");
    init_partie();
    return 0;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------FONCTIONS
void init_paquet(Paquet *paquet) {
    paquet->taille = TAILLE_DECK;
    for (int i = 0; i < TAILLE_DECK; i++) {
        paquet->cartes[i] = i + 1;
    }
}
void melanger_paquet(Paquet *paquet) {
    for (int i = 0; i < paquet->taille; i++) {
        int index_aleatoire = rand() % paquet->taille;
        int valeur_temporaire = paquet->cartes[i];
        paquet->cartes[i] = paquet->cartes[index_aleatoire];
        paquet->cartes[index_aleatoire] = valeur_temporaire;
    }
}
void generer_tableau(int tableau[TAILLE_MAX][TAILLE_MAX], int l, int c, Paquet *paquet1, Paquet *paquet2) {
    int index = 0;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (index < paquet1->taille) {
                tableau[i][j] = paquet1->cartes[index];
            }
            else {
                tableau[i][j] = paquet2->cartes[index - paquet1->taille];
            }
            index++;
        }
    }
}
//affiche le tableau avec valeurs
void afficher_tableau(int tableau[TAILLE_MAX][TAILLE_MAX], int l, int c) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (tableau[i][j] < 10) {
                printf("[ %d]", tableau[i][j]);
            }
            else if (tableau[i][j] >= 10) {
                printf("[%d]", tableau[i][j]);
            }
        }
        printf("\n");
    }
}

//affiche le tableau sans valeurs
void afficher_tableau_cachee(int tableau[TAILLE_MAX][TAILLE_MAX], int l, int c) {
    int k=0;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            k+=1;
            if (k < 10) {
                printf("[ %d]", k);
            }
            else if (k >= 10) {
                printf("[%d]", k);
            }
        }
        printf("\n");
    }
}
void afficher_tableau_cachee_avec_numero(int tableau[TAILLE_MAX][TAILLE_MAX], int l, int c, int numero) {
    int k = 0;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            k += 1;
            if (k == numero) {
                printf("[ %2d]", tableau[i][j]);
            }
            else {
                printf("[ **]");
            }
        }
        printf("\n");
    }
}
void effacement_3 () {
    sleep(5);
    printf("\033[1A\033[2K");
    printf("\033[1A\033[2K");
    printf("\033[1A\033[2K");
    printf("\033[1A\033[2K");
    fflush(stdout);
}
void effacement_5 () {
    sleep(5);
    printf("\033[1A\033[2K");
    printf("\033[1A\033[2K");
    printf("\033[1A\033[2K");
    printf("\033[1A\033[2K");
    printf("\033[1A\033[2K");
    printf("\033[1A\033[2K");
    fflush(stdout);
}
void effacement_7 () {
    sleep(5);
    printf("\033[1A\033[2K");
    printf("\033[1A\033[2K");
    printf("\033[1A\033[2K");
    printf("\033[1A\033[2K");
    printf("\033[1A\033[2K");
    printf("\033[1A\033[2K");
    printf("\033[1A\033[2K");
    printf("\033[1A\033[2K");
    fflush(stdout);
}
void une_manche_2(int tableau[TAILLE_MAX][TAILLE_MAX],int l, int c, int nbJoueurs, int ordi,int nombre, int nb_tentatives) {
    afficher_tableau_cachee(tableau, l, c);
    Joueur joueurs_2[nbJoueurs];

    // Initialize players 
    for (int i = 0; i < nbJoueurs; i++) {
        joueurs_2[i].id = i + 1;
        joueurs_2[i].points = 0;
        joueurs_2[i].nb_tentatives = nb_tentatives;
        joueurs_2[i].echecs = 0;
    }

    for (int i = 0; i < nombre; i++) {
        int num_carte = 2;
        int choixJoueur[nbJoueurs][num_carte];

        if (i+1 == 1) {
            printf("\nManche numéro %d \n",i+1);
        }

        else {
            printf("\n\nManche numéro %d \n",i+1);
        }

        // Each player chooses two card numbers
        for (int i = 0; i < nbJoueurs; i++) {
            num_carte=0;
            int joker=0;

            if (num_carte == 0) {

                if (joker == 1) {
                    printf("Joueur %d, choisissez le numéro de votre première carte : ", joueurs_2[i].id-1);
                    scanf("%d", &choixJoueur[i][num_carte]);
                }

                else {
                    printf("Joueur %d, choisissez le numéro de votre première carte : ", joueurs_2[i].id);
                    scanf("%d", &choixJoueur[i][num_carte]);
                }

                if (choixJoueur[i][0] >= 1 && choixJoueur[i][num_carte] <= l * c) {

                    int ligne_carte_1 = (choixJoueur[i][num_carte] - 1) / c;
                    int colonne_carte_1 = (choixJoueur[i][num_carte] - 1) % c;

                    if (tableau[ligne_carte_1][colonne_carte_1] == 0) {
                        printf("La valeur derrière le numéro %d est : 0 !\n Vous avez pioché le Joker.\n Vous devez donc passer votre tour.\n", choixJoueur[i][num_carte]);

                        joueurs_2[i].id++;
                        num_carte--;
                        joker=1;

                    }

                    else {

                        printf("La valeur derrière le numéro %d est : %d\n", choixJoueur[i][0], tableau[ligne_carte_1][colonne_carte_1]);
                        afficher_tableau_cachee_avec_numero(tableau, l, c, choixJoueur[i][num_carte]);

                        if (l == 3) {
                            effacement_3();
                        }

                        else if (l == 5) {
                            effacement_5();
                        }

                        else if (l == 7) {
                            effacement_7();
                        }

                        num_carte++;
                    }
                }
                else {

                    while (choixJoueur[i][num_carte] <= 0 || choixJoueur[i][num_carte] > l * c) {

                        printf("Erreur : Veuillez choisir un numéro entre 1 et %d.\n", l * c);
                        printf("Veuillez réessayer : ");
                        scanf("%d", &choixJoueur[i][num_carte]);

                    }

                    num_carte++;
                }
            }

            if (num_carte == 1){

                printf("Joueur %d, choisissez le numéro de votre deuxième carte : ", joueurs_2[i].id);
                scanf("%d", &choixJoueur[i][num_carte]);

                if (choixJoueur[i][num_carte] == choixJoueur[i][num_carte-1]) {

                    printf("Erreur : Veuillez prendre un numéro différent : ");
                    scanf("%d", &choixJoueur[i][num_carte]);

                    while (choixJoueur[i][num_carte] == choixJoueur[i][num_carte-1]) {
                        printf("Veuillez réessayer :");
                        scanf("%d", &choixJoueur[i][num_carte]);
                    }

                    num_carte--;
                }
                else {
                    if (choixJoueur[i][num_carte] >= 1 && choixJoueur[i][num_carte] <= l * c) {

                        int ligne_carte_2 = (choixJoueur[i][num_carte] - 1) / c;
                        int colonne_carte_2 = (choixJoueur[i][num_carte] - 1) % c;

                        if (tableau[ligne_carte_2][colonne_carte_2] == 0) {

                            printf("La valeur derrière le numéro %d est : 0 !\n Vous avez pioché le Joker.\n Vous devez donc passer votre tour.\n", choixJoueur[i][num_carte]);

                            joueurs_2[i].id--;
                            num_carte--;
                            choixJoueur[i][0] = 0;
                        }

                        else {

                            printf("La valeur derrière le numéro %d est : %d\n", choixJoueur[i][num_carte], tableau[ligne_carte_2][colonne_carte_2]);

                            afficher_tableau_cachee_avec_numero(tableau, l, c, choixJoueur[i][num_carte]);

                            if (l == 3) {
                                effacement_3();
                            }

                            else if (l == 5) {
                                effacement_5();
                            }

                            else if (l == 7) {
                                effacement_7();
                            }

                            num_carte--;

                        }

                    }

                    else {

                        while (choixJoueur[i][num_carte] <= 0 || choixJoueur[i][num_carte] > l * c) {
                            printf("Erreur : Veuillez choisir un numéro entre 1 et %d.\n", l * c);
                            printf("Veuillez réessayer : ");
                            scanf("%d", &choixJoueur[i][num_carte]);
                        }

                        num_carte--;

                    }
                }
            }
        }

        // Check if the chosen cards are the same and award points
        for (int i = 0; i < nbJoueurs; i++) {

            int ligne1 = (choixJoueur[i][0] - 1) / c;
            int colonne1 = (choixJoueur[i][0] - 1) % c;

            int ligne2 = (choixJoueur[i][1] - 1) / c;
            int colonne2 = (choixJoueur[i][1] - 1) % c;

            if (tableau[ligne1][colonne1] == tableau[ligne2][colonne2]) {

                joueurs_2[i].points++;

                if (joueurs_2[i].id == 1) {
                    printf("\nJoueur %d a trouvé une paire et gagne un point!\nSon score est de %d.\n", joueurs_2[i].id,joueurs_2[i].points);
                }

                else {
                    printf("\n\nJoueur %d a trouvé une paire et gagne un point!\nSon score est de %d.\n", joueurs_2[i].id,joueurs_2[i].points);
                }

                joueurs_2[i].echecs=0;

            }
            else {

                printf("\nJoueur %d n'a pas trouvé de paire.\n", joueurs_2[i].id);

                joueurs_2[i].nb_tentatives--;
                joueurs_2[i].echecs++;

                if (joueurs_2[i].nb_tentatives == 0){
                    joueurs_2[i].points--;
                    printf("Le joueur %d a perdu 1 point ce qui lui laisse un score de %d\n",i+1,joueurs_2[i].points);
                }

                else {
                    printf("Il lui reste %d tentatives avant de perdre un point.\nSon score est de %d",joueurs_2[i].nb_tentatives,joueurs_2[i].points);
                }
                
            }
        }

        if (ordi == 1) {

            int computerChoices_2[2*nombre];

            printf("Ordinateur joue :\n");
            // Loop until the computer player finds non-Joker cards for both choices
            do {
                computerChoices_2[i] = rand() % (l * c) + 1;
            } 
            while (tableau[(computerChoices_2[i] - 1) / c][(computerChoices_2[i] - 1) % c] == 0);

            do {
                computerChoices_2[1] = rand() % (l * c) + 1;
            } 
            while (tableau[(computerChoices_2[i+1] - 1) / c][(computerChoices_2[i+1] - 1) % c] == 0);
            // Check if the chosen cards by the computer form a matching pair
            int ligne1_comp = (computerChoices_2[i] - 1) / c;
            int colonne1_comp = (computerChoices_2[i] - 1) % c;

            int ligne2_comp = (computerChoices_2[i+1] - 1) / c;
            int colonne2_comp = (computerChoices_2[i+1] - 1) % c;
            // Display the choices made by the computer
            printf("L'Ordinateur choisit les cartes %d, qui a pour valeur %d et %d qui a pour valeur %d.\n", computerChoices_2[i],tableau[ligne1_comp][colonne1_comp], computerChoices_2[i+1],tableau[ligne2_comp][colonne2_comp]);

            if (tableau[ligne1_comp][colonne1_comp] == tableau[ligne2_comp][colonne2_comp]) {
                joueurs_2[nbJoueurs+1].points++;
                printf("\nL'Ordinateur a trouvé une paire et gagne un point!\n");
            } 

            else {
                printf("\nL'Ordinateur n'a pas trouvé de paire.\n");
            }
            // Display player points (Joueur 2)
            printf("Ordinateur : %d points\n", joueurs_2[nbJoueurs+1].points);
        }
    }

    printf("\nLe tableau était :\n\n");
    afficher_tableau(tableau, l, c);
    // Trier le tableau des participants en fonction des points
    for (int i = 0; i < nbJoueurs - 1; i++) {
        for (int j = 0; j < nbJoueurs - i - 1; j++) {

            if (joueurs_2[j].points < joueurs_2[j + 1].points) {
                Joueur temp = joueurs_2[j];
                joueurs_2[j] = joueurs_2[j + 1];
                joueurs_2[j + 1] = temp;
            }

        }
    }
    // Afficher le classement
    printf("\nClassement:\n");

    for (int i = 0; i < nbJoueurs; i++) {
        printf("%d. Joueur %d - %d points - %d echecs\n", i + 1, joueurs_2[i].id, joueurs_2[i].points,joueurs_2[i].echecs);
    }

}

int init_partie() {
    int l, c, nombre_de_manche;
    int tableau[TAILLE_MAX][TAILLE_MAX];
    Paquet paquet1, paquet2;
    init_paquet(&paquet1);
    init_paquet(&paquet2);
    melanger_paquet(&paquet1);
    melanger_paquet(&paquet2);

    printf("Bonsoir, combien de manches voulez-vous jouer ? ");
    scanf("%d",&nombre_de_manche);

    int sur;
    if (nombre_de_manche == 0){
        while(sur != 0){
            printf("Êtes-vous sûr de vouloir faire ***0*** manches ? (0 : oui /1 : non)");
            scanf("%d", &sur);
            if (sur == 0){
                printf("D'accord ! \n ☆꧁✬◦°˚°◦. Ciao .◦°˚°◦✬꧂☆\n\n");
                return 0;
            }
            else if (sur == 1){
                printf("Ah, et bien voici un deuxième chance de rentrer la bonne valeur : ");
                scanf("%d", &nombre_de_manche);
            }
            else{
                printf("Eummm, alors, la valeur n'est pas valide, réessayez\n");
            }
        }
    }

    srand(time(NULL));

    printf("Entrez le nombre de lignes (3, 5, 7) : ");
    scanf("%d", &l);

    if (l < 3 || l > 7 || l == 4 || l == 6) {
        while (l < 3 || l > 7 || l == 4 || l == 6) {
            printf("Erreur : Veuillez choisir 3 , 5 ou 7 lignes\n");
            printf("Veuillez réessayer : ");
            scanf("%d", &l);
        }
    }

    printf("Entrez le nombre de colonnes (5, 7, 9) : ");
    scanf("%d", &c);

    if (c < 5 || c > 9 || c == 6 || c == 8) {
        while (c < 5 || c > 9 || c == 6 || c == 8) {
            printf("Erreur : Veuillez choisir 5 , 7 ou 9 colonnes\n");
            printf("Veuillez réessayer : ");
            scanf("%d", &c);
        }
    }

    generer_tableau(tableau, l, c, &paquet1, &paquet2);
    int index_joker = rand() % (l * c);
    int ligne_joker = index_joker / c;
    int colonne_joker = index_joker % c;
    tableau[ligne_joker][colonne_joker] = 0;

    int nbJoueurs;
    printf("Entrez le nombre de joueurs : ");
    scanf("%d", &nbJoueurs);

    int ordi;
    printf("Voulez-vous rajouter un ordinateur ? (1 : Oui | 0 : Non) : ");
    scanf("%d",&ordi);

    while (ordi < 0 || ordi > 1) {
        ordi=0;
        printf("Erreur : Vous devez entrer 1 pour dire que vous voulez un ordinateur en plus dans la partie ou 0 pour le contraire.\n");
        printf("Veuillez réessayer : ");
        scanf("%d",&ordi);
    }
    
    int total = nbJoueurs + ordi;

    while (nbJoueurs < 1 || nbJoueurs > 4 || total > 4) {
        ordi=0;
        total=0;
        nbJoueurs=0;
        printf("Erreur : Veuillez choisir entre 1 et 4 joueurs en comptant l'ordinateur.\n");
        printf("Veuillez réentrer le nombre de joueurs : ");
        scanf("%d", &nbJoueurs);
        printf("Voulez-vous rajouter un ordinateur ? (1 : Oui | 0 : Non) : ");
        scanf("%d",&ordi);
    }

    int nb_essai;

    printf("Choisissez le nombre de tentatives maximum : ");
    scanf("%d", &nb_essai);

    while (nb_essai < 1 || nb_essai > nombre_de_manche){
        printf("Le nombre de tentatives doit être de 1 au minimum.\n Réessayez : ");
        scanf("%d", &nb_essai);
    }

    une_manche_2(tableau,l,c,nbJoueurs,ordi,nombre_de_manche,nb_essai);
    return 0;
}

/*
int paires;
    char jeu[14];
    creation_jeu(&jeu[14]);
    printf("Saisissez le nombre de paires");
    scanf("%i",&paires);

void creation_jeu(char *set[]) { //Cette fonction va créer un set de 13 cartes allant de 1 à 10 en plus du Valet, de la Dame et du Roi
    char set[14]; //On créer un tableau d'une taille de 14 caractères

    for (int i=0;i<15;i++) { //La boucle for va remplir le tableau, R = roi, D = dame, V = Valet
        set[i]=i+1;
        if (i=11) {
            set[11]='V';
        }
        else if (i=12) {
            set[12]='D';
        }
        else if (i=13) {
            set[13]='R';
        };
    };
    set[14]='\0'; // Ce caractère marque la fin du tableau

    return set[14]; //On retourne le tableau
};
*/
