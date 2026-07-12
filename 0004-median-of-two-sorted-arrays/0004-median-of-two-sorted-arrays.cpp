class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;

        int medianIndex1 = (total - 1) / 2;
        int medianIndex2 = total / 2;

        int i = 0, j = 0, count = 0, current = 0, prev = 0;

        while (count <= medianIndex2) {
            prev = current;

            if (i < m && (j >= n || nums1[i] <= nums2[j])) {
                current = nums1[i++];
            } else {
                current = nums2[j++];
            }
            count++;
        }

        if (total % 2 == 0) {
            return (prev + current) / 2.0;
        } else {
            return current;
        }
    }
};