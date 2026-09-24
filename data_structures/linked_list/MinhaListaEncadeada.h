#ifndef DEC0006_MINHA_LISTA_ENCADEADA_H
#define DEC0006_MINHA_LISTA_ENCADEADA_H

#include <cstddef>
// std::size_t

#include "Elemento.h"
// Elemento
#include "ListaEncadeadaAbstrata.h"
#include "excecoes.h"
// ExcecaoDadoInexistente
// ExcecaoListaEncadeadaVazia
// ExcecaoNaoImplementado
// ExcecaoPosicaoInvalida

/**
 * @brief Uma lista encadeada de dados.
 * 
 * @tparam T O tipo dos dados armazenados na lista.
 */
template<typename T>
class MinhaListaEncadeada: public ListaEncadeadaAbstrata<T>
{
    /**
     * @brief Destrutor. Destroi todos os elementos da lista
     */
    virtual ~MinhaListaEncadeada(){
        Elemento<T>* h = this->_primeiro; // head
        while(h != nullptr) // deletar todos os nodos
        {
            Elemento<T>* next = h->proximo;
            delete h;
            this->_tamanho--;
            h = next;
        }
        this->_primeiro = nullptr; // head = nullptr
        this->_tamanho = 0; // size = 0
    }

    /**
     * @brief Obtém a quantidade de itens na lista.
     * 
     * @return Um inteiro maior ou igual a 0.
     */
    virtual std::size_t tamanho() const
    {
        return this->_tamanho;
    };
    
    /**
     * @brief Indica se há algum item na lista ou não.
     * 
     * @return false se houver algum item na lista; true caso contrário.
     */
    virtual bool vazia() const 
    {
        if (this->_tamanho == 0)
        {
            return true;
        }
        else 
        {
            return false;
        }
        return 0;
    };

    /**
     * @brief Obtém a posição de um item na lista. Lança
     * ExcecaoListaEncadeadaVazia caso a lista esteja vazia ou
     * ExcecaoDadoInexistente caso o item não esteja contido na lista.
     * 
     * @param dado O item cuja posição deseja-se obter.
     * @return Um inteiro na faixa [0, tamanho); se houver mais que um mesmo
     * item na lista, a posição da primeira ocorrência.
     */
    virtual std::size_t posicao(T dado) const 
    {
        
        if (vazia())
        {
            throw ExcecaoListaEncadeadaVazia();
        }
        
        // Loop para procurar a posicao do nodo->dado == dado
        Elemento<T>* head = this->_primeiro;
        for (size_t i = 0; i < this->_tamanho && head != nullptr; i++){
            if (head->dado == dado){
                return i;
            }
            head = head->proximo;
        }
        
        throw ExcecaoDadoInexistente();
    };
    
    /**
     * @brief Indica se um dado item está contido na lista ou não.
     * 
     * @param dado O item sendo buscado.
     * @return true se o item está contido na lista; false caso contrário.
     */
    virtual bool contem(T dado) const
    {
        Elemento<T>* head = this->_primeiro;
        for (size_t i = 0; i < this->_tamanho && head != nullptr; i++){
            if (head->dado == dado){
                return true;
            }
            head = head->proximo;
        }
        
        return false;
        
    };

    /**
     * @brief Insere um item no início da lista.
     * 
     * @param dado O item sendo inserido.
     */
    virtual void inserirNoInicio(T dado) 
    {
        Elemento<T>* x = new Elemento<T>(dado); // x é nó criado com o dado
        x->proximo = this->_primeiro; //x->next = head
        this->_primeiro = x; // head = x
        this->_tamanho += 1; // incrementa o tamanho da lista
    };

    /**
     * @brief Insere um item em uma posição específica da lista. Lança
     * ExcecaoPosicaoInvalida caso a posição não esteja na faixa
     * [0, tamanho].
     * 
     * @param posicao Um inteiro dentro da faixa [0, tamanho]. Ao se inserir em
     * uma posição já ocupada, a posição do item que já estava naquela posição
     * será posicao + 1; inserir-se na posicao tamanho significa inserir-se no
     * fim da lista.
     * @param dado O item sendo inserido.
     */
    virtual void inserir(std::size_t posicao, T dado)
    {
        
        // Checa out of boundary
        if (posicao < 0 || posicao > this->_tamanho) //v[0...n-1]
        {
            throw ExcecaoPosicaoInvalida();
        }
        
        // Inserir no inicio (elemento = head) 
        if (posicao == 0)
        {
            inserirNoInicio(dado);
            return; 
        }
        
        // Inserir no meio
        // z -> x -> y
        // z [posicao-1] -> y [posicao+1] | z->proximo = y
        // x->proximo = z->proximo (y) && z->proximo = x
        
        Elemento<T>* z = this->_primeiro;
        for (int i = 0; i < posicao - 1; i++) // stop: ?[pos-2]-> z[pos-1] = z 
        {
            z = z->proximo;
        }
        
        Elemento<T>* x = new Elemento<T>(dado);
        x->proximo = z->proximo;
        z->proximo = x;
        
        this->_tamanho += 1;
    };


    /**
     * @brief Insere um item no fim da lista.
     * 
     * @param dado O item sendo inserido.
     */
    virtual void inserirNoFim(T dado)
    {
        // h -> nullptr
        // h -> x
        Elemento<T>* h = this->_primeiro;
        if (h == nullptr)
        {
            inserirNoInicio(dado);
            return;
        }
        while (h->proximo != nullptr)
        {
            h = h->proximo;
        }
        Elemento<T>* x = new Elemento<T>(dado);
        h->proximo = x;
        x->proximo = nullptr;
        
        this->_tamanho += 1;
    };

    /**
     * @brief Remove o primeiro item da lista. Lança ExcecaoListaEncadeadaVazia
     * caso não haja nenhum item na lista.
     * 
     * @return O item removido.
     */
    virtual T removerDoInicio()
    {
        
        Elemento<T>* h = this->_primeiro;
        
        if (h == nullptr) // head = null  lista vazia ou this->_tamanho == 0
        {
            throw ExcecaoListaEncadeadaVazia();
        }
        
        T dado = (*h).dado; // armazenar dado do nodo
        
        this->_primeiro = h->proximo; // h -> ? (head) -> ...
        
        delete h;                     // ? (head) -> ...
        
        this->_tamanho -= 1;
        
        return dado;
    };

    /**
     * @brief Remove um item de uma posição específica da lista. Lança
     * ExcecaoPosicaoInvalida caso a posição não esteja na faixa [0, tamanho).
     * 
     * @param posicao Um inteiro dentro da faixa [0, tamanho).
     * @return O item removido.
     */
    virtual T removerDe(std::size_t posicao)
    {
        if (posicao < 0 || posicao >= this->_tamanho){
            throw ExcecaoPosicaoInvalida();
        }
        
        if (vazia())
        {
            throw ExcecaoListaEncadeadaVazia();
        }
        
        if (posicao == 0)
        {
            return this->removerDoInicio();
        }
        
        Elemento<T>* x_prev = this->_primeiro;
        for (size_t i = 0; i < posicao - 1; i++)
        {
            x_prev = x_prev->proximo;
        }
        Elemento<T>* x = x_prev->proximo;
        if (x->proximo != nullptr){
            x_prev->proximo = x->proximo;
        }
        else {
            x_prev->proximo = nullptr;
        }
        
        T dado = x->dado;
        delete x;
        this->_tamanho--;
        
        return dado;
        
    };

    /**
     * @brief Remove o último item da lista. Lança ExcecaoListaEncadeadaVazia
     * caso não haja nenhum item na lista.
     * 
     * @return O item removido.
     */
    virtual T removerDoFim()
    {
        Elemento<T>* h = this->_primeiro;
        if (h == nullptr){
            throw ExcecaoListaEncadeadaVazia();
        }
        if (this->_tamanho == 1) {
            return this->removerDoInicio();
        }
        while(h->proximo->proximo != nullptr){ // h -> ? -> nullptr
            h = h->proximo;
        }
        T dado = (*h->proximo).dado; // dado do ultimo nodo
        delete h->proximo; // delete ?
        h->proximo = nullptr; // h -> nullptr
        this->_tamanho -= 1;
        
        return dado;
    };

    /**
     * @brief Remove um item específico da lista. Lança
     * ExcecaoListaEncadeadaVazia caso não haja nenhum item na lista ou
     * ExcecaoDadoInexistente caso o item não esteja contido na lista.
     * 
     * @param dado O item a ser removido. Se houver mais que um item com
     * o mesmo valor, remove a primeira ocorrência.
     */
    virtual void remover(T dado)
    {
        if (this->_primeiro == nullptr){
            throw ExcecaoListaEncadeadaVazia();
        }

        if (this->_primeiro->dado == dado) {
            this->removerDoInicio();
            return;
        }

        Elemento<T>* z = this->_primeiro;
        Elemento<T>* x = this->_primeiro->proximo; // z -> x -> y

        while (x != nullptr && x->dado != dado) {
            z = x;             // z = x
            x = x->proximo;    // x = y
        }

        if (x == nullptr) { // nao existe
            throw ExcecaoDadoInexistente();
        }

        z->proximo = x->proximo; // update z -> y
        
        delete x; // x != nullptr, delete x
        this->_tamanho -= 1;
    };
};

#endif