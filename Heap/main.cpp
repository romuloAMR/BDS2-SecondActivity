#include "../Headers/heapClass.h"

void imprimirNomeTeste(std::string msg){
    std::cout << ">>>>> " << msg << "\n\n";
}

std::string imprimirResultado(bool resultado){
    return (resultado ? "Sim" : "Não");
}

void imprimirDivisor(){
    std::cout << "==============================================\n";
}

int main() {
    Heap heap;


    {
        imprimirNomeTeste("Teste 1: Heap Máxima");
        std::vector<int> heap1 = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
        
        heap.setType(HeapType::MAX);
        heap.setVector(&heap1);
    
        std::cout << "Heap 1:\n";
        heap.imprimir();
        std::cout << "É uma heap máxima? " << imprimirResultado(heap.verificarMaxHeap()) << std::endl;

        heap.unsetVector();
    }

    imprimirDivisor();

    {
        imprimirNomeTeste("Teste 2: Heap Mínima");
        std::vector<int> heap2 = {10, 14, 20, 17, 27, 21, 25, 19, 40, 31};

        heap.setVector(&heap2);

        std::cout << "Heap 2:\n";
        heap.imprimir();
        std::cout << "É uma heap mínima? " << imprimirResultado(heap.verificarMinHeap()) << std::endl;

        heap.unsetVector();
    }

    imprimirDivisor();

    {
        imprimirNomeTeste("Teste 3: Não sabemos o que é");
        std::vector<int> heap3 = {20, 25, 32, 29, 27, 35, 40, 45};

        heap.setVector(&heap3);

        std::cout << "Heap 3:\n";
        heap.imprimir();
        std::cout << "É uma heap máxima? " << imprimirResultado(heap.verificarMaxHeap()) << std::endl;
        std::cout << "É uma heap mínima? " << imprimirResultado(heap.verificarMinHeap()) << std::endl;

        heap.unsetVector();
    }

    imprimirDivisor();

    {
        imprimirNomeTeste("Teste 4: Não sabemos o que é");
        std::vector<int> heap4 = {20, 32, 25, 29, 27, 35, 40, 45};

        heap.setVector(&heap4);

        std::cout << "Heap 4:\n";
        heap.imprimir();
        std::cout << "É uma heap máxima? " << imprimirResultado(heap.verificarMaxHeap()) << std::endl;
        std::cout << "É uma heap mínima? " << imprimirResultado(heap.verificarMinHeap()) << std::endl;

        heap.unsetVector();
    }

    imprimirDivisor();

    {
        imprimirNomeTeste("Teste 5: Não sabemos o que é");
        std::vector<int> heap5 = {50, 45, 48, 29, 15, 35, 40, 27};

        heap.setVector(&heap5);
        std::cout << "Heap 5:\n";
        heap.imprimir();
        std::cout << "É uma heap máxima? " << imprimirResultado(heap.verificarMaxHeap()) << std::endl;
        std::cout << "É uma heap mínima? " << imprimirResultado(heap.verificarMinHeap()) << std::endl;

        heap.unsetVector();
    }

    imprimirDivisor();

    {
        imprimirNomeTeste("Teste 6: Alteração de 50 para 10");
        std::vector<int> heap6 = {50, 45, 48, 29, 15, 35, 40, 27, 26, 14, 12, 33, 30, 37, 20, 21, 19, 25};

        heap.setVector(&heap6);
        heap.setType(HeapType::MIN);
        std::cout << "Heap 6 antes da alteração:\n";
        heap.imprimir();

        heap.alterarValor(0, 10);
        heap.construir();

        std::cout << "Heap 6 depois da alteração de 50 para 10:\n";
        heap.imprimir();

        std::cout << "É uma heap mínima? " << imprimirResultado(heap.verificarMinHeap()) << std::endl;

        heap.unsetVector();
    }

    imprimirDivisor();

    {
        imprimirNomeTeste("Teste 7: Alteração de 21 para 10");
        std::vector<int> heap7 = {50, 45, 48, 29, 15, 35, 40, 27, 26, 14, 12, 33, 30, 37, 20, 21, 19, 25};

        heap.setVector(&heap7);
        heap.setType(HeapType::MIN);
        std::cout << "Heap 7 antes da alteração:\n";
        heap.imprimir();
        
        heap.alterarValor(15, 10);
        heap.construir();

        std::cout << "Heap 7 depois da alteração de 21 para 10:\n";
        heap.imprimir();

        std::cout << "É uma heap mínima? " << imprimirResultado(heap.verificarMinHeap()) << std::endl;

        heap.unsetVector();
    }

    imprimirDivisor();

    {
        imprimirNomeTeste("Teste 8: Inserção de 47");
        std::vector<int> heap8 = {50, 45, 48, 29, 15, 35, 40, 27, 26, 14, 12, 33, 30, 37, 20, 21, 19, 25};

        heap.setVector(&heap8);
        heap.setType(HeapType::MAX);
        std::cout << "Heap 8 antes da inserção:\n";
        heap.imprimir();

        heap.inserir(47);

        std::cout << "Heap 8 depois da inserção de 47:\n";
        heap.imprimir();

        std::cout << "É uma heap máxima? " << imprimirResultado(heap.verificarMaxHeap()) << std::endl;

        heap.unsetVector();
    }

    imprimirDivisor();

    {
        imprimirNomeTeste("Teste 9: Remoção de 50");
        std::vector<int> heap9 = {50, 45, 48, 29, 15, 35, 40, 27, 26, 14, 12, 33, 30, 37, 20, 21, 19, 25};

        heap.setVector(&heap9);
        heap.setType(HeapType::MAX);
        std::cout << "Heap 9 antes da remoção:\n";
        heap.imprimir();

        heap.removerRaiz();

        std::cout << "Heap 9 depois da remoção de 50:\n";
        heap.imprimir();

        std::cout << "É uma heap máxima? " << imprimirResultado(heap.verificarMaxHeap()) << std::endl;

        heap.unsetVector();
    }

    imprimirDivisor();

    {
        imprimirNomeTeste("Teste 10: Ordenação do heap");
        std::vector<int> heap10 = {50, 45, 48, 29, 15, 35, 40, 27, 26, 14, 12, 33, 30, 37, 20, 21, 19, 25};

        heap.setVector(&heap10);
        heap.setType(HeapType::MIN);
        std::cout << "Lista anteriormente à ordenação:\n";
        heap.imprimir();

        heap.heapSort();

        std::cout << "Heap 10 (depois da ordenação):\n";
        heap.imprimir();

        heap.unsetVector();
    }

    imprimirDivisor();

    {
        imprimirNomeTeste("Teste 11: Construir Heap Máxima");
        std::vector<int> heap11 = {7, 5, 12, 4, 8, 9, 3, 14, 1, 5};

        heap.setVector(&heap11);
        heap.setType(HeapType::MAX);
        std::cout << "Heap 11 antes da construção:\n";
        heap.imprimir();

        heap.construir();

        std::cout << "Heap 11 depois da construção:\n";
        heap.imprimir();

        std::cout << "É uma heap máxima? " << imprimirResultado(heap.verificarMaxHeap()) << std::endl;

        heap.unsetVector();
    }

    imprimirDivisor();

    {
        imprimirNomeTeste("Teste 12: Construir Heap Mínima");
        std::vector<int> heap12 = {7, 5, 12, 4, 8, 9, 3, 14, 1, 5};

        heap.setVector(&heap12);
        heap.setType(HeapType::MIN);
        std::cout << "Heap 12 antes da construção:\n";
        heap.imprimir();

        heap.construir();

        std::cout << "Heap 12 depois da construção:\n";
        heap.imprimir();

        std::cout << "É uma heap mínima? " << imprimirResultado(heap.verificarMinHeap()) << std::endl;

        heap.unsetVector();
    }

    return 0;
}
