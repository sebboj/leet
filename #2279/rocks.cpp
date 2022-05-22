class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> left;
        int size = capacity.size();
        for(int x = 0; x < size; x++){
            left.push_back(capacity[x] - rocks[x]);
        }
        
        sort(left.begin(), left.end());
        
        int tot = 0;
        
        for(int x = 0; x < size; x++){
            cout << left[x] << " " << additionalRocks << endl;
            if(left[x] > additionalRocks){
                return tot;
            }
            else{
                additionalRocks -= left[x];
                tot++;
            }
        }
        
        return tot;
        
    }
};
