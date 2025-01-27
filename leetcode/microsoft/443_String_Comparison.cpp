// 443. String Compression
// https://leetcode.com/problems/string-compression
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*

0
    l
    a   b   b
    r

                        p
                                s
    a   4   b   3   c   2   b   c   c
                                        e
2


*/

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int n = chars.size();

        // p marks the last entered byte
        int p = -1;

        // s, e are the start & end indexes of continuous chars
        int s = 0;
        for (int e = 0; e < n; e++) {

            // Found a new sequence of characters
            if (chars[e] != chars[s]) {

                int char_count = e - s;

                if (char_count == 1) {
                    chars[p + 1] = chars[s];
                    p += 1;
                } else {
                    chars[p + 1] = chars[s]; // char
                    p += 1;

                    for (auto &ch : std::to_string(char_count)) {
                        chars[p + 1] = ch;
                        p += 1;
                    }
                }
                s = e;
            }
        }
        // Add the last char
        int char_count = n - s;
        if (char_count == 1) {
            chars[p + 1] = chars[s];
            p += 1;
        } else {
            chars[p + 1] = chars[s]; // char
            p += 1;

            for (auto &ch : std::to_string(char_count)) {
                chars[p + 1] = ch;
                p += 1;
            }
        }

        return p + 1;
    }
};

void printVector(const vector<char> &v)
{
    for (auto &c : v) {
        cout << c << " ";
    }
    cout << endl;
}

int main()
{
    Solution s;

    // TEST 1
    {
        vector<char> chars = { 'a', 'a', 'b', 'b', 'c', 'c', 'c' };
        printVector(chars);
        int result = s.compress(chars);
        printVector(chars);
        cout << "RESULT  : " << result << endl;
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
