class Solution { //long doubles to keep maximum precison
public:
    long double slope(vector<int> point1, vector<int> point2){
        long double one = 1.0;
        long double y2 = one * point2[1];
        long double y1 = one * point1[1];
        long double x2 = one * point2[0];
        long double x1 = one * point1[0];
        return (y2 - y1) / (x2 - x1);
    }
    
    int minimumLines(vector<vector<int>>& stockPrices) {
        
        if(stockPrices.size() == 1){
            return 0;
        }
        
        sort(stockPrices.begin(), stockPrices.end());
        
        vector<long double> slopes;
        for(int o = 0; o < stockPrices.size()-1; o++){
            slopes.push_back(slope(stockPrices[o], stockPrices[o+1]));
        }
        
        int lines = 1;
        for(int x = 0; x < slopes.size() - 1; x++){
            if(slopes[x] != slopes[x+1])
                lines++;
        }
        
        return lines;
    }
};
