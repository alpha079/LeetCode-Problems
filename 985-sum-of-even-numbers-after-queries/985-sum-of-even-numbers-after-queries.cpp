class Solution {
    int seg[400004]={0};
    void build(int node,int start,int end,vector<int> &nums){
        if(start==end) {
            if(nums[start]%2==0) seg[node]=nums[start];
            
            return;
        }
        int mid=start+(end-start)/2;
        build(node*2+1,start,mid,nums);
        build(node*2+2,mid+1,end,nums);
        if(seg[node*2+1]%2==0) seg[node]+=seg[node*2+1];
        if(seg[node*2+2]%2==0) seg[node]+=seg[node*2+2];
    }
    void update(int node,int start,int end,vector<int> & nums,int pos,int val){
        if(start==end){
            seg[node]=0;
            nums[start]+=val;
            //cout<<nums[start]<<endl;
            if(nums[start]%2==0) seg[node]=nums[start];
            return;
        }
        int mid=start+(end-start)/2;
        if(pos<=mid) update(2*node+1,start,mid,nums,pos,val);
        else update(2*node+2,mid+1,end,nums,pos,val);
        seg[node]=0;
        if(seg[node*2+1]%2==0) seg[node]+=seg[node*2+1];
        if(seg[node*2+2]%2==0) seg[node]+=seg[node*2+2];
        return ;
    }
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
            build(0,0,nums.size()-1,nums);
        vector<int> ans;
        cout<<seg[0]<<endl;
        for(int i=0;i<queries.size();i++){
            update(0,0,nums.size()-1,nums,queries[i][1],queries[i][0]);
            ans.push_back(seg[0]);
        }
        // for(int i=0;i<nums.size();i++){
        //     cout<<nums[i]<<endl;
        // }
        return ans;
    }
};