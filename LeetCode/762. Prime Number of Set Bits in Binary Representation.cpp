class Solution {
public:
    int count (int n) {
        int ones = 0;
        while (n) {
            if (n%2) ones++;
            n /= 2;
        }
        return ones;
    }
    
    int countPrimeSetBits(int L, int R) {
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
        int cnt = 0;
        for (int i = L; i <= R; i++) {
            if (find(primes.begin(), primes.end(), count(i)) != primes.end())
                cnt++;
        }
        return cnt;
    }
};