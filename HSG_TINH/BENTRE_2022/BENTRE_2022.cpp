#include <iostream>
#include <vector>
using namespace std;

int n, sum2 = 0;
long long k;
vector<long long> arr;

void init(vector<long long>& arr) {
    for (int i = 0; i < n; i++) {
        int tam;
        cin >> tam;
        sum2 += tam;
        arr.push_back(tam);
    }
}

int Bai1(vector<long long> arr, int n) {
    int res = 0, sum1 = arr[1];
    bool check = 0;
    sum2 -= arr[1];
    int i = 1;
    for (; i <= n; i++) {
        if (sum1 == sum2) {
            check = 1;
            break;
        }
        else {
            sum1 += arr[i];
            sum2 -= arr[i];
        }
    }
    if (check == 0) return 0;
    else return i;
}

void Bai2(int n, int k, vector<long long> arr) {
    int i = 0, j = 1, res = arr.size(), restam = 1, index = 1;
    int sum = arr[0];
    while (i <= j && i < n && j < n) {
        if (sum < k) {
            sum += arr[j++];
            restam++;
        }
        else if (sum == k) {
            res = min(restam, res);
            index = i + 1;
            i++;
            restam = 1;
            j = i + 1;
            sum = arr[i];
        }
        else {
            i++;
            j = i + 1;
            restam = 1;
            sum = arr[i];
        }
    }
    cout << index << " " << res;
}

int main()
{
    cin >> n >> k;
    init(arr);
    Bai2(n, k, arr);
    return 0;
}