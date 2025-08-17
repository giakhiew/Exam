#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <cctype>
using namespace std;

bool checkprime(int n) {
    bool check = true;
    if (n < 2) check = false;
    for (int i = 2; i <= round(sqrt(n)); i++) {
        if (n % i == 0) {
            check = false;
            break;
        }
    }
    return check;
}

void Bai1(long long n) {
    int test1 = n % 100;
    int X = 99 - test1;
    cout << X;
}

void Bai2(long long m) {
    long long n;
    if (m == 0) {
        n = 0;
        cout << n;
        return;
    }
    n = 2 + ((m + 1) * m) / 2;
    cout << n;
}

void Bai3(string str) {
    ifstream inFile("input.txt");
    inFile >> str;
    inFile.close();
    bool check = 0;
    ofstream outFile("output.txt");

    for (int i = 0; i < str.size()-2; i++) {
        if (tolower(str[i]) == tolower(str[i + 1]) && tolower(str[i]) == tolower(str[i + 2])) {
            outFile << i + 1 << " " << str[i] << str[i + 1] << str[i + 2] << endl;
            check = 1;
        }
    }
    if (check == 0) outFile << check;
    outFile.close();
}

void Bai4(string str) {
	ifstream inFile("input.txt");
	getline(inFile,str);
    bool check = 0;
    int Size = 0;
	inFile.close();
	ofstream outFile("output.txt");
    for (int i = 0; i < str.size(); i++) {
        check = isalnum(str[i]);
        if (check == 1) {
            Size++;
        }
	}
	outFile << Size << endl;
    for (int i = 0; i < str.size(); i++) {
		check = isalnum(str[i]);
        if (check == 1) {
            outFile << str[i];
		}
	}
	outFile.close();
}

void Bai5(long long n) {
	ifstream inFile("input.txt");
	inFile >> n;
	inFile.close();
	ofstream outFile("output.txt");
    long long thung=1;
    long long nuoc=1;
    while (nuoc < n) {
        thung++;
        nuoc += ((1+thung)*thung)/2;
    }
	outFile << thung << " " << nuoc;
	outFile.close();
}

void Bai6(long long t,long long n) {
	ifstream inFile("input.txt");
	inFile >> t >> n;
	inFile.close();

	ofstream outFile("output.txt");
    long long camac = 2022;
    long long ngaykhoi = 0;// 1 la chu nhat
    while (camac > 0) {
		cout << "Camac: " << camac << endl;
        camac -= n;
        ngaykhoi++;
        t++;
        if (t == 8) {
            t = 1; // reset to 1 after 7
		}
    }
	outFile << ngaykhoi << " " << t << endl;
    outFile.close();
}

void Bai7() {/*de thieu*/}

void Bai8( int n, int m ) {
    cin >> n >> m;
    double S;
    double duongkinh = n * sqrt(2);
    S = round(pow((duongkinh / 2), 2) * 3.14);
    int ca = m * (S - n * n);
    cout << ca;
}

void Bai9(int n) {
    int sum, tich, max;
    sum = n % 10 + n/10 % 10 + n/100 % 10;
	tich = (n % 10) * (n / 10 % 10) * (n / 100 % 10);
    for (int i = 999; i >= 100; i--) {
        if (i % n == 0) {
            max = i;
			break;
        }
    }
	cout << sum << " " << tich << " " << max;
}

void Bai10(long long n) {
    long long tam = n;
    long long t, reverse, l, check;
    reverse = 0;
    t = 0;
    check = 0;

    while (tam != 0) {
        reverse = reverse * 10 + tam % 10;
        tam /= 10;
    }
    if (reverse > n) l = reverse - n;
    else l = n - reverse;

    for (long long i = 1; i <= n; i++) {
        if (i % 4 == 0) {
            t += i;
            check++;
        }
    }
    if (check == 0) {
        cout << t << " " << l;
        return;
    }
    t /= check;
    cout << t << " " << l;
}

void Bai11(int n) {
    int m, k, x;
    if (n % 100 < n / 100 % 100) m = n / 100 % 100 - n % 100;
    else m = n % 100 - n / 100 % 100;

    k = 0;
    for (int i = n; i >= 1000; i--) {
        if (i % 5 == 0) k++;
    }

    x = 99 - n % 100;
    cout << m << " " << k << " " << x;
}

void Bai12(int n) {
    int m, k, t;
    m = 0;
    k = 0;
    for (int i = n; i >= 100; i--) {
        if (i % 3 == 0) m += i;
        if (i % 9 == 0) k++;
    }
    t = 999 - n % 10 - n / 10 % 100;
    cout << m << " " << k << " " << t;
}

void Bai13(long long m,long long n) {
    long long l, k, t;
    k = 0;
    t = 0;
    long long check = 0;

    l = n - m + 1;

    for (long long i = n; i >= 5; i--) {
        if (i % 5 == 0) {
            k = i;
            break;
        }
    }

    for (int i = m; i <= n; i++) {
        if (i % 5 == 3) {
            t += i;
            check++;
        }
    }

    if (check == 0) {
        cout << l << " " << k << " " << t;
        return;
    }

    t /= check;
    cout << l << " " << k << " " << t;
}

//Bai 14 = Bai 10

void Bai15(int n) {
    int sum = 0;
    for (int i = 100; i <= n; i++) {
        if (i % 3 == 0) {
           sum += i;
        }
    }
    cout << sum;
}

//void Bai16()

void Bai17(int n) {
    int ni;
    int sumi = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int Ni = 1; Ni <= n; Ni++) {
            if (i % Ni == 0) {
                sumi += Ni;
            }
        }
        if (n <= sumi) sum += i;
        sumi  = 0;
    }
    cout << sum;
}

void Bai18(string S) {
    long long sum = 0;
    for (int i = 0; i < S.size() - 1; i++) {
        if (S[i] != '0') {
            sum += (S[i] - '0') * 10 + (S[i + 1] - '0');
        }
        else continue;
    }
    cout << sum;
}

void Bai19(int n) {
    for (int j = 2; j <= n; j++) {
        if (checkprime(j) == true) cout << j << " ";
    }
}

int main()
{
    string str = "1,.Tin @! Hoc:; tre #&%2022 ";
	long long n =1 ;
    
	/*Bai10(123);*/
    cout << 8 % 5;// Example call for Bai6
    return 0;
}