// https://www.youtube.com/watch?v=LPFhl65R7ww
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        if (len1 == 0) {
            int len = nums2.size();
            int mid = len / 2;
            if (len % 2 == 0) {  // even
                return ((nums2[mid-1] + nums2[mid]) / 2.0);
            }
            else {
                return nums2[mid];
            }
        }
        else if (len2 == 0) {
            int len = nums1.size();
            int mid = len / 2;
            if (len % 2 == 0) {  // even
                return ((nums1[mid-1] + nums1[mid]) / 2.0);
            }
            else {
                return nums1[mid];
            }
        }
        
        if (len1 > len2) {
            swap(nums1, nums2);
            swap(len1, len2);
        }
        // len(nums1) < len(nums2)
        int low = 0, high = len1;
        while (low <= high) {
            int mid1 = (low + high) / 2;  // location of partition 1
            // left part >= right part
            int mid2 = ((len1 + len2 + 1) / 2) - mid1;  // location of partition 2
            
            if (mid1 < high && nums1[mid1] < nums2[mid2-1]) {
                // mid1 is too small
                low = mid1 + 1;
            }
            else if (mid1 > low && nums1[mid1-1] > nums2[mid2]) {
                // mid1 is too large
                high = mid1 - 1;
            }
            else {
                int maxLeft = 0, minRight = 0;
                
                // get the max of left partitions
                if (mid1 == 0) maxLeft = nums2[mid2-1];
                else if (mid2 == 0) maxLeft = nums1[mid1-1];
                else maxLeft = max(nums1[mid1-1], nums2[mid2-1]);
                
                // when total length is odd
                if ((len1 + len2) % 2) return maxLeft;
                
                // get the min of right partitions
                if (mid1 == len1) minRight = nums2[mid2];
                else if (mid2 == len2) minRight = nums1[mid1];
                else minRight = min(nums1[mid1], nums2[mid2]);
                
                return (maxLeft + minRight) / 2.0;
            }
        }
        return -1;
    }
};