//Simple Appraoch
// -> Just check if you can place a flower at current inde or  not, by checking it's previous 
// next value

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int prev=0;
        int next=0;
        
        int cnt=0;
        
        for(int i=0;i<flowerbed.size();i++)
        {
            if(flowerbed[i]==0)
            {
                 prev= (i==0 || flowerbed[i-1]==0) ?0 : 1;
                 next= (i==flowerbed.size()-1 || flowerbed[i+1]==0) ? 0: 1;
                
                if(prev==0 and next==0)
                
            {
                cnt++;
                i++;
                
            }
            }
           
            
            
        }
        return cnt>=n;
        
    }
};