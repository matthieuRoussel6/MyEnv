//  gcc -g -Wall -o mySpitofy mySpitofy.c linkedListOfMusic.c ../V1/linkedList.c
//  ./mySpitofy
//  valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all ./mySpitofy


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedListOfMusic.h"

Liste readCsv(FILE* csv){
    Liste listeObjetsFormes;
    listeObjetsFormes = NULL;
    char *line, *entree;
    line = calloc(256,sizeof(char));

    //initialisation de l'objet music tampon
    Music* musicTemp;

    while (fgets(line, 256, csv) != NULL){
        musicTemp = (Music *)malloc(sizeof(Music));
        entree = strdup(line);

        if (!entree)
            exit(EXIT_FAILURE);

        musicTemp->name = strsep(&entree, ",\n");
        musicTemp->artist = strsep(&entree, ",\n");
        musicTemp->album = strsep(&entree, ",\n");
        musicTemp->genre = strsep(&entree, ",\n");
        musicTemp->disc = strsep(&entree, ",\n");
        musicTemp->track = strsep(&entree, ",\n");
        musicTemp->year = strsep(&entree, ",\n");

        listeObjetsFormes = ajoutFin_i(musicTemp, listeObjetsFormes);
    }
    free(line);

    return listeObjetsFormes;
}


int main(int argc, char *argv[]) {

    // On ouvre le ficher
    FILE* ficherDeDonneeMusic = fopen("music.csv","r");

    Liste chaineDeMusic = readCsv(ficherDeDonneeMusic);
    chaineDeMusic = orderByYear(chaineDeMusic); 
    afficheListe_i(chaineDeMusic);


    detruire_i(chaineDeMusic);
    fclose(ficherDeDonneeMusic);
    return EXIT_SUCCESS;
}

