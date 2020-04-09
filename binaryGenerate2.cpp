#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b;
	cout <<"\nEnter the lower and upper limits: ";
	cin >> a >> b;
	int s = log(b)/log(2);
	for (int i = a; i <= b; ++i)
	{
		cout <<"\n--> " << i <<" = ";
		for (int j = s; j >= 0; --j)
		{
			if(i & (1 << j)) { cout << 1; } else { cout << 0; }
		}
	}

	cout << endl << endl;
	return 0;
}