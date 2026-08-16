class Solution {
public:

    int solve(int i, string &s, vector<int>& dp) {

       
        if(i == s.size())
            return 1;

       
        if(s[i] == '0')
            return 0;

        
        if(dp[i] != -1)
            return dp[i];

       
        int oneDigit = solve(i + 1, s, dp);

        
        int twoDigit = 0;

        if(i + 1 < s.size()) {

            int num = (s[i] - '0') * 10
                    + (s[i + 1] - '0');

            if(num >= 10 && num <= 26) {
                twoDigit = solve(i + 2, s, dp);
            }
        }

        
        dp[i] = oneDigit + twoDigit;

        return dp[i];
    }

    int numDecodings(string s) {

        int n = s.size();

        vector<int> dp(n, -1);

        return solve(0, s, dp);
    }
};