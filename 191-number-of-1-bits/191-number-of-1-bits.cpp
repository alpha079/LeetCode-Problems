class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int cnt=0;
      /*  Here is the thing,
finding n&(n-1) is a way to remove the least significant bit (LSB).

Here is an example (n=1011) :
n=1011 (n-1)=1010 n&(n-1)=1011 & 1010 = 1010 (new n) -- count=1
n=1010 (n-1)=1001 n&(n-1)=1010 & 1001 = 1000 (new n) -- count=2
n=1000 (n-1)=0111 n&(n-1)=1000 & 0111 = 0000 (condition to exit while) -- count=3

*/
        while(n)
        {
          n=n&(n-1);
            cnt++;
        }
        return cnt;
        
    }
};