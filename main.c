#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int nombreMystere, nombreUtilisateur, compteur, continuerPartie, modeDeJeux, niveau, MAX;
    srand(time(NULL));
    continuerPartie = 0;
    printf("JEUX DE CHIFFRE PLUS OU MOINS\n\n");
    // choix de joueur
    printf("== Manu ==\n\n");
    printf("1 - Mode un joueur\n");
    printf("2 - Mode deux joueur\n");
    do {
        printf("\nQue voulez-vous ? ");
        scanf("%d", &modeDeJeux);
    } while (modeDeJeux != 1 && modeDeJeux != 2);
    
    printf("== Niveau ==\n\n");
    printf("1 - 1 à 100\n");
    printf("2 - 1 à 1000\n");
    printf("3 - 1 à 10000\n");
    do {
        printf("\nQue voulez-vous ? ");
        scanf("%d", &niveau);
    } while (niveau != 1 && niveau != 2 && niveau != 3);
    
    switch (niveau) {
        case 1 :
            MAX = 100;
            printf("Niveau facile");
            break;
        case 2 :
            MAX = 1000;
           printf("Niveau normale"); 
            break;
        case 3 :
            MAX = 10000;
            printf("Niveau difficile");
            break;
        default :
            printf("Aucun niveau");
    }
    
    if (modeDeJeux == 1) {
        do {
            compteur = 1;
            nombreMystere = (rand() % MAX) + 1;
            printf("\n\n");
            do {
                printf("Quelle est le nombre ? ");
                scanf("%d", &nombreUtilisateur);
                if (nombreUtilisateur < nombreMystere) {
                    printf("C'est plus\n\n");
                } else if (nombreUtilisateur > nombreMystere) {
                    printf("C'est moins\n\n");
                } else {
                    printf("Bravo, vous avez trouve le nombre mystere en %d coups\n", compteur);
                }
                compteur++;
            } while(nombreMystere != nombreUtilisateur);
            printf("\n\nVoulez-vous continuer ?\n");
            printf("1 pour oui et 0 pour non : ");
            scanf("%d", &continuerPartie);
            switch (continuerPartie) {
                case 1 :
                    continuerPartie = 1;
                    break;
                case 0 :
                    continuerPartie = 0;
                    break;
                default :
                    while (continuerPartie != 0 && continuerPartie != 1) {
                        printf("\nChoisir entre 0 et 1 : ");
                        scanf("%d", &continuerPartie);
                    }
            }
        } while (continuerPartie != 0);
    } else if (modeDeJeux == 2) {
        int compteur1, compteur2,nombreMystere1, nombreMystere2, nombreUtilisateur1, nombreUtilisateur2;
        do {
            compteur1 = 1;
            nombreMystere1 = (rand() % MAX) + 1;
            printf("\n\n=== Joeur 1 ===\n\n");
            do {
                printf("Quelle est le nombre ? ");
                scanf("%d", &nombreUtilisateur1);
                if (nombreUtilisateur1 < nombreMystere1) {
                    printf("C'est plus\n\n");
                } else if (nombreUtilisateur1 > nombreMystere1) {
                    printf("C'est moins\n\n");
                } else {
                    printf("Joeur 1, vous avez trouve le nombre mystere en %d coups\n", compteur1);
                    compteur2 = 1;
                    nombreMystere2 = (rand() % MAX) + 1;
                    printf("\n\n=== Joeur 2 ===\n\n");
                    do {
                        printf("Quelle est le nombre ? ");
                        scanf("%d", &nombreUtilisateur2);
                        if (nombreUtilisateur2 < nombreMystere2) {
                            printf("C'est plus\n\n");
                        } else if (nombreUtilisateur2 > nombreMystere2) {
                            printf("C'est moins\n\n");
                        } else {
                            printf("Joeur 2, vous avez trouve le nombre mystere en %d coups\n", compteur2);
                            if (compteur1 > compteur2) {
                                printf("joueur 2 vous avez gagner !\n");
                            } else {
                                printf("joueur 1 vous avez gagner !\n");
                            }
                        }
                        compteur2++;
                    } while(nombreMystere2 != nombreUtilisateur2);
                }
                compteur1++;
            } while(nombreMystere1 != nombreUtilisateur1);
            printf("\n\nVoulez-vous continuer ?\n");
            printf("1 pour oui et 0 pour non : ");
            scanf("%d", &continuerPartie);
            switch (continuerPartie) {
                case 1 :
                    continuerPartie = 1;
                    break;
                case 0 :
                    continuerPartie = 0;
                    break;
                default :
                    while (continuerPartie != 0 && continuerPartie != 1) {
                        printf("\nChoisir entre 0 et 1 : ");
                        scanf("%d", &continuerPartie);
                    }
            }
        } while (continuerPartie != 0);
    } else {
        printf("Votre choix est aucun");
    }
    return 0;
}