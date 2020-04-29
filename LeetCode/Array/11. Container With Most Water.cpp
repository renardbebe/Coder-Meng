class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxn = 0;
        int i = 0, j = height.size() - 1;  // 2 pointers, maxArea is determined by shorter height
        while (i <= j) {
            int area = min(height[i], height[j]) * (j - i);
            maxn = max(maxn, area);
            if (height[i] < height[j]) {
                i++;
            }
            else {
                j--;
            }
        }
        return maxn;
    }
};