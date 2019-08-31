class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int len = A.size();
        int n = len / 2, ret = 0;
        map<int, int> myMap;
        for (int i = 0; i < len; i++) {
            myMap[A[i]] += 1;
        }
        for (int i = 0; i < myMap.size(); i++) {
            if (myMap[i] == n) {
                ret = i;
            }
        }
        return ret;
    }
};