class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        heights.push_back(0);
        stack<int> indexes;
        
        for (int i = 0; i < heights.size(); i++) {
            // 出现了断层点，需要更新断点之前的最大面积
            while (!indexes.empty() && heights[indexes.top()] > heights[i]) {
                int h = heights[indexes.top()]; 
                indexes.pop();
                int l = indexes.empty() ? -1 : indexes.top();
                int area = h * (i - l - 1);
                maxArea = max(area, maxArea);
            }
            indexes.push(i);
        }
        return maxArea; 
    }
};