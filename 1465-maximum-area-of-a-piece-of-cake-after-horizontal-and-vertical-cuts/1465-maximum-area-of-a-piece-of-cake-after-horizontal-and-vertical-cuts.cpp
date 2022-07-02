class Solution {
public:
    int maxArea(int h, int w, vector<int>& hC, vector<int>& vC) {
        
        hC.push_back(h);
        sort(hC.begin(),hC.end());
        
        int maxH=hC[0];
        for(int i=1;i<size(hC);i++)
        {
            maxH=max(maxH,(hC[i]-hC[i-1]));
        }
        
        vC.push_back(w);
        sort(vC.begin(),vC.end());
        
        int maxV=vC[0];
        for(int i=1;i<size(vC);i++)
        {
            maxV=max(maxV,(vC[i]-vC[i-1]));
        }
       return (1LL*maxH*maxV) % 1000000007;
        
    }
};