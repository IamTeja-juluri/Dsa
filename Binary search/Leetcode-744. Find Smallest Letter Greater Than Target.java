class Solution {
    

    public char nextGreatestLetter(char[] letters, char target) {
        
        
        char ans=target;
        int n=letters.length;
        if(target>=letters[n-1])
            return letters[0];
            
        int low=0;
        int high=n-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            char ch=letters[mid];
            if(ch<=target)
                low=mid+1;
            else if(ch>target){
                ans=ch;
                high=mid-1;
            }
        }
        
        return ans;
        
    }
}
