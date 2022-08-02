//O(nlogn)
//n = length of nums

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        int max = 0;
        string res;
        
        for(string s: nums)
            if(s.length() > max)
                max = s.length();
        
        for(int i = 0; i < nums.size(); i++)
            nums[i].insert(nums[i].begin(), max - nums[i].length(), '0');
        
        sort(nums.begin(), nums.end());
        res = nums[nums.size() - k];
        
        while(res[0] == '0' && res.length() > 1)
            res = res.substr(1);
        
        return res;
    }
};
