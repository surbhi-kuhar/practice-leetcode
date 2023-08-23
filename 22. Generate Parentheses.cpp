void solve( int n, int open, int closed, vector<string>&ans, string temp ){
        
        if (temp.size() == 2*n){
            ans.push_back(temp);
            return;
        }

        if( open < n ){
            solve(n, open+1 , closed, ans, temp + '(');
        }

        if( closed < open ){
            solve(n, open, closed+1, ans, temp + ')');
        }
        
}

vector<string> generateParenthesis(int n) {
        
        vector<string>ans;
        string temp = "";
        solve(n,0,0,ans,temp);
        return ans;

}
