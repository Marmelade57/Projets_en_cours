#include <stdio.h>
#include <stdlib.h>
#define True 0
#define False 1

struct joueur{
    char nom[51];
    int points = 0;
    int nb_tentatives;
    int ordre_passage;
}

int est_joker(*carte){
    if (*carte = 0){
        return True;
    }
    return False;
}

int paire_ou_non(*points_du_joueur, *carte1, *carte2, *nb_tentatives){
    if (*carte1 == *carte2){
        *points_du_joueur += 1;
        printf("Vous avez trouvé la paire de %d ! Vous avez désormais %d points !", *carte1, *points_du_joueur);
    }
    else{
        *nb_tentatives -= 1;
        printf("Les cartes avaient des valeurs différentes : %d et %d. Il vous reste %d", *carte1, *carte2, *nb_tentatives);
        if (*nb_tentatives = 0){
            *points_du_joueur -= 1;
            printf("Vous avez perdu 1 point ce qui vous laisse avec un score de %d", *points_du_joueur);
            *nb_tentatives = *nb_echecs;
        }
    }
}

void creation_jeu(*nb_paires){

}

void init_joueurs(*nb_joueurs){
    int i;
    while (*nb_joueurs != i){
        printf("Entrez un nom de 50 caractères ou moins pour le joueur :");
        fgets((joueur.nom), 50, stdin);
        joueur.ordre_passage = i;
    }
}

void initialisation_partie(){
    int l, c, nb_joueurs, ordinateur=False, joueur_ordinateur;
    printf("Indiquez le nombre de joueurs (maximum 4 et sans compter l'ordinateur) : ");
    scanf("%d", nb_joueurs);
    if (*nb_joueurs < 1) or (*nb_joueurs >= 5){
        printf("Veuillez entrer un nombre valide de joueurs ! ");
    }
    if (*nb_joueurs >= 1) and (*nb_joueurs <= 3){
        printf("Voulez-vous que l'ordinateur joue avec vous ? (Oui : 1, Non : 2)");
        scanf("%d", &joueur_ordinateur);
        if (*joueur_ordinateur == 1){
            ordinateur=True;
            printf("D'accord, il y aura un ordinateur alors !");
            *nb_joueurs += 1;
        }
        else if (*joueur_ordinateur == 2){
            printf("D'accord, il n'y aura pas d'ordinateur alors !");
        }
        else {
            printf("La valeur entrée est invalide, réessayez.")
        }
    }
    printf("Choisissez le nombre de lignes (3, 5 ou 7) et de colonnes (5, 7 ou 9) du plateau. ");
    scanf("%d %d", *l, *c);
    while ((*l != 3) or (*l != 5) or (*l != 7)) or ((*c != 5) or (*c != 7) or (*c != 9)) {
        if ((*l != 3) and (*l != 5) and (*l != 7)){
            printf("Entrez un nombre de lignes valide (3, 5 ou 7) :");
            scanf("%d", *l);
        }
        if ((*c != 5) and (*c != 7) and (*c != 9)){
            printf("Entrez un nombre de colonnes valide (5, 7 ou 9) :");
            scanf("%d", *c);
        }
    }
    int n = ((l*c) - 1) / 2;
    creation_jeu(&n);
    printf("Choisissez le nombre d'échecs maximum : ")
    scanf("%d", nb_echecs);
    if (nb_echecs < 1){
        printf("Le nombre d'échecs doit être de 1 au minimum. Réessayez.");
        scanf("%d", nb_echecs);
    }
}

void affiche_tableau(){

}

int main () {
    
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
