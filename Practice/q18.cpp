#include <iostream>
#include <cmath>

using namespace std;

int** snail(int **m, int n)
{
	int a, b, i = 0, j = 0, x = 1;
	for (a = 0, b = n-1; a <= b, b > 0; a += 1, b -= 1)
	{
		i = a;
		for(j = a; j <= b; j++) { m[i][j] = x; x++; }

		j = b;
		for(i = a+1; i <= b; i++) { m[i][j] = x; x++; }

		i = b;
		for(j = b-1; j >= a; j--) { m[i][j] = x; x++; }

		j = a;
		for(i = b-1; i > a; i--) { m[i][j] = x; x++; }
	}
	return m;
}

int main()
{
	int n;
	cout <<"\nEnter the +ve integer: ";
	cin >> n;

	int **a = new int*[n];
	for (int i = 0; i < n; ++i) { a[i] = new int[n]; }

	a = snail(a, n);

	cout << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << a[i][j] <<"  ";
		}
		cout << endl;
	}

	cout << endl;
	return 0;
}