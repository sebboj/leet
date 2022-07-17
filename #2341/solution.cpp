class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int count[101] = {0};
        int p = 0;
        vector<int> ans(2, 0);
        
        for(int n: nums)
            count[n]++;
        
        for(int i = 0; i < 101; i++)
            ans[0] += count[i] / 2;
        
        ans[1] = nums.size() - ans[0] * 2;
        
        return ans;
            
    }
};
