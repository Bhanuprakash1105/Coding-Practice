#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cout <<"\nArray size: ";
	cin >> n;

	int *a = new int[n];
	cout <<"\nValues of array: ";
	for (int i = 0; i < n; ++i)
	{ cin >> a[i]; }

	int i, j, t;
	for( i = j = 0; i < n && j < n;) {
		if( a[i] == 0 && a[j] != 0 ) {
			t = a[i]; a[i] = a[j]; a[j] = t;
			i++;
		} else if ( a[i] != 0 ) { i++; } else { j++; }
	}

	cout <<"\nResult Array is: ";
	for (int i = 0; i < n; ++i)
	{ cout <<" "<< a[i]; }
	
	cout << endl << endl;
	return 0;
}