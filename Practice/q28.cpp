#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int index_value(int *a, int start, int end)
{
	if(start == end) {
		if(a[start] == start) { return end; } else { return -1; }
	}

	int m = (start + end)/2;
	int vm = a[m];

	if(vm >= m) { index_value(a, start, m); } else { index_value(a, m+1, end); }
}

int main()
{
	int n, x;
	cout <<"\nSize of array: "; cin >> n;
	int *a = new int[n];

	cout <<"\nValues of array sorted: ";
	for (int i = 0; i < n; ++i) { cin >> a[i]; }

	//sort(a, a+n);
	set <int> s;
	for (int i = 0; i < n; ++i)
	{ s.insert(a[i]); }

	cout <<"\nSorted and unique element array: "; x = 0;
	for (auto i = s.begin(); i != s.end(); ++i, ++x) {
		a[x] = *i;
		cout << a[x] <<" ";
	} cout << endl;

	int r = index_value(a, 0, x-1);

	cout <<"\nThe output is: "<< r << endl;

	cout << endl;
	return 0;
}