class Solution {
public:
    
    //intuition
    //refer youtube
    
    int minimumSwap(string s1, string s2) {
        
        int cnt=0;
        int n=s1.size();
       
        int xy=0,yx=0;
        
        for(int i=0;i<n;i++){
            if(s1[i]==s2[i])
                continue;
            else{
                if(s1[i]=='x')
                    xy+=1;
                else
                    yx+=1;
            }
        }
        
        if(xy%2 + yx%2 == 1) //case where one xy or yx pair extra which cant be made equal
            return -1;
        
      return xy/2 + yx/2 + xy%2 + yx%2; 
    }
};
