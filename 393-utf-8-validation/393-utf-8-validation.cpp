class Solution {
    int countFrontOne(int num){    //count number of 1's in the front
        int consecutive_1 = 0;   //count from the front
        int digit = 0;     //count digits of binary(num)
        
        while(num){
            consecutive_1 = (num%2) ? consecutive_1 +1 : 0;
            num /= 2;
            digit++;
        }
        
        if(digit != 8) return 0;
        return consecutive_1;
    }
    
public:
    bool validUtf8(vector<int>& data) {
        int remain = 0;     //the remaining number of consecutive 10xxxxxxxxx
        int count = 0;      //the number of 1's in the front
        
        for(auto& d: data){
            count = countFrontOne(d);
            if(remain>0 && count != 1){
                return false;
            }
            if(remain<=0 && count == 1){
                return false;
            }
            if(count > 4)
                return false;
            
            if(count != 1) remain = count;
            remain--;
        }
        
        if(remain == -1 || remain == 0) return true;
        return false;
    }
};