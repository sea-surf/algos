#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <utility>

using namespace std;

void selectionSort(vector<int> &v, int n)
{
	int min;
	for (int i=0; i < n; i++)
	{
		min = i;
		for (int j=i+1; j < n; j++)
		{
			if(v[j] < v[min])
			{
				min = j;
			}
		}
		swap(v[min], v[i]);
	}
	
}

int main()
{
	std::vector<int> v = {4,3,1,5,2};
	selectionSort(v, 5);
	for (auto vv : v) cout << vv << " ";
	return 0;
}
