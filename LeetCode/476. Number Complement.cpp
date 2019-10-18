class Solution {
public:
    string toBinary (int n) {
        string ret = "";
        while(n) {
            ret += char((n%2) + '0');
            n /= 2;
        }
        return ret;
    }
    
    int findComplement(int num) {
        string vbin = toBinary(num);
        int ret = 0;
        for (int i = 0; i < vbin.length(); i++) {
            ret += abs(1 - (vbin[i] - '0')) * pow(2, i);
        }
        return ret;
    }
};