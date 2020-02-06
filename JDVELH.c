#include <stdio.h>
#include <string.h>

// Declaration des structures
struct Chapitre{
    char description[400];
    int gainOr;
    int gainPDV;
    int id[15];
    int prix;
}; typedef struct Chapitre chapitre;


// Declaration des variables globales
int numChoix;
int numChoixChapitre;
int numChapitre;
int or;
int PDV;

int deplacement(chapitre * adresse){  
    int numChapitreD=-2;
    int i;
    printf("\n\nOu Voulez vos aller?");
    printf("\n(-1) Quitter");

    for(i=0; i<2; i++){
        printf(" || (%d) ",i+1);
        printf("chapitre %d",(*adresse).id[i]);
    }
    printf("\n");
    
    while(numChapitreD<-1 || numChapitreD>i){
        scanf("%d",&numChapitreD);
        if(numChapitreD<-1 || numChapitreD>i){
                printf("\n ! DEPLACEMENT IMPOSSIBLE !\n");
        }
        
    }
    if(numChapitreD==-1){
        return numChapitreD;
    }else{
        return (*adresse).id[numChapitreD-1];
    }

}

int main(){
    // Affectation des variables globales
    numChapitre=0;
    numChoix=-1;
    or=0;
    PDV = 80;

    //Creation des structures
    chapitre chapitres[15]={{"Aller a ZELANDIA",0,20,{1,2},0},
                    {"Aller a IRLANDIA",10,-10,{0,2},10},
                    {"Aller a BRITANNIA",30,-15,{0,1}},15};

    // fonction
    
    while(numChapitre!=-1 && numChoixChapitre!=-1 && PDV>0){
        numChoix=-1;
        printf("\n\nVous avez %d or\n",or);
        printf("\nVous avez %dPDV\n\n",PDV);
        printf("\nChapitre %d : ",numChapitre);
        printf("%s",chapitres[numChapitre].description);

        or += chapitres[numChapitre].gainOr;
        PDV += chapitres[numChapitre].gainPDV;

        printf("\n\nVous gagnez %d or",chapitres[numChapitre].gainOr);



        numChoixChapitre=deplacement(&chapitres[numChapitre]);
        
        while(chapitres[numChoixChapitre].prix > or){
            printf("\n\nVous n'avez pas assez d'argent pour faire ce niveau\n\n");
            numChoixChapitre=deplacement(&chapitres[numChapitre]);
        }

        while(chapitres[numChoixChapitre].prix>0 && numChoix!=1){
            printf("\nIl vous faut %d or pour faire ce niveaux etes vous sur de vouloir le faire ?\n(0) non (1) oui",chapitres[numChoixChapitre].prix);
            while(numChoix != 0 & numChoix != 1){
                scanf("%d",&numChoix);
            }


            if(numChoix ==0){
                 numChoix = numChoixChapitre;
                while(numChoix == numChoixChapitre){ 
                    numChoix=deplacement(&chapitres[numChoixChapitre]);
                }
                numChoixChapitre = numChoix;
            }else if(numChoix == 1){
                or -= chapitres[numChoixChapitre].prix;
                printf("Vous perdez %d or\n",chapitres[numChoixChapitre].prix);
            }
            
        }

        numChapitre = numChoixChapitre;


    }
    

    return 0;
}