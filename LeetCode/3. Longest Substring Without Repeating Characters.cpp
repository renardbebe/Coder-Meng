class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        map<char, int> pos;
        
        int curLen = 0, start_pos = 0;
        for (int i = 0; i < s.length(); i++) {
            if (pos.find(s[i]) == pos.end() || pos.find(s[i])->second < start_pos) {
                pos[s[i]] = i;
                curLen++;
            }
            else {
                curLen = i - pos[s[i]];
                start_pos = i - curLen + 1;  // start_pos of substring
                pos[s[i]] = i;
            }
            maxLen = max(maxLen, curLen);
        }
        return maxLen;
    }
};