class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt = 0;
        string str1 = "", str2 = "";
        while (x) {
            str1 += ((x % 2) + '0');
            x /= 2;
        }
        while (y) {
            str2 += ((y % 2) + '0');
            y /= 2;
        }
        
        int len1 = str1.length(), len2 = str2.length();
        if (len1 < len2) {
            for (int i = 0; i < (len2-len1); i++)
                str1 = str1 + '0';
        }
        else if (len1 > len2) {
            for (int i = 0; i < (len1-len2); i++)
                str2 = str2 + '0';
        }
        
        for (int i = 0; i < str1.length(); i++) {
            if (str1[i] != str2[i])
                cnt++;
        }
        return cnt;
    }
};