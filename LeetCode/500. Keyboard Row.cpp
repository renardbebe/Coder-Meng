class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        map<char, int> key;
        key['Q'] = key['W'] = key['E'] = key['R'] = key['T'] = key['Y'] = key['U'] = key['I'] = key['O'] = key['P'] = 1;
        key['A'] = key['S'] = key['D'] = key['F'] = key['G'] = key['H'] = key['J'] = key['K'] = key['L'] = 2;
        key['Z'] = key['X'] = key['C'] = key['V'] = key['B'] = key['N'] = key['M'] = 3;
        
        vector<string> ret;
        for (int i = 0; i < words.size(); i++) {
            bool find = true;
            for (int j = 1; j < words[i].length(); j++) {
                if (key[toupper(words[i][0])] != key[toupper(words[i][j])]) {
                    find = false;
                    break;
                }
            }
            if (find) ret.push_back(words[i]);
        }
        return ret;
    }
};