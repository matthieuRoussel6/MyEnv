#include <stdio.h>

//  1

typedef struct {
    int nbLigne;
    int nbColonne;
    int matrice[][15];
} Matrix;

typedef struct {
    int taille;
    Matrix matrices[];
}  MatrixArray;

//  2

Matrix readMatrix(FILE* f ){
    char buffer[15];
    fgets(buffer,15,f);
    int nbLigne = buffer[0];
    int nbColonne = buffer[2];
    if (nbColonne != NULL) {
        int matricee[nbLigne][15];
        // On est sur une ligne qui correspond 
        for (int i = 0; i < nbLigne; i++) {
            fgets(buffer,15,f);
        }
    }
}

//   3

void afficherMatrix(Matrix M){
    printf("%i %i \n", &M.nbLigne, &M.nbColonne);
    for (int i =0; i < M.nbLigne; i ++){
        char ligne[2*M.nbColonne-1];
        for (int j=0; j< M.nbColonne; j++){
            ligne[2*j] = M.matrice[i][j];
            if(j != M.nbColonne-1) {
                ligne[2*j+1] = ' ';
            }
        }
        printf(ligne);
    }
}


//   4

void readFichier(FILE* f ){
    char buffer[15];
    while( fgets(buffer,15,f) != NULL ) {
        printf(">%s",buffer);
    }
}


int main(void) {
    char fileName[] = "matrices.txt";
    FILE* f;
    f = fopen(fileName,"r");

    //MatrixArray resultat := readMatrixArray(f);
    fclose(f);
    return 0;
}