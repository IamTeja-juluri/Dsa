/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        
       long long l=1,h=n;
        long long ans=-1;
        
        while(l<=h){
            
            long long mid=l+(h-l)/2;
            int pr=guess(mid);
            if(pr==0)
                return mid;
            else if(pr==-1)
                h=mid-1;
            else
                l=mid+1;
        }
        
        return ans;
    }
};
