class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char, int> myMap;
        int cnt = 0;
        for (int i = 0; i < chars.length(); i++) {
            myMap[chars[i]]++;
        }
        
        for (int i = 0; i < words.size(); i++) {
            map<char, int> d(myMap);
            string word = words[i];
            bool flag = true;
            for (int j = 0; j < word.length(); j++) {
                if (d[word[j]]) {
                    d[word[j]]--;
                }
                else {
                    flag = false;
                    break;
                }
            }
            if (flag) cnt += word.length();
        }
        return cnt;
    }
};