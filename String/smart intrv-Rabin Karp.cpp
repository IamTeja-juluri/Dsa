#include<bits/stdc++.h>
using namespace std;
#define int long long int
int mod=1e9+7,p=31;

int powr(int a,int b){
    
    int res=1;
    
    while(b){
        if(b & 1ll){
            res*=a;
            res%=mod;
        }
        a*=a;
        a%=mod;
        b/=2;
    }
    
    return res;
}

int inv(int a){
    //fermats little theorem
    return powr(a,mod-2); 
}

int polyhash(string s){
    
    int hash=0, p_powr=1, size=s.size();
    
    for(int i=0;i<size;i++){
        hash=hash+(s[i]-'a'+1)*p_powr;
        hash%=mod;
        p_powr*=p;
        p_powr%=mod;
    }
    
    return hash;
}

int32_t main(){
    
    int t;
    cin>>t;
    
    while(t--){
        
        string pat,txt;
        cin>>pat>>txt;
        
        int n=txt.size(),m=pat.size();
        
        int pat_hash=polyhash(pat);
        int txt_hash=polyhash(txt.substr(0,m));
        int count=0;
        
        if(pat_hash==txt_hash)
            count+=1;
        
        int calpwr=powr(p,m-1);
        int calinv=inv(p);
        
        for(int i=1;i+m<=n;i++){
        
            int newhash=txt_hash;
            newhash=(newhash-(txt[i-1]-'a'+1)+mod)%mod;
            newhash*=calinv;
            newhash%=mod;
            newhash=newhash+(txt[i+m-1]-'a'+1)*calpwr;
            newhash%=mod;
            
            if(newhash==pat_hash)
                count+=1;
            
            txt_hash=newhash;
        }
        
        cout<<count<<endl;
        
    }
    
}
