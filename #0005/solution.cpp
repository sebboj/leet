//finally made sense

class Solution {
public:
    string longestPalindrome(string s) {
        string longest = "";
        
        //single char center
        for(int i = 0; i < s.length(); i++){
            if((i == 0 || i == s.length() -  1) && longest.length() == 0) longest = s[i];
            else
                for(int k = 1; k <= s.length() / 2; k++){
                    if((i - k < 0 || i + k >= s.length() || s[i-k] != s[i+k])) break;
                    if(2 * k + 1 > longest.length()) longest = s.substr(i - k, 2 * k + 1);
                }
        }
        
        //double char center
        for(int i = 0; i < s.length() - 1; i++){
            if(s[i] == s[i+1]){
                if(longest.length() < 2) longest = s.substr(i, 2);
                for(int k = 1; k < s.length() / 2; k++){
                    if((i - k < 0 || i + k + 1 >= s.length() || s[i-k] != s[i+k+1])) break;
                    if(2 * k + 2 > longest.length()) longest = s.substr(i - k, 2 * k + 2);
                }
            }
        }
        
        return longest;
    }
};
