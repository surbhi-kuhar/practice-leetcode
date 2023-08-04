// RECURSIVE 

    // int solve(int n){
      //     if(n<4) return n;
  
      //     int ans  = n;
  
      //     for(int i = 1; i*i<=n; i++ ){
      //         ans = min(ans, 1+solve(n-i*i));
      //     }
  
      //     return ans;
    // }

// RECURSION + MEMOIZATION

    int solve(int n,vector<int>&dp){

        if(n<4) return n;

        if(dp[n] != -1) return dp[n];

        int ans  = n;

        for(int i = 1; i*i<=n; i++ ){
            ans = min(ans, 1+solve(n-i*i,dp));
        }
        dp[n] = ans;

        return dp[n];
    }


    int numSquares(int n) {
      
        vector<int>dp(n+1,-1);
        return solve(n,dp);     // call for recursive + memoization function
      //  return solve(n,);     // call for recursive function
      
    }
