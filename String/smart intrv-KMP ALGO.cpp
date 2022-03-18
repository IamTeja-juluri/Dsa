#include<bits/stdc++.h>
using namespace std;

vector<int>lps(string &pat){
    
    int m=pat.size();
    vector<int>lps_arr(m,0);
    int i=1,j=0;
    
    while(i<m){
        if(pat[j]==pat[i]){
            lps_arr[i]=j+1;
            i++;
            j++;
        }
        else{
            if(j==0){
                lps_arr[i]=0;
                i++;
            }
            else
                j=lps_arr[j-1];
        }
    }
    
    return lps_arr;
    
}


int kmp(string txt,string pat){
    
    int i=0,j=0;
    int count=0;
    int n=txt.size();
    int m=pat.size();
    
    vector<int>lps_arr=lps(pat);
    
    while(i<n){
        
        if(i<n && j<m && txt[i]==pat[j]){
            i++;
            j++;
        }
        
        if(j==m){
            j=lps_arr[j-1];
            count+=1;
        }
        else if(i<n && txt[i]!=pat[j]){
            if(j==0)
                i++;
            else
                j=lps_arr[j-1];
        }
        
    }
    
    
    return count;
}

int main() {
      
    int t;
    cin>>t;
    
    while(t--){
        
        string pat,s;
        cin>>pat>>s;
        
        cout<<kmp(s,pat)<<endl;
    }
    
    return 0;
}
