#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int* insert(int *c, int v, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if(abs(c[i]) < abs(v)) {
			int temp = v;
			v = c[i];
			c[i] = temp;
		}
	}
	return c;
}

int find_max_3_prod(int *a, int n)
{
	int prod = 1;
	
	int *neg = new int[2], *pos = new int[3];
	
	for (int i = 0; i < n; ++i)
	{
		neg[i] = 0; pos[i] = 0;

		if(a[i] >= 0) { pos = insert(pos, a[i], 3); }
		
		else { neg = insert(neg, a[i], 2); }
	}

	int i = 0, j = 0, count = 0;;
	while(count < 3) {
		
		if(pos[i] >= abs(neg[j])) { prod *= pos[i]; i++; }

		else { prod *= neg[j]; j++; }

		count++;
	}
	
	return prod;
}

int main()
{
	int n;
	cout <<"\nSize of array: "; cin >> n;

	int *a = new int[n];
	cout <<"\nValues of array: ";
	for (int i = 0; i < n; ++i) { cin >> a[i]; }

	int prod = find_max_3_prod(a, n);

	cout <<"\nThe maximum triplet product is: "<< prod << endl;

	cout << endl;
	return 0;
}