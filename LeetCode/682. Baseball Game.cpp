class Solution {
public:
    int convert (string s) {
        int h = 0, spos = 0;
        bool flag = true;
        if (s[0] == '-') {
            flag = false;
            spos = 1;
        }      
        for (int i = spos; i < s.length(); i++) {
            h = h * 10 + (s[i] - '0');
        }     
        if(flag) return h;
        else return (0-h);
    }
    
    int calPoints(vector<string>& ops) {
        vector<int> points;
        for (int i = 0; i < ops.size(); i++) {
            int len = points.size();
            if (ops[i] == "+") {
                points.push_back(points[len-1] + points[len-2]);
            }
            else if (ops[i] == "D") {
                points.push_back(2 * points[len-1]);
            }
            else if (ops[i] == "C") {
                points.pop_back();
            }
            else {
                points.push_back(convert(ops[i]));
            }
        }
        int sum = 0;
        for (int i = 0; i < points.size(); i++) sum += points[i];
        return sum;
    }
};