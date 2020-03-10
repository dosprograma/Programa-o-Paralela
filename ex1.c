//Dados 2 vetores, calcular a soma deles;

#include <omp.h>
#include <stdio.h>

int t = 5;
int i;
        
int main(){
    int v1[t];
    int v2[t];
    int final[t];
    
    for(i=0 ; i<t ; i++){
        v1[i] = i;
        v2[i] = i+5;
    }  
    
    #pragma omp parallel num_threads(6)
    {  
        #pragma omp for
            for(i=0 ; i<t ; i++){
                final[i] = v1[i] + v2[i];
            }
    }
    
    for(i=0 ; i<t ; i++){
        printf("%d ", final[i]);
    }   

    getchar();
}