#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int uli;

uli *a;

uli facotrial(uli n, uli i)
{
	if(n == 0) { 
		a[i] = 1;
		return a[i];
	} else{
		uli temp = facotrial(n-1, i-1);
		a[i] = n*temp;
	}
}

int main()
{
	uli n;
	cout <<"\nEnter the upper limit: ";
	cin >> n;

	a = new uli[n];

	facotrial(n, n-1);

	cout <<"\nFactorial array: ";
	for (int i = 0; i < n; ++i) { cout << a[i] <<" "; }
	cout << endl;

	cout << endl;
	return 0;
}