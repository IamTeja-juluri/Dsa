class Solution {
public:
    long long int mod;
    long long int p;
    
    long long int powr(long long int a,long long int b){
        
       long long int res=1;
        while(b){
            if(b & 1ll){
                res=res*a;
                res%=mod;
            }
            a=a*a;
            a%=mod;
            b=b>>1;
        }
        return res;
        
    }
    
    long long int inv(long long int a){
        return powr(a,mod-2);
    }
    
    long long int polyHash(string s){
        
        long long int hash=0;
        long long int p_powr=1;
        
        for(int i=0;i<s.size();i++){
            hash=hash+(s[i]-'a'+1)*p_powr;
            hash%=mod;
            p_powr*=p;
            p_powr%=mod;
        }
        
        return hash;
    }
    
    
    string rabinKarp(string &s,int m){
        
        long long int windowHash=polyHash(s.substr(0,m));
        long long int txtHash=windowHash;
        
        long long int calpwr=powr(p,m-1);
        long long int calinv=inv(p);
        
        unordered_map<long long int,vector<int> >mp;
        mp[windowHash].push_back(0);
        
        
        for(int i=1;i+m<=s.size();i++){
            txtHash=(txtHash-(s[i-1]-'a'+1)+mod)%mod;
            txtHash*=calinv;
            txtHash%=mod;
            txtHash=txtHash+(s[i+m-1]-'a'+1)*calpwr;
            txtHash%=mod;
            if(mp.find(txtHash)!=mp.end()){
                string curr=s.substr(i,m);
                for(auto idx:mp[txtHash]){
                    string x=s.substr(idx,m);
                    if(x==curr)
                        return x;
                }
            }
            mp[txtHash].push_back(i);
        }
        
        
        return "";
    }    
    
    
string binarySearch(string &s){
    
    int n=s.size();
    int low=1;
    int high=n-1;
    string ans="";
    
    while(low<=high){
        int mid=low+(high-low)/2;
        string x=rabinKarp(s,mid);
        if(x.size()>ans.size()){
            ans=x;
            low=mid+1;
        }
        else
            high=mid-1;
    }
    
    return ans;
}
    
    string longestDupSubstring(string s) {
        
        mod=1e9+7;
        p=31;
        
        return binarySearch(s);
        
    }
};
