#include <bits/stdc++.h>

using namespace std;

bool prime(int n)
{
	if(n <= 2) { return true; } else if(n%2 == 0) { 
		return false;
	} else {
		for (int i = 3; i < n; i = i + 2) {
			if(n%i == 0) { return false; }
		}
	} return true;
}

int main()
{
	int n;
	cout <<"\nSize of array: "; cin >> n;

	cout <<"\nValues into array: ";
	int *a = new int[n];
	for (int i = 0; i < n; ++i) { cin >> a[i]; }

	std::vector<int> p, c;

	for (int i = 0; i < n; ++i)
	{
		if(prime(a[i])) {
			p.push_back(a[i]);
		} else {
			c.push_back(a[i]);
		}
	}

	sort(p.begin(), p.end());
	sort(c.begin(), c.end());

	int x = 0;
	for (auto i = c.rbegin(); i != c.rend(); ++i, ++x) { a[x] = *i; } c.clear();
	for (auto i = p.begin(); i != p.end(); ++i, ++x) { a[x] = *i; } p.clear();

	cout <<"\nArray sorted - factors is:";
	for (int i = 0; i < x; ++i) {
		cout <<" "<< a[i];
	} cout << endl;

	cout << endl;
	return 0;
}