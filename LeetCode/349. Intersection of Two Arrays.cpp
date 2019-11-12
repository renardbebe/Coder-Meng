class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        set<int> arr1(nums1.begin(), nums1.end());
        set<int> arr2(nums2.begin(), nums2.end());
        int len1 = arr1.size(), len2 = arr2.size();
        if (len1 < len2) {
            for (set<int>::iterator it = arr1.begin(); it != arr1.end(); it++) {
                if (arr2.find(*it) != arr2.end()) ret.push_back(*it);
            }
        }
        else {
            for (set<int>::iterator it = arr2.begin(); it != arr2.end(); it++) {
                if (arr1.find(*it) != arr1.end()) ret.push_back(*it);
            }
        }
        return ret;
    }
};