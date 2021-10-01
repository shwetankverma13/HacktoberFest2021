#include<bits/stdc++.h>
using namespace std;

string  encrypt(string s, int n) {
    string s1;
    int j = 0, i;
    vector<vector<char>> a(n, vector<char>(s.size(), ' '));
    j = 0;
    int flag = 0;
    for (i = 0; i < s.size(); i++) {
        a[j][i] = s[i];
        if (j == n - 1) {
            flag = 1;
        }
        else if (j == 0)
            flag = 0;

        if (flag == 0) {
            j++;
        }
        else j--;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < s.size(); j++) {
            if (a[i][j] != ' ')
                s1 += a[i][j];
        }
    }
    return s1;

}
string decrypt(string s, int n) {
    vector<vector<char>> a(n, vector<char>(s.size(), ' '));

    int j = 0, i = 0;
    int flag = 0;
    for (i = 0; i < s.size(); i++) {
        a[j][i] = '0';
        if (j == n - 1) {
            flag = 1;
        }
        else if (j == 0)
            flag = 0;

        if (flag == 0) {
            j++;
        }
        else j--;
    }
    int temp = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < s.size(); j++) {
            if (a[i][j] == '0')
                a[i][j] = s[temp++];
        }
    }
    flag = 0;
    j = 0; string s1 = "";
    for (i = 0; i < s.size(); i++) {
        s1 += a[j][i];
        if (j == n - 1) {
            flag = 1;
        }
        else if (j == 0)
            flag = 0;

        if (flag == 0) {
            j++;
        }
        else j--;
    }
    return s1;
}
int main() {
    int t, n, m, i, j, k, sum = 0;
    string s;
    cout << "Enter Plain Text : ";
    cin >> s;
    cout << "Enter Key :";
    cin >> n;
    string ciphertext;
    ciphertext = encrypt(s, n);


    cout << "\nCipher Text is: " << ciphertext << endl;
    string originalmsg;
    originalmsg = decrypt(ciphertext, n);
    cout << "\nDecrypted Text is: " << originalmsg << endl;

    return 0;
}