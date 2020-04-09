//Question: https://www.geeksforgeeks.org/maximum-product-of-4-adjacent-elements-in-matrix/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int r, c;
	cout <<"\nEnter the size of matrix row (>= 4) and column (>= 4) : ";
	cin >> r >> c;

	cout <<"\nEnter the elements into matrix"<< endl;
	int **a = new int*[r];
	for (int i = 0; i < r; ++i) {
		a[i] = new int[c];
		for (int j = 0; j < c; ++j) {
			cout <<"\na[" << i+1 <<"]["<< j+1 <<"] = "; cin >> a[i][j];
		}
		cout << endl;
	}

	cout <<"\nThe matrix\n"<< endl;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cout <<"  "<< a[i][j];
		}
		cout << endl;
	}

	int maxr = 1, maxc = 1, i, j, x, prod;
	std::vector<int> v;
	int *arR = new int[r*c];
	int *arC = new int[r*c];

	x = 0;
	for (i = 0; i < r; ++i) {
		for (j = 0; j < c; ++j) { arR[x] = a[i][j]; x++; }
	}
	x = 0;
	for (i = 0; i < c; ++i) {
		for (j = 0; j < r; ++j) { arC[x] = a[j][i]; x++; }
	}

	for (i = 0; i < 4; ++i) { v.push_back(arR[i]); maxr *= arR[i]; }
	for (i = 4; i < r*c; ++i) {
		auto trav = v.begin();
		v.erase(trav); v.push_back(arR[i]);
		prod = 1;
		for (auto itr = v.begin(); itr != v.end(); ++itr) { prod *= *itr; }
		if(maxr < prod) { maxr = prod; }
	}

	cout <<"\nThe output of rows is: "<< maxr << endl;

	v.clear();

	for (i = 0; i < 4; ++i) { v.push_back(arC[i]); maxc *= arC[i]; }
	for (i = 4; i < r*c; ++i) {
		auto trav = v.begin();
		v.erase(trav); v.push_back(arC[i]);
		prod = 1;
		for (auto itr = v.begin(); itr != v.end(); ++itr) { prod *= *itr; }
		if(maxc < prod) { maxc = prod; }
	}

	cout <<"\nThe output of columns is: "<< maxc << endl;

	cout <<"\nThe output is: "<< max(maxr, maxc) << endl;

	cout << endl;
	return 0;
}