class Solution {
public:
    inline bool isL (char ch) {
        if (ch >= 'a' && ch <= 'z') return true;
        else if (ch >= 'A' && ch <= 'Z') return true;
        else return false;
    }
    
    string reverseOnlyLetters(string S) {
        vector<char> letter;
        for (int i = 0; i < S.length(); i++) {
            if (isL(S[i])) letter.push_back(S[i]);
        }
        for (int i = 0; i < S.length(); i++) {
            if (isL(S[i])) {
                S[i] = letter.back();
                letter.pop_back();
            }
        }
        return S;
    }
};