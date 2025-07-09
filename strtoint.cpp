#include <iostream>
#include <string>
#include <climits> // For INT_MAX and INT_MIN
using namespace std;

int myAtoi(string s) 
{
    int i = 0;
    int n = s.size();
    long result = 0; // Use long to detect overflow
    int sign = 1;

    // 1. Skip leading whitespaces
    while (i < n && s[i] == ' ')
    {
        ++i;
    }

    // 2. Check for sign
    if (i < n && (s[i] == '+' || s[i] == '-'))
    {
        if (s[i] == '-')
            sign = -1;
        ++i;
    }

    // 3. Convert digits
    while (i < n && isdigit(s[i]))
    {
        result = result * 10 + (s[i] - '0');

        // 4. Clamp if out of 32-bit int range
        if (sign * result <= INT_MIN)
            return INT_MIN;
        if (sign * result >= INT_MAX)
            return INT_MAX;

        ++i;
    }

    return sign * result;
}

int main()
{
    cout << myAtoi("   -42") << endl;        // -42
    cout << myAtoi("4193 with words") << endl; // 4193
    cout << myAtoi("words and 987") << endl;   // 0
    cout << myAtoi("-91283472332") << endl;    // -2147483648 (INT_MIN)
    cout << myAtoi("+0000123") << endl;        // 123

    return 0;
}
