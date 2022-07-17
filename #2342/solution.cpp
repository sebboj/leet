class Solution {
public:
    int digitsum(int n){
        int sum = 0;
        
        while(n > 0){
            sum += n % 10;
            n /= 10;
        }
            
        return sum;
    }
    
    int nopairs(vector<int> arr){
        sort(arr.begin(), arr.end());
        for(int i = 1; i < arr.size(); i++)
            if(arr[i] == arr[i - 1])
                return 1;
        return 0;
    }
    
    int maximumSum(vector<int>& nums) {
        vector<int> sums(nums.size(), 0);
        vector<int> maxsums(nums.size(), 0);
        int max = 0;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++)
            sums[i] = digitsum(nums[i]);
        
        if(nopairs(sums) == 0)
            return -1;
       
        unordered_map<int, int> check;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(check[sums[i]] == NULL)
                check[sums[i]] = i;
            else if(nums[check[sums[i]]] + nums[i] > max)
                max = nums[check[sums[i]]] + nums[i];
        }
        
        return max;     
    }
};
