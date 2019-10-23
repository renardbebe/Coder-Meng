class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            sort(stones.begin(), stones.end());
            int last = stones.size() - 1;
            if (stones[last] > stones[last - 1]) {
                stones[last] -= stones[last - 1];
                swap(stones[last], stones[last - 1]);
            }
            else {
                stones.pop_back();
            }
            stones.pop_back();
        }
        if (stones.size() == 1) return stones[0];
        else return 0;
    }
};