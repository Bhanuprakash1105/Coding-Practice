#include <bits/stdc++.h>

using namespace std;

int main()
{
	int na, nb;
	
	cout <<"\nSize of array1: "; cin >> na;
	int *a = new int[na];
	cout <<"\nValues into array1: ";
	for (int i = 0; i < na; ++i) { cin >> a[i]; }

	cout <<"\nSize of array2: "; cin >> nb;
	int *b = new int[nb];
	cout <<"\nValues into array2: ";
	for (int i = 0; i < nb; ++i) { cin >> b[i]; }

	unordered_map<int, int> m;
	map<int, int> rem;
	
	for (int i = 0; i < nb; ++i) { m[b[i]] = -1; }
	
	for (int i = 0; i < na; ++i) {

		if(m[a[i]] == -1) { m[a[i]] = 1; }
		
		else if(m[a[i]] == 0) { m.erase(a[i]); rem[a[i]] += 1; }

		else { m[a[i]] += 1; }
	
	}

	int x = 0;
	for (int i = 0; i < nb; i++) {
		int temp = m[b[i]];
		for (int j = 0; j < temp; ++j) {
			a[x] = b[i], x++;
		}
	}

	for(auto trav = rem.begin(); trav != rem.end(); ++trav) {
		for (int i = 0; i < trav->second; ++i) {
			a[x] = trav->first, x++;
		}
	}

	cout <<"\nArr1 after sorting w.r.t Arr2: ";
	for (int i = 0; i < na; ++i) {
		cout << a[i] <<" ";
	} cout << endl;

	cout << endl;
	return 0;
}