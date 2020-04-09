#include <iostream>
#include <cmath>
#include <set>

using namespace std;

int main()
{
	string s, temp;
	cout <<"\nEnter a string: "; cin >> s;

	set <string> set;

	int n = s.length(), p = pow(2, n);
	for (int i = 0; i < p; ++i)
	{
		temp = "";
		for (int j = 0; j < n; ++j)
		{
			if(i & 1 << j) { temp = temp + s[j]; }
		}
		set.insert(temp);
	}

	cout <<"\nThe distinct sub-strings are: "<< endl; int count = 0;
	for (auto i = set.begin(); i != set.end(); ++i)
	{
		cout <<"--> "<< *i << endl;
		count++;
	}

	cout <<"\nTotal no.of distinct sub-strings equal = "<< count << endl;

	cout << endl;
	return 0;
}