// 29. Divide Two Integers
// https://leetcode.com/problems/divide-two-integers

#include <iostream>
#include <limits.h>

using namespace std;

class Solution
{
public:
    int add(int x, int y)
    {
        int carry;
        while (y != 0) {
            carry = x & y;
            x = x ^ y;
            y = carry << 1;
        }
        return x;
    }

    int subtract(int x, int y) { return add(x, add(~y, 1)); }

    // Bit Manipulation
    int divide(int dividend, int divisor)
    {

        // Edge case
        if (dividend == INT_MIN && divisor == -1) {
            // Special case: INT_MIN / -1 causes overflow
            return INT_MAX;
        }

        bool neg = (dividend < 0) ^ (divisor < 0); // Determine the sign
        dividend = abs(dividend);
        divisor = abs(divisor);
        int quotient = 0;

        while (dividend >= divisor) {
            int temp_divisor = divisor, multiple = 1;
            while (dividend >= (temp_divisor << 1)) {
                temp_divisor <<= 1;
                multiple <<= 1;
            }
            dividend = subtract(dividend, temp_divisor);
            quotient = add(quotient, multiple);
        }
        return neg ? -quotient : quotient;
    }
};

int main()
{
    Solution s;
    // Test 1
    {
        cout << s.divide(10, 3) << endl;
        cout << 3 << "\n" << endl;
    }
    // Test 2
    {
        cout << s.divide(7, -3) << endl;
        cout << -2 << "\n" << endl;
    }
    // Test 3
    {
        cout << s.divide(1, 1) << endl;
        cout << 1 << "\n" << endl;
    }
    // Test 4
    {
        cout << s.divide(2147483647, 1) << endl;
        cout << 2147483647 << "\n" << endl;
    }
    // Test 5
    {
        cout << s.divide(2147483647, 2) << endl;
        cout << 2147483647 << "\n" << endl;
    }
};
