class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int pos[1005];
        memset(pos, 0, sizeof(pos));
        sort(arr1.begin(), arr1.end());
        vector<int> ret;
        for (int i = 0; i < arr2.size(); i++) {
            for (int j = 0; j < arr1.size(); j++) {
                if (pos[j]) continue;
                if (arr1[j] == arr2[i]) {
                    ret.push_back(arr1[j]);
                    pos[j] = 1;
                }
            }
        }
        for (int j = 0; j < arr1.size(); j++) {
            if (pos[j] == 0) ret.push_back(arr1[j]);
        }
        return ret;
    }
};