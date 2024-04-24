#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mode() {
    int modeDeJoueur = 0;
    printf("=== Mode de joeur ===\n\n");
    printf("1 - mode 1 joueur\n");
    printf("2 - mode 2 joueur\n");
    printf("\n");
    while (modeDeJoueur != 1 && modeDeJoueur != 2) {
        printf("Que voulez-vous ? ");
        scanf("%d", &modeDeJoueur);
    }
    return modeDeJoueur;
}

int niveau() {
    int Max, niveau;
    printf("\n=== Niveau ===\n\n");
    printf("1 - 1 à 100\n");
    printf("2 - 1 à 1000\n");
    printf("3 - 1 à 10000\n");
    printf("\n");
    // 1 <= niveau <=3 => 1 > niveau > 3
    do {
        printf("Que voulez-vous ? ");
        scanf("%d", &niveau);
    } while (niveau < 1 || niveau > 3);
    switch (niveau) {
        case 1 :
            Max = 100;
            break;
        case 2 :
            Max = 1000;
            break;
        case 3 :
            Max = 10000;
            break;
    }
    return Max;
}

int jeux(int nombreEntrer, int Max) {
    int nombreMystere = 0, Min = 1, compteur = 0;
    
    srand(time(NULL));
    nombreMystere = (rand() % (Max - Min + 1)) + Min;
    
    printf("Entrer le nombre entre %d et %d\n\n", Min, Max);
    do {
        compteur++;
        printf("Quelle est ce nombre ? ");
        scanf("%d", &nombreEntrer);
        
        if (nombreEntrer > nombreMystere) printf("C'est moins !\n");
        else if (nombreEntrer < nombreMystere) printf("C'est plus !\n");
        else printf("\nBravo, vous avez trouvé le nombre mystère en %d coups !\n", compteur);
    } while (nombreEntrer != nombreMystere);
    return compteur;
}

int main(int argc, char *argv[]) {
    int Max = niveau(), continuerPartie = 1;
    
    // demand de deviner le nombre
    int nombreEntrer = 0;
    
    // lanchement du jeux
    while (continuerPartie != 0) {
        if (mode() == 1) {
            jeux(nombreEntrer, Max);
        } else {
            int coups1, coups2;
            // deux joueur
            printf("\n=== joueur 1 ===\n\n");
            coups1 = jeux(nombreEntrer, Max);
            printf("\n=== joueur 2 ===\n\n");
            coups2 = jeux(nombreEntrer, Max);
            
            if (coups2 > coups1) {
                printf("\njoueur 1 vous avez gagné.\n");
            } else if (coups1 > coups2) {
                printf("\njoueur 2 vous avez gagné.\n");
            } else {
                printf("\négaux, donc sans vaincaire !\n");
            }
        }
        
        printf("\nVous-voulez continuer ?\n\n");
        printf("0 - non\n");
        printf("1 - oui\n");
        printf("\n");
        
        do {
            printf("Que voulez-vous ? ");
            scanf("%d", &continuerPartie);
        } while (continuerPartie != 1 && continuerPartie != 0);
    }
}