 int widthOfBinaryTree(TreeNode* root) {

      queue<pair<TreeNode*,int>>q;
      q.push({root,0});

      long long ans = 0;
      
      while(!q.empty()){

        int n = q.size();
        long long start = q.front().second;
        long long end = q.back().second;
        ans = max(ans,end-start+1);

        for(int i =0 ; i < n; i++){
           auto top = q.front();
           TreeNode* node = top.first;
           long long index = top.second;
           q.pop();

           if(node->left){
             q.push({node->left,2*index+1});
           }
           if(node->right){
             q.push({node->right,2*index+2});
           }
        }

      }
      
      return ans;
}
