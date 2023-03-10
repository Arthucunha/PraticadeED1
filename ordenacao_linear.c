#include "ordenacao_linear.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// https://www.programiz.com/dsa/radix-sort

// Manter como especificado
int char2int(char c)
{
    /* Funcao auxiliar para converter um char em um inteiro */
    return (int)(c - '0');
}

int getMax(int array[], int n)
{
    int max = array[0];
    for (int i = 1; i < n; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

// Manter como especificado
void le(Paciente *pacientes, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s", pacientes[i].senha, pacientes[i].nome);
    }
}

// Manter como especificado
void imprime(Paciente *pacientes, int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%s  %s", pacientes[i].senha, pacientes[i].nome);
        printf("\n");
    }
}

// Manter como especificado
void coutingSort(Paciente *A, Paciente *B, int n, int i)
{
    // PREENCHER AQUI
    /*
     * A = vetor a ser ordenado
     * B = vetor auxiliar para armazenar o vetor A ordenado
     * n = tamanho do vetor A
     * i = digito a ser usado na ordenacao
     */

    char temp[MAX_N];
    int count[10];
    /*int max = atoi(A[0].senha);


    printf("\n\nTamanho da string: %d\n\n", max);


    count = (int *) malloc((max + 1)*sizeof(int));*/
    for (int k = 0; k < 10; ++k)
    {
        count[k] = 0;
    }

    for (int j = 0; j < n; j++)
    {
        count[char2int(A[j].senha[i])] = count[char2int(A[j].senha[i])] + 1;
    }

    for (int k = 1; k < n; k++)
    {
        count[k] = count[k] + count[k - 1];
    }

    for (int j = n - 1; j >= 0; j--)
    {
        strcpy(temp, A[j].senha);
        B[count[char2int(temp[i])] - 1] = A[j];
        count[char2int(temp[i])]--;
    }

}

// Manter como especificado
void radixSort(Paciente *pacientes, int n, int m)
{
    Paciente B[MAX_N];

    for (int i = m - 1; i >= 0; i--)
    {
        m--;
        coutingSort(pacientes, B, n, m);
    }
    for (int j = 0; j < n; j++)
    {
        pacientes[j] = B[j];
    }
}
