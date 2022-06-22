class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        
        int n=num_people;
        vector<int> res(num_people);
        for(int i=0,round=0;candies>0;)
        {
            int noOfCandies=(int)round*n+i+1;
            if(noOfCandies<=candies)
            {
                res[i]+=noOfCandies;
                candies-=noOfCandies;
            }
            else{
                 res[i]+=candies;
                candies=0;
            }
            if(++i>=n)
            {
                i=0;
                round++;
            }
        }
        return res;
        
    }
};