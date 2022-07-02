class Solution {
public:
    int reverse(int x) {
        const int MIN = pow(-2, 31);
        const int MAX = pow(2, 31) - 1;
        
        int sign = 1;
        
        if(x < 0)
            sign *= -1;
        
        vector<int> temp;
        while(x != 0){
            temp.push_back(abs(x) % 10);
            x /= 10;
        }
        
        if(temp.size() == 10){ //big num
            int check = MAX;
            vector<int> big;

            while(check != 0){
                big.insert(big.begin(), check % 10);
                check /= 10;
            } 
            
            for(int g = 0; g < 10; g++){
                if(g == 9 and sign == -1 and temp[g] > 8){//last digit for negative numbers
                    return 0;
                }
                else if(temp[g] < big[g]){
                    break;
                }
                else if(temp[g] > big[g]){
                    return 0;
                }
            }
            
            big.clear();
        }
        
        int mun = 0;
        
        for(int i = 0; i < temp.size(); i++){
            mun += temp[i] * pow(10, temp.size() - i - 1);
        }
            
        
        temp.clear();
        return mun * sign;
    }
};
