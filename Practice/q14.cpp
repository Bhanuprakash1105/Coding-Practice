#include <iostream>
#include <numeric>

using namespace std;

int main()
{
	int n;
	cout <<"\nSize of array: ";
	cin >> n;

	int *a = new int[n];
	cout <<"\nValues into array: ";
	for (int i = 0; i < n; ++i) { cin >> a[i]; }

	int r = (n*(n + 1)/2) - accumulate(a, a+n, 0);
	cout <<"\nThe missing number is: "<< r << endl;

	cout << endl;
	return 0;
}