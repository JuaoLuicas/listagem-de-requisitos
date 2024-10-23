#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

	int funcionalidade, prioridade, i = 0, n = 0;
	char arrayFuncionalidades[20][70] = {};
	char arrayPrioridades[20][10] = {};
	char nomeRequisito[100];
	bool verificador = true;
	bool verificadorPrioridade;

void inserirRequisito() {
	printf("\n-> Insira o nome do requisito: ");
	fgets(nomeRequisito, sizeof(nomeRequisito), stdin);
	nomeRequisito[strcspn(nomeRequisito, "\n")] = 0;
	strcpy(arrayFuncionalidades[i], nomeRequisito);
				
	verificadorPrioridade = true;
	while (verificadorPrioridade == true) {
		printf("\t-----------\n");
		printf("  Lista de prioridades:\n  (1) BAIXO\n  (2) MÉDIO\n  (3) ALTO\n");
		printf("\t-----------\n");
		printf("-> Prioridade desejada: ");
		scanf("%d", &prioridade);
	
	getchar();

		if (prioridade >= 1 || prioridade <= 3) {
			if (prioridade == 1) {
				strcpy(arrayPrioridades[i], "BAIXO");
			} else if (prioridade == 2) {
				strcpy(arrayPrioridades[i], "MÉDIO");
			} else if (prioridade == 3) {
				strcpy(arrayPrioridades[i], "ALTO");
			} 
		} else  {
			printf("Prioridade inválida");
		}
			n++;
			i++;
			printf("Requisito armazenado.\n");
			verificadorPrioridade = false;
	} 
}

void mostrarLista() {
	for (n = 0; n < i; n++) {
		printf("Requisito %d: %s - Prioridade: %s\n", n + 1, arrayFuncionalidades[n], arrayPrioridades[n]);
	}
}

void esperar(int segundos) {
    #ifdef _WIN32
        Sleep(segundos * 1000);  // Windows usa milissegundos
    #else
        sleep(segundos);         // Unix usa segundos
    #endif
}

void limparTela() {
    #ifdef _WIN32
        // Sistema Windows
        system("cls");
    #else
        // Sistema Linux ou macOS
        system("clear");
    #endif
}

int main() {	
	setlocale(LC_ALL, "Portuguese");
	
	printf("\tREQUISITOS DO SISTEMA\n");
	
	// Enquanto for verdadeiro rodará essa funcionalidade
	while (verificador == true) {
		printf("\n-> ESCOLHA UMA FUNCIONALIDADE:\n ");
		printf("(1) Inserir requisito\n (2) Mostrar lista de requisitos\n (3) Encerrar o programa\n");
		printf("-> Funcionalidade desejada: ");
		scanf("%d", &funcionalidade);
		
		getchar();
		
			switch (funcionalidade) {
			case 1: 		
				if (i < 20) {
					limparTela();
					inserirRequisito();
				} else {
					printf("Quantidade de requsitos máximas.");
				}
					esperar(1);
					limparTela();
				break;
				
			case 2:
				if (i == 0) {
					printf("Nenhum requisito armazenado.\n");
					esperar(1);
					limparTela();
				} else {
					limparTela();
					printf("\nLista de Requisitos\n");
					mostrarLista();
					
					printf("\nAperte ENTER para continuar\n");
					getchar();
					limparTela();
				}		
				break;
				
			case 3:
				verificador = false;
				break;
				
			default:
				printf("Valor inválido.");
				break;
		}
	}
	return 0;
}
