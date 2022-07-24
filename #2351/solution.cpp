//linear

class Solution {
public:
    char repeatedCharacter(string s) {
        int abc[26] = {0};
        
        for(char c: s){
            abc[c - 'a']++;
            if(abc[c - 'a'] == 2)
                return c;
        }
            
        return 'a';
    }
};
