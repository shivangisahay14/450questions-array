brute force: using STL command
 next_permutation(nums.begin(),nums.end());
    
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    
}

optimized approach:O(n)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    
    int n = nums.size(), k, l;
        for(k=n-2; k>=0; k--){
            if(nums[k]<nums[k+1]){
                break;
            }
        }
        if(k<0){
            reverse(nums.begin(), nums.end());
        }
        else{
            for(l=n-1; l>k; l--){
                if(nums[l]>nums[k]){
                    break;
                }
            }
            swap(nums[l], nums[k]);
            reverse(nums.begin()+k+1, nums.end());
        }
        
    }
};
