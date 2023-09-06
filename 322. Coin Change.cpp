// RECURSIVE APPROACH

int solve(vector<int>&coins, int index, int amount){
        if( index == 0){
           if (amount % coins[0] == 0) return amount/coins[0];
           return 1e9;
        }

        int notTake = solve(coins, index-1, amount);
        int take = INT_MAX;
        if(coins[index] <= amount){
            take = 1 + solve(coins, index, amount-coins[index]);
        }

        return min(take,notTake);

}

// MEMOIZATION

int solve(vector<int>&coins, int index, int amount, vector<vector<int>>&dp){
        if( index == 0){
           if (amount % coins[0] == 0) return amount/coins[0];
           return 1e9;
        }

        if(dp[index][amount] != -1) return dp[index][amount];

        int notTake = solve(coins, index-1, amount, dp);
        int take = INT_MAX;
        if(coins[index] <= amount){
            take = 1 + solve(coins, index, amount-coins[index], dp);
        }

        return dp[index][amount] = min(take,notTake);

}

// TABULATION

int solve(vector<int>&coins, int amount){

        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));

        for(int i=0 ;i<=amount ;i++){
           if (i % coins[0] == 0) dp[0][i] = i/coins[0];
           else dp[0][i] = 1e9;
        }

        for( int i=1 ;i<n ;i++){
            for(int j=0 ;j<=amount ;j++){

                int notTake = dp[i-1][j];
                int take = INT_MAX;
                if(coins[i] <= j){
                    take = 1 + dp[i][j-coins[i]];
                }

                dp[i][j] = min(take, notTake);
            }
        }

        return dp[n-1][amount];
}



int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));

        int ans = solve(coins, n-1, amount);           //   --------> recursive call

        int ans = solve(coins, n-1, amount,dp);         //    --------> memoization call

        int ans = solve(coins, amount);               //     -------> tabulation call
        if ( ans == 1e9) return -1;
        return ans;
}
