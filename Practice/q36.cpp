#include <bits/stdc++.h>

using namespace std;

int thePaths;

int print_paths(int**, int, int, int, int, int, int);

void printStack();

int main()
{
	int r, c;
	cout <<"\nSize of matrix (rows and columns): "; cin >> r >> c;

	cout <<"\nValues into array\n";
	int **a = new int*[r];
	for (int i = 0; i < r; ++i)
	{
		a[i] = new int[c];
		for (int j = 0; j < c; ++j) {
			cout <<"\na[" << i+1 << "][" << j+1 << "] = ";
			cin >> a[i][j];
		}
		cout << endl;
	}

	system("clear");

	cout <<"\nThe Matrix\n"<< endl;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) { cout <<" "<< a[i][j]; }
		cout << endl;
	}

	int k = 0;
	cout <<"\nEnter the value of k: "; cin >> k;

	thePaths = 0;
	print_paths(a, 0, 0, r, c, 0, k);
	cout <<"\nThe number of paths are: "<< thePaths/2 << endl;

	cout << endl;
	return 0;
}

stack <int> s;

int print_paths(int **a, int i, int j, int r, int c, int k, int n)
{
	if(j < c && i < r)
	{	
		k += a[i][j];
		
		s.push(a[i][j]);

		thePaths += print_paths(a, i, j+1, r, c, k, n);

		thePaths += print_paths(a, i+1, j, r, c, k, n);
		
		s.pop();

		k -= a[i][j];
	}

	if ( ( (i == r && j == c-1) || (i == r-1 && j == c) ) && (k == n) ) { 
		printStack();
		return 1;
	}
	
	return 0;
}

void printStack()
{
	
	std::vector<int> v;
	while (!s.empty()) {
		v.push_back(s.top());
		s.pop();
	}

	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i) { s.push(*i); }

	cout <<"\nThe path is: ";
	for (std::vector<int>::reverse_iterator i = v.rbegin(); i != v.rend(); ++i) {
		cout <<"-> "<< *i;
	}
	cout << endl;
}
