

#include <stdio.h>
#include <stdlib.h>
#include"cabecalho.h"

int main(int argc, char** argv) {
    int opcao = 0;
    Grafo * grafo;
    int valor;
    printf("Portinho e MiniMarina Productions EC e nois 2017.\n");
    do {
        printf("\nMenu:\n 1-Criar grafo\n 2-Inserir aresta\n 3-Imprimir grafo em matriz\n 4-Imprimir grafo em lista\n 5-Sair\nOpcao: ");
        scanf("%i", &opcao);
        switch(opcao){
            case 1: {
                printf("Digite o valor que deseja inserir: ");
                scanf("%d",&valor);
                grafo = criaGrafo(valor);
                break;
            }
                
            
            
            
            
            
        }
        

    } while (opcao != 5);

    
        
        
        
        
        
        
        
        
return (EXIT_SUCCESS);
}


