class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        int bingo = 0;
        
        bingo = 1;
        for(int i = 0; i < 4; i++)
            if(suits[i] != suits[i + 1]) bingo = 0;
        if(bingo) return "Flush";
        
        int cards[13] = {0};
        for(int n: ranks)
            cards[n - 1]++;
        
        bingo = 0;
        for(int i = 0; i < 13; i++)
            if(cards[i] > bingo) bingo = cards[i];
        
        if(bingo >= 3) return "Three of a Kind";
        
        if(bingo > 1) return "Pair";
        
        return "High Card";
    }
};
