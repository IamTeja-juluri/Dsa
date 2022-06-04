class Solution {
    public int minSwaps(String s) {
        
        //algo 
        //we assign 1 to right paranthesis
        //we assign -1 to left paranthesis
        //at any point in time maximum value of score
        //is the max swaps we can make to make string balanced
        // but if we look carefully one swap not just makes one pair balanced
        // but if makes two pairs balanced 
        //so for minimum swaps we take half of max swaps
        
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
