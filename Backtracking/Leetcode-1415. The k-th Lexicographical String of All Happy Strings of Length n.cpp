1)class Solution {
public:
    
   vector<string> ans;
    
    void constructStrings(string &s,int idx,int n){
        
        if(n==0){
            ans.push_back(s);
            return;
        }
        
       for(char ch='a';ch<='c';ch++){
           if(s.size()==0 || s.back()!=ch){
              s.push_back(ch);
              constructStrings(s,idx+1,n-1);
               s.pop_back();
           }
       }
        
        return ;
    }
    
    
    string getHappyString(int n, int k) {
        
        string temp="";
        constructStrings(temp,0,n);
       
        int size=ans.size();
        
        if(k<=size)
             return ans[k-1];
        
        return "";

    }
};
2)class Solution {
public:
    
   vector<string> ans;
    
    void constructStrings(string &s,int idx,int n){
        
        if(n==0){
            ans.push_back(s);
            return;
        }
        
       for(int i=0;i<3;i++){
           if(s.size()==0 || s.back()!='a'+i){
              s.push_back('a'+i);
              constructStrings(s,idx+1,n-1);
               s.pop_back();
           }
       }
        
        return ;
    }
    
    
    string getHappyString(int n, int k) {
        
        string temp="";
        constructStrings(temp,0,n);
       
        int size=ans.size();
        
        if(k<=size)
             return ans[k-1];
        
        return "";

    }
};
