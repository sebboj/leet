class Solution { //O(n)
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1){
            return s;
        }
        
        string zig = "";
        
        for(int i = 0; i < numRows; i++){
            if(i == 0 or i == numRows - 1){ //ends
                int c = i;
                while(c < s.size()){
                    zig += s[c];
                    c += 2 * numRows - 2;
                }
                
            }
            else if(numRows % 2 == 1 && i == numRows / 2){ //middle
                int c = numRows / 2;
                while(c < s.size()){
                    zig += s[c];
                    c += numRows - 1;
                    cout << c << "mid" << endl;
                }
            }
            else{ //everything else
                int c = i;
                bool buff = true;
                while(c < s.size()){
                    zig += s[c];
                    if(buff){
                        c += 2 * numRows - (2 * i) - 2;
                        buff = !buff;
                    }
                    else{
                        c += (2 * i);
                        buff = !buff;
                    }
                }
            }
        }
        return zig;
    }
};
