/*Here we have to find second largest element present in array without using sorting technique
Input: 
N = 6
Arr[] = {12, 35, 1, 10, 34, 1}
Output: 34
Explanation: The largest element of the 
array is 35 and the second largest element
is 34.
*/

/*Approach:
1) We will maintain two variable storing index of largest and second largest element.
2) Consider first element as maximum and intialize value of larInd as 0
3) Similarly initialize value of resInd as -1
4) Traverse the array
5) Check if element at ith position is greater than maximum element than update resInd to larInd and larInd to i
6) If not then check if element at ith position is greater than resInd if yes than update resInd to i
7) Continue traversing entire array
8) At end if resInd stores value -1 than return -1. It indicate no second largest element is present.
9) Else return element present at resIndex.
*/

int secondLargest(int a[], int n){
    //using two index larInd and resInd
    int larInd=0, resInd=-1;
    int max=a[larInd];
    for(int i=1; i<n; i++){
        //if a[i]>a[larInd] then update larInd with i
        if(a[i]>a[larInd]){
            resInd=larInd;
            larInd=i;
        }

        // a[i]<a[larInd]
        else if (a[i]!=a[lar]){
            if(a[i]>a[resInd]){
                resInd=i;
            }

        }
    }
    //No second largest element is present
    if (resInd==-1) return -1;
    //Second largest element is present
    else return a[resInd];
}