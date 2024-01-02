#include <stdio.h>
#include <stdlib.h>

#define True 0
#define False 1
#define Taille_deck 20
#define Taille_max 9

struct Deck{
    int cartes[Taille_deck];
    int taille;
};
typedef Deck Paquet;

void init_paquet(Paquet *paquet_jeu)
{
    paquet_jeu->taille = Taille_deck;
    for (int i = 0; i < Taille_deck; i++) {
        paquet_jeu->cartes[i] = i + 1;
    }
}

void melanger_deck(Paquet *paquet_jeu) {
    for (int i = 0; i < paquet_jeu->taille; i++) {
        int index_aleatoire = rand() % paquet_jeu->taille;
        int valeur_temporaire = paquet_jeu->cartes[i];
        paquet_jeu->cartes[i] = paquet_jeu->cartes[index_aleatoire];
        paquet_jeu->cartes[index_aleatoire] = valeur_temporaire;
    }
}

struct Inf_Joueur{
    char nom[51];
    int points;
    int nb_tentatives;
    int ordre_passage;
};
typedef Inf_Joueur Joueur;

int nombre_joueurs(int *ordinateur){
    int nb_joueurs=0, joueur_ordinateur:
    while ((nb_joueurs < 1) || (nb_joueurs >= 5))
    {
        printf("Indiquez le nombre de joueurs (maximum 4 et sans compter l'ordinateur) : ");
        scanf("%d", nb_joueurs);
        if ((nb_joueurs < 1) || (nb_joueurs >= 5)){
            printf("Veuillez entrer un nombre valide de joueurs ! ");
        }
        if ((nb_joueurs >= 1) && (nb_joueurs <= 3)){
            printf("Voulez-vous que l'ordinateur joue avec vous ? (Oui : 1, Non : 2)");
            scanf("%d", &joueur_ordinateur);
            if (joueur_ordinateur == 1){
                *ordinateur=True;
                printf("D'accord, il y aura un ordinateur alors !");
                nb_joueurs += 1;
            }
            else if (joueur_ordinateur == 2){
                printf("D'accord, il n'y aura pas d'ordinateur alors !");
            }
            while ((joueur_ordinateur!=1) && (joueur_ordinateur !=2))
            {            
                printf("La valeur entrée est invalide, réessayez.");
                printf("Voulez-vous que l'ordinateur joue avec vous ? (Oui : 1, Non : 2)");
                scanf("%d", &joueur_ordinateur);
            }
        };
    }
    return nb_joueurs;
}

void init_joueurs(int *nb_joueurs, int *ordinateur){
    int i=0;
    if (*ordinateur==True)
    {
        Joueur->nom="Ordinateur";
        Joueur->points=0;
        Joueur->ordre_passage=nb_joueurs;
        i += 1;
    }
    while (*nb_joueurs != i){
        printf("Entrez un nom de 50 caractères ou moins pour le joueur :");
        fgets(&(joueur->nom), 50, stdin);
        Joueur->points = 0;
        Joueur->ordre_passage = i;
        i += 1;
    }
}



void generer_tableau(int tableau[Taille_max][Taille_max], int l, int c, Paquet *deck1, Paquet *deck2) {
    int index = 0;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (index < deck1->taille) {
                tableau[i][j] = deck1->cartes[index];
            } else {
                tableau[i][j] = deck2->cartes[index - deck1->taille];
            }
            index++;
        }
    }
}

void taille_tableau(int *l, int *c){
    printf("Choisissez le nombre de lignes (3, 5 ou 7) et de colonnes (5, 7 ou 9) du plateau. ");
    scanf("%d %d", &l, &c);
    while (l!=3 || l!=5 || l!=7 || c!=5 || c!=7 || c!=9){
        if ((l != 3) && (l != 5) && (l != 7)){
            printf("Entrez un nombre de lignes valide (3, 5 ou 7) :");
            scanf("%d", l);
        };
        if ((c != 5) && (c != 7) && (c != 9)){
            printf("Entrez un nombre de colonnes valide (5, 7 ou 9) :");
            scanf("%d", c);
        };
    };
}

void affiche_tableau_valeurs(int tableau[Taille_max][Taille_max], int l, int c){
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

void afficher_tableau_cachee(int tableau[Taille_max][Taille_max], int l, int c) {
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

void afficher_tableau_cachee_avec_carte_demandee(int tableau[Taille_max][Taille_max], int l, int c, int numero) {
    int k = 0;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            k += 1;
            if (k == numero) {
                printf("[ %2d]", tableau[i][j]);
            } else {
                printf("[ **]");
            }
        }
        printf("\n");
    }
}

void init_echecs(int *nb_echecs){
    printf("Choisissez le nombre d'échecs maximum : ");
    scanf("%d", nb_echecs);
    if (nb_echecs < 1){
        printf("Le nombre d'échecs doit être de 1 au minimum. Réessayez.");
        scanf("%d", nb_echecs);
    };
}

int est_joker(int *carte){
    if (*carte = 0){
        return True;
    }
    return False;
};

int paire_ou_non(int *points_du_joueur, int *carte1, int *carte2, int *nb_tentatives){
    if (*carte1 == *carte2){
        *points_du_joueur += 1;
        printf("Vous avez trouvé la paire de %d ! Vous avez désormais %d points !", *carte1, *points_du_joueur);
    }
    else{
        *nb_tentatives -= 1;
        printf("Les cartes avaient des valeurs différentes : %d et %d. Il vous reste %d", *carte1, *carte2, *nb_tentatives);
        tentatives(&(&nb_tentatives));
    };
}

void choix_de_cartes(int *carte1, int *carte2)
{
    for (int i = 0; i < nbJoueurs; i++) 
    {
        printf("Joueur %d, choisissez le numéro de votre première carte : ", joueurs[i].ordre_passage);
        scanf("%d", &carte1[i][0]);
        if (carte1[i][0] >= 1 && carte1[i][0] <= l * c) {
            int ligne = (carte1[i][0] - 1) / c;
            int colonne = (carte1[i][0] - 1) % c;

            printf("La valeur derrière le numéro %d est : %d\n", carte1[i][0], tableau[ligne][colonne]);
            afficher_tableau_cachee_avec_numero(tableau, l, c, carte1[i][0]);
        } 
        else 
        {
        printf("Choix invalide. Veuillez choisir un numéro entre 1 et %d.\n", l * c);
        }
        printf("Joueur %d, choisissez le numéro de votre deuxième carte : ", joueurs[i].ordre_passage);
        scanf("%d", &carte2[i][1]);
        if (carte2[i][1] >= 1 && carte2[i][1] <= l * c) 
        {
            int ligne = (carte2[i][1] - 1) / c;
            int colonne = (carte2[i][1] - 1) % c;

            printf("La valeur derrière le numéro %d est : %d\n", carte2[i][1], tableau[ligne][colonne]);
            afficher_tableau_cachee_avec_numero(tableau, l, c, carte2[i][1]);
        } 
        else 
        {
            printf("Choix invalide. Veuillez choisir un numéro entre 1 et %d.\n", l * c);
        }
    }
}

void tentatives(int *nb_tentatives, int *points_du_joueur, int *nb_echecs){
    if (*nb_tentatives = 0){
        *points_du_joueur -= 1;
        printf("Vous avez perdu 1 point ce qui vous laisse avec un score de %d", *points_du_joueur);
        *nb_tentatives = *nb_echecs;
    };
}

void affiche_points_joueur(Joueur)
{
    printf("Joueur %d : %d points\n", joueurs[i].ordre_passage, joueurs[i].points);
}

void initialisation_partie(){
    int l, c, nb_joueurs, ordinateur=False, joueur_ordinateur, n;
    int tableau[TAILLE_MAX][TAILLE_MAX];
    Paquet deck1, deck2;
    init_deck(&deck1);
    init_deck(&deck2);
    melanger_deck(&deck1);
    melanger_deck(&deck2);

    srand(time(NULL));

    nb_joueurs = nombre_joueurs(&ordinateur);
    init_joueurs(&nb_joueurs, &ordinateur);

    int nb_echecs;
    init_echecs(&nb_echecs);
    
    taille_tableau(&l, &c);
    generer_tableau(tableau, l, c, &deck1, &deck2);
    int index_joker = rand() % (l * c);
    int ligne_joker = index_joker / c;
    int colonne_joker = index_joker % c;
    tableau[ligne_joker][colonne_joker] = 0;
    
    afficher_tableau_cachee(tableau, l, c);

    int carte1, carte2;
    choix_de_cartes(&carte1, &carte2);
    est_joker(&carte1);
    est_joker(&carte2);
}

int main () {
    printf("Bonjour et bienvenu ! \n Pour commencer, initialisons la partie.");
    initialisation_partie();

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
