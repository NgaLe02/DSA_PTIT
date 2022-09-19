#include <bits/stdc++.h>
using namespace std;

char flip(char a)
{
    if (a == '0')
        return '1';
    else
        return '0';
}
void grayToBinary(string &gray)
{
    string binary = "";
    binary += gray[0];
    for (int i = 1; i < gray.length(); i++)
    {
        if (gray[i] == '0')
            binary += binary[i - 1];
        else
        {
            binary += flip(binary[i - 1]);
        }
    }
    cout << binary << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string gray;
        cin >> gray;
        grayToBinary(gray);
    }
    return 0;
}