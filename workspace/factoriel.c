#include <stdio.h>

typedef short TypeEntier;

TypeEntier factorielle(TypeEntier n){
    int produit = 1;
    for(int k = 0; k<n ; k++ ) {
        produit = produit*(n-k);
    }
    return produit;
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