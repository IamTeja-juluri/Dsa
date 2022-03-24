class Solution {
public:
    
  // come in reverse way
  // increment target by 1 if its odd
  // or divide by 2
    int brokenCalc(int startValue, int target) {
      
        int count=0;
    
        while(target>startValue){
            
            if(target&1)
                target+=1;
            else
                target/=2;
            
            count+=1;
        }
        
        
        return count+startValue-target;
    }
};
