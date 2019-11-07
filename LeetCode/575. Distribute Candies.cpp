class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        set<int> st(candies.begin(), candies.end());
        int n1 = candies.size() / 2;
        int n2 = st.size();
        return min(n1, n2);
    }
};