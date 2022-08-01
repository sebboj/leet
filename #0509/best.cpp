//no repeats

class Solution {
public:
    int dp[31];
    
    int fib(int n) {
        dp[1] = 1;

        if(n != 0 && dp[n] == 0)
            for(int i = 2; i <= n; i++)
                if(dp[i] == 0) dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }
};
