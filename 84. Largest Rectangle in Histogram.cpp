vector<int> nextSmallest(vector<int>&heights, int n){
            vector<int>ans(n);

            stack<int>st;    // push only indexes in stack
            st.push(-1);

            for( int i= n-1 ;i>=0 ;i--){
                while(st.top() != -1 && heights[st.top()] >= heights[i]){
                    st.pop();
                }
                ans[i] = st.top();
                st.push(i);

            }

            return ans;

        }

        vector<int> prevSmallest(vector<int>&heights,int n){

            vector<int>ans(n);

            stack<int>st;
            st.push(-1);

            for( int i= 0 ;i<n ;i++){
                while(st.top() != -1 && heights[st.top()] >= heights[i]){
                    st.pop();
                }
                ans[i] = st.top();
                st.push(i);

            }

            return ans;

        }

 int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int>next(n);
        next = nextSmallest(heights,n);

        vector<int>prev(n);
        prev = prevSmallest(heights,n);

        int ans = INT_MIN;

        for( int i=0 ; i<n ; i++){
           
            int l = heights[i];

            if( next[i] == -1) next[i] = n; 
             // for the case [2,2,2,2] next =[-1,-1,-1,-1] && prev[i] = [-1,-1,-1,-1] but prev[i] == -1 is feasible but next[i] == -1 is not because b = -1 +1-1 will give -1 as index which is invalid.

            int b = next[i] - prev[i] - 1 ;

            int newArea = l*b;
            ans = max(ans,newArea);
        }

        return ans;
        
    }
