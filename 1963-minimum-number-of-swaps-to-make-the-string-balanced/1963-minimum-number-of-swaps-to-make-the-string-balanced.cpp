class Solution {
public:
    
    //TC:- O(N)
    //SC:- O(1)
    int minSwaps(string s) {
       
    int stack_size=0;
        
        for(int i=0;i<size(s);i++)
        {
            if(s[i]=='[')
            {
                stack_size++;
            }
            else
            {
                if(stack_size>0)
                {
                    stack_size--;
                }
            }
        }
        return (stack_size+1)/2;
    
    }
};