class Solution {
public:
    string convert (int n) {
        string s = "";
        while (n) {
            s = char(n % 2 + '0') + s;
            n /= 2;
        }
        return s;
    }
    int binaryGap(int N) {
        string bin = convert(N);
        int ret = 0, pos = 0;
        for (int i = 0; i < bin.length(); i++) {
            if (bin[i] == '1') {
                if (pos != i) {
                    int len = (i - pos);
                    ret = max(ret, len);
                    pos = i;
                }
            }
        }
        return ret;
    }
};