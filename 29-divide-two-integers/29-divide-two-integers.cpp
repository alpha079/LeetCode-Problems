class Solution {
public:
 	int divide(int dividend, int divisor) {
        if(dividend == INT_MIN and divisor == -1) return INT_MAX;
        long d = abs(dividend), dv = abs(divisor), ans = 0;
        while(d>=dv){
            long temp = dv, mul = 1;
            while(d>=temp){
                d-=temp;
                ans+=mul;
                mul+=mul;
                temp+=temp;
            }
        }
        if((dividend<0 and divisor>=0) or (divisor<0 and dividend>=0))
                ans = -ans;
        return ans;
    }
};