/*
Generate a binary string of given length
2
3
000
001
010
100
101
4
0000
0001
0010
0100
0101
1000
1001
1010
*/

#include<bits/stdc++.h>
#include<string>
using namespace std;

void generateStringUtil(int k, char str[], int n) {
    if (n == k) {
        str[n] = '\0';
        cout << str << endl;
        return;
    }
    if (str[n-1] == '0') {
        str[n] = '0';
        generateStringUtil(k, str, n+1);
        str[n] = '1';
        generateStringUtil(k, str, n + 1);
    }
    if (str[n - 1] == '1') {
        str[n] = '0';
        generateStringUtil(k, str, n + 1);
    }
}

void generateStrings(int k) {
    if(k<=0) {
        return;
    }
    char str[k];
    str[0] = '0';
    generateStringUtil(k, str, 1);
    str[0] = '1';
    generateStringUtil(k, str, 1);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        generateStrings(k);
    }
    return 0;
}
