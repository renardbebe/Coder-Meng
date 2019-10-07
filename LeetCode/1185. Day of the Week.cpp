class Solution {
public:
    bool isYear (int y) {
        return (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0));
    }
    
    string dayOfTheWeek(int day, int month, int year) {
        // 1971-1-1 Friday
        vector<string> week = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
        vector<int> D = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int w = 0;
        for (int y = 1971; y < year; y++) {
            if (isYear(y)) w += 366;
            else w += 365;
        }
        for (int m = 1; m < month; m++) {
            w += D[m-1];
        }
        if (isYear(year) && month > 2) w += 1;
        w += (day - 1);
        return week[w % 7];
    }
};