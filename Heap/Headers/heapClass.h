/**
 * @file heapClass.h
 * @brief Declaração da classe Heap e seus métodos.
 * 
 * Este arquivo contém a declaração da classe Heap, que implementa uma estrutura de dados de heap (montículo).
 * A classe fornece métodos para inserir, remover, construir o heap, ordenar o heap e imprimir o heap.
 * 
 * @author Seu Nome
 * @date Data de Criação
 */

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>

/**
 * @class Heap
 * @brief Classe que representa um heap (montículo).
 * 
 * A classe Heap fornece métodos para manipulação de um heap, incluindo inserção, remoção, construção,
 * ordenação e impressão dos elementos do heap.
 */

enum HeapType { MAX, MIN };

class Heap {
private:
    std::vector<int> heapList; ///< Vetor que armazena os elementos do heap.
    HeapType type; ///< Tipo do heap (MAX ou MIN).

    bool comparar(int rhs, int lhs);

    /**
     * @brief Desce um elemento na árvore do heap.
     * 
     * Este método é utilizado para manter a propriedade do heap ao descer um elemento na árvore.
     * 
     * @param i Índice do elemento a ser descido.
     * @param n Tamanho do heap.
     */
    void descer(int i, int n);

    /**
     * @brief Sobe um elemento na árvore do heap.
     * 
     * Este método é utilizado para manter a propriedade do heap ao subir um elemento na árvore.
     * 
     * @param i Índice do elemento a ser subido.
     */
    void subir(int i);

public:
    void setVector(std::vector<int>* heapList);
    void unsetVector();

    void setType(HeapType type);
    /**
     * @brief Insere um elemento no heap.
     * 
     * Este método insere um novo elemento no heap e ajusta a estrutura para manter a propriedade do heap.
     * 
     * @param x Elemento a ser inserido.
     */
    void inserir(int x);

    /**
     * @brief Remove um elemento de valor arbitrário do heap.
     * 
     * @param valor Valor do elemento a ser removido.
     * 
     * Este método remove o elemento e ajusta a estrutura para manter a propriedade do heap.
     */
    void remover(int valor);

    /**
     * @brief Remove o elemento raiz do heap.
     * 
     * Este método remove o elemento raiz do heap e ajusta a estrutura para manter a propriedade do heap.
     */
    void removerRaiz();

    /**
     * @brief Constrói o heap a partir de um vetor de elementos.
     * 
     * Este método constrói o heap a partir dos elementos presentes no vetor heapList.
     */
    void construir();

    /**
     * @brief Ordena os elementos do heap.
     * 
     * Este método ordena os elementos do heap utilizando o algoritmo de heapsort.
     */
    void heapSort();

    /**
     * @brief Imprime os elementos do heap.
     * 
     * Este método imprime os elementos do heap na saída padrão.
     */
    void imprimir();

    /**
     * @brief Obtém uma referência constante ao vetor do heap.
     * 
     * Este método retorna uma referência constante ao vetor que armazena os elementos do heap.
     * 
     * @return Referência constante ao vetor heapList.
     */
    const std::vector<int>& getHeap() const;

    /**
     * @brief Verifica se o heap é um heap mínimo.
     * 
     * Este método verifica se o heap é um heap mínimo, ou seja, se o valor de cada nó é menor ou igual ao valor de seus filhos.
     * 
     * @return true se o heap é um heap mínimo, false caso contrário.
     */
    bool verificarMinHeap();

    /**
     * @brief Verifica se o heap é um heap máximo.
     * 
     * Este método verifica se o heap é um heap máximo, ou seja, se o valor de cada nó é maior ou igual ao valor de seus filhos.
     * 
     * @return true se o heap é um heap máximo, false caso contrário.
     */
    bool verificarMaxHeap();

    /**
     * @brief Altera o valor de um nó do heap.
     * 
     * Este método altera o valor de um nó do heap e ajusta a estrutura para manter a propriedade do heap.
     * 
     * @param idx Índice do nó a ser alterado.
     * @param valor Novo valor do nó.
     */
    void alterarValor(size_t idx, int valor);


};

#endif