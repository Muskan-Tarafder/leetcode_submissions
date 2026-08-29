class Solution {
public:
    int solve(vector<int>& nums,int i, int prev,vector<vector<int>> &dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int notTake = solve(nums, i + 1, prev,dp);

        int take = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + solve(nums, i + 1, i,dp);
        }
        // cout<<"take: "<<take<<" nottake:"<<notTake<<endl;
        return dp[i][prev+1]=max(take, notTake);
    }

    int solveTab(vector<int>& nums){
        vector<vector<int>> dp(nums.size()+1,vector<int> (nums.size()+1,0));

        for(int i=nums.size()-1;i>=0;i--){
            for(int prev=i-1;prev>=-1;prev--){
                int notTake = dp[i + 1][prev+1];

                int take = 0;
                if (prev == -1 || nums[i] > nums[prev]) {
                    take = 1 + dp[i + 1][i+1];
                }
                dp[i][prev+1]=max(take,notTake);
            }
        }
        return dp[0][0];
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int> (nums.size()+1,-1));
        // return solve(nums,0,-1,dp);
        return solveTab(nums);
    }
};