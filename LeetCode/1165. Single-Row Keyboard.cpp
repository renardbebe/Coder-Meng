class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int sum = 0, last_pos = 0;
        vector<int> move;
        move.push_back(0);
        for (int i = 0; i < word.length(); i++) {
            int pos = keyboard.find(word[i]);
            sum += (pos - last_pos);
            last_pos = pos;
        }
        return sum;
    }
};