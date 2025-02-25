// 767. reorganize String
// https://leetcode.com/problems/reorganize-string

#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

typedef pair<int, char> CharFreq;

class Solution {
 public:
  string reorganizeString(string s) {
    // Count the number of chars for each char
    unordered_map<char, int> counter;
    for (char ch : s) {
      counter[ch]++;
    }

    // add all char-freq to max_heap. This now only holds unique char's
    priority_queue<pair<int, char>> max_heap;
    for (const auto& [ch, freq] : counter) {
      max_heap.push({freq, ch});
    }

    string result;
    pair<int, char> prev = {0, ' '};

    // process heap
    while (!max_heap.empty() || prev.first > 0) {
      // there are no more char-freq in heap, but we still have previously added
      // char on to the result. Ex: res="aba"  mh={a:1}
      if (prev.first > 0 && max_heap.empty()) {
        return "";
      }

      // pop the top item
      auto [count, ch] = max_heap.top();
      max_heap.pop();

      // add this char to result and update count
      result += ch;
      count--;

      // if there was a previous char to reinsert, push it back into the heap
      if (prev.first > 0) {
        max_heap.push(prev);
      }

      // update prev char and count
      prev = {count, ch};
    }

    return result;
  }
};
