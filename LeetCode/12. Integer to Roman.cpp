class Solution {
public:
    string intToRoman(int num) {
        string roman = "";
        int val[7] = {1000, 500, 100, 50, 10, 5, 1};
        int mod[7] = {1000, 100, 100, 10, 10, 1, 1};
        char symbol[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        int i = 0;
        for (int i = 0; i < 7; i++) {
            int n = num / val[i];
            if (n == 0) {
                continue;
            }
            
            int top = num / mod[i];
            if (top == 9) {
                roman += symbol[i+1];
                roman += symbol[i-1];
                num -= top * mod[i];
            }
            else if (top == 4) {
                roman += symbol[i];
                roman += symbol[i-1];
                num -= top * mod[i];
            }
            else {
                while (n--) roman += symbol[i];
                num %= val[i];
            }
        }
        return roman;
    }
};