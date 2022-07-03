class Solution {
public:
    int countChar(string s, char c){
        int num = 0;
        for(auto g: s){
            if(g == c) num++;
        }
        return num;
    }
    int rearrangeCharacters(string s, string target) {
        vector<int> count;
        count.assign(target.length(), 0);
        
        for(int i = 0; i < target.length(); i++){
            count[i] = countChar(s, target[i]) / countChar(target, target[i]);
        }
        
        int min = count[0];
        for(int i = 1; i < target.length(); i++){
            if(count[i] < min)
                min = count[i];
        }
        
        return min;
        
        
    }
};
