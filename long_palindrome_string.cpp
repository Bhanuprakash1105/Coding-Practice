#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

int main(int argc, char const *argv[])
{
	string s; cout <<"\nEnter a string: "; cin >> s;

	unordered_map <char, li> m;
	for (char c: s) { m[c] += 1; }

	string r = "";
	for(char c: s) {
		if(!(m[c] & 1) && m[c] != 0) {
			r += c;
			m[c] /= 2;
		}
		if(m[c] > 2) {
			r += c;
			m[c] -= 2;
		}
	}

	li x = 1;
	if(2*(r.length()) - s.length() != 0) {
		for(char c: s) {
			if(m[c] & 1) { r += c; break; }
		}
		x = 2;
	}

	for(li i = r.length() - x; i >= 0; --i) { r += r[i]; }

	cout <<"\nLength of the longest palindrome string, made from the string ("<< s <<") is = "<< r.length() << endl;

	cout <<"\nOne among the all possible answers is -> "<< r << endl;

	cout << endl;
	return 0;
}