class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> ret;
        int i = 0, j = n - 1;
        while (i <= j) {
            int sum_ = numbers[i] + numbers[j];
            if (sum_ == target) {
                ret.push_back(i + 1);
                ret.push_back(j + 1);
                break;
            }
            else if (sum_ > target) j--;
            else i++;
        }
        return ret;
    }
};