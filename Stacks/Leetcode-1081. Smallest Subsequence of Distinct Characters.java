class Solution {
    public String smallestSubsequence(String s) {
        
        // we will first store right most indices of all the characters in cnt array
        //then if stack is empty we push character
        //at every iteration we check if the curr character is smaller or greater than prev character(top of stack)
        //if curr character is greater than prev character we simply push the character into the stack if n only if
        // character is not visited
        //otherwise if curr character is smaller than prev character we will see if there is another occurence of
        // that particular prev character on the right side .If its present  we pop it and mark it unvisited n we will do it as long as this 
        //condn holds true and when u come out of stack loop u simply add curr character
        
        int[] cnt=new int[26];
        int[] visited=new int[26];
        
        for(int i=0;i<s.length();i++){
            char ch=s.charAt(i);
            cnt[ch-'a']=i;
        }
        
        Stack<Character> st=new Stack<>();
        
        for(int i=0;i<s.length();i++){
            
            char ch=s.charAt(i);
            if(st.isEmpty()==true){
                st.push(ch);
                visited[ch-'a']=1;
            }
            
            if(visited[ch-'a']==1)
                continue;
            
            while(st.isEmpty()==false && ch<st.peek() && cnt[st.peek()-'a']>i){
                visited[st.peek()-'a']=0;
                st.pop();
            }
            
            st.push(ch);
            visited[ch-'a']=1; 
        }
        
        String res=""; 
        
        while(st.isEmpty()==false){
            res=st.peek()+res;
            st.pop();
        }
        
        return res;
        
    }
}
