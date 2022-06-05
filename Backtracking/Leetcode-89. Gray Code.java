//algo
//refer aayushi sharma video for intuition

//java
class Solution {
    
    public ArrayList<String> backtrack(int n){
        
        if(n==1){
            ArrayList<String> al=new ArrayList<>();
            al.add("0");
            al.add("1");
            return al;
        }
            
        ArrayList<String> ans=backtrack(n-1);
        ArrayList<String> curr=new ArrayList<>();
        
        int size=ans.size();
        
        for(int i=0;i<size;i++){
            String s=ans.get(i);
            curr.add("0"+s);
        }
        
        for(int i=size-1;i>=0;i--){
            String s=ans.get(i);
            curr.add("1"+s);
        }
        
        return curr;
        
    }
    
    public List<Integer> grayCode(int n) {
        
        ArrayList<String> arrl=backtrack(n);
        
        List<Integer> l=new ArrayList<>();
        
        for(int i=0;i<arrl.size();i++)
            l.add(Integer.parseInt(arrl.get(i),2));
        
        return l;
    }
}
//cpp
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
