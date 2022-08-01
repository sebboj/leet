//O(nlogn)

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int tot = 0;
        int res = 0;
        for(int n: nums){
            if(n != 0 && tot < n){
                res++;
                tot = n;
            }
        }
        return res;
    }
};
