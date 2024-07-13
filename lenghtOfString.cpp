#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int lengthOfLongestSubstring(const string &s) {
    unordered_map<char, int> charIndexMap;
    int maxLength = 0;
    int start = 0;

    for (int end = 0; end < s.size(); ++end) {
        char currentChar = s[end];

        if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= start) {
            start = charIndexMap[currentChar] + 1;
        }

        // Update
        charIndexMap[currentChar] = end;

        // Calculate the length
        int currentLength = end - start + 1;
        // Update maxLength
        maxLength = max(maxLength, currentLength);
    }

    return maxLength;
}

int main() {
    string s = "abcabcbb";
    cout << "The length of the longest substring without repeating characters is: " << lengthOfLongestSubstring(s) << endl;
    return 0;
}
