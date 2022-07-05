class Solution {
public:
    int findMin(vector<int>& num) {
        
        int n=num.size();
         if(n==1)return num[0];
        if(num[0]<num[n-1])
            return num[0];
        int low=0;int high=n-1;
        int mid;
        
        while(low<high)
        {
            if(num[low]<num[high])
                return num[low];
            mid=(low+high)/2;
            
            if(num[mid]>=num[0])
                low=mid+1;
            else high=mid;
        }
        return num[low];
        
    }
};