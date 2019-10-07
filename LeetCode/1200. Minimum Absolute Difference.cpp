class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int minn = 0xffffff;
        sort(arr.begin(), arr.end());
        vector<vector<int>> ret;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i-1] < minn) minn = arr[i] - arr[i-1];
        }
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i-1] <= minn) {
                vector<int> tmp;
                tmp.push_back(arr[i-1]);
                tmp.push_back(arr[i]);
                ret.push_back(tmp);
            }
        }
        return ret;
    }
};