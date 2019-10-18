class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        for (int i = 0; i < A.size(); i++) {
            vector<char> odd;
            vector<char> even;
            for (int j = 0; j < A[i].length(); j++) {
                if (j%2) odd.push_back(A[i][j]);
                else even.push_back(A[i][j]);
            }
            sort(odd.begin(), odd.end());
            sort(even.begin(), even.end());
            
            string tmp = "";
            for (int p = 0; p < odd.size(); p++) {
                tmp += odd[p];
            }
            for (int q = 0; q < even.size(); q++) {
                tmp += even[q];
            }
            A[i] = tmp;
        }
        set<string> mySet(A.begin(), A.end());
        return mySet.size();
    }
};