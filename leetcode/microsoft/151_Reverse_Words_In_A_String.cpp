#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string si = "HI";
        return si;
    }
};

int main()
{
    Solution s;

    // TEST 1
    {
        cout << "RESULT  : " << s.reverseWords("the sky is blue") << endl;
        cout << "EXPECTED: " << "blue is sky the" << endl;
        cout << endl;
    }
    // TEST 2
    {
        cout << "RESULT  : " << s.reverseWords("  hello world  ") << endl;
        cout << "EXPECTED: " << "world hello" << endl;
        cout << endl;
    }
    // TEST 3
    {
        cout << "RESULT  : " << s.reverseWords("a good   example") << endl;
        cout << "EXPECTED: " << "example good a" << endl;
    }
}
