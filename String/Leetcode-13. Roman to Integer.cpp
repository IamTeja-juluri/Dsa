class Solution {
public:
    int romanToInt(string s) {
     
       unordered_map<string,int> mp;
        
        mp["I"]=1;
        mp["V"]=5;
        mp["X"]=10;
        mp["L"]=50;
        mp["C"]=100;
        mp["D"]=500;
        mp["M"]=1000;
        mp["IV"]=4;
        mp["IX"]=9;
        mp["XL"]=40;
        mp["XC"]=90;
        mp["CD"]=400;
        mp["CM"]=900;
        
        int ans=0;
        int n=s.size();
        
        for(int i=0;i<n;){
            
            string temp=s.substr(i,2);
            if(mp.find(temp)!=mp.end()){
                ans=ans+mp[temp];
                i+=2;
            }
            else{
                string temp2="";
                temp2+=s[i];
                ans=ans+mp[temp2];
                i+=1;
            }
            
        }
        
        return ans;
        
        
    }
};
