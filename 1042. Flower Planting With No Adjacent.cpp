vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {

        if(paths.size() == 0) return vector<int>(n,1);

        unordered_map<int,list<int>>adj;

        for(int i = 0 ; i < paths.size() ; i++){

            int u = paths[i][0];
            int v = paths[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        vector<int>colors(n+1,-1);
      
        for(auto x : adj){
            vector<bool>colors_used(4,0);

            for(auto y: x.second){
                if( colors[y] != -1 ){
                    colors_used[colors[y]-1] = 1 ;
                }
            }

            for(int i = 0 ; i < 4 ; i++){
                if( colors_used[i] == 0 ){
                    colors[x.first] = i+1;
                    break;
                } 
            }

        }

        vector<int>ans;
        for(int i = 1;i<colors.size();i++) {
            if(colors[i] == -1){
                ans.push_back(1);
            }
            else ans.push_back(colors[i]);
        }

        return ans;   
    }
