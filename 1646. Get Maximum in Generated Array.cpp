  int getMaximumGenerated(int n) {

        if( n==0 ) return 0;

        int arr[n+1];
        arr[0] = 0;
        arr[1] = 1;

        for(int i = 1; i<=n ; i++){
            if( (2*i) >=2 && (2*i)<=n){
                arr[2*i] = arr[i];
            }
            if( (2*i+1) >=2 && (2*i+1)<=n){
                arr[2*i+1] = arr[i] + arr[i+1];
            }
        }
        
        int ans = INT_MIN;
        for(int i=0; i<=n ;i++){
            if(arr[i]>ans){
                ans = arr[i];
            }
        }
        return ans;
    }
