class Solution {
public:
    
    int count(int num)
    {
        
        int len=0;
        while(num!=0)
        {
            len++;
            num/=10;
        }
        return len;
        
    }
    vector<int> sequentialDigits(int low, int high) {
        
        string digit="123456789";
        int n=digit.size();
        
        int lowLen=count(low);
        int highLen=count(high);
        vector<int> res;
        for(int l=lowLen;l<=highLen;l++)
        {
            for(int i=0;i<=n-l;i++)
            {
                int num=stoi(digit.substr(i,l));
                
                if(num>=low and num<=high)
                {
                    res.push_back(num);
                }
            }
        }
        return res;
        
        
    }
};