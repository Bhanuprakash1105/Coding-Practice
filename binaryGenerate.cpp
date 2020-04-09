#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void generate(int n) {

	int s = log(n)/log(2);

	cout << endl;
	for (int i = 0; i <= n; ++i)
	{
		cout << "--> "<< i <<" = ";
		for (int j = s; j >= 0; --j)
		{
			if(i & (1 << j)) { cout << 1; } else { cout << 0; }
		}
		cout << endl;
	}
}

int main()
{
	int n;
	cout <<"\nEnter the number: ";
	cin >> n;

	generate(n);

	cout << endl;
	return 0;
}
