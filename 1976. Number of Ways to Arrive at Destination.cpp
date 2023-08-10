int countPaths(int n, vector<vector<int>>& roads) 
    {
        unordered_map<int,list<pair<int,int>>>adj;

        for(int i = 0 ; i<roads.size() ; i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        } 

        set<pair<long long,long long>>s;
        vector<long long>dist(n+1,LLONG_MAX);
        vector<long long>dp(n+1,0);   // it stores number of ways to reach a node

        s.insert({0,0});

        dist[0] = 0;
        dp[0] = 1;

        int MOD = 1e9 + 7;

        while(!s.empty()){

            pair<long long,long long> p = *(s.begin());
            s.erase(s.begin());

            for(auto x: adj[p.second]){
                
                if( p.first + x.second < dist[x.first] ){
                    
                    dist[x.first] = p.first + x.second;
                    s.insert({ dist[x.first] ,x.first});
                    dp[x.first] = dp[p.second];
                    
                }

                else if ( p.first + x.second  == dist[x.first] ) {
                    dp[x.first] = ((long long) dp[x.first] + dp[p.second]) % MOD;
                }  
                 
            }
        }

        return dp[n-1];

    }
