#include <iostream>
#include <map>

using namespace std;

typedef unsigned long long int uli;

uli factorial(uli n) { if(n == 0) { return 1; } else { return factorial(n-1)*n; } }

int main()
{
	string s;
	cout <<"\nEnter a string: ";
	cin >> s;

	std::map<char, uli> m;
	for (uli i = 0; i < s.length(); ++i) { m[s[i]] += 1; }

	uli repeated = 1;
	for (auto i = m.begin(); i != m.end(); ++i) {
		if(i->second > 1) {
			repeated = repeated*factorial(i->second);
		}
	}
	uli r = factorial(s.length())/repeated;
	cout <<"\nNo.of distinct permuatutions = "<< r << endl;

	cout << endl;
	return 0;
}