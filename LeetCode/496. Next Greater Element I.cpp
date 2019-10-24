class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        nums2.push_back(0);  // set an end
        
        vector<int> ret;
        for (int i = 0; i < nums1.size(); i++) {
            vector<int>::iterator it = find(nums2.begin(), nums2.end(), nums1[i]);
            bool find = false;
            for (vector<int>::iterator j = it+1; j < nums2.end(); j++) {
                if (*j > nums1[i]) {
                    ret.push_back(*j);
                    find = true;
                    break;
                }
            }
            if (!find) ret.push_back(-1);
        }
        return ret;
    }
};