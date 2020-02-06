#include <stdio.h>
#include <string.h>

// Declaration des structures
struct Chapitre{
    char description[400];
    int gainOr;
    int gainPDV;
    int id[15];
}; typedef struct Chapitre chapitre;


// Declaration des variables globales
int numChapitre;

int deplacement(chapitre * adresse){  
    int numChapitreD=-2;
    int i;

    printf("\n\n(-1) Quitter");

    for(i=0; i<2; i++){
        printf(" || (%d) ",i+1);
        printf("chapitre %d",(*adresse).id[i]);
    }
    printf("\n");
    
    while(numChapitreD<-1 || numChapitreD>i){
        scanf("%d",&numChapitreD);
    }

    return numChapitreD;
}

int main(){
    // Affectation des variables globales
    numChapitre=0;

    //Creation des structures
    chapitre chapitres[15]={{"Aller a ZELANDIA",100,10,{1,2}},
                    {"Aller a IRLANDIA",150,25,{0,2}},
                    {"Aller a BRITANNIA",200,50,{0,1}}};

    // fonction
    
    while(numChapitre!=-1){
        printf("\nChapitre %d : ",numChapitre);
        printf("%s",chapitres[numChapitre].description);



        numChapitre=deplacement(&chapitres[numChapitre]);

    }
    

    return 0;
}