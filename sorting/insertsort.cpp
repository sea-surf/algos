#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <utility>

using namespace std;

void insertSort(vector<int> &v, int n)
{
	int vtemp, k;
	for (int i=1; i < n; i++)
	{
		vtemp = v[i];
		k = i-1;
		while(k >= 0 && v[k] > vtemp)
		{
			v[k+1] = v[k];
			k=k-1;
		}
		v[k+1] = vtemp;
	}
}

int main()
{
	std::vector<int> v = {4,3,1,5,2};
	insertSort(v, v.size());
	for (auto vv : v) cout << vv << " ";
	return 0;
}
