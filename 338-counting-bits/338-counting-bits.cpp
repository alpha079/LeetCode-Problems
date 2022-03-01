class Solution {
public:
    
    //TIme:- O(Nlogn)
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);
        if(num==0)
            return res;
        
        //for each number, count the set bits;
        
        for(int i=1;i<=num;i++)
        {
            int sum=0;
            int number=i;
            while(number!=0)
            {
                sum+=number%2;
                number/=2;
            }
            res.push_back(sum);
        }
        return res;
    }
};