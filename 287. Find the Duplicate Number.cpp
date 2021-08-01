Brute force: sort the array and use the condition ; if(a[i]==a[i+1])

int findDuplicate(vector<int>& nums) {
        
        int n=nums.size();
        int ans;
        for(int i=0;i<n;i++){
            
            nums[nums[i]%n]+=n;            
           
            
        }
        for(int i=0;i<n;i++){
             if(nums[i]/n > 1){
                ans=i;
                break;
            }
        }
        return ans;
        
    }


Solution 1:

Approach:The elements in the array is from 0 to n-1 and all of them are positive.
So to find out the duplicate elements, a HashMap is required, but the question is to solve the problem in constant space. 
There is a catch, the array is of length n and the elements are from 0 to n-1 (n elements). The array can be used as a HashMap.
Algorithm:
Traverse the array from start to end.
For every element,take its absolute value and if the abs(array[i])‘th element is positive, the element has not encountered before,
else if negative the element has been encountered before print the absolute value of the current element.
Implementation:


void printRepeating(int arr[], int size) 
{ 
int i; 
cout << "The repeating elements are:" << endl; 
for (i = 0; i < size; i++) 
{ 
    if (arr[abs(arr[i])] >= 0) 
    arr[abs(arr[i])] = -arr[abs(arr[i])]; 
    else
    cout << abs(arr[i]) << " "; 
} 
} 

Complexity Analysis:
Time Complexity: O(n), only one traversal is needed, so time complexity is O(n)
Auxiliary Space: O(1), no extra space is required, so space complexity is constant.


Alternate Solution:

Approach: The basic idea is to use a HashMap to solve the problem.
But there is a catch, the numbers in the array are from 0 to n-1, and the input array has length n.
So, the input array can be used as a HashMap. While Traversing the array, if an element ‘a’ is encountered then increase the value of a%n‘th element by n.
The frequency can be retrieved by dividing the a % n’th element by n.

Algorithm:
Traverse the given array from start to end.
For every element in the array increment the arr[i]%n‘th element by n.
Now traverse the array again and print all those indexes i for which arr[i]/n is greater than 1. Which guarantees that the number n has been added to that index
This approach works because all elements are in the range from 0 to n-1 and arr[i] would be greater than n only if a value “i” has appeared more than once.

Implementation:

int main() 
{ 
      
    int numRay[] = {0, 4, 3, 2, 7, 8, 2, 3, 1}; 
    int arr_size = sizeof(numRay) /  
                   sizeof(numRay[0]);  
    for (int i = 0; i < arr_size; i++) 
    { 
        numRay[numRay[i] % arr_size] = numRay[numRay[i] % arr_size] + arr_size; 
    } 
    cout << "The repeating elements are : " << endl; 
    for (int i = 0; i < arr_size; i++)  
    { 
        if (numRay[i] >= arr_size*2)  
        { 
            cout << i << " " << endl; 
        } 
    } 
    return 0; 
} 


Another approach: Using two pointers slow and fast


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    
    int s=nums[0];
    int f=nums[0];
    
    do{
          s=nums[s];
          f=nums[nums[f]];
       }
     while(s!=f);
     
     f=nums[0]
     while(s!=f){
                    s=nums[s];
                    f=nums[f];
     }
     
     return s;
        
    }
};

