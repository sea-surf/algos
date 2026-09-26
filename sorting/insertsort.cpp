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
			// inspeciona os elementos da esquerda de v[i]
			v[k+1] = v[k]; // passa o elemento maior +1 posicao para a direita
			k--; // decrementa k para inspecionar o elemento anterior
		}
		v[k+1] = vtemp; // se v[k] <= vtemp - v: v[k], v[k+1] (vtemp), elementos maiores que vtemp, ..., v[n-1]
	}
}

int main()
{
	std::vector<int> v = {4,3,1,5,2};
	insertSort(v, v.size());
	for (auto vv : v) cout << vv << " ";
	return 0;
}
