class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int len = S.length();
        vector<int> ret;
        vector<int> pos;
        for (int i = 0; i < len; i++) {
            if (S[i] == C) {
                pos.push_back(i);
            }
        }
        
        for (int i = 0; i < len; i++) {
            int dis = 0xffffff;
            for (int j = 0; j < pos.size(); j++) {
                if (abs(i - pos[j]) < dis) {
                    dis = abs(i - pos[j]);
                }
                else {
                    break;
                }
            }
            ret.push_back(dis);
        }
        
        return ret;
    }
};