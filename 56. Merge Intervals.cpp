 vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> arr;
        
        for(auto i : intervals){
            if(arr.empty()){
                arr = i;
            }
            else if(arr[1] < i[0]){
                ans.push_back(arr);
                arr = i;
            }
            else{
                arr[1] = max(arr[1], i[1]);
            }
        }
        ans.push_back(arr);
        
        return ans;
        
    }
