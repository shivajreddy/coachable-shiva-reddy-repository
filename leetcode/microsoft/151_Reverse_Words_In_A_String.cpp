#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
    // Reverse the string
    void reverse(string &sentence, int start, int end)
    {
        while (start < end) {
            swap(sentence[start++], sentence[end--]);
        }
    }

public:
    // In-Place with O(1) space
    string reverseWords(string sentence)
    {
        int n = sentence.size();

        // Reverse the entire input string
        reverse(sentence, 0, n - 1);

        // Reverse individual words
        int start = 0; // find the start
        for (int end = 0; end < n; end++) {
            if (sentence[end] == ' ') {
                reverse(sentence, start, end - 1);
                start = end + 1;
            }
        }
        // Reverse the last word
        reverse(sentence, start, n - 1);

        // Remove extra space
        int write = 0;
        for (int read = 0; read < n; read++) {
            if (sentence[read] != ' ' ||
                (write > 0 && sentence[write - 1] != ' ')) {
                sentence[write++] = sentence[read];
            }
        }

        // Remove trailing space if exists
        if (write > 0 && sentence[write - 1] == ' ') {
            write--;
        }

        // Resize the vector
        sentence.resize(write);

        return sentence;
    }

    string reverseWords2(string sentence)
    {
        int n = sentence.size();

        // Trim leading & trailing spaces
        int left = 0, right = n - 1;

        while (left <= right && sentence[left] == ' ')
            left++;
        while (left <= right && sentence[left] == ' ')
            right--;

        // Split words
        vector<string> words;
        string word;
        for (int i = left; i <= right; i++) {
            if (sentence[i] != ' ') {
                word += sentence[i];
            } else if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        // Add last word
        if (!word.empty())
            words.push_back(word);

        // Reverse the words
        std::reverse(words.begin(), words.end());

        // Join the words
        string result;
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i < words.size() - 1) {
                result += ' ';
            }
        }

        return result;
    }
};

int main()
{
    Solution s;

    // TEST 1
    {
        // cout << "RESULT  : " << s.reverseWords("the sky is blue") << endl;
        cout << "RESULT  : " << s.reverseWords2("the sky is blue") << endl;
        cout << "EXPECTED: " << "blue is sky the" << endl;
        cout << endl;
    }
    // TEST 2
    {
        // cout << "RESULT  : " << s.reverseWords("  hello world  ") << endl;
        cout << "RESULT  : " << s.reverseWords2("  hello world  ") << endl;
        cout << "EXPECTED: " << "world hello" << endl;
        cout << endl;
    }
    // TEST 3
    {
        // cout << "RESULT  : " << s.reverseWords("a good   example") << endl;
        cout << "RESULT  : " << s.reverseWords2("a good   example") << endl;
        cout << "EXPECTED: " << "example good a" << endl;
    }
}
