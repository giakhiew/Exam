#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n,k,tam;
	bool ktr;
	cin>>n>>k;
	vector <int> a(n);
	for (int i=0;i<n;i++) {
		a[i]=tam;
	}
	
	sort(a.begin(), a.end());
	int day=0;
	int max=0;
	for (int i=0;i<n;i++) {
		tam = i+1;
	if (a[tam]-a[i]<=k) {
		ktr=true;
		day++;
	}
	else {
		ktr = false;
	}
	
	if (ktr == false) {
		day = 0;
	}
	
	if (day>max) {
		max = day;
	}
	}
	cout<<max;
	return 0;
}
