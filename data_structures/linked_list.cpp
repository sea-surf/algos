#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <utility>
#include <stdexcept>

using namespace std;

template<typename T>
struct Node {
    T key; // data / key inside the node (int = 1, string="Soren")
    Node<T>* next;
    Node<T>* prev;
    
    Node(T k) : key(k), next(nullptr), prev(nullptr) {}
};

// Linked List 
template <typename T>
class List {
private:
    Node<T>* _head;
    size_t _size;

public:
    List() : _head(nullptr), _size(0) {} 

    ~List() {
        Node<T>* h = _head;
        while(h != nullptr) {
            Node<T>* next = h->next;
            delete h;
            h = next;
        }
    }

    // Insert: Starts the Linked List
    void list_insert(T k) {
        Node<T>* x = new Node<T>(k);
        x->next = _head;
        if (_head != nullptr) {
            _head->prev = x;
        }
        _head = x;
        _size++;
    }

    // Search
    Node<T>* list_search(T k) const {
        Node<T>* x = _head;
        while (x != nullptr && x->key != k) {
            x = x->next;
        }
        return x;
    }

    // Delete
    void list_delete(T k) {
        Node<T>* x = list_search(k);
        if (x != nullptr) {
            if (x->prev != nullptr) {
                x->prev->next = x->next;
            } else {
                _head = x->next;
            }
            
            if (x->next != nullptr) {
                x->next->prev = x->prev;
            }
            delete x;
            _size--;
        }
    }

    // Size
    size_t list_size() const {
        return _size;
    }

    // Print
    void print() const {
        Node<T>* x = _head;
        while (x != nullptr) {
            cout << x->key << " ";
            x = x->next;
        }
        cout << endl;
    }
};

// ------------------------------------------------

int main()
{
	List<int> l;

	l.list_insert(65);
	l.list_insert(32);
	l.list_insert(70);

    cout << "List 1 size: " << l.list_size() << endl;

    cout << "List 1: ";
    l.print();
    
    Node<int>* node_delete = l.list_search(32);
    if (node_delete != nullptr)
    {
		cout << "Deleted element with data-key: " << node_delete->key << endl;
        l.list_delete(32);
    } else {
		cout << "Node not found." << endl;
	}
    
    cout << "List 1: ";
    l.print();

	// ------------------------

	List<string> l2;

	l2.list_insert("Soren Kierkegaard");
	l2.list_insert("Aldous Huxley");
	l2.list_insert("Leo Tolstoy");
	l2.list_insert("Dostoyevsky");

	cout << "List 2 size: " << l2.list_size() << endl;

    cout << "List 2: ";
    l2.print();


	return 0;
}
/*
	Linked List - Unsorted Doubly Linked

	* List Search - O(n)
	  - Uses the key k (data inside the node) to find the node
	  - Iterates linearly through the list to find the node containing key 'k'.
	  - Returns a pointer to the node or nullptr if not found.

	* List Insert - O(1)
	  - Insert a new node to the front of the list, making it the new head.
	  - _head->next is never modified to not break the link
	    1. x->next points to the old head.
	    2. If the list is not empty (_head != nullptr), the old head->prev points to x.
	    3. The _head is updated to point to x.
	    4. x->prev points to nullptr (since it is now the first element).
	  
	    l2.list_insert("Lovecraft"); // Inserts "Lovecraft"
	    List state becomes: [Head] -> "Lovecraft" -> "Dostoyevsky" -> "Leo Tolstoy" -> "Aldous Huxley" -> "Soren Kierkegaard"

	* List Delete - O(1) assuming node is already known, but O(n) to find it by key
	  - Bypasses node 'x' by linking its previous and next nodes together.
	  - Time complexity is O(1) assuming the pointer to node 'x' is already known.
	  - Note: Since list_search is called first to find 'x' by key, the total time is O(n).

	Node
	
	* key / data:
	  - Holds the actual value (e.g., int = 1, string = "Soren").
	  - Example: Node<string>* x = new Node<string>("Soren");
	  - To return the data inside the node, dereference the pointer using 
	    either (*x).key or x->key.

	* Pointers:
	  - x->next: Stores the memory address of the next Node in the sequence.
	  - x->prev: Stores the memory address of the previous Node in the sequence.
*/