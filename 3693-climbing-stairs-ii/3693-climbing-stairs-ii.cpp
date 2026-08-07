class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;

        for (int j = 1; j <= n; j++) {
            dp[j] = INT_MAX;

            if (j - 1 >= 0) dp[j] = min(dp[j], dp[j - 1] + costs[j - 1] + 1);
            if (j - 2 >= 0) dp[j] = min(dp[j], dp[j - 2] + costs[j - 1] + 4);
            if (j - 3 >= 0) dp[j] = min(dp[j], dp[j - 3] + costs[j - 1] + 9);
        }

        return dp[n];
    }
};

// class Solution {
// public:

//     int solve(int i,int n, vector<int>& costs,vector<int>&dp){
//         if(i>n) return INT_MAX;

//         if(i==n) return 0;

//         if(dp[i]!=-1) return dp[i];

//         int onestep=(costs[i]+1)+solve(i+1,n,costs,dp);
//         int twostep=(i+2<=n)? (costs[i+1]+4)+solve(i+2,n,costs,dp):INT_MAX;
//         int threestep=(i+3<=n)?(costs[i+2]+9)+solve(i+3,n,costs,dp):INT_MAX;

//         return dp[i]=min({onestep,twostep,threestep});
//     }

//     int climbStairs(int n, vector<int>& costs) {
//         vector<int> dp(n+1,-1);
//         return solve(0,n,costs,dp);
//     }
// };

