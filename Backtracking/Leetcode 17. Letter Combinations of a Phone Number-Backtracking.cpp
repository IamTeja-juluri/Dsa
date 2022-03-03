class Solution {
public:
    
    vector<string> res;
    vector<string> v;
    
    void findCombinations(string digits,string ans,int idx){
        
        if(idx==digits.size()){
            res.push_back(ans);
            return;
        }
         
        int x=int(digits[idx])-48;
        
        for(int i=0;i<v[x].size();i++){
            
            ans.push_back(v[x][i]);
            findCombinations(digits,ans,idx+1);
            ans.pop_back();
            
        }
       
        
        
    }
    
    vector<string> letterCombinations(string digits) {
       
        if(digits==""){
            return res;
        }
        
       v.resize(10);
        
        v[0]="0";
        v[1]="0";
        v[2]="abc";
        v[3]="def";
        v[4]="ghi";
        v[5]="jkl";
        v[6]="mno";
        v[7]="pqrs";
        v[8]="tuv";
        v[9]="wxyz";
        
        findCombinations(digits,"",0);
        return res;
        
    }
};
