/*Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.
Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].
*/

/*Approach:
1) Traverse the array uptil last second element
2) Check if a[i+1] > a[i]
if not then increment the count variable
3) Then compare last elemnt with the first element and if a[n-1] > a[0] then increment count.
4) At the end check if count is greater than 1 return false else return zero.
*/
class Solution {
public:
    bool check(vector<int>& a) {
        int count=0;
        int n=a.size();
        for(int i=0; i<n-1; i++){
            if(a[i]>a[i+1]){
               count++;
            }
        }
        if(a[n-1]>a[0]){
            count++;
        }
        
        if(count==0 || count==1){
            return 1;
        }
        else{
            return 0;
        }
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1)