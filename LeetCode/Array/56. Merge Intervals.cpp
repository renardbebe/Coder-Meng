class Solution {
public:
    static bool cmp (const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        if (intervals.empty()) return ret;
        
        sort(intervals.begin(), intervals.end(), cmp);  // sort by left position !!
        ret.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            vector<int> last = ret.back();
            if(intervals[i][0] <= last[1]) {
                ret[ret.size()-1][1] = max(ret[ret.size()-1][1], intervals[i][1]);
            }
            else {
                ret.push_back(intervals[i]);
            }
        }
        return ret;
    }
};