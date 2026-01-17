#include <string>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s) {
  if (s.size() == 0) return 0;
  int left = 0;
  unordered_set<char> window;
  int max_length = 0;
  for (int right = 0; right < s.size(); right++) {
    while (window.find(s[right]) != window.end()) {
      window.erase(s[left]);
      left++;
    }
    window.insert(s[right]);
    max_length = max(max_length, right - left + 1);
  }
  return max_length;
}

int main(int argc, char *argv[]) { return lengthOfLongestSubstring("pwwkew"); }
