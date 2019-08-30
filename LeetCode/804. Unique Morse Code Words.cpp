#include <vector>
#include <algorithm>

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        int cnt = 0;
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        for (int i = 0; i < words.size(); i++) {
            string str = "";
            for (int j = 0; j < words[i].length(); j++) {
                str += morse[int(words[i][j] - 'a')];
            }
            words[i] = str;
        }

        vector<string> result;
        for (int i = 0; i < words.size(); i++) {
            if (find(result.begin(), result.end(), words[i]) == result.end()) {
                cnt++;
                result.push_back(words[i]);
            }
        }

        return cnt;
    }
};