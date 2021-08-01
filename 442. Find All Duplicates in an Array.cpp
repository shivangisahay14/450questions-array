vector<int> findDuplicates(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>v;
        for(int i=0;i<n;i++){
            
            int index=abs(nums[i])-1;
            if(nums[index]<0){
                v.push_back(index+1);
            }
            nums[index]=-nums[index];           
            
        }
        
        return v;
        
    }
