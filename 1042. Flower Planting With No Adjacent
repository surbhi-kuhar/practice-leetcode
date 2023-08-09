int solve(int a, int b, int x,int pos, set<int>&s, bool back, vector<vector<int>>&dp){

        if( pos == x ) return 0;

        if ( pos <0 || pos > 6000 ||  s.find(pos) != s.end()) return 1e9;

        if(dp[pos][back] != -1) return dp[pos][back];

        dp[pos][back] = solve(  a , b , x , pos + a , s, false,dp) + 1;

        if(!back) dp[pos][back] = min( dp[pos][back], solve(  a , b , x , pos - b, s, true,dp) + 1) ;

        return dp[pos][back];

    }

    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {

        set<int>s;
        for( int i=0 ; i < forbidden.size() ; i++ ) s.insert(forbidden[i]);

        vector<vector<int>>dp(6001,vector<int>(2,-1));

        int ans = solve(a, b, x,0,s,0,dp);
        if (ans >= 1e9) return -1;
        return ans;
        
    }
