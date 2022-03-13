int Solution::solve(vector<int> &A, int B) {
//unique pairs

 int n=A.size();
 int count=0;
 unordered_set<int> st;

 for(auto x:A){

     if(st.find(x^B)!=st.end())
     count+=1;

     st.insert(x);
     
 }

 return count;

    
}
