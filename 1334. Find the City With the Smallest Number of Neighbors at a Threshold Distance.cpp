class Solution {
public:

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        unordered_map<int,list<pair<int,int>>>adj;

        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v= edges[i][1];
            int w= edges[i][2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<pair<int,int>>ans;

        for(int i = 0; i<n; i++){
          
            vector<int>dist(n,INT_MAX);
            dist[i] = 0;

            set<pair<int,int>>s;

            s.insert({i,0});

            while(!s.empty()){

                auto top = *(s.begin());
                s.erase(top);

                int neigh = top.first;
                int w = top.second;

                for(auto y : adj[neigh]){

                    if(w + y.second <dist[y.first] ){
                        dist[y.first] = w+y.second;
                        s.insert({y.first, dist[y.first]});
                    }
                }
            }

            int count = 0;
            for( int j=0 ; j<dist.size() ; j++ ){
                if( j!= i && dist[j] <= distanceThreshold){
                    count++;
                }
            }
           
            ans.push_back({i,count});

        }

        int mini = INT_MAX;
        int res = 0;

        for(int i=0;i<ans.size();i++){
            if(ans[i].second <= mini){
                res = ans[i].first;
                mini = ans[i].second;
            }
        }

        return res;
    }
};
