class Solution {
public:
    string deal (string s, int num) {
        map<char, int> vowel;
        vowel['a'] = vowel['e'] = vowel['i'] = vowel['o'] = vowel['u'] = 1;
        vowel['A'] = vowel['E'] = vowel['I'] = vowel['O'] = vowel['U'] = 1;
        
        string ret = "";
        if (vowel[s[0]] == 1) {
            ret += s;
            ret += "ma";
        }
        else {
            for (int i = 1; i < s.length(); i++) {
                ret += s[i];
            }
            ret += s[0];
            ret += "ma";
        }
        for (int j = 0; j < num; j++) ret += "a";
        return ret;
    }
    
    string toGoatLatin(string S) {
        string ret = "", tmp = "";
        int num = 1;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == ' ') {
                string s = deal(tmp, num++);
                tmp = "";
                ret += s + ' ';
            }
            else {
                tmp += S[i];
            }
        }
        if (tmp != "") {
            ret += deal(tmp, num);
        }
        return ret;
    }
};