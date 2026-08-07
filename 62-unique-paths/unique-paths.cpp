class Solution {
public:
    int solve(int m,int n,int i,int j,vector<vector<int>> &dp){
        if(i<0 ||j<0 ||i>=m ||j>=n){
            return 0;
        }
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=solve(m,n,i,j+1,dp);
        int bot=solve(m,n,i+1,j,dp);
        return dp[i][j]=right+bot;
    }
    int solveTab(int m,int n){
        vector<vector<int>> dp(m,vector<int> (n,-1));
        dp[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1)
                    continue;

                int right = 0;
                int down = 0;

                if(i+1 < m)
                    down = dp[i+1][j];

                if(j+1 < n)
                    right = dp[i][j+1];

                dp[i][j] = right + down;
            }
        }
        return dp[0][0];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        // return solve(m,n,0,0,dp);
        return solveTab(m,n);
    }
};