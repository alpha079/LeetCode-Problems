class Solution {
public:
    int minimumRounds(vector<int>& task) {
        
        //sort(task.begin(),task.end());
        //No need to sort, we are already doing hashing.
        unordered_map<int,int> map;
        
        for(auto it: task)
        {
            map[it]++;
        }
        
        int cnt=0;
        for(auto it: map)
        {
            if(it.second==1)
                return -1;
            //if it.second is divisible by 3, then it cover divisibility by 2 also.
            cnt+=(it.second)/3;
            
            /* if x.second is not divisible by 3, then we would be required to consider the cases when only two                  tasks are selected 
            - in last round for (x.second%3==2)
            - in last two rounds (x.second%3==1) */
            if(it.second%3==1 || it.second%3==2)
                cnt++;
         }
        return cnt++;
    }
};