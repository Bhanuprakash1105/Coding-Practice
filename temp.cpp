#include <bits/stdc++.h>
using namespace std;

void print(auto &v) {
	cout <<"\nOutput matrix:\n";
	for(auto x: v) { for(auto y: x) { cout << y <<" "; } cout << endl; }
	cout << endl;
}

bool check(auto &v) {
	for(int i = 0; i < 4; ++i) {
		for(int j = 1; j < 4; ++j) {
			// cout << v[i][j-1] <<" -- " << v[i][j] << endl;
			if(v[i][j-1] + 1 != v[i][j] && v[i][j] != 0 && v[i][j-1] != 0) {
				return false;
			}
		}
		if(i > 0) {
			if(v[i-1][3] + 1 != v[i][0]) { return false; }
		}
	}
	if(v[3][3] != 0) {
		return false;
	}
	return true;
}

void giveAns(auto &v, int i, int j) {
	if(check(v)) {
		return;
	}
	vector< pair <int, int> > dir = { {i-1, j}, {i, j-1}, {i, j+1}, {i+1, j} };
	for(int x = 0; x < 4; ++x) {
		if( dir[x].first < 0 || dir[x].first > 3 || dir[x].second < 0 || dir[x].second > 3 || dir[x].first == i || dir[x].second == i) {
			continue;
		}
		cout << dir[x].first <<" -- "<< dir[x].second << endl;
		int temp = v[dir[x].first][dir[x].second];
		v[dir[x].first][dir[x].second] = v[i][j];
		v[i][j] = temp;
		giveAns(v, dir[x].first, dir[x].second);
	}
	cout <<"\nAfter: ";
	print(v);
}

int main(int argc, char const *argv[])
{
	int SIZE = 4;
	vector< vector<int> > v(SIZE, vector <int> (SIZE, 0));
	cout <<"\nEnter the matrix:\n";
	for (int i = 0; i < 4; ++i) { for (int j = 0; j < 4; ++j) {
			cin >> v[i][j];
	} }
	giveAns(v, 3, 3);
	print(v);
	return 0;
}