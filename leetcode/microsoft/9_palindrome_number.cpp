// 9. Palindrome Number
// https://leetcode.com/problems/palindrome-number

#include <iostream>
#include <string>

using namespace std;

// Run: O(m/2) => O(m) where m is the number of digits including signs
// Space: O(m) where m is the number of digits including signs
class Solution
{
public:
    bool isPalindrome(int x)
    {
        string s = std::to_string(x);

        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};

int main()
{
    Solution s;
    // Test 1
    {
        cout << s.isPalindrome(121) << endl;
        cout << 1 << "\n" << endl;
    }
    // Test 2
    {
        cout << s.isPalindrome(-121) << endl;
        cout << 0 << "\n" << endl;
    }
};
