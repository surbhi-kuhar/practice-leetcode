// APPROACH 1

bool divisorGame(int n) {

        if(n%2 ==0 ) return true;

        return false;
              
}

// APPROACH 2 ( Recursion )

bool solve (int n){

        if ( n==1 ) return false;
        if ( n==2 ) return true;

        for( int x = 1; x<n ; x++){
            if( n%x == 0 ){
                return !solve(n-x);
            }
        }
        return false;
}

bool divisorGame(int n) {
        return solve(n);
}

// APPROACH 3 ( Recursion + Memoization )

bool solve (int n, vector<bool>&dp){

        if ( n==1 ) return false;
        if ( n==2 ) return true;

        if( dp[n] != false ) return dp[n];

        for( int x = 1; x<n ; x++){
            if( n%x == 0 ){
                dp[n] = !solve(n-x,dp);
                return dp[n];
            }
        }
        return dp[n];
}

bool divisorGame(int n) {

        vector<bool>dp(n+1,false);
        return solve(n,dp);
}

// APPROACH 4 ( DP )

bool solve (int n){

        vector<bool>dp(n+1,false);

        for ( int i = 1 ;i<=n ;i++){
            if( i == 1) dp[i] = false;
            else if( i == 2) dp[i] = true;

            else {
                for( int j = 1; j<n ;j++){
                    if(i%j ==0){
                        dp[i] = !dp[i-j];
                        break;
                    }
                }
            }
        }

        return dp[n];
}

bool divisorGame(int n) {
  
         return solve(n);
}

