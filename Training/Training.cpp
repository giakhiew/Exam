#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

void bai1GiaoDau(int n, vector<int> a1, vector<int> a2) {
    for (int i = 0; i < n; i++) cin >> a1[i];
    for (int i = 0; i < n; i++) cin >> a2[i];
    sort(a1.begin(), a1.end(), greater<int>());
    sort(a2.begin(), a2.end(), greater<int>());
    int i = n - 1, j = i, res = 0;
    while (i >= 0 && j >= 0) {
        if (a2[j] <= a1[i]) j--;
        else {
            j--;
            i--;
            res++;
        }
    }
    cout << res;
}

void bai2DuongHoaCACH1(int n, int m, vector<int> a) {
    set<int> s;
    int len = m, i = 0, j = len - 1, Min = n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    while (i < n && j < n) {
        if (i <= j) {
            s.insert(a[i]);
            i++;
        }
        else {
            int res = s.size();
            if (res == m) {
                Min = min(Min, len);
                i = j - len + 2;
                len = j - i + 1;
                s.clear();
            }
            else {
                i = j - len + 1;
                j++;
                len++;
                s.clear();
            }
        }
    }
    cout << Min;
}

void bai2DuongHoa(int n, int m, vector<int> a) {
    map<int, int> M;
    int i = 0, j = m - 1, Min = n;
    for (int k = 0; k < n; k++) cin >> a[k];
    for (int k = 1; k <= m; k++) M[k] = 0;
    for (int k = 0; k <= j; k++) M[a[k]]++;

    while (j < n) {
        int len = j - i + 1;
        bool check = true;
        for (auto item : M) {
            if (item.second == 0) {
                check = false;
                break;
            }
        }
        if (check == true) {
            Min = (min(Min, len));
            M[a[i++]]--;
        }
        else {
            j++;
            if (j == n) break;
            M[a[j]]++;
        }
    }
    cout << Min;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    bai2DuongHoa(n, m, a);
    return 0;
}