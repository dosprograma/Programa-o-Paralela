//Calcular a média harmônica de um vetor
#include <omp.h>
#include <stdio.h>
#include <math.h>

int t = 5;
int i;
        
int main(){
    float vet[t] ;
    float mediaHarmonica = 0, soma=0, aux;
    
    for(i=0 ; i<t ; i++){
        vet[i] = i+1;
    }

    #pragma omp parallel num_threads(6)
    {  
        #pragma omp for reduction(+: soma)
            for(i=0 ; i<t ; i++){
                soma += 1 / vet[i];
            }
    }

    mediaHarmonica = t / soma;

    printf("Media Harmonica: %.2f ", mediaHarmonica);

    getchar();
}