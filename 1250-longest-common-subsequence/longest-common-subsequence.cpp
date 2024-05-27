class Solution {
public:
    // int f(string & text1,string&  text2,int i, int j ,vector<vector<int>>&dp){
    //     if(i<0 || j<0)return 0;
    //     if(dp[i][j]!= -1)return dp[i][j];
    //     // matching 
    //     if(text1[i] == text2[j]) return dp[i][j] = 1+ f(text1,text2,i-1,j-1,dp);

    //     // not matching
    //     int ans = 0 + max(f(text1,text2,i-1,j,dp), f(text1,text2,i,j-1,dp));
    //     return dp[i][j] = ans;
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return f(text1,text2,n-1,m-1,dp);

        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        // for(int i = 0;i<n;i++) dp[i][0] =0;
        // for(int j = 0;j<m;j++) dp[0][j] =0;
        // for(int i = 1;i<=n;i++){
        //     for(int j = 1;j<=m;j++){
        //         if(text1[i-1] == text2[j-1]) dp[i][j] = 1+ dp[i-1][j-1];
        //         else dp[i][j] = max(dp[i-1][j] ,dp[i][j-1]);
        //     }
        // }
        // return dp[n][m];


        // ----------------- M3 space optimisation
        vector<int>prev(m+1,0),curr(m+1,0);

        for(int j = 0;j<m;j++) prev[j] =0;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(text1[i-1] == text2[j-1]) curr[j] = 1+ prev[j-1];
                else curr[j] = max(prev[j] , curr[j-1]);
            }
            prev = curr;
        }
        return prev[m];

    }
};