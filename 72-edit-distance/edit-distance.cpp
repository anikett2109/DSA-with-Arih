class Solution {
public:
    int f(string & word1, string & word2 , int i , int j ,vector<vector<int>>&dp){
        if(i<0){
            return j+1; // word1 is exhausted so we print the count of string 2 that is left
        }
        if(j<0){
            return i+1; // word1 is exhausted so we print the count of string 2 that is left
        }
        if(dp[i][j]!= -1)return dp[i][j];

        if(word1[i]== word2[j]) return dp[i][j] = 0+ f(word1,word2, i-1 , j-1,dp);
        return dp[i][j] = 1+ min({ f(word1,word2, i-1 , j-1,dp),f(word1,word2, i , j-1,dp),f(word1,word2, i-1 , j,dp)});

    }
    int minDistance(string word1, string word2) {
        int n = word1.length() , m = word2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(word1, word2, n-1, m-1, dp);
    }
};