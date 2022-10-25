class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& w1, vector<string>& w2) {
        
        
        
     //two pointers solution 
    
      int row1=0,row2=0;
        int col1=0,col2=0;
        
        while(row1<w1.size() and row2<w2.size())
        {
            if(w1[row1][col1++]!=w2[row2][col2++])
                return false;
        
            if(col1>=w1[row1].size())
            {
                col1=0;row1++;
            }
            if(col2>=w2[row2].size())
            {
                col2=0;row2++;
            }
        }
        
        return row1==w1.size() and row2==w2.size();
        
        //TC:- O(N+M)
        //SC:- O(1)
    }
};