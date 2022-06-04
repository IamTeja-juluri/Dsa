class Solution {
    public int minSwaps(String s) {
        
        int score=0;
        int ans=Integer.MIN_VALUE;
        for(char ch:s.toCharArray()){
            if(ch==']')
                score+=1;
            else
                score-=1;
            ans=Math.max(ans,score);
        }
        
        return (ans+1)/2;
    }
}
