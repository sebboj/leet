class Solution { //O(n) hash map cheat code
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sol;
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            if(map.find(target-nums[i]) == map.end())
                map[nums[i]] = i;
            else{
                sol.push_back(map[target-nums[i]]);
                sol.push_back(i);
                break;
            }   
        }
        return sol;
    }
};
