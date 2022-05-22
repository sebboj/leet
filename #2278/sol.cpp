class Solution {
public:
    int percentageLetter(string s, char letter) {
        int p = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == letter)
                p++;
        }
        p *= 100;
        return p / s.size();
    }
};
