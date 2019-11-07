class Solution {
public:
    string convert (int n) {
        string s = "";
        while (n) {
            s = char(n%10 + '0') + s;
            n /= 10;
        }
        return s;
    }
    
    vector<string> fizzBuzz(int n) {
        vector<string> ret;
        for (int i = 1; i <= n; i++) {
            string tmp = "";
            if (i % 3 == 0) {
                tmp += "Fizz";
            }
            if (i % 5 == 0) {
                tmp += "Buzz";
            }
            if (i % 3 && i % 5) {
                tmp += convert(i);
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};