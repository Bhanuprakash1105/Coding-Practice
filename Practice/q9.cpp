#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cout <<"\nSize of array: ";
	cin >> n;

	cout <<"\nValues into array (sorted): ";
	int *a = new int[n];
	for (int i = 0; i < n; ++i) { cin >> a[i]; }

	sort(a, a+n);

	cout <<"\nThe sorted array: ";
	for (int i = 0; i < n; ++i) { cout <<" "<< a[i]; }
	cout << endl;

	int sum;
	cout <<"\nEnter the required sum: ";
	cin >> sum;

	bool flag = false;
	int x = 0, y = n-1;
	while (x <= y) {
		if( a[x] + a[y] == sum ) { flag = true; break; }
		else if ( a[x] + a[y] > sum ) { y--; }
		else { x++; }
	}

	if(flag) {
		cout <<"\nThe sorted array index are: ("<< x <<","<< y <<")"<< endl;
		cout <<"\nThe values are: ("<< a[x] <<","<< a[y] <<")"<< endl;
	} else { cout <<"\nResult:- failure"<< endl; }

	cout << endl;
	return 0;
}