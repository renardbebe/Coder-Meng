class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ret;
        for (int i = 0; i < num_people; i++) ret.push_back(0);
        int c = 1;
        while (candies) {
            for (int i = 0; i < num_people; i++) {
                if (candies >= c) {
                    ret[i] += c;
                    candies -= c;
                    c++;
                }
                else {
                    ret[i] += candies;
                    candies = 0;
                    break;
                }
            }
        }
        return ret;
    }
};