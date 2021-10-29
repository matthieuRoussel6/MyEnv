#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a) {
	return a == NULL;
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire* a) {
	*a = NULL;
}

// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e) {
	
	ArbreBinaire arbre;
	arbre = malloc(sizeof(ArbreBinaire));
	arbre->val = e;

	initialiser(&arbre->filsDroit);
	initialiser(&arbre->filsGauche);
	return arbre;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e) {
	if (estVide(a)){
		return creer(e);
	}
	if (a->val == e) {
		return a;
	}
	ArbreBinaire arbreParcourant = a;

	while( arbreParcourant->val != e && !estVide(a)) {
		Element valeurActuelle = arbreParcourant->val;
		
		if(valeurActuelle = e){
			return a;
		}

		if(valeurActuelle < e){
			arbreParcourant = arbreParcourant->filsDroit;
			Element valeurGauche = arbreParcourant->filsGauche->val;
			printf(valeurActuelle);
			if(valeurGauche == NULL) {
				ArbreBinaire new = creer(e);
				arbreParcourant->filsGauche = new;
				return a;
			} else if(valeurGauche >= e) {
			//inserer à gauche
			ArbreBinaire new = creer(e);
			new->filsGauche = arbreParcourant->filsGauche;
			arbreParcourant->filsGauche = new;
			return a;
			}
		}
		if(valeurActuelle >= e){
			arbreParcourant = arbreParcourant->filsGauche;
			Element valeurDroit = arbreParcourant->filsDroit->val;
			if(valeurDroit == NULL) {
				ArbreBinaire new = creer(e);
				arbreParcourant->filsGauche = new;
				return a;
			} else if( valeurDroit < e ) {
			//inserer à droite
			ArbreBinaire new = creer(e);
			new->filsDroit = arbreParcourant->filsDroit;
			arbreParcourant->filsDroit = new;
			return a;
			}
		}
	}
	
	return a;
}	

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e) {
	//Cas de base
	if(estVide(a)) {
		a = creer(e);
		return a;
	}
	if(a->val==e) {
		return a;
	}

	if(a->val < e) {
		if( a->filsDroit != NULL && a->filsDroit->val > e) {
			ArbreBinaire new = creer(e);
			ArbreBinaire tamp = a->filsDroit;
			a->filsDroit = new;
			new->filsDroit = tamp;
			return a;
		}
		a->filsDroit = insere_r(a->filsDroit, e);
		return a;
	} else {
		if(a->filsGauche != NULL && a->filsGauche->val < e) {
			ArbreBinaire new = creer(e);
			ArbreBinaire tamp = a->filsGauche;
			a->filsGauche = new;
			new->filsGauche = tamp;
			return a;
		}
		a->filsGauche = insere_r(a->filsGauche, e);
		return a;
	}
	return a;
}

// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a){
	if(estVide(a)){
		return 0;
	} else {
		return 1 + nombreDeNoeud(a->filsDroit) + nombreDeNoeud(a->filsGauche);
	}
}


// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e){
	if(estVide(a)){
		return -1;
	}
	return 0;
}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a){
	return 0;
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element elem){

	return NULL;
}


void afficheRGD_r(ArbreBinaire a){
}

void afficheGRD_r(ArbreBinaire a){
	if(estVide(a)){
		printf("()");
	} else {
		printf("( ");
		afficheGRD_r(a->filsGauche);
		printf(" %i ", a->val);
		afficheGRD_r(a->filsDroit);
		printf(")");
	}
	

}

void afficheGDR_r(ArbreBinaire a){
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a){
	return NULL;
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a){
	return NULL;
}


// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a 
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element elem){

	return NULL;
}


// suppime x de a
ArbreBinaire supprimer_r(ArbreBinaire a,Element x)
{

	return NULL;
}

void detruire_r(ArbreBinaire a){

}

