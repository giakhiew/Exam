#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
using namespace std;

#define pb push_back

int n;
vector<int> arr, res;

void init(vector<int> &arr) {
    for (int i = 0; i < n; i++) {
        int tam;
        cin >> tam;
        arr.pb(tam);
    }
}

//23990
//24089
void Bai1() {
    ifstream inFile("in.txt");
    string tmp;
    getline(inFile, tmp);
    int n = stoi(tmp);
    ofstream outFile("out.txt");
    string line;
    while (getline(inFile, line)) {
        int found = line.find(' '), Size = line.size();
        if (found == 0) {
            string tmp1;
            tmp1.append(line, 1, Size - 1);
            int i1 = stoi(tmp1);
            arr.pb(i1);
        }
        else {
            string tmp1, tmp2;
            tmp1 = line.substr(0, found);
            tmp2 = line.substr(found + 1, found);
            int i1 = stoi(tmp1);
            int i2 = stoi(tmp2);
            arr.pb(i1);
            arr.pb(i2);
        }
    }
    inFile.close();
    for (int i = 0; i < n; i += 2) outFile << arr[i] << " ";
    for (int i = n - 1; i >= 1; i -= 2) outFile << arr[i] << " ";
    outFile << endl;
    map<int, int> m;
    for (auto item : arr) m[item]++;
    outFile << m.size();
    outFile.close();
}

void check9(int &x) {
    int Size = res.size() - 2, check = 0;//0 1 2 3
    for (int i = Size; i >= 1; i--) {
        if (res[i] >= 9) {
            res[i] = 0;
            res[i - 1]++;
            check = 1;
        }
        else {
            if (check == 0) res[i]++;
            x = i;
            return;
        }
    }
}

void Bai2() {
    cin >> n;
    init(arr);
    res = arr;
    int sum = 0, index = 0;
    for (auto item : arr) sum += item;
    int sumtmp = sum;

    check9(index);
    if (res[0] > 9) {
        cout << 0;
        return;
    }

    for (int i = 0; i <= index; i++) sumtmp -= res[i];

    int i = n - 1;
    while (i > index) {
        if (sumtmp >= 9) {
            res[i--] = 9;
            sumtmp -= 9;
        }
        else {
            res[i--] = sumtmp;
            sumtmp = 0;
        }
    }
    cout << 1;
    cout << endl;
    for (auto item : res) cout << item << " ";
}

//void xuLyHaiSoDau() {
//    res = arr;
//    if (res[0] < 9 && res[1] == 9) {
//        res[1] = 0;
//        res[0]++;
//    }
//    else if (res[0] < 9 && res[1] < 9) {
//        res[1]++;
//    }
//    else if (res[0] == 9) {
//        cout << 0;
//        return;
//    }
//}

//23999 = 32
int main()
{
    Bai2();
   
    return 0;
}
