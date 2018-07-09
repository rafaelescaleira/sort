/* * * * * * * * * * * * * * * * * * * * * * * * *
 *                                               *
 * Nome : Rafael Escaleira Ferreira dos Santos.  *
 * Universidade Federal do Mato Grosso do Sul    *
 *                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include "sort.h"

/* * * * * * * * * * * * Função Principal * * * * * * * * * * * */

int main (void) {

	int op, n;

	do {

		gerar_menu ();

		printf("       Informe a operação desejada : ");

		cor_texto (vermelho);
		scanf ("%d", &op);
		estilo_texto (resetar);

		switch (op) {

			case 1:

			printf("       Informe a quantidade de elementos : ");

			cor_texto (verde);
			scanf ("%d", &n);
			estilo_texto (resetar);		

			cor_texto (ciano);
    		printf("\n       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    		printf("       *                                                                     *\n");
    		printf("       *");
    		estilo_texto (resetar);

    		cor_texto (verde);
    		printf("                              PIOR CASO                              ");
    		estilo_texto (resetar);

    		cor_texto (ciano);
    		printf("*\n");
    		printf("       *                                                                     *\n");
    		estilo_texto (resetar);

			teste_pior_caso (n);

			break;

			case 2:

			printf("       Informe a quantidade de elementos : ");

			cor_texto (verde);
			scanf ("%d", &n);
			estilo_texto (resetar);

			cor_texto (ciano);
    		printf("\n       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    		printf("       *                                                                     *\n");
    		printf("       *");
    		estilo_texto (resetar);

    		cor_texto (verde);
    		printf("                             MÉDIO CASO                              ");
    		estilo_texto (resetar);

    		cor_texto (ciano);
    		printf("*\n");
    		printf("       *                                                                     *\n");
    		estilo_texto (resetar);

			teste_medio_caso (n);

			break;

			case 3:

			printf("       Informe a quantidade de elementos : ");

			cor_texto (verde);
			scanf ("%d", &n);
			estilo_texto (resetar);

			cor_texto (ciano);
    		printf("\n       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    		printf("       *                                                                     *\n");
    		printf("       *");
    		estilo_texto (resetar);

    		cor_texto (verde);
    		printf("                             MELHOR CASO                             ");
    		estilo_texto (resetar);

    		cor_texto (ciano);
    		printf("*\n");
    		printf("       *                                                                     *\n");
    		estilo_texto (resetar);

			teste_melhor_caso (n);

			break;

			case 4:

			break;

		}

	} while (op > 0 && op < 4);

    printf("\n");

    cor_texto (vermelho);
    printf("       FIM DE EXECUÇÃO\n\n");
    estilo_texto (resetar);
    
    return 0;
    
}
