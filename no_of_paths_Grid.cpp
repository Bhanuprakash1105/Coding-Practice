//Question: https://www.geeksforgeeks.org/count-possible-paths-top-left-bottom-right-nxm-matrix/
#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long int uli;

uli no_of_paths(uli i, uli j, auto v, uli &r, uli &c)
{
	if( i >= r || j >= c || v[i][j] ) { return 0; }
	
	v[i][j] = true;

	if( i == r-1 && j == c-1 ) { return 1; }

	else { return no_of_paths(i+1, j, v, r, c) + no_of_paths(i, j+1, v, r, c); } 
}

int main()
{
	uli r, c; cout <<"\nEnter the size of the grid: "; cin >> r >> c;

	vector < vector<bool> > v(r, vector<bool> (c, false));

	uli ans = no_of_paths(0, 0, v, r, c);

	cout <<"\nNo.of possible paths top left bottom right "<< r <<" x "<< c <<" matrix: "<< ans << endl;

	cout << endl;
	return 0;
}