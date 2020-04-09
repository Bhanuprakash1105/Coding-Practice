#include <bits/stdc++.h>

using namespace std;

typedef long long int li; 

auto give_common(auto a, auto b)
{
	unordered_set <li> s;
	
	for(li i = 0, j = 0; i < a.size() && j < b.size(); )
	{
		if(a[i] < b[j]) { ++i; } else if(a[i] > b[j]) { ++j; } else {
			
			s.insert(a[i]); /*s.insert(b[j]);*/ ++i; ++j;
		}
	}
	return s;
}

int main(int argc, char const *argv[])
{
	li n;

	cout <<"\nSize of array1: "; cin >> n;
	std::vector<li> a(n);
	cout <<"\nElements of array1: "; for(auto i = 0; i < a.size(); ++i) { cin >> a[i]; }

	cout <<"\nSize of array2: "; cin >> n;
	std::vector<li> b(n);
	cout <<"\nElements of array2: "; for(auto i = 0; i < b.size(); ++i) { cin >> b[i]; }

	sort(a.begin(), a.end()); sort(b.begin(), b.end());

	auto common = give_common(a, b);

	if(common.size()) {
		cout <<"\nCommon elements: "; for(auto x: common) { cout << x <<" "; } cout << endl;
	} else {
		cout <<"\nNo common elements"<< endl;
	}

	cout << endl;
	return 0;
}