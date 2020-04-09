#include <bits/stdc++.h>

using namespace std;

int solution(int *a, int n)
{
	int *r = new int[n];
	for (int i = 0; i < n; ++i) { r[i] = 1; }

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if(a[j] < a[i]) { r[i] = max(r[i], r[j] + 1); }	
		}
	}

	int max = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		if(r[i] > max) { max = r[i]; }
	}

	return max;
}

int main()
{
	int n;
	cout <<"\nEnter the size: ";
	cin >> n;

	int *a = new int[n];
	cout <<"\nEnter the elements: ";
	for (int i = 0; i < n; ++i)
	{ cin >> a[i]; }

	int r = solution(a, n);

	cout <<"\nThe result is: "<< r << endl;

	cout << endl;
	return 0;
}