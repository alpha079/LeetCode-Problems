class Solution {
public:
    
    //two pointers Appraoch
    /*
    We can initialize two pointers L=0 and R=n-1. Now our window size is n and contains excess elements. We will keep reducing the [L, R] window size till it becomes exactly equal to k. We can do this based on the condition - x - arr[L] <= arr[R] - x. If it is true, then it means arr[R] is farther away from x than arr[L] and thus we will eliminate arr[R]. Otherwise, we will eliminate arr[L].
*/
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int low=0;
        int high=arr.size()-1;
        
        while(high-low>=k)
        {
            if(abs(arr[low]-x)>abs(arr[high]-x))low++;
            else high--;
        }
        return vector<int>(begin(arr)+low,begin(arr)+high+1);
        //Time Complexity : O(n-k), we will keep reducing the window size from initial n to final k which will require a total of n-k comparisons.
//Space Complexity : O(1)
    }
};