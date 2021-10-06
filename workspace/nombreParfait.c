#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool estUnNombreParfait(int k) {
    int sommeDiviseurs = 0;
    for(int i =1; i < k; i++){
        if(k % i == 0){
            sommeDiviseurs += i;
        }
    }
    if(sommeDiviseurs == k){
        return true;
    } else {
        return false;
    }
}

int main(void) {
    int N = 10005;

    for(int i= 1; i< N+1; i++){
        if (estUnNombreParfait(i)){
            printf("nombre Parfait : %i\n", i);
        }
    }
    
    return EXIT_SUCCESS;
}
