#include <bits/stdc++.h>
using namespace std;
// For a given n, following are the two cases to be considered.
// Case 1: n < 10 When n is smaller than 10,
// the output is always n+10.
// For example for n = 7, the output is 17.
// For n = 9, output is 19.
// Case 2: n >= 10:
// Find all factors of n which are between 2 and 9 (both inclusive).
// The idea is to start searching from 9 so that
// the number of digits in the result is minimized.
// For example, 9 is preferred over 33 and 8 is preferred over 24.
// Store all found factors in an array.
// The array would contain digits in non-increasing order,
// so finally print the array in reverse order.

string getSmallest(long long n)
{
    // Case 1: n < 10
    if (n < 10)
        return to_string(n);
    string res = "";
    // Case 2: Start with 9 and
    //  try every possible digit
    for (int i = 9; i > 1; i--)
    {
        while (n % i == 0)
        {
            n /= i;
            res += to_string(i);
        }
    }
    // If n could not be broken
    // in form of digits (prime factors
    // of n are greater than 9
    if (n > 10)
        return "-1";
    reverse(res.begin(), res.end());
    return res;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout << getSmallest(n) << endl;
    }
    return 0;
}