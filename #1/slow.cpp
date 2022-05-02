class Solution { //O(n^2) complexity gross
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sol;
        for(int i = 0; i < nums.size(); i++){
            sol.clear();
            sol.push_back(i);
            int looking = target - nums[i];
            for(int j = 0; j < nums.size(); j++){
                if(i != j and nums[j] == looking){
                    sol.push_back(j);
                    return sol;
                }    
            }
        }
        return sol;
    }
};
