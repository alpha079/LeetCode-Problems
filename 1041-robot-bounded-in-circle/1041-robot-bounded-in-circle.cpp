/*

   N (0)
           |
   W (1) ------ E (3)
           |
        S (2)
This represents how we keep our "direction" array. Starting from N(0) representing "N" at index 0 with direction (0,1), rotate by "L" and we reach at index 1 with direction (-1,0)(W). Further rotate by "L", we reach our direction (0,-1)(South) at index 2 and one last rotation moves it to East at index 3 with direction (1,0).

Further , One Right Turn = 3 times left Turn

So (i+1)%4 represents one "L" turn, while (i+3)%4 represents one right Turn (i.e. 3"L" turns).


Time Complexity :- BigO(N)

Space Complexity :- BigO(1)

*/



class Solution {
public:
    bool isRobotBounded(string str) {
        
       vector<vector<int>> dir = {{0,1}, {-1, 0}, {0, -1}, {1,0}};
        
        int x=0;
        int y=0;
        int i=0;
        
        for(int s=0;s<size(str);s++)
        {
            if(str.at(s)=='L')
            {
                i=(i+1)%4;
            }
            else if(str.at(s)=='R')
            {
                i=(i+3)%4;
            }
            else{
                
                x+=dir[i][0];
                y+=dir[i][1];
            }
        }
        return (x==0 and y==0) || i!=0;
        
    }
};