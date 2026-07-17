class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int A = m - 1;
        int B = n - 1;
        int right = m + n - 1;

        while (B >= 0) {
            if (A >= 0 && nums1[A] > nums2[B]) {
                nums1[right] = nums1[A];
                A--;
            } else {
                nums1[right] = nums2[B];
                B--;
            }
            right--;
        }
    }
};