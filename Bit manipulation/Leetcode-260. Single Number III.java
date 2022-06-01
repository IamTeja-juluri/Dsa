class Solution {
    public int[] singleNumber(int[] nums) {
        
        int pos=0;
        
        int xorvar=0;
        
        for(int x:nums)
            xorvar=xorvar^x;
        
        int temp=xorvar;
        int a=0,b=0;
        
        int[] arr=new int[2];
        
        while(temp!=0){
            if((temp&1)!=0)
                break;
            pos+=1;
            temp/=2;
        }
        
        for(int x:nums){
            if(((1<<pos)&x)!=0)
                a^=x;
            else
                b^=x;
        }
        
        arr[0]=a;
        arr[1]=b;
            
            return arr;
    }
}
