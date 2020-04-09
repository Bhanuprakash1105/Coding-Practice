#include <bits/stdc++.h>

using namespace std;

int** generateBinary(int n)
{
	int s = pow(2, n);
	int **t = new int*[s];
	for (int i = 0; i < s; ++i)
	{
		t[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			if(i & (1 << j)) { t[i][j] = 1; } else { t[i][j] = 0; }
		}
	}
	return t;
}

set<string> powerSet(int **b, char a[], int n)
{
	set<string> s;
	for (int i = 0; i < pow(2, n); ++i)
	{
		string temp = "";
		for (int j = 0; j < n; ++j)
		{
			if(b[i][j] == 1) { temp = temp + a[j]; }
		}
		s.insert(temp);
	}
	return s;
}

int main()
{
	int n;
	cout <<"\nEnter the size of set: ";
	cin >> n;

	char *a = new char[n];
	cout <<"\nEnter the elements of set: ";
	for (int i = 0; i < n; ++i) { cin >> a[i]; }

	int **b = generateBinary(n);

	set<string> s = powerSet(b, a, n);
	cout <<"\nThe powerSet of the given set is:\n";
	for (set<string>::iterator trav = s.begin(); trav != s.end(); ++trav) { cout <<"--> "<< *trav << endl; }

	cout << endl;
	return 0;
}