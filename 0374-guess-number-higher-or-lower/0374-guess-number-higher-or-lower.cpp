/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
      long long low=1;
        int high=n;
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(guess(mid)==0)
                return mid;
            else if(guess(mid)==-1)
                high=mid-1;
            else low=mid+1;
        }
        return ans;
    }
};