int findParent ( int ele , vector<int>&parent) {
        if(parent[ele] == ele) return ele;
        return findParent(parent[ele],parent);
    }

vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        vector<int>parent(n+1);

        for(int i=0 ; i<=n ;i++){
            parent[i] = i;
        }


        for(vector<int>x : edges){

                int u = x[0];
                int v = x[1];

                int uParent = findParent(u,parent);
                int vParent = findParent(v,parent);
           
                if ( uParent == vParent ){
                   return x;
                }
                else{
                    parent[vParent] = uParent;
                }
            
        }

        return {};
}
