//Calcular a média e o desvio padrão dos dados de um vetor

#include <omp.h>
#include <stdio.h>
#include <math.h>

int t = 5;
int i;
        
int main(){
    float vet[t] ;
    float media, desvioPadrao = 0, soma = 0, aux;
    
    for(i=0 ; i<t ; i++){
        vet[i] = i+1;
    }

    #pragma omp parallel num_threads(6)
    {  
        #pragma omp for reduction(+: soma)
            for(i=0 ; i<t ; i++){
                soma = soma + vet[i];
            }
    }

    media = soma / t;

    #pragma omp parallel num_threads(6)
    {  
        #pragma omp for reduction(+: soma)
            for(i=0 ; i<t ; i++){
                desvioPadrao += pow(vet[i]  - media, 2);
            }
    }

    desvioPadrao = sqrt(desvioPadrao / t);
  
    printf("Media: %.2f ", media);
    printf("Desvio Padrao: %.2f", desvioPadrao);

    getchar();
}