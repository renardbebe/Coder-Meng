class Solution {
public:
    static bool cmp (const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), cmp);
        ret.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > ret[ret.size()-1][1]) {
                ret.push_back(intervals[i]);
            }
            else {
                ret[ret.size()-1][0] = min(ret[ret.size()-1][0], intervals[i][0]);
                ret[ret.size()-1][1] = max(ret[ret.size()-1][1], intervals[i][1]);
            }
        }
        return ret;
    }
};