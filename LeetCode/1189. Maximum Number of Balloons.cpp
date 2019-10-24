class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> cnt;
        for (int i = 0; i < text.length(); i++) {
            cnt[text[i]] += 1;
        }
        int least1 = min(cnt['b'], cnt['a']);
        least1 = min (least1, cnt['n']);
        int least2 = min(cnt['l'], cnt['o']);
        if (2 * least1 > least2) {
            if(least2 % 2 == 0) return (least2 / 2);
            else return ((least2 - 1) / 2);
        }
        else return least1;
    }
};