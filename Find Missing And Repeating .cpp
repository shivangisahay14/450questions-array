static int ans[2];
         long  totalsum=(n*(n+1))/2;
         long  sqsum=(n*(n+1)*(2*n+1))/6;
         long  missing=0,duplicate=0;
        
        for(int i=0;i<n;i++){
            totalsum-=(long)arr[i];
            sqsum-=((long)arr[i]*(long)arr[i]);
        }
         missing=(totalsum + (sqsum/totalsum))/2;
         duplicate=(missing-totalsum);
        
        ans[0]=duplicate;
        ans[1]=missing;
        
        return ans;
