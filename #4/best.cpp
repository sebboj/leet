class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        nums.assign((nums1.size()+nums2.size())/2 + 1, 0);
        int pos1 = 0;
        int pos2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(pos1 < nums1.size() and pos2 < nums2.size()){
                if(nums1[pos1] < nums2[pos2]){
                    nums[i] = nums1[pos1];
                    pos1++;
                }
                else{
                    nums[i] = nums2[pos2];
                    pos2++;
                }
            }
            else if(pos1 <nums1.size()){
                nums[i] = nums1[pos1];
                    pos1++;
            }
            else{
                    nums[i] = nums2[pos2];
                    pos2++;
                }
        }
        if((nums1.size()+nums2.size())%2 == 0)
            return (nums[nums.size()-1] + nums[nums.size()-2]) / 2.0;
        return nums[nums.size()-1]/1.0;
    }
};
