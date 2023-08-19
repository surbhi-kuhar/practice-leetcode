 int edgeScore(vector<int>& edges) {
        
        unordered_map<int,list<int>>adj;   // node, list of nodes pointing to this node

        for(int i=0 ;i<edges.size();i++){
            int u = i;
            int v = edges[i];

            adj[v].push_back(u);
        }

        long long int maxi = 0;
        long long int val = 0;
        for( auto y : adj ){
            long long sum = 0;
            for(auto x : adj[y.first]){
                sum += x;
            }

            if( sum == maxi && y.first < val){
                maxi = sum;
                val = y.first;
            }
           
            if( sum > maxi){
                 maxi = sum;
                 val = y.first;
            }
        }


        return val;
    }
