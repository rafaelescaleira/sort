Sort (Ordenação) : Benchmark
============================

![Build](https://img.shields.io/gitlab/pipeline/rafaelescaleira/sort.svg)
![Size](https://img.shields.io/github/repo-size/rafaelescaleira/sort.svg)
![License](https://img.shields.io/github/license/rafaelescaleira/sort.svg)

Esse repositório possui funções implementadas em linguagem C.
Segue a lista das funções :

* Bogo Sort;
* Bubble Sort;
* Bucket Sort;
* Cocktail Sort;
* Comb Sort;
* Counting Sort;
* Gnome Sort;
* Heap Sort;
* Insertion Sort;
* Insertion Sort (Recursivo);
* Merge Sort;
* Odd Even Sort;
* Pancake Sort;
* Quick Sort;
* Radix Sort;
* Selection Sort;
* Selection Sort (Recursivo);
* Shell Sort;
* Tree Sort;

Instruções para Compilação
--------------------------
Para compilar `` sort.c `` com `` teste_sort.c `` , ou seja, caso deseja testar o código de `` sort.c `` :

* `` ~$ gcc sort.c teste_sort.c -Wall -std=c99 -pedantic ``

Para compilar `` sort.c `` com `` main.c `` , ou seja, caso deseja executar o código e realizar seus próprios testes :

* `` ~$ gcc sort.c main.c -Wall -std=c99 -pedantic ``

Instruções para Execução
------------------------
Para executar o arquivo já compilado com `` teste_sort.c `` :

* `` ~$ ./a.out ``

Para executar o arquivo já compilado com `` main.c `` :

* `` ~$ ./a.out ``
* `` ~$ ./a.out < arquivo_entrada.txt ``

Complexidade de Tempo dos Métodos de Ordenação
----------------------------------------------

| Casos | Bogo Sort | Bubble Sort | Bucket Sort | Cocktail Sort | Comb Sort |  Counting Sort  |
|:---------:|:----------:|:---------:|:---------:|:----------:|:---------:|:---------:|
| Pior Caso | O ((n+1)!) | O (n²) | O (n²) | O (n²) | O (n²) | O(n+k) |
| Médio Caso | O ((n+1)!) | O (n²) | O (n) | O (n²) | O (n²) | O(n+k) |
| Melhor Caso | O (n) | O (n) | O (n) | O (n) | O (n log(n)) | O(n+k) |

| Casos | Gnome Sort | Heap Sort | Insertion Sort | Merge Sort | Odd Even Sort | Pancake Sort |
|:---------:|:----------:|:---------:|:---------:|:----------:|:---------:|:---------:|
| Pior Caso | O (n²) | O (n log(n)) | O (n²) | O (n log(n)) | O (n²) | O (n²) |
| Médio Caso | O (n²) | O (n log(n)) | O (n²) | O (n log(n)) | O (n²) | * |
| Melhor Caso | O (n) | O (n log(n)) | O (n) | O (n log(n)) | O (n log(n)) | * |

| Casos | Quick Sort | Radix Sort | Selection Sort | Shell Sort | Tree Sort | Selection Sort (Recursivo) |
|:---------:|:----------:|:---------:|:---------:|:----------:|:---------:|:---------:|
| Pior Caso | O (n²) | O(n.k) | O (n²) | O(n(log(n))^2) | O (n²) | O (n²) |
| Médio Caso | O (n log(n)) | O(n.k) | O (n²) | O(n(log(n))^2) | O (n log(n)) | O (n²) |
| Melhor Caso | O (n) | O(n.k) | O (n²) | O (n log(n)) | O (n log(n)) | O (n²) |

Execução do Programa (Teste)
----------------------------
![grab-landing-page](https://j.gifs.com/mQp059.gif)

Execução do Programa (Principal)
--------------------------------
![grab-landing-page](https://j.gifs.com/G5OXOK.gif)
