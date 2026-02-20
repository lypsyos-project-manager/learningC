#include <stdlib.h> 
#include <stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numeSize, int target, int* returnSize); // chamada da funcao antes para o programa saber que existe
int main(){
    int vetorTam = 0;
    

    printf("Quantos n° vai conter a lista? ");
    scanf("%d" ,&vetorTam);
    int* meusNumeros = (int*)malloc(vetorTam * sizeof(int));
    for (int i = 0; i<vetorTam; i++){
        printf("Digite um Numero: ");
        scanf("%d", &meusNumeros[i]);
    }

    int tamanho = sizeof(meusNumeros) / sizeof(meusNumeros[0]);

    int alvo = 9;
    int tamanhoRetorno;

    int* resultado = twoSum(meusNumeros, tamanho, alvo, &tamanhoRetorno);
    if (resultado != NULL){
        printf("Indices: [%d, %d]\n", resultado[0], resultado[1]);
        free(resultado);
    } else {
        printf("Nenhuma solucao encontrada.\n");
    }
    return 0;

}
int* twoSum(int* nums, int vetorTam, int target, int* returnSize) {
    int* result = (int*)malloc(2*sizeof(int));

    for (int i = 0; i < vetorTam; i++){
        for (int j = i + 1; j< vetorTam; j++){

            if (nums[i] + nums[j] == target){

                result[0] = i;
                result[1] = j;
                
                *returnSize = 2;

                return result;
            }
        }
    }

    *returnSize = 0;
    free(result);
    return NULL;
}

