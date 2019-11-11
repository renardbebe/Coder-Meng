class Solution {
public:
    string c_convert(int n) {
        string ret = "";
        if (!n) ret = "1";
        while(n) {
            if (n%2 == 0) 
                ret = '1' + ret;
            else 
                ret = '0' + ret;
            n /= 2;
        }
        return ret;
    }
    
    int bitwiseComplement(int N) {
        string bin = c_convert(N);
        int num = 0, len = bin.length();
        for (int i = len-1; i >= 0; i--) {
            num += (bin[i] - '0') * pow(2, len-1-i);
        }
        return num;
    }
};