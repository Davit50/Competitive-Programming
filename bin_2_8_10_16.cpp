#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

//string bit2to10(string bit2) {int bit10 = 0;while (bit2[0] == '0') bit2 = bit2.substr(1, bit2.size() - 1);for (int i = 0; i < bit2.size(); i++) {if (bit2[bit2.size() - 1 - i] == '1') {bit10 += pow(2, i);}}return to_string(bit10);}
//string bit2to8(string bit2) {string concat = "";string bit8 = "";while (bit2[0] == '0') bit2 = bit2.substr(1, bit2.size() - 1);if (bit2.size() % 3 == 1) bit2 = "00" + bit2;if (bit2.size() % 3 == 2) bit2 = '0' + bit2;for (int i = 0; i < (bit2.size() / 3); i++) {if (bit2.substr(i * 3, 3) == "000")concat = '0';if (bit2.substr(i * 3, 3) == "001")concat = '1';if (bit2.substr(i * 3, 3) == "010")concat = '2';if (bit2.substr(i * 3, 3) == "011")concat = '3';if (bit2.substr(i * 3, 3) == "100")concat = '4';if (bit2.substr(i * 3, 3) == "101")concat = '5';if (bit2.substr(i * 3, 3) == "110")concat = '6';if (bit2.substr(i * 3, 3) == "111")concat = '7';bit8 += concat;}return bit8;}
//string bit2to16(string bit2) {string bit16 = "";string concat;if (bit2.size() % 4 == 1)bit2 = "000" + bit2;if (bit2.size() % 4 == 2)bit2 = "00" + bit2;if (bit2.size() % 4 == 3)bit2 = '0' + bit2;for (int i = 0; i < (bit2.size() / 4); i++) {if (bit2.substr(4 * i, 4) == "0000")concat = '0';if (bit2.substr(4 * i, 4) == "0001")concat = '1';if (bit2.substr(4 * i, 4) == "0010")concat = '2';if (bit2.substr(4 * i, 4) == "0011")concat = '3';if (bit2.substr(4 * i, 4) == "0100")concat = '4';if (bit2.substr(4 * i, 4) == "0101")concat = '5';if (bit2.substr(4 * i, 4) == "0110")concat = '6';if (bit2.substr(4 * i, 4) == "0111")concat = '7';if (bit2.substr(4 * i, 4) == "1000")concat = '8';if (bit2.substr(4 * i, 4) == "1001")concat = '9';if (bit2.substr(4 * i, 4) == "1010")concat = 'A';if (bit2.substr(4 * i, 4) == "1011")concat = 'B';if (bit2.substr(4 * i, 4) == "1100")concat = 'C';if (bit2.substr(4 * i, 4) == "1101")concat = 'D';if (bit2.substr(4 * i, 4) == "1110")concat = 'E';if (bit2.substr(4 * i, 4) == "1111")concat = 'F';bit16 += concat;}return bit16;}
//string bit10to2(string bit10str) {string bit2 = "";ll bit10 = stoll(bit10str);if (bit10 == 0)return "0";while (bit10 != 1) {bit10 % 2 == 0 ? bit2 += "0" : bit2 += "1";bit10 /= 2;}bit2 += "1";reverse(bit2.begin(), bit2.end());return bit2;}
//string bit8to2(string bit8) {string bit2 = "";string concat = "";for (int i = 0; i < bit8.size(); i++) {if (bit8[i] == '0')concat = "000";if (bit8[i] == '1')concat = "001";if (bit8[i] == '2')concat = "010";if (bit8[i] == '3')concat = "011";if (bit8[i] == '4')concat = "100";if (bit8[i] == '5')concat = "101";if (bit8[i] == '6')concat = "110";if (bit8[i] == '7')concat = "111";bit2 += concat;}return bit2;}
//string bit16to2(string bit16) {string concat;string bit2 = "";for (int i = 0; i < bit16.size(); i++) {if (bit16[i] == '0')concat = "0000";if (bit16[i] == '1')concat = "0001";if (bit16[i] == '2')concat = "0010";if (bit16[i] == '3')concat = "0011";if (bit16[i] == '4')concat = "0100";if (bit16[i] == '5')concat = "0101";if (bit16[i] == '6')concat = "0110";if (bit16[i] == '7')concat = "0111";if (bit16[i] == '8')concat = "1000";if (bit16[i] == '9')concat = "1001";if (bit16[i] == 'A')concat = "1010";if (bit16[i] == 'B')concat = "1011";if (bit16[i] == 'C')concat = "1100";if (bit16[i] == 'D')concat = "1101";if (bit16[i] == 'E')concat = "1110";if (bit16[i] == 'F')concat = "1111";bit2 += concat;}return bit2;}

int tryagain() {
    int variant;
    cin >> variant;
    if (variant == 2 || variant == 10 || variant == 8 || variant == 16) return variant;
    else {
        cout << "try again" << endl;
        tryagain();
    }
}

string bit2to10(string bit2) {
    int bit10 = 0;
    while (bit2[0] == '0') bit2 = bit2.substr(1, bit2.size() - 1);
    for (int i = 0; i < bit2.size(); i++) {
        if (bit2[bit2.size() - 1 - i] == '1') {
            bit10 += pow(2, i);
        }
    }
    return to_string(bit10);

}


string bit2to8(string bit2) {
    string concat = "";
    string bit8 = "";
    while (bit2[0] == '0') bit2 = bit2.substr(1, bit2.size() - 1);
    if (bit2.size() % 3 == 1) bit2 = "00" + bit2;
    if (bit2.size() % 3 == 2) bit2 = '0' + bit2;
    for (int i = 0; i < (bit2.size() / 3); i++) {
        if (bit2.substr(i * 3, 3) == "000")concat = '0';
        if (bit2.substr(i * 3, 3) == "001")concat = '1';
        if (bit2.substr(i * 3, 3) == "010")concat = '2';
        if (bit2.substr(i * 3, 3) == "011")concat = '3';
        if (bit2.substr(i * 3, 3) == "100")concat = '4';
        if (bit2.substr(i * 3, 3) == "101")concat = '5';
        if (bit2.substr(i * 3, 3) == "110")concat = '6';
        if (bit2.substr(i * 3, 3) == "111")concat = '7';
        bit8 += concat;
    }
    return bit8;
}


string bit2to16(string bit2) {
    string bit16 = "";
    string concat;
    if (bit2.size() % 4 == 1)bit2 = "000" + bit2;
    if (bit2.size() % 4 == 2)bit2 = "00" + bit2;
    if (bit2.size() % 4 == 3)bit2 = '0' + bit2;
    for (int i = 0; i < (bit2.size() / 4); i++) {
        if (bit2.substr(4 * i, 4) == "0000")concat = '0';
        if (bit2.substr(4 * i, 4) == "0001")concat = '1';
        if (bit2.substr(4 * i, 4) == "0010")concat = '2';
        if (bit2.substr(4 * i, 4) == "0011")concat = '3';
        if (bit2.substr(4 * i, 4) == "0100")concat = '4';
        if (bit2.substr(4 * i, 4) == "0101")concat = '5';
        if (bit2.substr(4 * i, 4) == "0110")concat = '6';
        if (bit2.substr(4 * i, 4) == "0111")concat = '7';
        if (bit2.substr(4 * i, 4) == "1000")concat = '8';
        if (bit2.substr(4 * i, 4) == "1001")concat = '9';
        if (bit2.substr(4 * i, 4) == "1010")concat = 'A';
        if (bit2.substr(4 * i, 4) == "1011")concat = 'B';
        if (bit2.substr(4 * i, 4) == "1100")concat = 'C';
        if (bit2.substr(4 * i, 4) == "1101")concat = 'D';
        if (bit2.substr(4 * i, 4) == "1110")concat = 'E';
        if (bit2.substr(4 * i, 4) == "1111")concat = 'F';
        bit16 += concat;
    }
    return bit16;

}


string bit10to2(string bit10str) {
    string bit2 = "";
    ll bit10 = stoll(bit10str);
    if (bit10 == 0)return "0";
    while (bit10 != 1) {
        bit10 % 2 == 0 ? bit2 += "0" : bit2 += "1";
        bit10 /= 2;
    }
    bit2 += "1";
    reverse(bit2.begin(), bit2.end());
    return bit2;
}

string bit8to2(string bit8) {
    string bit2 = "";
    string concat = "";
    for (int i = 0; i < bit8.size(); i++) {
        if (bit8[i] == '0')concat = "000";
        if (bit8[i] == '1')concat = "001";
        if (bit8[i] == '2')concat = "010";
        if (bit8[i] == '3')concat = "011";
        if (bit8[i] == '4')concat = "100";
        if (bit8[i] == '5')concat = "101";
        if (bit8[i] == '6')concat = "110";
        if (bit8[i] == '7')concat = "111";
        bit2 += concat;
    }

    return bit2;

}

string bit16to2(string bit16) {
    string concat;
    string bit2 = "";
    for (int i = 0; i < bit16.size(); i++) {
        if (bit16[i] == '0')concat = "0000";
        if (bit16[i] == '1')concat = "0001";
        if (bit16[i] == '2')concat = "0010";
        if (bit16[i] == '3')concat = "0011";
        if (bit16[i] == '4')concat = "0100";
        if (bit16[i] == '5')concat = "0101";
        if (bit16[i] == '6')concat = "0110";
        if (bit16[i] == '7')concat = "0111";
        if (bit16[i] == '8')concat = "1000";
        if (bit16[i] == '9')concat = "1001";
        if (bit16[i] == 'A')concat = "1010";
        if (bit16[i] == 'B')concat = "1011";
        if (bit16[i] == 'C')concat = "1100";
        if (bit16[i] == 'D')concat = "1101";
        if (bit16[i] == 'E')concat = "1110";
        if (bit16[i] == 'F')concat = "1111";
        bit2 += concat;
    }
    return bit2;
}


int main() {
    string bit2;
    string bit10;
    string bit8;
    string bit16;
    cout << "select | 2 | 10 | 8 | 16 |" << endl;
    int variant = tryagain();
    if (variant == 2) {
        cin >> bit2;
        bit10 = bit2to10(bit2);
        bit8 = bit2to8(bit2);
        bit16 = bit2to16(bit2);
    }
    if (variant == 10) {
        cin >> bit10;
        bit2 = bit10to2(bit10);
        bit8 = bit2to8(bit2);
        bit16 = bit2to16(bit2);
    }
    if (variant == 8) {
        cin >> bit8;
        bit2 = bit8to2(bit8);
        bit10 = bit2to10(bit2);
        bit16 = bit2to16(bit2);
    }
    if (variant == 16) {
        cin >> bit16;
        bit2 = bit16to2(bit16);
        bit10 = bit2to10(bit2);
        bit8 = bit2to8(bit2);
    }
    cout << "bit2 - " << bit2 << endl;
    cout << "bit10 - " << bit10 << endl;
    cout << "bit8 - " << bit8 << endl;
    cout << "bit16 - " << bit16 << endl;
}