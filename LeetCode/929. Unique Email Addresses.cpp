class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int cnt = 0;
        for (int i = 0; i < emails.size(); i++) {
            int len = emails[i].length();
            string str = "";
            bool shown = false;
            for (int j = 0; j < len; j++) {
                if (shown) {
                    str += emails[i][j];
                }
                else if (emails[i][j] == '.') {
                    continue;
                }
                else if (emails[i][j] == '@') {
                    shown = true;
                    str += emails[i][j];
                }
                else if (emails[i][j] == '+') {
                    while (emails[i][j+1] != '@') j++;
                }
                else 
                    str += emails[i][j];
            }
            emails[i] = str;
        }
        map<string, int> myMap;
        for (int i = 0; i < emails.size(); i++) {
            cout << emails[i] << endl;
            if (myMap[emails[i]]) continue;
            else {
                myMap[emails[i]] = 1;
                cnt += 1;
            }
        }
        return cnt;
    }
};