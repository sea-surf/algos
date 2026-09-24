#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <utility>

using namespace std;

int partition(vector<int> &v, int p, int r)
{
	int x = v[r];
	int i = p-1;
	for(int j = p; j < r; j++)
	{
		if (v[j] <= x)
		{
			i = i+1;
			swap(v[i], v[j]);
		}
	}
	swap(v[i+1], v[r]);
	return i+1;
}

void quicksort(vector<int> &v, int p, int r)
{
	if (p < r)
	{
		int q = partition(v,p,r); // O(n)
		quicksort(v, p, q-1);     // T(n/2)
		quicksort(v, q+1, r);     // T(n/2)
	}
}

int main()
{
	std::vector<int> v = {16,14,10,8,7,9,3,2,4,1};
	quicksort(v, 0, v.size()-1);
	for (auto vv : v) cout << vv << " ";
	return 0;
}

/*
 * O(nlog(n))
 * p = index of v[0] = 0
 * r = index of v[n-1] = v.size()-1
 * It always swaps a lesser element than the pivot to the left and increment i
 * Checks every element for this O(n)
 * In the end, swaps the v[i+1] with the pivot, the index of the pivot is now i+1
 * Do this recursively for the subvectors until the full vector is sorted
 * The operation swap inside the algorithm is reponsible for sorting the vector
*/
