#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void Bai1(int a, int b) {
    int res = 0;
    int UCLN = gcd(a , b);
    for (int i = 1; i * i <= UCLN; i++) {
        if (UCLN % i == 0) {
            res++;
            if (UCLN / i != i) res++;
        }
    }
    cout << res;
}

bool checkPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void Bai2(int n) {
    double tmp = sqrt(n);
    tmp = round(tmp);
    for (int i = 2; i <= sqrt(n); i++) {
        if (checkPrime(i)) tmp = i;
    }
    cout << tmp * tmp;
}

int main()
{
    int n, m;
    cin >> n >> m;
    Bai1(n, m);
    return 0;
}