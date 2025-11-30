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
	int i = 0, j = 0, w_tmp = 0, check = 0;
	double res = 0;
	while (i < n && j <= n) {
		int v_tmp = INT_MAX;
		w_tmp += w[j];
		if (w_tmp <= P) ++j;
		else {
			j--;
			v_tmp = min(v_tmp, v[i]);
			for (int k = i; k < j; k++) {
				if (v[k] <= v[k + 1]) {
					v_tmp = min(v_tmp, v[k]);
					check++;
				}
				else {
					break;
				}
			}
			w_tmp = 0;
			res += L / (double)v_tmp;
			i += check;
			i++;
			j = i;
			check = 0;
		}
		if (j == n && i < j) {
			j--;
			v_tmp = min(v_tmp, v[i]);
			for (int k = i; k < j; k++) {
				if (v[k] <= v[k + 1]) {
					v_tmp = min(v_tmp, v[k]);
					check++;
				}
				else {
					break;
				}
			}
			w_tmp = 0;
			res += L / (double)v_tmp;
			i += check;
			i++;
			j = i;
			check = 0;
		}
	}
	cout << fixed << setprecision(2) << res;
}
/*6
4 2 13 7 5 10*/
int main() {
	Bai2();
	return 0;
}