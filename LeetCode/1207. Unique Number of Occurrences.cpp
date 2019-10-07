class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int cnt = 1;
        int appear[1005];
        memset(appear, 0, sizeof(appear));

        for (int i = 0; i < arr.size(); i++) {
            if (i != arr.size()-1 && arr[i] == arr[i+1]) cnt++;
            else {
                if (appear[cnt]) return false;
                else appear[cnt] = 1;
                cnt = 1;
            }
        }
        return true;
    }
};