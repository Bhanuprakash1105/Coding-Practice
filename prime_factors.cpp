#include "iostream"
#include "vector"
#include "cmath"
using namespace std;
typedef long long int li;

vector<li> primeFactors(li n)
{
	std::vector<li> v;
	li s = (li)sqrt(n);
	if(n%2 == 0) {
		while(n%2 == 0 /*&& n > 0*/) {
			n = n/2;
			v.push_back(2);
		}
	}
	if(n > 1) {
		for (li i = 3; i <= s; i += 2) {
			while(n%i == 0 /*&& n > 0*/) {
				n = n/i; v.push_back(i);
			}
		}
	}

	if(n > 1) { v.push_back(n); }

	return v;
}

int main()
{
	li n;
	cout <<"\nEnter a number: "; cin >> n;
	
	std::vector<li> v = primeFactors(n);
	cout <<"\nThe prime factors are: ";
	for(auto itr = v.begin(); itr != v.end(); ++itr) {
		cout << *itr <<" ";
	} cout << endl;
	v.clear();

	cout << endl;
	return 0;
}