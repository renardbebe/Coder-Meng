class Solution {
public:
    inline bool large (string s1, string s2, string ord) {  // s1 > s2
        int len1 = s1.length(), len2 = s2.length();
        if (len1 < len2) {
            for (int i = 0; i < len1; i++) {
                int pos1 = ord.find(s1[i]);
                int pos2 = ord.find(s2[i]);
                if (pos1 > pos2) return true;
                if (pos1 < pos2) return false;
            }
            return false;
        }
        else {
            for (int i = 0; i < len2; i++) {
                int pos1 = ord.find(s1[i]);
                int pos2 = ord.find(s2[i]);
                if (pos1 > pos2) return true;
                if (pos1 < pos2) return false;
            }
            return true;
        }
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 1; i < words.size(); i++) {
            if (large(words[i-1], words[i], order)) return false;
        }
        return true;
    }
};