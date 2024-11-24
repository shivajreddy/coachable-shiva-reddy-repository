// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <string>
#include <unordered_map>

using std::max;
using std::string;
using std::unordered_map;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        size_t maxLength { 0 };

        unordered_map<char, size_t> visited;

        size_t left { 0 }, right { 0 };

        while (right < s.size()) {
            char currChar = s[right];
            if (visited.find(currChar) != visited.end() &&
                visited[currChar] >= left) {
                left = max(left, visited[currChar]) + 1;
            }
            maxLength = max(maxLength, right - left + 1);
            visited[currChar] = right;
            right += 1;
        }

        return maxLength;
    }
};
