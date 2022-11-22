class Solution {
public:
    int numSquares(int n) {
        unordered_set<int> check;
        queue<int> q({0});
        int count = 1;
        while(!q.empty())
        {   
            int size = q.size();
            while(size--)
            {
                int cur = q.front(); q.pop();
                for(int i = 1; cur + i * i <= n; ++i)
                {
                    int newVal = cur + i * i;
                    if(newVal == n)
                        return count;
                    if(!check.count(newVal))
                    {
                        check.insert(newVal);
                        q.push(newVal);
                    }
                }  
            }          
            ++count;
        }
        return -1;
    }
};