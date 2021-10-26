#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlistOfMusic.h"

void afficheElement(Element e){
    Music *music = (Music *)e;
    printf(
		"%s,%s,%s,%s,%s,%s,%s\n",
        music->name, 
		music->artist, 
		music->album, 
		music->genre, 
		music->disc, 
		music->track, 
		music->year);
}

void detruireElement(Element e){
    free(e);
}

//Tampon ici
bool equalsElement(Element m1, Element m2){
    return true;
}

Liste orderByYear(Liste listeATrier){
    
	//Cas d'arrêt de la recurence
    if(estVide(listeATrier) || estVide(listeATrier->suiv))
        return listeATrier;

    Liste actuel = listeATrier;
	Liste prev = listeATrier;
	Liste plusVielle = listeATrier;
	Liste plusViellePrecedente = listeATrier;

	//Recherche de la plus vielle valeur
    while(!estVide(actuel)){

        if(strcmp(((Music *)actuel->val)->year, ((Music *)plusVielle->val)->year) <= 0){
            plusViellePrecedente = prev;
            plusVielle = actuel;
        }
        prev = actuel;
		actuel = actuel->suiv;
	}

    // On met à jour la tete de liste
    if (plusVielle != listeATrier){
    	Liste tmp;
        plusViellePrecedente->suiv = listeATrier;
        tmp = listeATrier->suiv;
        listeATrier->suiv = plusVielle->suiv;
        plusVielle->suiv = tmp;
    }

	//On continu notre traitement
    plusVielle->suiv = orderByYear(plusVielle->suiv);

    return plusVielle;
}