class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> textList;
        string tmp = "";
        for (int i = 0; i < text.length(); i++) {
            if (text[i] == ' ') {
                textList.push_back(tmp);
                tmp = "";
            }
            else {
                tmp += text[i];
            }
        }
        if (tmp != "") textList.push_back(tmp);
            
        vector<string> ret;
        int len = textList.size();
        for (int i = 0; i+2 < len; i++) {
            if (textList[i] == first && textList[i+1] == second) {
                ret.push_back(textList[i+2]);
            }
        }
        return ret;
    }
};