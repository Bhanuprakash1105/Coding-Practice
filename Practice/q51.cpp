//Question: https://www.interviewbit.com/problems/merge-intervals/
#include <bits/stdc++.h>

using namespace std;

struct Interval {
	
	int start, end;
	
	Interval() : start(0), end(0) {}
	
	Interval(int s, int e) : start(s), end(e) {}
};

bool mycomp(Interval a,Interval b) { return (a.start < b.start); }

vector<Interval> insert(vector<Interval> &A, Interval newInterval) {
    
    A.push_back(newInterval);
    
    sort(A.begin(), A.end(), mycomp);
    
    vector<Interval> res;
    
    int n = A.size();
    
    res.push_back(A[0]);
    
    for(int i = 1; i < n; i++) {
        
        if(A[i].start <= res[res.size()-1].end) { res[res.size()-1].end = max(res[res.size()-1].end, A[i].end); }
        
        else { res.push_back(A[i]); }
    }
    
    return res;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);

	int n, s, e; cout <<"\nNumber of intervals: "; cin >> n;

	std::vector<Interval> v;
	if(n) { cout <<"\nEnter start and end of intervals" << endl; }
	for(auto i = 0; i < n; ++i) {
		cout <<"\nInterval "<< i+1 <<" -> "; cin >> s >> e; Interval obj(min(s, e), max(s, e));
		v.push_back(obj);
	}

	cout <<"\nEnter the start and end of new interval: "; cin >> s >> e;
	Interval newInterval(min(s, e), max(s, e));

	auto result = insert(v, newInterval);

	cout <<"\n  The final intervals"<< endl;
	for(auto i: result) {
		cout <<"\n[" << i.start <<", "<< i.end <<"]"<< endl;
	} cout << endl;

	cout << endl;
	return 0;
}
