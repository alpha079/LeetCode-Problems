class Solution {
public:
    int BinarySearch(vector<int> &arr, int k){
        int res=INT_MIN;
        int sum=0;
        set<int> s;
        s.insert(0);
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            auto it=s.lower_bound(sum-k);
//the reason why we take lower bound is--> let's say, at any general index idx, the prefix sum is cur. We take lower bound of (cur- k). This will give me a value greater than or equal to (cur-k) , lets say we got cur-k + lambda, where lambda>=0. So the sum of the segment that we get is cur - (cur - k + lambda) = k-lambda. So we can clearly see, we got a value less than or equal to k, as lambda>=0.
            if(it!=s.end()){
                res=max(res,sum-*it);
            }
            if(res==k){
                return k;
            }
            s.insert(sum);
        }  
        return res;
    }
    
    int KadaneAlgo(vector<int> &arr, int k){
        int sum=0;
        int maxSum=INT_MIN;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            maxSum=max(maxSum,sum);
            if(sum<0){
                sum=0;
            }
        }
        maxSum=max(maxSum,*max_element(arr.begin(),arr.end()));
        return maxSum;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& M, int k) {
        int res=INT_MIN;
        int R=M.size();       
        int C=M[0].size();
        for(int i=0;i<C;i++){
            vector<int> arr(R,0);
            for(int j=i;j<C;j++){
                for(int k=0;k<R;k++){
                    arr[k]+=M[k][j];
                }
                int tempSum=KadaneAlgo(arr,k);
                if(tempSum==k){
                    return k;
                }
                else if(tempSum<k){
                    res=max(res,tempSum);
                }
                else{
                    tempSum=BinarySearch(arr,k);
                    res=max(res,tempSum);
                }
            }
        }
        return res;
    }
};