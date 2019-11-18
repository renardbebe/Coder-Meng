class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if (start > destination) swap(start, destination); // important
        int dir1Dis = 0, dir2Dis = 0;
        for (int i = 0; i < distance.size(); i++) {
            if (i >= start && i < destination) {
                dir1Dis += distance[i];
            }
            else dir2Dis += distance[i];
        }
        return min (dir1Dis, dir2Dis);
    }
};