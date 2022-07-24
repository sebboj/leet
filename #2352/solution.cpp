//brute force

class Solution {
public:
    
    int check(int r, int c, vector<vector<int>>& g){
        for(int i = 0; i < g.size(); i++)
            if(g[r][i] != g[i][c])
                return 0;
        return 1;
    }
    
    int equalPairs(vector<vector<int>>& grid) {
        int res = 0;
        for(int r = 0; r < grid.size(); r++)
            for(int c= 0; c < grid.size(); c++)
                res += check(r, c, grid);
        return res;
    }
};
