class Solution {
public:
    bool array_contains(vector<int>& nums, int num) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == num)
                return true;
        }
        return false;
    }
    
    
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        for (int num : nums) {
            int cur_num = num;
            int cur_streak = 1;
            
            while (array_contains(nums, cur_num + 1)) {
                ++cur_num;
                ++cur_streak;
            }
            res = max(res, cur_streak);
        }
        return res;
    }
};


// Time O(nlgn) + O(n) = o(nlgn)
// Space O(1) sort array in place

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        sort(nums.begin(), nums.end());
        int res = 1;
        int cur_streak = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                if (nums[i] == nums[i - 1] + 1) {
                    ++cur_streak;
                } else {
                    // previous streak ends
                    res = max(res, cur_streak);
                    cur_streak = 1;
                }
            } // skip equal
        }
        
        // input [100, 4, 200, 1, 3, 2], cur_streak is 4, res is 1
        return max(res, cur_streak);
    }
};


class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for (int x : nums) {
            if (!s.count(x))
                continue;
            
            s.erase(x);
            int l = x - 1, r = x + 1;
            while (s.count(l)) s.erase(l--);  
            while (s.count(r)) s.erase(r++);
            res = max(res, r - l - 1);
        }
        return res;
    }
};


Unordered_set
Time Complexity: O (n)
Space Complexity: O (n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> uset (nums.begin(), nums.end());
        int res=0;
        for (int n: nums) {
            if (!uset.count(n)) continue;
            else {
                uset.erase(n);
                int prev=n-1, next=n+1;
                while (uset.count(prev)) uset.erase(prev--);
                while (uset.count(next)) uset.erase(next++);
                res=max(res, next-prev-1);
            }
        }
    return res;
    }
};


Time Complexity: O(3N)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hs;
        
        for(auto num :nums)
            hs.insert(num);
        
        int res = 0;
        
        for(auto num:nums){
            if(!hs.count(num-1)){
                int currents = 1;
                int c = num;
                
                while(hs.count(c+1)){
                    c+=1;
                    currents+=1;
                }
                
                res = max(res, currents);
            }
        }
        
        return res;
    }
};
