#include <bits/stdc++.h>
using namespace std;

char xor_c(char a, char b)
{
    if (a == b)
        return '0';
    return '1';
}
void binaryToGray(string &binary)
{
    string gray = "";
    gray += binary[0];
    for (int i = 1; i < binary.length(); i++)
    {
        gray += xor_c(binary[i], binary[i - 1]);
    }
    cout << gray << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string binary;
        cin >> binary;
        binaryToGray(binary);
    }
    return 0;
}