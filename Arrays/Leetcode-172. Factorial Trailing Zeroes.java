class Solution {
    public int trailingZeroes(int num) {
     
        int sum=0;
        int i=5;
        
        while(true){
           
           long x=num/i;
           x=(long)(Math.floor(x));
           
           if(x==0)
           break;
           
           sum+=x;
           i=i*5;
          
        }
        
        return sum;
        
        
        
    }
}
