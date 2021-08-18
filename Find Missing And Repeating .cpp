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

Swap Sort:
int i=0;
        int *ans=new int(2);
        while(i<n){
            if(arr[i]!=arr[arr[i]-1]){
                swap(arr[i],arr[arr[i]-1]);
            }else i++;
        }
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1){
                ans[0]=arr[i];
                ans[1]=i+1;
            }
        }
        return ans;
        
