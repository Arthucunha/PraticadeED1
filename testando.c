#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_M 7
#define MAX_N 10000

typedef struct {
    char senha[MAX_M + 1];
    char nome[21];
} Paciente;

int getMax(int array[], int n) {
    int max = array[0];
    
    for (int i = 1; i < n; i++)
    if (array[i] > max)
        max = array[i];
    return max;
}


int char2int(char c) {
    /* Funcao auxiliar para converter um char em um inteiro */
    return (int) (c - '0');
}

int main(){
    Paciente pacientes[MAX_N];
    int posicao;
    int vetor[5];

    for(int i = 0; i < 5; i++){
        scanf("%s %s", pacientes[i].senha, pacientes[i].nome);
        //printf("\n");
    }

    /*posicao = strlen(pacientes[0].senha) - 1;
    
    for(int i = 0; i < 5; i++){
        if(posicao >= 0){

            for(int i = 0; i < 5; i++){
                vetor[i] = char2int(pacientes[i].senha[posicao]);
            }
            for(int i = 0; i < 5; i++){
                //printf("\n%d\n", vetor[i]);
            }


            posicao = posicao - 1;
            int max = getMax(vetor, 5);
            printf("\nmax: %d\n", max);
        }
        
        
    }*/

    //itoa(9999, pacientes[0].senha, 10);
    

    sprintf(pacientes[0].senha, "%d", 9999);
    printf("\nItoa:: %s\n", pacientes[0].senha);



    //printf("\n%d\n", posicao);

    return 0;
}