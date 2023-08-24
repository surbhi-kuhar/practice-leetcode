 bool isEvenOddTree(TreeNode* root) {

        queue<TreeNode*>q;

        q.push(root);
        q.push(NULL);

        int index = 0;
        int temp = -1;

        while(!q.empty()){
            TreeNode*top = q.front();
            q.pop();

            if(top != NULL){

                if( index % 2 == 0){
                    if(top->val % 2 == 0)  return false;
                }
                else{
                    if(top->val % 2 !=0 ) return false;
                }

                if(top->left){
                    q.push(top->left);
                }

                if(top->right){
                    q.push(top->right);
                }

            }

            else if(!q.empty()){
                q.push(NULL);

                index++;
                temp = -1;

                while(q.front() != NULL){
                    if ( index % 2 ==0){

                        if( q.front()->val % 2 == 0 || temp != -1 && q.front()->val <= temp){
                            return false;
                        }
                            temp = q.front()->val;
                            q.push(q.front());
                            q.pop();
                      
                    }
                    else{

                        if( q.front()->val % 2 != 0 || (temp != -1 && q.front()->val >= temp)){
                            return false;
                        }

                            temp = q.front()->val;
                            q.push(q.front());
                            q.pop();
                            
                    }
                }

                q.pop();
                q.push(NULL);


            }
        }

        return true;

}
