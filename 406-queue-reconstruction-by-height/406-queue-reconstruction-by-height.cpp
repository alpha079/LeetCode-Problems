class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>> res;
        for(auto it: people)
        {
            res.insert(res.begin()+it[1],it);
        }
        return res;
        
    }
    static bool cmp(vector<int>& v1, vector<int>& v2)
    {
        if(v1[0]!=v2[0])
            return v1[0]>v2[0];
        else return v1[1]<v2[1];
    }
};