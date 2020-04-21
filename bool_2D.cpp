#include <iostream>
using namespace std;

int main()
{
	int r, c;
	cout <<"\nNo.of the rows and columns: ";
	cin >> r >> c;

	bool **b = new bool*[r];
	cout <<"\n\tValues into bool matrix"<< endl;
	for (int i = 0; i < r; ++i)
	{
		b[i] = new bool[c];
		for (int j = 0; j < c; ++j)
		{
			cout <<"\nb["<< i+1 <<"]"<<"["<< j+1 <<"] = ";
			cin >> b[i][j];
		}
		cout << endl;
	}

	cout <<"\n The bool matrix\n "<< endl;
	for (int i = 0; i < r; ++i) {
		cout <<"  ";
		for (int j = 0; j < c; ++j) { cout << b[i][j] <<"  "; }
		cout << endl;
	}

	cout << endl;
	return 0;
}
