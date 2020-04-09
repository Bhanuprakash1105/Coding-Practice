#include <iostream>
#include <algorithm>

using namespace std;

int *b;

bool check_ascending(int *a, int f, int l)
{
	for (int i = f; i <= l; ++i)
	{
		if(b[i] != a[i]) { return false; }
	}
	return true;
}

int find_sub_array_len(int *a, int n)
{
	int end, start;

	for (int i = 0; i < n; ++i) {
		end = i;
		if(check_ascending(a, i+1, n-1)) { break; }
	}

	for (int i = end; i >= 0; --i) {
		start = i;
		if(check_ascending(a, 0, i-1)) { break; }
	}

	return (end - start + 1);
}

int main()
{
	int n;
	cout <<"\nSize of array: "; cin >> n;

	b = new int[n];
	
	int *a = new int[n];

	cout <<"\nValues of array: ";
	for (int i = 0; i < n; ++i) { cin >> a[i]; b[i] = a[i]; }

	sort(b, b+n);

	int r = find_sub_array_len(a, n);

	cout <<"\nThe output is: "<< r << endl;

	cout << endl;
	return 0;
}