class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        
        int count=0;
        
       while(target!=1 && maxDoubles){
           if(target%2)
               target-=1;
           else{
               target/=2;
               maxDoubles-=1;
           }
           count+=1;
       }
        
        return count+target-1;
        
    }
};
