/* * * * * * * * * * * * * * * * * * * * * * * * *
 *                                               *
 * Nome : Rafael Escaleira Ferreira dos Santos.  *
 * Universidade Federal do Mato Grosso do Sul    *
 *                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef _SORT_H_
#define _SORT_H_

/* * * * * * * * * * * Cores * * * * * * * * * * */

#define cor_texto(cor) cor
#define estilo_texto(estilo_texto_) estilo_texto_

/* * * * * * * * * Cor do Texto * * * * * * * * * */

#define preto printf("\033[30m") 
#define vermelho printf("\033[31m") 
#define verde printf("\033[32m") 
#define amarelo printf("\033[33m") 
#define azul printf("\033[34m") 
#define magenta printf("\033[35m") 
#define ciano printf("\033[36m") 
#define branco printf("\033[37m") 
#define normal printf("\033[39m") 

/* * * * * * * * Estilo do Texto * * * * * * * * */

#define negrito printf("\033[1m")
#define fosco printf("\033[2m")
#define estilo_normal printf("\033[22m")
#define resetar printf("\033[0m")
#define sublinhado printf("\033[4m")
#define piscar printf("\033[5m")
#define italico printf("\033[3m")
#define negativo printf("\033[7m")

/* * * * * * * * * Declaração de Funções * * * * * * * * */

void bogo_sort (int * v, int n);

void bubble_sort (int * v, int n);

void bucket_sort (int * v, int n, int max);

void cocktail_sort (int * v, int n);

void comb_sort (int * v, int n);

void counting_sort (int * v, int n, int maior_valor);

void gnome_sort (int * v, int n);

void heap_sort (int * v, int n);

void insertion_sort (int * v, int n);

void insertion_sort_recursiva (int * v, int n);

void merge_sort (int inicio, int fim, int * v);

void odd_even_sort (int * v, int n);

void pancake_sort (int * v, int n);

void quick_sort (int p, int r, int * v);

void radix_sort (int * v, int n);

void selection_sort (int * v, int n);

void selection_sort_recursiva (int * v, int n);

void shell_sort (int * v, int n);

void tree_sort (int * v, int n);

void imprime_resultado (double * tempo);

/* * * * * * * Declaração de Funções (Teste) * * * * * * */

void teste_pior_caso (int n);

void teste_medio_caso (int n);

void teste_melhor_caso (int n);

void gerar_menu ();

void confere_funcionamento (int n);

#endif
