class Solution {
    public int minAddToMakeValid(String s) {
     
       Stack<Character> st=new Stack<>();
        
        int score=0;
        
       for(char ch:s.toCharArray()){
           
           if(ch=='(')
               st.push(ch);
           else{
               if(st.isEmpty()==false)
                   st.pop();
               else
                   score+=1;
           }
       } 
        
        score+=st.size();
        
        return score;
    }
}
