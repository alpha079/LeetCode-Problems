class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        priority_queue<int> pq;
        int i;
        for( i=0;i<heights.size()-1;i++)
        {
            int diff=heights[i+1]-heights[i];
            
            if(diff<=0)continue;
            else if(diff<=bricks)
            {
                pq.push(diff);
                bricks-=diff;
                
            }
            else if(ladders>0)
            {
                if(pq.size())
                {
                    int top=pq.top();
                    if(top>diff)
                    {
                        bricks+=top;
                        pq.pop();
                        pq.push(diff);
                        bricks-=diff;
                    }
                    
                }
                ladders--;
            }
            else break;
        }
        return i;
    }
};