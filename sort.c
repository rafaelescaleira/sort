/* * * * * * * * * * * * * * * * * * * * * * * * *
 *                                               *
 * Nome : Rafael Escaleira Ferreira dos Santos.  *
 * Universidade Federal do Mato Grosso do Sul    *
 *                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

/* * * * * * * * * * * * Bogo Sort * * * * * * * * * * * */

bool confere_ordenacao (int * v, int n) {
    
    while (-- n >= 1) {
        
        if (v[n] < v[n - 1]) {
            
            return false;
            
        }
        
    }
    
    return true;
    
}

void embaralhar (int * v, int n) {
    
    int i, t, r;
    
    for (i = 0; i < n; i ++) {
        
        t = v[i];
        r = rand() % n;
        v[i] = v[r];
        v[r] = t;
        
    }
    
}

void bogo_sort (int * v, int n) {
    
    while (!confere_ordenacao (v, n)) {
        
        embaralhar (v, n);
        
    }
    
}

/* * * * * * * * * * * * Bubble Sort * * * * * * * * * * * */

void bubble_sort (int * v, int n) {
    
    unsigned int aux;
    int i = 0;
    int j;
    
    while (i < n) {
        
        j = 0;
        
        while (j < i) {
            
            if (v[j] > v[i]) {
                
                aux = v[j];
                v[j] = v[i];
                v[i] = aux;
                
            }
            
            j ++;
            
        }
        
        i ++;
        
    }
    
}

/* * * * * * * * * * * * Bucket Sort * * * * * * * * * * * */

struct node {
    
    int valor;
    struct node * next;
    
};

struct list {
    
    struct node * endereco_primeiro;
    struct node * endereco_ultimo;
    int total_elementos;
    
};

int obtem_divisor (int valor) {
    
    int divisor, aux;
    
    divisor = 1;
    aux = valor;
    
    while (valor > 0) {
        
        valor /= 10;
        divisor *= 10;
        
    }
    
    return (aux == 0) ? 1 : divisor;
    
}

void bucket_sort (int * v, int n, int max) {
    
    struct list vetor[n];
    int divisor = obtem_divisor (max);
    int i;
    
    for (i = 0; i < n; ++ i) {
        
        vetor[i].endereco_primeiro = NULL;
        vetor[i].endereco_ultimo = NULL;
        vetor[i].total_elementos = 0;
        
    }
    
    for (i = 0; i < n; ++ i) {
        
        int indice = (v[i] * n) / divisor;
        
        if (vetor[indice].endereco_ultimo == NULL || vetor[indice].endereco_primeiro == NULL) {
            
            struct node * aux = (struct node *) malloc (sizeof (struct node));
            aux -> valor = v[i];
            aux -> next = NULL;
            
            vetor[indice].endereco_primeiro = aux;
            vetor[indice].endereco_ultimo = aux;
            vetor[indice].total_elementos = 1;
            
        }
        
        else {
            
            struct node * aux = (struct node *) malloc (sizeof (struct node));
            aux -> valor = v[i];
            aux -> next = NULL;
            
            vetor[indice].endereco_ultimo -> next = aux;
            vetor[indice].endereco_ultimo = aux;
            vetor[indice].total_elementos += 1;
            
        }
        
    }
    
    for (i = 0; i < n; ++ i) {
        
        if (vetor[i].endereco_primeiro != NULL && vetor[i].endereco_primeiro != vetor[i].endereco_ultimo) {
            
            int tamanho_atual = vetor[i].total_elementos;
            int vetor_aux[tamanho_atual], j = 0;
            struct node * aux = vetor[i].endereco_primeiro;
            
            for (j = 0; (j < tamanho_atual); ++ j) {
                
                vetor_aux[j] = aux -> valor;
                aux = aux -> next;
                
            }
            
            for (j = 1; j < tamanho_atual; ++ j) {
                
                int chave = vetor_aux[j];
                int k = (j - 1);
                
                while (k >= 0 && vetor_aux[k] > chave) {
                    
                    vetor_aux[k + 1] = vetor_aux[k];
                    -- k;
                    
                }
                
                vetor_aux[k + 1] = chave;
                
            }
            
            aux = vetor[i].endereco_primeiro;
            j = 0;
            
            while (aux != NULL) {
                
                aux -> valor = vetor_aux[j];
                ++ j;
                aux = aux -> next;
                
            }
            
        }
        
    }
    
    int j = 0;
    
    for (i = 0; i < n; ++ i) {
        
        if (vetor[i].endereco_primeiro != NULL && vetor[i].endereco_ultimo != NULL) {
            
            struct node * aux = vetor[i].endereco_primeiro;
            
            while (aux != NULL) {
                
                v[j] = aux -> valor;
                ++ j;
                aux = aux -> next;
                
            }
            
        }
        
    }
    
}

/* * * * * * * * * * * * Cocktail Sort * * * * * * * * * * * */

void cocktail_sort (int * v, int n) {
    
    bool trocado = true;
    int i = 0;
    int j = n - 1;
    
    while (i < j && trocado) {
        
        trocado = false;
        
        for (int k = i; k < j; k ++) {
            
            if (v[k] > v[k + 1]) {
                
                int aux = v[k];
                
                v[k] = v[k + 1];
                v[k + 1] = aux;
                trocado = true;
                
            }
            
        }
        
        j --;
        
        if (trocado) {
            
            trocado = false;
            
            for (int k = j; k > i; k --) {
                
                if (v[k] < v[k - 1]) {
                    
                    int aux = v[k];
                    
                    v[k] = v[k - 1];
                    v[k - 1] = aux;
                    trocado = true;
                    
                }
                
            }
            
        }
        
        i ++;
        
    }
    
}

/* * * * * * * * * * * * Comb Sort * * * * * * * * * * * */

void comb_sort (int * v, int n) {
    
    int aux;
    int intervalo = n;
    int escolha = 3;
    bool trocado;
    
    while (intervalo != 1 || trocado == true) {
        
        intervalo = (intervalo / escolha);
        
        if (intervalo < 1) {
            
            intervalo = 1;
            
        }
        
        trocado = false;
        
        for (int i = 0; i < n - intervalo; i ++) {
            
            if (v[i] > v[i + intervalo]) {
                
                aux = v[i + intervalo];
                v[i + intervalo] = v[i];
                v[i] = aux;
                trocado = true;
                
            }
            
        }
        
    }
    
}

/* * * * * * * * * * * * Counting Sort * * * * * * * * * * * */

void counting_sort (int * v, int n, int maior_valor) {
    
    int i;
    int * contas;
    
    contas = (int *) calloc (maior_valor, sizeof (* contas));
    
    for (i = 0; i < n; i ++) {
        
        contas[v[i]] ++;
        
    }
    
    int indice = 0;
    
    for (int i = 0; i < n + 1; i ++) {
        
        for (int j = 0; j < contas[i]; j ++) {
            
            v[indice] = i;
            indice ++;
            
        }
        
    }
    
    free (contas);
    
}

/* * * * * * * * * * * * Gnome Sort * * * * * * * * * * * */

void gnome_sort (int * v, int n) {
    
    int i = 0;
    int aux;
    
    while (i < n) {
        
        if (i == 0 || v[i] >= v[i - 1]) {
            
            i ++;
            
        } 
        
        else {
            
            aux = v[i];
            v[i] = v[i - 1];
            v[i - 1] = aux;
            
            i --;
            
        }
        
    }
    
}

/* * * * * * * * * * * * Heap Sort * * * * * * * * * * * */

void fix_heap (int * v, int i, int tamanho_heap) {
    
    int esq, dir, maior, aux;
    
    esq = 2 * i;
    dir = 2 * i + 1;
    
    if (esq <= tamanho_heap && v[esq] > v[i]) {
        
        maior = esq;
        
    } 
    
    else {
        
        maior = i;
        
    }
    
    if (dir <= tamanho_heap && v[dir] > v[maior]) {
        
        maior = dir;
        
    }
    
    if (maior != i) {
        
        aux = v[i];
        v[i] = v[maior];
        v[maior] = aux;
        
        fix_heap(v, maior, tamanho_heap);
        
    }
    
}

void constroi_heap (int * v, int n) {
    
    int i, tamanho_heap;
    
    tamanho_heap = n - 1;
    
    for (i = (n / 2); i >= 0; i --) {
        
        fix_heap (v, i, tamanho_heap);
        
    }
    
}

void heap_sort (int * v, int n) {
    
    constroi_heap (v, n);
    
    int tamanho_heap, i, aux;
    
    tamanho_heap = n - 1;
    
    for (i = tamanho_heap; i >= 0; i --) {
        
        aux = v[0];
        v[0] = v[tamanho_heap];
        v[tamanho_heap] = aux;
        tamanho_heap --;
        
        fix_heap (v, 0, tamanho_heap);
        
    }
    
}

/* * * * * * * * * * * * Insertion Sort * * * * * * * * * * * */

void insertion_sort (int * v, int n) {
    
    int i, j, elemento;
    
    for (i = 1; i < n; i ++) {
        
        elemento = v[i];
        
        for (j = i - 1; j >= 0 && v[j] > elemento; j --) {
            
            v[j + 1] = v[j];
            
        }
        
        v[j + 1] = elemento;
        
    }
    
}

/* * * * * * * * * * * * Insertion Sort (Recursivo) * * * * * * * * * * * */

void insertion_sort_recursiva (int * v, int n) {
    
    if (n <= 1) {
        
        return ;
        
    }
    
    insertion_sort_recursiva (v, n - 1);
    
    int x, j;
    
    x = v[n - 1];
    j = n - 2;
    
    while (j >= 0 && v[j] > x) {
        
        v[j + 1] = v[j];
        j = j - 1;
        
    }
    
    v[j + 1] = x;
    
}

/* * * * * * * * * * * * Merge Sort * * * * * * * * * * * */

void intercala_merge (int inicio, int meio, int fim, int * v){
    
    int i, j, contador, intercala[fim];
    
    i = inicio;
    j = meio;
    contador = 0;
    
    while (i < meio && j < fim) {
        
        if (v[i] < v[j]){
            
            intercala[contador] = v[i];
            i = i + 1;
            
        }
        
        else {
            
            intercala[contador] = v[j];
            j = j + 1;
            
        }
        
        contador = contador + 1;
        
    }
    
    while (i < meio) {
        
        intercala[contador] = v[i];
        i = i + 1;
        contador = contador + 1;
        
    }
    
    while (j < fim) {
        
        intercala[contador] = v[j];
        j = j + 1;
        contador = contador + 1;
        
    }
    
    for (i = inicio; i < fim; i ++) {
        
        v[i] = intercala[i - inicio];
        
    }
    
}

void merge_sort (int inicio, int fim, int * v) {
    
    int meio;
    
    if (inicio < fim - 1) {
        
        meio = (inicio + fim) / 2;
        
        merge_sort (inicio, meio, v);
        merge_sort (meio, fim, v);
        intercala_merge (inicio, meio, fim, v);
        
    }
    
}

/* * * * * * * * * * * * Odd Even Sort * * * * * * * * * * * */

void odd_even_sort (int * v, int n) {
    
    bool sortiado = false;
    int aux;
    
    while (!sortiado) {
        
        sortiado = true;
        
        for (int i = 1; i <= n - 2; i += 2) {
            
            if (v[i] > v[i + 1]) {
                
                aux = v[i + 1];
                v[i + 1] = v[i];
                v[i] = aux;
                sortiado = false;
                
            }
            
        }
        
        for (int i = 0; i <= n - 2; i += 2) {
            
            if (v[i] > v[i + 1]) {
                
                aux = v[i + 1];
                v[i + 1] = v[i];
                v[i] = aux;
                sortiado = false;
                
            }
            
        }
        
    }
    
}

/* * * * * * * * * * * * Pancake Sort * * * * * * * * * * * */

void flip (int * v, int i) {
    
    int aux, inicio = 0;
    
    while (inicio < i) {
        
        aux = v[inicio];
        v[inicio] = v[i];
        v[i] = aux;
        inicio ++;
        i --;
        
    }
    
}

int busca_maior (int * v, int n) {
    
    int maior_i, i;
    
    for (maior_i = 0, i = 0; i < n; ++ i) {
        
        if (v[i] > v[maior_i]) {
            
            maior_i = i;
            
        }
        
    }
    
    return maior_i;
    
}


void pancake_sort (int * v, int n) {
    
    for (int tamanho_atual = n; tamanho_atual > 1; -- tamanho_atual) {
        
        int maior_i = busca_maior (v, tamanho_atual);
        
        if (maior_i != tamanho_atual - 1) {
            
            flip (v, maior_i);
            flip (v, tamanho_atual - 1);
            
        }
        
    }
    
}

/* * * * * * * * * * * * Quick Sort * * * * * * * * * * * */

void troca (int * a, int * b) {
    
    int aux;
    
    aux = * a;
    * a = * b;
    * b = aux;
    
}

void quick_sort (int p, int r, int * v) {
    
    int i, j, x;
    
    x = v [(p + r) / 2];
    i = p;
    j = r;
    
    while (i <= j) {
        
        while (v[i] < x && i < r) {
            
            i ++;
            
        }
        
        while (v[j] > x && j > p) {
            
            j --;
            
        }
        
        if (i <= j) {
            
            troca (&v[i], &v[j]);
            
            i ++;
            j --;
            
        }
        
    }
    
    if (j > p) {
        
        quick_sort (p, j, v);
        
    }
    
    if (i < r) {
        
        quick_sort (i, r, v);
        
    }
    
}

/* * * * * * * * * * * * Radix Sort * * * * * * * * * * * */

void radix_sort (int * v, int n) {
    
    int i;
    int * b;
    int maior = v[0];
    int exp = 1;
    
    b = (int *) calloc (n, sizeof (int));
    
    for (i = 0; i < n; i ++) {
        
        if (v[i] > maior) {
            
            maior = v[i];
            
        }
        
    }
    
    while (maior / exp > 0) {
        
        int bucket[10000] = { 0 };
        
        for (i = 0; i < n; i ++) {
            
            bucket[(v[i] / exp) % 10] ++; 
            
        }
        
        for (i = 1; i < 10; i ++) {
            
            bucket[i] += bucket[i - 1];
            
        }
        
        for (i = n - 1; i >= 0; i--) {
            
            b[-- bucket[(v[i] / exp) % 10]] = v[i];
            
        }
        
        for (i = 0; i < n; i ++) {
            
            v[i] = b[i];
            
        }
        
        exp *= 10;
        
    }
    
    free (b);
    
}

/* * * * * * * * * * * * Selection Sort * * * * * * * * * * * */

void selection_sort (int * v, int n) {
    
    int i, j, menor;
    
    for (i = 0; i < n - 1; i ++) {
        
        menor = i;
        
        for (j = i + 1; j < n; j ++) {
            
            if (v[j] < v[menor]) {
                
                menor = j;
                
            }
            
        }
        
        troca (&v[i], &v[menor]);
        
    }
    
}

/* * * * * * * * * * * * Selection Sort (Recursivo) * * * * * * * * * * * */

void selection_sort_recursiva (int * v, int n) {
    
    int menor, j = 0;
    
    if (n - 1 == 0) {
        
        return ;
        
    }
    
    menor = n - 1;
    
    for (j = n - 2; j >= 0; j --) {
        
        if (v[menor] < v[j]) {
            
            menor = j;
            
        }
        
    }
    
    troca (&v[n - 1], &v[menor]);
    
    selection_sort_recursiva (v, n - 1);
    
}

/* * * * * * * * * * * * Shell Sort * * * * * * * * * * * */

void shell_sort (int * v, int n) {
    
    int j;
    
    for (int escolha = n / 2; escolha > 0; escolha /= 2) {
        
        for (int i = escolha; i < n; ++ i) {
            
            int temp = v[i];
            
            for (j = i; j >= escolha && temp < v[j - escolha]; j -= escolha) {
                
                v[j] = v[j - escolha];
                
            }
            
            v[j] = temp;
            
        }
        
    }
    
}

/* * * * * * * * * * * * Tree Sort * * * * * * * * * * * */

typedef struct _node {

    int chave;
    struct _node * esq;
    struct _node * dir;

} node;

node * constroi_arv (int chave) {

    node * novo = (node *) malloc (sizeof (node));

    novo -> chave = chave;
    novo -> esq = NULL;
    novo -> dir = NULL;

    return novo;

}

node * insere (node * folha, int valor) {

    if (folha == NULL) {

        folha = constroi_arv (valor);

    }

    if (valor < folha -> chave) {

        folha -> esq = insere (folha -> esq, valor);

    }

    if (valor > folha -> chave) {

        folha -> dir = insere (folha -> dir, valor);

    }
    
    return folha;

}

void in_order (node * raiz, int * v, int * i) {

    if (raiz != NULL) {

        in_order (raiz -> esq, v, i);
        v[* i] = raiz -> chave;
        * i += 1;
        in_order (raiz -> dir, v, i);

    }

}

void tree_sort (int * v, int n) {

    node * raiz;
    
    raiz = NULL;
    
    int i;
    
    for (i = 0; i < n; i ++) {

        raiz = insere (raiz, v[i]);

    }
    
    i = 0;
    
    in_order (raiz, v, &i);

}

/* * * * * * * * * * * * Funções Geradoras * * * * * * * * * * * */

int * aloca_vetor (int n) {
    
    int * v;
    
    v = (int *) malloc (n * sizeof (int));
    
    return v;
    
}

int * gerar_pior_caso (int n) {
    
    int i;
    int * v;
    
    v = aloca_vetor (n);
    
    for (i = n; i > 0; i --) {
        
        v[n - i] = i;
        
    }
    
    return v;
    
}

int * gerar_medio_caso (int n) {
    
    int i, j, meio;
    int * v;
    
    v = aloca_vetor (n);
    meio = n / 2;
    
    for (i = 0; i < meio; i ++) {
        
        v[i] = i;
        
    }
    
    for (i = n - 1, j = meio; i >= meio; i --, j ++) {
        
        v[i] = j;
        
    }
    
    return v;
    
}

int * gerar_melhor_caso (int n) {
    
    int i;
    int * v;
    
    v = aloca_vetor (n);
    
    for (i = 0; i < n; i ++) {
        
        v[i] = i;
        
    }
    
    return v;
    
}

/* * * * * * * * * * * * Funções de Teste * * * * * * * * * * * */

int tamanho;

void teste_pior_caso (int n) {
    
    int * v;
    clock_t inicio, fim;
    double * tempo;
    
    tamanho = n;
    tempo = (double *) malloc (20 * sizeof (double));
    
    /* Bogo Sort

    v = gerar_pior_caso (n);
     
    inicio = clock ();
    bogo_sort (v, n);
    fim = clock ();

    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Bogo Sort)\n");
        
    }
     
    tempo [0] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
     
    */
    
    /* Bubble Sort */

    v = gerar_pior_caso (n);
    
    inicio = clock ();
    bubble_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Bubble Sort)\n");
        
    }
    
    tempo [1] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Bucket Sort
    
    v = gerar_pior_caso (n);
    
    inicio = clock ();
    bucket_sort (v, n, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Bucket Sort)\n");
        
    }
    
    tempo [2] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);

    */
    
    /* Cocktail Sort */
    
    v = gerar_pior_caso (n);
    
    inicio = clock ();
    cocktail_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Cocktail Sort)\n");
        
    }
    
    tempo [3] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Comb Sort */
    
    v = gerar_pior_caso (n);
    
    inicio = clock ();
    comb_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Comb Sort)\n");
        
    }
    
    tempo [4] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Counting Sort */
    
    v = gerar_pior_caso (n);
    
    inicio = clock ();
    counting_sort (v, n, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Counting Sort)\n");
        
    }
    
    tempo [5] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Gnome Sort */
    
    v = gerar_pior_caso (n);
    
    inicio = clock ();
    gnome_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Gnome Sort)\n");
        
    }
    
    tempo [6] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Heap Sort */
    
    v = gerar_pior_caso (n);
    
    inicio = clock ();
    heap_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Heap Sort)\n");
        
    }
    
    tempo [7] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Insertion Sort */
    
    v = gerar_pior_caso (n);
    
    inicio = clock ();
    insertion_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Insertion Sort)\n");
        
    }
    
    tempo [8] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Insertion Sort (Recursivo) */
    
    v = gerar_pior_caso (n);
    
    inicio = clock ();
    insertion_sort_recursiva (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Insertion Sort (Recursivo))\n");
        
    }
    
    tempo [9] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Merge Sort */
    
    v = gerar_pior_caso (n);
    
    inicio = clock ();
    merge_sort (0, n, v);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Merge Sort)\n");
        
    }
    
    tempo [10] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Odd Even Sort */
    
    v = gerar_pior_caso (n);
    
    inicio = clock ();
    odd_even_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Odd Even Sort)\n");
        
    }
    
    tempo [11] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Pancake Sort */
    
    v = gerar_pior_caso (n);
    
    inicio = clock ();
    pancake_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Pancake Sort)\n");
        
    }
    
    tempo [12] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Quick Sort */
    
    v = gerar_pior_caso (n);
    
    inicio = clock ();
    quick_sort (0, n - 1, v);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Quick Sort)\n");
        
    }
    
    tempo [13] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Radix Sort */
    
    v = gerar_pior_caso (n);
    
    inicio = clock ();
    radix_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Radix Sort)\n");
        
    }
    
    tempo [14] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Selection Sort */
    
    v = gerar_pior_caso (n);
    
    inicio = clock ();
    selection_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Selection Sort)\n");
        
    }
    
    tempo [15] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Selection Sort (Recursivo) */
    
    v = gerar_pior_caso (n);
    
    inicio = clock ();
    selection_sort_recursiva (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Selection Sort (Recursivo))\n");
        
    }
    
    tempo [16] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Shell Sort */
    
    v = gerar_pior_caso (n);
    
    inicio = clock ();
    shell_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Shell Sort)\n");
        
    }
    
    tempo [17] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);

    /* Tree Sort */
    
    v = gerar_pior_caso (n);
    
    inicio = clock ();
    tree_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Tree Sort)\n");
        
    }
    
    tempo [18] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    imprime_resultado (tempo);
    free (tempo);
    
}

void teste_medio_caso (int n) {
    
    int * v;
    clock_t inicio, fim;
    double * tempo;
    
    v = gerar_medio_caso (n);
    tamanho = n;
    
    tempo = (double *) malloc (20 * sizeof (double));
    
    /*
     
     inicio = clock ();
     bogo_sort (v, n);
     fim = clock ();
     
     tempo [0] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
     
     */
    
    /* Bubble Sort */
    
    inicio = clock ();
    bubble_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Bubble Sort)\n");
        
    }
    
    tempo [1] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Bucket Sort
    
    v = gerar_medio_caso (n);
    
    inicio = clock ();
    bucket_sort (v, n, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Bucket Sort)\n");
        
    }
    
    tempo [2] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);

    */
    
    /* Cocktail Sort */
    
    v = gerar_medio_caso (n);
    
    inicio = clock ();
    cocktail_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Cocktail Sort)\n");
        
    }
    
    tempo [3] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Comb Sort */
    
    v = gerar_medio_caso (n);
    
    inicio = clock ();
    comb_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Comb Sort)\n");
        
    }
    
    tempo [4] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Counting Sort */
    
    v = gerar_medio_caso (n);
    
    inicio = clock ();
    counting_sort (v, n, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Counting Sort)\n");
        
    }
    
    tempo [5] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Gnome Sort */
    
    v = gerar_medio_caso (n);
    
    inicio = clock ();
    gnome_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Gnome Sort)\n");
        
    }
    
    tempo [6] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Heap Sort */
    
    v = gerar_medio_caso (n);
    
    inicio = clock ();
    heap_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Heap Sort)\n");
        
    }
    
    tempo [7] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Insertion Sort */
    
    v = gerar_medio_caso (n);
    
    inicio = clock ();
    insertion_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Insertion Sort)\n");
        
    }
    
    tempo [8] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Insertion Sort (Recursivo) */
    
    v = gerar_medio_caso (n);
    
    inicio = clock ();
    insertion_sort_recursiva (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Insertion Sort (Recursivo))\n");
        
    }
    
    tempo [9] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Merge Sort */
    
    v = gerar_medio_caso (n);
    
    inicio = clock ();
    merge_sort (0, n, v);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Merge Sort)\n");
        
    }
    
    tempo [10] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Odd Even Sort */
    
    v = gerar_medio_caso (n);
    
    inicio = clock ();
    odd_even_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Odd Even Sort)\n");
        
    }
    
    tempo [11] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Pancake Sort */
    
    v = gerar_medio_caso (n);
    
    inicio = clock ();
    pancake_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Pancake Sort)\n");
        
    }
    
    tempo [12] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Quick Sort */
    
    v = gerar_medio_caso (n);
    
    inicio = clock ();
    quick_sort (0, n - 1, v);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Quick Sort)\n");
        
    }
    
    tempo [13] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Radix Sort */
    
    v = gerar_medio_caso (n);
    
    inicio = clock ();
    radix_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Radix Sort)\n");
        
    }
    
    tempo [14] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Selection Sort */
    
    v = gerar_medio_caso (n);
    
    inicio = clock ();
    selection_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Selection Sort)\n");
        
    }
    
    tempo [15] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Selection Sort (Recursivo) */
    
    v = gerar_medio_caso (n);
    
    inicio = clock ();
    selection_sort_recursiva (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Selection Sort (Recursivo))\n");
        
    }
    
    tempo [16] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Shell Sort */
    
    v = gerar_medio_caso (n);
    
    inicio = clock ();
    shell_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Shell Sort)\n");
        
    }
    
    tempo [17] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);

    /* Tree Sort */
    
    v = gerar_medio_caso (n);
    
    inicio = clock ();
    tree_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Tree Sort)\n");
        
    }
    
    tempo [18] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    imprime_resultado (tempo);
    free (tempo);
    
}

void teste_melhor_caso (int n) {
    
    int * v;
    clock_t inicio, fim;
    double * tempo;
    
    v = gerar_melhor_caso (n);
    tamanho = n;
    
    tempo = (double *) malloc (20 * sizeof (double));
    
    /*
     
     inicio = clock ();
     bogo_sort (v, n);
     fim = clock ();
     
     tempo [0] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
     
     */
    
    /* Bubble Sort */
    
    inicio = clock ();
    bubble_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Bubble Sort)\n");
        
    }
    
    tempo [1] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Bucket Sort
    
    v = gerar_melhor_caso (n);
    
    inicio = clock ();
    bucket_sort (v, n, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Bucket Sort)\n");
        
    }
    
    tempo [2] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);

    */
    
    /* Cocktail Sort */
    
    v = gerar_melhor_caso (n);
    
    inicio = clock ();
    cocktail_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Cocktail Sort)\n");
        
    }
    
    tempo [3] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Comb Sort */
    
    v = gerar_melhor_caso (n);
    
    inicio = clock ();
    comb_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Comb Sort)\n");
        
    }
    
    tempo [4] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Counting Sort */
    
    v = gerar_melhor_caso (n);
    
    inicio = clock ();
    counting_sort (v, n, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Counting Sort)\n");
        
    }
    
    tempo [5] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Gnome Sort */
    
    v = gerar_melhor_caso (n);
    
    inicio = clock ();
    gnome_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Gnome Sort)\n");
        
    }
    
    tempo [6] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Heap Sort */
    
    v = gerar_melhor_caso (n);
    
    inicio = clock ();
    heap_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Heap Sort)\n");
        
    }
    
    tempo [7] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Insertion Sort */
    
    v = gerar_melhor_caso (n);
    
    inicio = clock ();
    insertion_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Insertion Sort)\n");
        
    }
    
    tempo [8] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Insertion Sort (Recursivo) */
    
    v = gerar_melhor_caso (n);
    
    inicio = clock ();
    insertion_sort_recursiva (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Insertion Sort (Recursivo))\n");
        
    }
    
    tempo [9] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Merge Sort */
    
    v = gerar_melhor_caso (n);
    
    inicio = clock ();
    merge_sort (0, n, v);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Merge Sort)\n");
        
    }
    
    tempo [10] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Odd Even Sort */
    
    v = gerar_melhor_caso (n);
    
    inicio = clock ();
    odd_even_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Odd Even Sort)\n");
        
    }
    
    tempo [11] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Pancake Sort */
    
    v = gerar_melhor_caso (n);
    
    inicio = clock ();
    pancake_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Pancake Sort)\n");
        
    }
    
    tempo [12] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Quick Sort */
    
    v = gerar_melhor_caso (n);
    
    inicio = clock ();
    quick_sort (0, n - 1, v);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Quick Sort)\n");
        
    }
    
    tempo [13] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Radix Sort */
    
    v = gerar_melhor_caso (n);
    
    inicio = clock ();
    radix_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Radix Sort)\n");
        
    }
    
    tempo [14] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Selection Sort */
    
    v = gerar_melhor_caso (n);
    
    inicio = clock ();
    selection_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Selection Sort)\n");
        
    }
    
    tempo [15] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Selection Sort (Recursivo) */
    
    v = gerar_melhor_caso (n);
    
    inicio = clock ();
    selection_sort_recursiva (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Selection Sort (Recursivo))\n");
        
    }
    
    tempo [16] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    /* Shell Sort */
    
    v = gerar_melhor_caso (n);
    
    inicio = clock ();
    shell_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Shell Sort)\n");
        
    }
    
    tempo [17] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);

    /* Tree Sort */
    
    v = gerar_melhor_caso (n);
    
    inicio = clock ();
    tree_sort (v, n);
    fim = clock ();
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Tree Sort)\n");
        
    }
    
    tempo [18] = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    free (v);
    
    imprime_resultado (tempo);
    free (tempo);
    
}

void imprime_resultado (double * tempo) {
    
    cor_texto (ciano);
    printf("       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    estilo_texto (resetar);
    printf("       *                                                                     *\n");
    printf("       *                     Quantidade Elementos (%6d)                   *\n", tamanho);
    printf("       *                                                                     *\n");
    printf("       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("       *                             *                   *                   *\n");
    printf("       *           Métodos           *     Pontuação     *      Tempo (s)    *\n");
    printf("       *                             *                   *                   *\n");
    printf("       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("       *                             *                   *                   *\n");
    printf("       * Bubble Sort                 * %17d * %17lf *\n", (int)(100 / tempo [1]), tempo [1]);
    printf("       * Cocktail Sort               * %17d * %17lf *\n", (int)(100 / tempo [3]), tempo [3]);
    printf("       * Comb Sort                   * %17d * %17lf *\n", (int)(100 / tempo [4]), tempo [4]);
    printf("       * Counting Sort               * %17d * %17lf *\n", (int)(100 / tempo [5]), tempo [5]);
    printf("       * Gnome Sort                  * %17d * %17lf *\n", (int)(100 / tempo [6]), tempo [6]);
    printf("       * Heap Sort                   * %17d * %17lf *\n", (int)(100 / tempo [7]), tempo [7]);
    printf("       * Insertion Sort              * %17d * %17lf *\n", (int)(100 / tempo [8]), tempo [8]);
    printf("       * Insertion Sort (Recursivo)  * %17d * %17lf *\n", (int)(100 / tempo [9]), tempo [9]);
    printf("       * Merge Sort                  * %17d * %17lf *\n", (int)(100 / tempo [10]), tempo [10]);
    printf("       * Odd Even Sort               * %17d * %17lf *\n", (int)(100 / tempo [11]), tempo [11]);
    printf("       * Pancake Sort                * %17d * %17lf *\n", (int)(100 / tempo [12]), tempo [12]);
    printf("       * Quick Sort                  * %17d * %17lf *\n", (int)(100 / tempo [13]), tempo [13]);
    printf("       * Radix Sort                  * %17d * %17lf *\n", (int)(100 / tempo [14]), tempo [14]);
    printf("       * Selection Sort              * %17d * %17lf *\n", (int)(100 / tempo [15]), tempo [15]);
    printf("       * Selection Sort (Recursivo)  * %17d * %17lf *\n", (int)(100 / tempo [16]), tempo [16]);
    printf("       * Shell Sort                  * %17d * %17lf *\n", (int)(100 / tempo [17]), tempo [17]);
    printf("       * Tree Sort                   * %17d * %17lf *\n", (int)(100 / tempo [18]), tempo [18]);
    printf("       *                             *                   *                   *\n");
    printf("       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    
}

void gerar_menu () {

	cor_texto (ciano);
    printf ("\n       * * * * * * * * ");
    estilo_texto (resetar);
   
    cor_texto (amarelo);
    printf ("BENCHMARCKING");
    estilo_texto (resetar);
    
    cor_texto (ciano);
    printf (" * * * * * * * *\n       *                                           *\n");
    estilo_texto (resetar);
    
    cor_texto (ciano);
	printf("       *");
	estilo_texto (resetar);

	cor_texto (vermelho);
	printf("              1) ");
	estilo_texto (resetar);

	printf ("Pior Caso;");

	cor_texto (ciano);
	printf("                *\n");
	estilo_texto (resetar);

	cor_texto (ciano);
	printf("       *");
	estilo_texto (resetar);

	cor_texto (vermelho);
	printf("              2) ");
	estilo_texto (resetar);

	printf ("Médio Caso;");

	cor_texto (ciano);
	printf("               *\n");
	estilo_texto (resetar);

	cor_texto (ciano);
	printf("       *");
	estilo_texto (resetar);

	cor_texto (vermelho);
	printf("              3) ");
	estilo_texto (resetar);

	printf ("Melhor Caso;");

	cor_texto (ciano);
	printf("              *\n");
	estilo_texto (resetar);

	cor_texto (ciano);
	printf("       *");
	estilo_texto (resetar);

	cor_texto (vermelho);
	printf("              4) ");
	estilo_texto (resetar);

	printf ("Sair;");

	cor_texto (ciano);
	printf("                     *\n");
	estilo_texto (resetar);
    
    cor_texto (ciano);
    printf ("       *                                           *\n       * * * * * * * * * * * * * * * * * * * * * * *\n\n");
    estilo_texto (resetar);

}

void confere_funcionamento (int n) {

    int * v;
    
    /* Bogo Sort
     
    v = gerar_medio_caso (n);
    bogo_sort (v, n);
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Bubble Sort)\n");
        
    }
    
    free (v);
     
    */
    
    /* Bubble Sort */
    
    v = gerar_medio_caso (n);
    bubble_sort (v, n);
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Bubble Sort)\n");
        
    }
    
    free (v);
    
    /* Bucket Sort
    
    v = gerar_medio_caso (n);
    bucket_sort (v, n, n);
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Bucket Sort)\n");
        
    }
    
    free (v);

    */
    
    /* Cocktail Sort */
    
    v = gerar_medio_caso (n);
    cocktail_sort (v, n);
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Cocktail Sort)\n");
        
    }
    
    free (v);
    
    /* Comb Sort */
    
    v = gerar_medio_caso (n);
    comb_sort (v, n);
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Comb Sort)\n");
        
    }

    free (v);
    
    /* Counting Sort */
    
    v = gerar_medio_caso (n);
    counting_sort (v, n, n);
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Counting Sort)\n");
        
    }

    free (v);
    
    /* Gnome Sort */
    
    v = gerar_medio_caso (n);
    gnome_sort (v, n);
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Gnome Sort)\n");
        
    }
    
    free (v);
    
    /* Heap Sort */
    
    v = gerar_medio_caso (n);
    heap_sort (v, n);
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Heap Sort)\n");
        
    }
    
    free (v);
    
    /* Insertion Sort */
    
    v = gerar_medio_caso (n);
    insertion_sort (v, n);
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Insertion Sort)\n");
        
    }

    free (v);
    
    /* Insertion Sort (Recursivo) */
    
    v = gerar_medio_caso (n);
    insertion_sort_recursiva (v, n);
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Insertion Sort (Recursivo))\n");
        
    }

    free (v);
    
    /* Merge Sort */
    
    v = gerar_medio_caso (n);
    merge_sort (0, n, v);
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Merge Sort)\n");
        
    }
    
    free (v);
    
    /* Odd Even Sort */
    
    v = gerar_medio_caso (n);
    odd_even_sort (v, n);
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Odd Even Sort)\n");
        
    }
    
    free (v);
    
    /* Pancake Sort */
    
    v = gerar_medio_caso (n);
    pancake_sort (v, n);
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Pancake Sort)\n");
        
    }
    
    free (v);
    
    /* Quick Sort */
    
    v = gerar_medio_caso (n);
    quick_sort (0, n - 1, v);
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Quick Sort)\n");
        
    }

    free (v);
    
    /* Radix Sort */
    
    v = gerar_medio_caso (n);
    radix_sort (v, n);
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Radix Sort)\n");
        
    }
    
    free (v);
    
    /* Selection Sort */
    
    v = gerar_medio_caso (n);
    selection_sort (v, n);
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Selection Sort)\n");
        
    }

    free (v);
    
    /* Selection Sort (Recursivo) */
    
    v = gerar_medio_caso (n);
    selection_sort_recursiva (v, n);
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Selection Sort (Recursivo))\n");
        
    }

    free (v);
    
    /* Shell Sort */
    
    v = gerar_medio_caso (n);
    shell_sort (v, n);
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Shell Sort)\n");
        
    }
    
    free (v);

    /* Tree Sort */
    
    v = gerar_medio_caso (n);
    tree_sort (v, n);
    
    if (!confere_ordenacao (v, n)) {
        
        printf("Não está Ordenado (Tree Sort)\n");
        
    }

    free (v);

    cor_texto (ciano);
    printf ("\n       * * * * * * * * ");
    estilo_texto (resetar);

    cor_texto (amarelo);
    printf ("CONFERE FUNCIONAMENTO");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf (" * * * * * * * *\n       *                                                   *\n");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *");
    estilo_texto (resetar);

    cor_texto (vermelho);
    printf("         * ");
    estilo_texto (resetar);

    /*
    

Shell Sort;
Tree Sort;
    */

    printf ("Bogo Sort                ");
    cor_texto (verde);
    printf("      OK");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *\n");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *");
    estilo_texto (resetar);

    cor_texto (vermelho);
    printf("         * ");
    estilo_texto (resetar);

    printf ("Bubble Sort            ");
    cor_texto (verde);
    printf("        OK");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *\n");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *");
    estilo_texto (resetar);

    cor_texto (vermelho);
    printf("         * ");
    estilo_texto (resetar);

    printf ("Buckte Sort            ");
    cor_texto (verde);
    printf("        OK");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *\n");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *");
    estilo_texto (resetar);

    cor_texto (vermelho);
    printf("         * ");
    estilo_texto (resetar);

    printf ("Cocktail Sort          ");
    cor_texto (verde);
    printf("        OK");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *\n");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *");
    estilo_texto (resetar);

    cor_texto (vermelho);
    printf("         * ");
    estilo_texto (resetar);

    printf ("Comb Sort              ");
    cor_texto (verde);
    printf("        OK");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *\n");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *");
    estilo_texto (resetar);

    cor_texto (vermelho);
    printf("         * ");
    estilo_texto (resetar);

    printf ("Counting Sort          ");
    cor_texto (verde);
    printf("        OK");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *\n");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *");
    estilo_texto (resetar);

    cor_texto (vermelho);
    printf("         * ");
    estilo_texto (resetar);

    printf ("Gnome Sort             ");
    cor_texto (verde);
    printf("        OK");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *\n");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *");
    estilo_texto (resetar);

    cor_texto (vermelho);
    printf("         * ");
    estilo_texto (resetar);

    printf ("Heap Sort              ");
    cor_texto (verde);
    printf("        OK");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *\n");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *");
    estilo_texto (resetar);

    cor_texto (vermelho);
    printf("         * ");
    estilo_texto (resetar);

    printf ("Insertion Sort         ");
    cor_texto (verde);
    printf("        OK");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *\n");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *");
    estilo_texto (resetar);

    cor_texto (vermelho);
    printf("         * ");
    estilo_texto (resetar);

    printf ("Insertion Sort (Recursivo)");
    cor_texto (verde);
    printf("     OK");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *\n");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *");
    estilo_texto (resetar);

    cor_texto (vermelho);
    printf("         * ");
    estilo_texto (resetar);

    printf ("Merge Sort             ");
    cor_texto (verde);
    printf("        OK");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *\n");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *");
    estilo_texto (resetar);

    cor_texto (vermelho);
    printf("         * ");
    estilo_texto (resetar);

    printf ("Odd Even Sort          ");
    cor_texto (verde);
    printf("        OK");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *\n");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *");
    estilo_texto (resetar);

    cor_texto (vermelho);
    printf("         * ");
    estilo_texto (resetar);

    printf ("Pancake Sort           ");
    cor_texto (verde);
    printf("        OK");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *\n");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *");
    estilo_texto (resetar);

    cor_texto (vermelho);
    printf("         * ");
    estilo_texto (resetar);

    printf ("Quick Sort             ");
    cor_texto (verde);
    printf("        OK");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *\n");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *");
    estilo_texto (resetar);

    cor_texto (vermelho);
    printf("         * ");
    estilo_texto (resetar);

    printf ("Radix Sort             ");
    cor_texto (verde);
    printf("        OK");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *\n");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *");
    estilo_texto (resetar);

    cor_texto (vermelho);
    printf("         * ");
    estilo_texto (resetar);

    printf ("Selection Sort         ");
    cor_texto (verde);
    printf("        OK");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *\n");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *");
    estilo_texto (resetar);

    cor_texto (vermelho);
    printf("         * ");
    estilo_texto (resetar);

    printf ("Selection Sort (Recursivo)");
    cor_texto (verde);
    printf("     OK");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *\n");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *");
    estilo_texto (resetar);

    cor_texto (vermelho);
    printf("         * ");
    estilo_texto (resetar);

    printf ("Shell Sort             ");
    cor_texto (verde);
    printf("        OK");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *\n");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *");
    estilo_texto (resetar);

    cor_texto (vermelho);
    printf("         * ");
    estilo_texto (resetar);

    printf ("Tree Sort              ");
    cor_texto (verde);
    printf("        OK");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *\n");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf ("       *                                                   *\n       * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
    estilo_texto (resetar);



}
