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
class Stack {
private:
    Elemento<T>* _primeiro;
    size_t _tamanho;

public:
    Stack() : _primeiro(nullptr), _tamanho(0) {}

    ~Stack() {
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

    T removerDoFim() {
        if (_primeiro == nullptr) {
            throw runtime_error("Pilha vazia");
        }
        if (_tamanho == 1) {
            T dado = _primeiro->dado;
            delete _primeiro;
            _primeiro = nullptr;
            _tamanho -= 1;
            return dado;
        }

        Elemento<T>* h = _primeiro;
        while(h->proximo->proximo != nullptr) {
            h = h->proximo;
        }
        T dado = h->proximo->dado;
        delete h->proximo;
        h->proximo = nullptr;
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
    Stack<int> s;
    
    cout << "Insert 10, 20, 30 on the stack" << endl;
    s.inserirNoFim(10);
    s.inserirNoFim(20);
    s.inserirNoFim(30);

    cout << "Size of the stack: " << s.tamanho() << endl;

    cout << "Remove from the end: " << s.removerDoFim() << endl;
    cout << "Remove from the end: " << s.removerDoFim() << endl;

    cout << "Insert 40" << endl;
    s.inserirNoFim(40);
    
    cout << "Remove every element:" << endl;
    while (!s.vazia()) {
        cout << "Remove: " << s.removerDoFim() << endl;
    }

    return 0;
}
