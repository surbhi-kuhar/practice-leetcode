  // RECURSION
   int solve(vector<vector<int>>&mat, int i, int j,int ans){
        if( i >= mat.size() || j>= mat[0].size() || mat[i][j]==0) return 0;


        int right = solve(mat, i,j+1,ans);
        int down  = solve(mat, i+1, j,ans);
        int diag  = solve(mat, i+1,j+1,ans);

        return min(right,min(down,diag))+1;

    }

   // RECURSION + MEMOIZATION

    int solve(vector<vector<int>>&mat, int i, int j,int ans,vector<vector<int>>&dp){
        if( i >= mat.size() || j>= mat[0].size() || mat[i][j]==0) return 0;

        if(dp[i][j] != -1) return dp[i][j];


        int right = solve(mat, i,j+1,ans,dp);
        int down  = solve(mat, i+1, j,ans,dp);
        int diag  = solve(mat, i+1,j+1,ans,dp);

        dp[i][j] = min(right,min(down,diag))+1;

        return dp[i][j];

    }


    int countSquares(vector<vector<int>>& matrix) {

        int ans = 0;
        vector<vector<int>>dp(matrix.size()+1,vector<int>(matrix[0].size()+1,-1));
        for(int i=0 ; i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==1){
                    // ans += solve(matrix,i,j,ans);            ( call for recursive function )
                    ans += solve(matrix,i,j,ans,dp);
                }
            }
        }
        
        return ans;

    }
