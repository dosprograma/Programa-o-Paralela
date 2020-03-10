//Encontrar o maior e o menor valor de um vetor.

#include <omp.h>
#include <stdio.h>
#include <math.h>

int t = 5;
int i;
        
int main(){
    float vet[t] ;
    
    for(i=0 ; i<t ; i++){
        vet[i] = 7-i;
    }

    float menor = vet[0], maior = vet[0];

    #pragma omp parallel num_threads(6)
    {  
        #pragma omp for reduction(min: minimo)
            for(i=1 ; i<t ; i++){
                if (vet[i] < menor){
                    menor = vet[i];
                }
            }
        #pragma omp for reduction(max: maximo)
            for(i=1 ; i<t; i++){
                if (vet[i] > maior){
                    maior = vet[i];
                }  
            }
    }

    printf("Menor: %.2f \n", menor);
    printf("Maior: %.2f \n", maior);

    getchar();
}