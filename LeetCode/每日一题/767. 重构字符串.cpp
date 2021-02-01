class Solution {
public:
    string reorganizeString(string S) {
        int len = S.length();
        map<char, int> count;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            count[ch] = 0;
        }
        for (int i = 0; i < len; i++) {
            count[S[i]] += 1;
            if (count[S[i]] > (len + 1) / 2) return "";
        }
        // sort map by value
        vector<pair<char, int> > vec;
        for (auto it = count.begin(); it != count.end(); it++) {
            vec.push_back(make_pair(it->first, it->second));
        }
        sort(vec.begin(), vec.end(), 
            [](const pair<char, int> &x, const pair<char, int> &y) -> int {
                return x.second > y.second;
            });
        // Alternate placing the most common letters
        string ret(len, ' ');
        int idx = 0;
        for (auto it = vec.begin(); it != vec.end(); it++) {
            char ch = it->first;
            int times = it->second;
            for (int i = 1; i <= times; i++) {
                if (idx >= len) idx = 1;
                ret[idx] = ch;
                idx += 2;
            }
        }
        return ret;
    }
};