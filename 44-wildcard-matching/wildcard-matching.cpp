class Solution {
public:
    bool isAllStar(string &p , int j){
        for(int i = 0;i<=j;i++){
            if(p[i]!= '*')return false;
        }
        return true;
    }
    bool f(string &s, string &p , int i , int j, vector<vector<int>>&dp){
        if(i<0 && j<0) return true;
        if(i >= 0 && j<0)return false;
        if(i<0 && j>=0) return isAllStar(p,j);

        if(dp[i][j] != -1)return dp[i][j];

        if(s[i] == p[j] || p[j]== '?'){
            return dp[i][j]=  f(s,p,i-1,j-1,dp);
        }
        if(p[j] == '*'){
            return dp[i][j] = f(s,p,i-1,j,dp) || f(s,p,i,j-1,dp);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return  f(s,p,n-1,m-1,dp);
    }
};