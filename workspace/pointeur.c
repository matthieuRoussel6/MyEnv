#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

// Exercice 1 

void echangeContenu(int * a, int * b) {
    int c = *a;
    *a = *b;
    *b = c;
}

//Exercice 2

bool estConvexe(bool tab[], int length) {
    int * debutTab = tab; //Premiere case
    bool valeurPrecedante = *(debutTab+length-1); //valeur dernière case
    int rupture = 0;
    for(int compteur = 0; compteur < length-1; compteur ++) {
        if(tab[compteur] != valeurPrecedante) {
            rupture += 1;
        }
    }
    if (rupture > 2){
        return true;
    }
    return false;
}

//Exercice 3

void mult_matrice(int64_t matriceResultat[][5], int64_t matrice1[][5], int64_t matrice2[][5]) {
    for (int compteurLigne = 0; compteurLigne  < 5; compteurLigne++) {
        for (int compteurColonne = 0; compteurColonne  < 5; compteurColonne++) {
            int somme = 0;
            for (int compteurSomme = 0; compteurSomme  < 5; compteurSomme++) {
                somme += matrice1[compteurLigne][compteurSomme]*matrice2[compteurSomme][compteurColonne]; 
            }
            matriceResultat[compteurLigne][compteurColonne] = somme;
        }
    }
}

void affiche_matrice(int64_t matrice[][5]){
    for (int i= 0; i < 5 ; i++) {
        for (int j = 0; j < 5; j++) 
            printf("\t %ld \t", matrice[i][j]);
        printf("\n");
    }
}


//Exercice 4


typedef enum {jan = 1, fev, mars, avr, mai, juin, juil, aout, sept, oct, nov, dec} Mois;

typedef struct{
int jour;
Mois mois;
int annee;
} Date;

initialiseDate(Date * d) {
    int jourdonne, annee;
    scanf("%i", jourdonne);
    *d.jour = jourdonne;
    scanf
    scanf("")
    *d.mois = juil;
    *d.annee = 2021;
}

afficheDate(Date d) {
    printf("le " + *d.jour + " " + *d.mois + " " + *d.annee);
}


int main(void) {
    // int a = 19;
    // int b = 12;
    // echangeContenu(&a, &b);
    // printf(" a égal %d", a);
    // printf(" b égal %d\n", b);

    // bool tab[5] = {true, true, false, true};
    // if(estConvexe(tab, 5)){
    //     printf(" il est convexe\n");
    // }else {
    //     printf(" il est pas convexe\n");
    // }

    // int64_t matrice1[5][5]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
    // int64_t matrice2[5][5]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
    // int64_t matriceResultat[5][5];
    // mult_matrice(matriceResultat,matrice1,matrice2);
    // affiche_matrice(matriceResultat);

    Date d;
    initialiseDate(&d);
    afficheDate(&d);

    return EXIT_SUCCESS;
}