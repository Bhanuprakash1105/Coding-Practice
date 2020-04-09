#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	string pattern;
	cout <<"\nEnter a pattern with '{' and '}': "; cin >> pattern;

	stack <char> s;
	for (int i = 0; i < pattern.length(); ++i) {
		if(pattern[i] == '{') { s.push('{'); } else {
			if(!s.empty()) {
				if(pattern[i] == '}' && s.top() == '{') { s.pop(); } else {
					s.push('}');
				}
			} else {
				s.push('}');
			}
		}
	}

	char *c = new char[s.size()];
	vector<char> v;
	if(s.size()%2 != 0) { cout <<"\nCannot be balanced"<< endl; } else {
		while(!s.empty()) { v.insert(v.begin(), s.top()); s.pop(); }
		int min_flips = v.size()/2;
		int r = 0, l = 0;
		for(int i = 0; i < v.size(); i++) {
			if(v[i] == '}') { l++; } else { r++; }
		}
		if(max(l, r)%2 != 0) { min_flips++; }
		cout <<"\nThe minimum reversals to make the pattern balance = "<< min_flips << endl;  
	}

	cout << endl;
	return 0;
}