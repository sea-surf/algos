#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <utility>

using namespace std;

// Linked List 
template <typename Data>
struct List
{
	struct Node
	{
		Data key; // data / key inside the node (int = 1, string="Soren")
		Node *next;
		Node *prev;
		
		Node(Data k) : key(k), next(nullptr), prev(nullptr) {}
	};

	// First node element
	// (*head).key: data
	// head->next, head->prev: pointers
	Node *head; 
	List() : head(nullptr) {} 

	// Insert: Starts the Linked List
	void list_insert(Node* x)
	{
		x->next = head;
		if (head != nullptr)
		{
			head->prev = x;
		}
		head = x;
		x->prev = nullptr;
	}

	// Search
	Node* list_search(Data k) 
	{
		Node *x = head;
		while (x != nullptr && x->key != k)
		{
			x = x->next;
		}
		return x;
	}

	// Delete
	void list_delete(Node* x)
	{
		if (x->prev != nullptr)
		{
			x->prev->next = x->next;
		} 
		else
		{
			head = x->next;
		}
		
		if (x->next != nullptr)
		{
			x->next->prev = x->prev;
		}
	}

	// Size
	int list_size()
	{
		int count = 0;
		Node* x = head;
		
		while (x != nullptr)
		{
			count++;
			x = x->next;
		}
		return count;
	}
};
// --------------------------------------------

int main()
{
	List<int> l;

	List<int>::Node* n1 = new List<int>::Node(65);
	List<int>::Node* n2 = new List<int>::Node(32);
	List<int>::Node* n3 = new List<int>::Node(70);

	l.list_insert(n1);
	l.list_insert(n2);
	l.list_insert(n3);

    cout << "List 1 size: " << l.list_size() << endl;

    cout << "List 1: ";
    List<int>::Node* x = l.head;
    while (x != nullptr) 
    {
        cout << x->key << " ";
        x = x->next;
    }
    cout << endl;
    
    List<int>::Node* node_delete = l.list_search(32);
    if (node_delete != nullptr)
    {
		cout << "Deleted element with data-key: " << node_delete->key << endl;
        l.list_delete(node_delete);
        delete node_delete;
    } else{
		cout << "Node not found inside the linked list." << endl;
	}
    
    cout << "List 1: ";
    x = l.head;
    while (x != nullptr) 
    {
        cout << x->key << " ";
        x = x->next;
    }
    cout << endl;

	// ------------------------

	List<string> l2;

	List<string>::Node* n4 = new List<string>::Node("Soren Kierkegaard");
	List<string>::Node* n5 = new List<string>::Node("Aldous Huxley");
	List<string>::Node* n6 = new List<string>::Node("Leo Tolstoy");
	List<string>::Node* n7 = new List<string>::Node("Dostoyevsky");

	l2.list_insert(n4);
	l2.list_insert(n5);
	l2.list_insert(n6);
	l2.list_insert(n7);

	cout << "List 2 size: " << l2.list_size() << endl;

    cout << "List 2: ";
    List<string>::Node* x_2 = l2.head;
    while (x_2 != nullptr) 
    {
        cout <<  x_2->key << " ";
        x_2 = x_2->next;
    }
    cout << endl;


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
	  - L.head->next is never modified to not break the link
	    1. x->next points to the old head.
	    2. If the list is not empty (L.head != nullptr), the old head->prev points to x.
	    3. The L.head is updated to point to x.
	    4. x->prev points to nullptr (since it is now the first element).
	  
	    list_insert(l2, n6); // Inserts "Lovecraft"
	    List state becomes: [Head] -> "Lovecraft" -> "Aldous Huxley" -> "Soren"

	* List Delete - O(1)
	  - Bypasses node 'x' by linking its previous and next nodes together.
	  - Time complexity is O(1) assuming the pointer to node 'x' is already known.
	  - Note: If list_search must be called first to find 'x', the total time is O(n).

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