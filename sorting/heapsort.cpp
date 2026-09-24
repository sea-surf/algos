#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <utility>

using namespace std;

void heapify(vector<int> &v, int heap_size, int i)
{
	int left = 2*i + 1;
	int right = 2*i + 2;
	int max = i;
	if (left < heap_size && v[left] > v[max]) max = left;
	if (right < heap_size && v[right] > v[max]) max = right;
	if (max != i)
	{
		swap(v[i], v[max]);
		heapify(v, heap_size, max);
	}
}

void buildheap(vector<int> &v)
{
	for (int i = v.size()/2; i >= 0; i--)
	{
		heapify(v, v.size(), i);
	}
}

void heapsort(vector<int> &v)
{
	buildheap(v);
	int heap_size = v.size();
	for (int i = v.size() - 1; i > 0; i--)
	{
		swap(v[i], v[0]);        
		heap_size = heap_size - 1; 
		heapify(v, heap_size, 0);           
	}
}

int main()
{
	std::vector<int> v = {16,14,10,8,7,9,3,2,4,1};
	heapsort(v);
	for (auto vv : v) cout << vv << " ";
	return 0;
}

/* 

Heapify
	Maintains the max-heap property for a given node 'i' in a binary tree.
	The index positions of the vector follows line by line on the binary tree,
	so the left and right children of a parent node are different 
	than i+1 or i+2 (other parents).
	Left and Right are the childre v[2*i+1] and v[2*i+2]. 
	The max-heap property dictates that a parent node must be greater than 
	or equal to its children (located at v[2*i+1] and v[2*i+2] for 0-based indexing).
	It compares the parent with its children and, if a child is greater, 
	it swaps them. It then recursively calls itself to ensure the swapped 
	child node also maintains the max-heap property downwards.
	The 'heap_size' parameter is crucial here because during the sorting phase, 
	the "logical" size of the heap shrinks, preventing the algorithm from 
	modifying elements that are already sorted at the end of the vector.

Buildheap
	Constructs a heap binary tree out of an unsorted vector.
	It iterates from the middle of the array down to the root v[0].
	Only need to process the first half of the tree (parent nodes) because 
	the elements in the second half are leaf nodes. By definition, leaf nodes 
	have no children / no v[2i+1] or v[2i+2] and satisfy the heap property 
	on their own.

Heapsort
	1. Calls Buildheap to create the initial heap.
	2. The largest element is now at the root (v[0]). We swap it with the last 
	   element in the current logical heap.
	3. We decrement 'heap_size' to isolate this largest element at the end 
	   of the vector, effectively removing it from the heap so it remains sorted.
	4. Since the new root might violate the max-heap property, we call 
	   Heapify on index 0 to fix the tree and find the next largest element.
	5. This process repeats from v.size() - 1 down to 1. The loop naturally ends, 
	   leaving v[0] as the smallest element in its correct sorted position.
*/
