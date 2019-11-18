#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 100005

int hIndex (vector<int> nums) {
    if (nums.empty()) return 0;

    sort(nums.begin(), nums.end());
    int n = nums.size();
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (n - mid <= nums[mid]) r = mid;
        else l = mid + 1;
    }
    return min((n-l), nums[l]);
}

int main () {
    int T, N, num;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        cin >> N;
        vector<int> A;
        vector<int> H;
        for (int i = 0; i < N; i++) {
            cin >> num;
            A.push_back(num);
            H.push_back(hIndex(A));
        }

        cout << "Case #" << kase << ":";
        for (int j = 0; j < N; j++) {
            cout << " " << H[j];
        }
        cout << '\n';
    }
}