#include <iostream>
#include <cmath>
#include <string>
#include <climits>
#include <cstring>

using namespace std;

void check_chinh_phuong(long long x) {
    bool check = false;
	long long canx = sqrt(x);

    if (canx * canx == x) {
        check = true;
	}

    if (check) {
        cout << "YES";
    } else {
        cout << "NO";
	}
}

void max_trong_xau(string str) {
    string tam;
    long long max = LLONG_MIN, tamnum, size = str.size();

    for (int i = 0; i < size; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            tam += str[i];
        }
        else if (tam != "") {
                tamnum = stoll(tam);
                if (tamnum > max) max = tamnum;
                tam = "";
        }
    }

    cout << max;
 }

int main()
{
    int x;
    string str = "7abd54cage99";
    //cin >> str; //7abd54cage31
	max_trong_xau(str);
    return 0;
}