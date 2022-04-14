class Solution {
public:
    int minOperations(int n) {
     int ans=0;
     int median=n/2;
     int val=2*median+1;
     int s1=(median+1)*(median+1);
     int s2=((n/2)+1)*val;
     ans=s2-s1;
     if((n%2)==0)
         ans=s2-s1-(val-1)/2;
     return ans;
    }
};
