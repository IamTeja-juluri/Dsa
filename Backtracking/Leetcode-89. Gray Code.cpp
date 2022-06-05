//algo
//refer aayushi sharma video for intuition

class Solution {
public:
   
    vector<string> backtrack(int n){
        
        if(n==1)
            return {"0","1"};
        
        vector<string>ans=backtrack(n-1);
        
        int size=ans.size();
        vector<string> curr;
        
        for(int i=0;i<size;i++)
            curr.push_back("0"+ans[i]);
            
        for(int i=size-1;i>=0;i--)
            curr.push_back("1"+ans[i]);
        
        return curr;
    }
   

    vector<int> grayCode(int n) {
        
        vector<int> res;
        vector<string> bstr=backtrack(n);
       
        for(int i=0;i<bstr.size();i++)
            res.push_back(stoi(bstr[i],0,2));
        
        return res;
    }
};
