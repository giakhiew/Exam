#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <climits>
using namespace std;
#define pb push_back

int n, P, L;
vector<int> arr, w, v;
vector<pair <int, int>> p;

void init1(vector<int>& a) {
	for (int i = 0; i < n; i++) {
		int tam;
		cin >> tam;
		a.pb(tam);
	}
}

void init2(vector<int> &a, vector<int>& a1) {
	for (int i = 0; i < n; i++) {
		int tam, tam1;
		cin >> tam >> tam1;
		a.pb(tam);
		a1.pb(tam1);
	}
}

void Bai1() {
	cin >> n;
	init1(arr);
	sort(arr.begin(), arr.end());
	int res = 0, a = 0, c = 1, b = 2;
	for (; c < n - 2; c++) {
		int sum = arr[a] + arr[c];
		if (sum == arr[b]) {
			res += 2;
			b++;
		}
		else if (sum > arr[b]) {
			b++;
			if (arr[a] + arr[c] == arr[b]) res += 2;
		}
		else {
			continue;
		}

		if (c - a > 2) {
			for (int i = a; i < c; i++) {
				if (arr[a] + arr[c] > arr[b]) break;
				else if (arr[a] + arr[c] == arr[b]) res += 2;
			}
		}
	}
	cout << res;
}

void Bai2() {
	cin >> n >> P >> L;
	init2(w, v);
	int i = 0, j = 0;
	double res = 0;
	while (i < n && j <= n) {
		int k = i;
		int w_tmp = w[i];
		bool check = true;
		while (w_tmp < P && j < n - 1 && (v[k] <= v[k + 1])) {
			w_tmp += w[++j];
			k++;
			if (w_tmp > P) check = false;
		}
		if (check == false) j--;
		res += L / (double)v[i];
		i = j + 1;
		j = i;
	}
	cout << fixed << setprecision(2) << res;
}
/*6
4 2 13 7 5 10*/
int main() {
	Bai2();
	return 0;
}