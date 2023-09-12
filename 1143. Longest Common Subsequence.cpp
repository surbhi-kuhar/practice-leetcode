// RECURSION 

int solve(int index1, int index2, string text1, string text2)
{
        if(index1 < 0 || index2 < 0) return 0;

        int match = 0;
        int notMatch  = 0;

        if(text1[index1] == text2[index2]){
            match += 1 + solve(index1-1, index2-1, text1, text2);
        }

        notMatch += max (solve(index1-1, index2, text1, text2), solve(index1, index2-1, text1, text2));

        return max(match, notMatch);

}

// RECURSION + MEMOIZATION

int solve(int index1, int index2, string text1, string text2, vector<vector<int>>&dp)
{
        if(index1 < 0 || index2 < 0) return 0;

        int match = 0;
        int notMatch  = 0;

        if(dp[index1][index2] != -1) return dp[index1][index2];

        if(text1[index1] == text2[index2]){
            match += 1 + solve(index1-1, index2-1, text1, text2, dp);
        }

        notMatch += max (solve(index1-1, index2, text1, text2, dp), solve(index1, index2-1, text1, text2, dp));

        dp[index1][index2] =  max(match, notMatch);

        return dp[index1][index2];

}

// TABULATION

int solve(int n, int m, string text1, string text2)
{

        vector<vector<int>>dp(n+1, vector<int>(m+1,0));

        for( int i = 0 ; i<= m ;i++) dp[0][i] = 0;
        for( int i = 0 ; i<= n ; i++) dp[i][0] = 0;

        for( int i = 1; i<=n ;i++){
            int match = 0;
            int notMatch  = 0;
            for( int j = 1 ; j<=m ;j++){
                 if(text1[i-1] == text2[j-1]){
                    match = 1 + dp[i-1][j-1];
                  }

                  notMatch = max(dp[i-1][j], dp[i][j-1]);
                  
                  dp[i][j] =  max(match, notMatch);

            }
            
        }
    
        return dp[n][m];

}

int longestCommonSubsequence(string text1, string text2) 
{
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        return solve(n-1, m-1, text1, text2);                  // recursion
        return solve(n-1, m-1, text1, text2, dp);              // recursion + memoization            
        return solve(n, m, text1, text2);                      // tabulation 
}
