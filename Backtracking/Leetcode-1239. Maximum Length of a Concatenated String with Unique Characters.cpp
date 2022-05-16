class Solution {
public:
    int res;
    
    bool isValid(string s1){
        
        unordered_set<char> st;
        
        for(auto x:s1){
            if(st.find(x)!=st.end())
                return false;
            st.insert(x);
        }
        
       
        return true;
    }
    
    void solve(vector<string>&arr,string &ans,int idx){
        
        
        for(int i=idx;i<arr.size();i++){
            
             if(isValid(arr[i]+ans)){
                 string temp=ans;
                 ans=ans+arr[i];
                 solve(arr,ans,i+1);
                 int size=ans.size();
                 res=max(size,res);
                 ans=temp;
             }
        }
        
    }
    

    int maxLength(vector<string>& arr) {
        
        string temp="";
        res=0;
        solve(arr,temp,0);
        
        return res;
    }
};
