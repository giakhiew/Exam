#include <iostream>
#include <cmath>
using namespace std;

void Bai1(int A, int B) {
    int min = ((A < B) ? A : B);
    for (int i = 1;)
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