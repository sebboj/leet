//beats O(n^2)
class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int curr = 0;
        int left = 0;
        for(int i = 0; i<s.size(); i++){
            if(s.substr(left, curr).find(s[i]) != string::npos){
                int loc = s.substr(left, curr).find(s[i]);
                left += loc + 1;
                curr -= loc;   
            }
            else{ 
                curr++;
                if(curr > max)
                    max = curr;
            }
        } 
        return max;
    }
};
