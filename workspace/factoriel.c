#include <stdio.h>

typedef unsigned long long TypeEntier;

TypeEntier factorielle(TypeEntier n){
    int produit = 1;
    for(int k = 0; k<n ; k++ ) {
        produit = produit*(n-k);
    }
    return produit;
}

void calculfactoriel(int nb) {
    for (int u; u<=nb; u++) {
        printf("%d! = %lld\n", u, factorielle(u));
    }
}

void afficheFactorielle(void) {
    int N =0;
    printf("Un nombre entier :");
    scanf("%d", &N);
    printf("%d! = %lld\n", N, factorielle(N));
}

int main(void){
    afficheFactorielle();
    return 0;
}