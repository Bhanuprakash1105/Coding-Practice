#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	cout<<"\nSize of array: ";
	cin >> n;

	int *a = new int[n];
	
	unordered_map <int, int> m;
	vector<int> v;

	cout <<"\nValue into array: ";
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		m[a[i]] += 1;
	}

	cout <<"\nValue of k: ";
	cin >> k;

	for (unordered_map<int, int>::iterator i = m.begin(); i != m.end(); ++i)
	{
		if(i->second >= k) { v.push_back(i->first); }
	}

	cout <<"\nThe output array is: ";
	for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
	{
		cout << *i <<" ";
	}

	cout << endl << endl;
	return 0;
}