#include <iostream>
#include <vector>

using namespace std;

std::vector<int> v;

/* This minimum function assumes that a[i+1][j] != a[i+1][j+1] */
int minimum(int **a, int i, int j)
{
	if(a[i+1][j] < a[i+1][j+1]) { return j; }
	else if (a[i+1][j] > a[i+1][j+1]) { return j+1; }
	else {
		cout <<"\nERROR: The adjacent values in row "<< i+1 <<" are eqaul\n"<< endl;
		exit(0);
	}
}

int calculate_minimum(int **a, int n)
{
	int sum = a[0][0], temp, j = 0;
	
	v.push_back(a[0][0]);
	
	for (int i = 0; i < n-1; ++i)
	{
		j = minimum(a, i, j);
		temp = a[i+1][j];
		sum += temp;
		v.push_back(temp);
	}
	return sum;
}

int main()
{
	int n;
	cout <<"\nNo.of values in base of triangle: "; cin >> n;

	int **a = new int*[n];
	/* The adjacent values in a row should not be equal */
	for (int i = 0; i < n; ++i) {
		a[i] = new int[i+1];
		cout <<"\nRow "<< i+1 <<" values: ";
		for (int j = 0; j < i+1; ++j) {
			cin >> a[i][j];
		}
	}

	cout <<"\n\n\tTRIANGLE\n"<< endl;
	for (int i = 0; i < n; ++i) {
		for (int s = n-i-1; s > 0; --s) {
			cout <<" ";
		}
		for (int j = 0; j < i+1; ++j) {
			cout << a[i][j] <<" ";
		}
		cout << endl;
	}

	int r = calculate_minimum(a, n);

	cout <<"\nThe minimum sum result is: "<< r << endl;

	cout <<"\nThe path from apex to base of triangle is: ";
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
	{ cout << *i <<" "; } cout << endl;

	cout << endl;
	return 0;
}