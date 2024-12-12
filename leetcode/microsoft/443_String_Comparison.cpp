#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int result = -1;
        return result;
    }
};

int main()
{
    Solution s;

    // TEST 1
    {
        vector<char> chars = { 'a', 'a', 'b', 'b', 'c', 'c', 'c' };
        cout << "RESULT  : " << s.compress(chars) << endl;
        cout << "EXPECTED: " << 6 << "\n" << endl;
    }
    // TEST 2
    {
        vector<char> chars = { 'a' };
        cout << "RESULT  : " << s.compress(chars) << endl;
        cout << "EXPECTED: " << 1 << "\n" << endl;
    }
    // TEST 1
    {
        vector<char> chars = { 'a', 'b', 'b', 'b', 'b', 'b', 'b',
                               'b', 'b', 'b', 'b', 'b', 'b' };
        cout << "RESULT  : " << s.compress(chars) << endl;
        cout << "EXPECTED: " << 4 << "\n" << endl;
    }

    return 0;
}
