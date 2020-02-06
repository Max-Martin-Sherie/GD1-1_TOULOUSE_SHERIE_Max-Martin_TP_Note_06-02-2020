#include <stdio.h>

// Declaration des variables globales
int numChoix;

int main(){
    // Affectation des variables globales
    numChoix=0;

    // fonction
    printf("Vous vous trouvez face a une fourchette dans la route.\nIl y a deux panneaux : ZELANDIA et IRLANDIA\n\n(1)Aller a ZELANDIA || (2)Aller a IRLANDIA");
    
    while(numChoix!=1 && numChoix!=2){
        scanf("%d",&numChoix); 
    }

    if(numChoix==1){
        printf("\nvous partez vers ZELANDIA");
    }else {
        printf("\nvous partez vers ZELANDIA");
    }

    return 0;
}