class Solution {
    public String longestWord(String[] words) {
        
        Arrays.sort(words);
        HashSet<String> st=new HashSet();
        String ans="";
        for(String x:words){
               
          if ( (x.length()==1) ||  (st.contains(x.substring(0,x.length()-1))) ){
               if(ans.length()<x.length()) 
                   ans=x;
                st.add(x);
            }
            
        }
        
        return ans;
    }
}
