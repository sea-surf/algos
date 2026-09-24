#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
struct Elemento {
    T dado;
    Elemento<T>* proximo;
    Elemento(T dado) : dado(dado), proximo(nullptr) {}
};

template<typename T>
class Queue {
private:
    Elemento<T>* _primeiro;
    size_t _tamanho;

public:
    Queue() : _primeiro(nullptr), _tamanho(0) {}

    ~Queue() {
        Elemento<T>* h = _primeiro;
        while(h != nullptr) {
            Elemento<T>* next = h->proximo;
            delete h;
            h = next;
        }
    }

    void inserirNoFim(T dado) {
        Elemento<T>* h = _primeiro;
        if (h == nullptr) {
            _primeiro = new Elemento<T>(dado);
        } else {
            while (h->proximo != nullptr) {
                h = h->proximo;
            }
            Elemento<T>* x = new Elemento<T>(dado);
            h->proximo = x;
        }
        _tamanho += 1;
    }

    T removerDoInicio() {
        if (_primeiro == nullptr) {
            throw runtime_error("Fila vazia");
        }
        Elemento<T>* h = _primeiro;
        T dado = h->dado;
        _primeiro = h->proximo;
        delete h;
        _tamanho -= 1;
        return dado;
    }

    bool vazia() const {
        return _tamanho == 0;
    }

    size_t tamanho() const {
        return _tamanho;
    }
};

int main() {
    Queue<int> q;
    
    cout << "Insert at the end: 10, 20, 30" << endl;
    q.inserirNoFim(10);
    q.inserirNoFim(20);
    q.inserirNoFim(30);

    cout << "Size queue: " << q.tamanho() << endl;

    cout << "Remove from the start: " << q.removerDoInicio() << endl;
    cout << "Remove from the start: " << q.removerDoInicio() << endl;

    cout << "Insert 40" << endl;
    q.inserirNoFim(40);
    
    cout << "Remove every element" << endl;
    while (!q.vazia()) {
        cout << "Remove: " << q.removerDoInicio() << endl;
    }

    return 0;
}
