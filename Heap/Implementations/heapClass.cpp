#include "../Headers/heapClass.h"
#include <algorithm>


void Heap::setType(HeapType type){
    this->type = type;
}

void Heap::setVector(std::vector<int>* heapList){
    this->heapList = *heapList;
}

void Heap::unsetVector(){
    this->heapList.clear();
}

bool Heap::comparar(int rhs, int lhs){
    if(type == MAX){
        return rhs > lhs;
    } else {
        return rhs < lhs;
    }
}

void Heap::descer(int i, int n){
    int prioridade = i;
    int filho_esq = 2 * i + 1;
    int filho_dir = 2 * i + 2;

    if(filho_esq < n && comparar(heapList[filho_esq], heapList[prioridade])){
        prioridade = filho_esq;
    }

    if(filho_dir < n && comparar(heapList[filho_dir], heapList[prioridade])){
        prioridade = filho_dir;
    }

    if(prioridade != i){
        std::swap(heapList[i], heapList[prioridade]);
        descer(prioridade, n);
    }
}

void Heap::subir(int i){
    int pai =(i - 1) / 2;
    if(i > 0 && comparar(heapList[i], heapList[pai])){
        std::swap(heapList[i], heapList[pai]);
        subir(pai);
    }
}

void Heap::inserir(int x){
    heapList.push_back(x);
    size_t index = heapList.size() - 1;
    subir(index);
}


void Heap::remover(int valor){
    if(heapList.empty()){
        std::cout << "A heap está vazia!\n";
        return;
    }

    auto it = std::find(heapList.begin(), heapList.end(), valor);

    if(it == heapList.end()){
        std::cout << "Este valor não existe na heap!\n";
        return;
    }

    size_t index = std::distance(heapList.begin(), it);

    heapList[index] = heapList.back();
    heapList.pop_back();

    if(index < heapList.size()){
        descer(index, heapList.size());
    }
}

void Heap::removerRaiz(){
    if(heapList.size() > 1){
        heapList[0] = heapList[heapList.size() - 1];
        heapList.pop_back();
        descer(0, heapList.size());
    } else if(!heapList.empty()){
        heapList.pop_back();
    }
}

void Heap::construir(){
    int n = heapList.size();
    for(int i =(n / 2) - 1; i >= 0; i--){
        descer(i, n);
    }
}

void Heap::heapSort(){
    int n = heapList.size();
    construir();
    for(int i = n - 1; i > 0; --i){
        std::swap(heapList[0], heapList[i]);
        descer(0, i);
    }
}

void Heap::imprimir(){
    std::cout << "[";
    for(size_t i = 0; i < heapList.size(); i++){
        if(i == heapList.size() - 1){
            std::cout << heapList[i];
        } else {
            std::cout << heapList[i] << ", ";
        }
    }
    std::cout << "]\n\n";
}

const std::vector<int>& Heap::getHeap() const {
    return heapList;
}

bool Heap::verificarMinHeap() {
    int n = heapList.size();
    for (int i = 0; i <= (n / 2) - 1; i++) {
        int filho_esq = 2 * i + 1;
        int filho_dir = 2 * i + 2;

        if (filho_esq < n && heapList[i] > heapList[filho_esq]) {
            return false;
        }

        if (filho_dir < n && heapList[i] > heapList[filho_dir]) {
            return false;
        }
    }
    return true;
}

bool Heap::verificarMaxHeap() {
    int n = heapList.size();
    for (int i = 0; i <= (n / 2) - 1; i++) {
        int filho_esq = 2 * i + 1;
        int filho_dir = 2 * i + 2;

        if (filho_esq < n && heapList[i] < heapList[filho_esq]) {
            return false;
        }

        if (filho_dir < n && heapList[i] < heapList[filho_dir]) {
            return false;
        }
    }
    return true;
}

void Heap::alterarValor(size_t idx, int valor){
    if(idx < heapList.size()){
        int antigoValor = heapList[idx];
        heapList[idx] = valor;

        if(comparar(valor, antigoValor)){
            subir(idx);
        } else {
            descer(idx, heapList.size());
        }
    }
}
