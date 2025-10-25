#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n;
vector<int> arr;

void init(vector<int>& arr) {
    for (int i = 0; i < n; i++) {
        int tam;
        cin >> tam;
        arr.push_back(tam);
    }
}
//23990
//24089
void Bai1(int n, vector<int> arr) {
    for (int i = 0; i < 12; i += 2) cout << arr[i] << " ";
    for (int i = 11; i >= 1; i -= 2) cout << arr[i] << " ";
    cout << endl;
    map<int, int> m;
    for (auto item : arr) m[item]++;
    cout << m.size();
}

int resSum(vector<int> arr) {
    int sum = 0;
    for (auto item : arr) sum += item;
    return sum;
}

void Bai2(int n, vector<int> arr) {
    int sum = 0, res = 0, i = n - 1;
    for (auto item : arr) sum += item;
    while (i >= 0) {
        if (arr[i] < 10) arr[i]++;
        else {
            arr[i] = 0;
            j--;
        }
    }
}

int main()
{
    cin >> n;
    init(arr);
    Bai1(n, arr);
    return 0;
}
