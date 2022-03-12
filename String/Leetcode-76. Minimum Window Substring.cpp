class Solution {
public:
    string minWindow(string s, string p) {
        
        int sl=s.size();
        int pl=p.size();
        
        if(pl>sl)
            return "";
        
        int fs[256]={0};
        int fp[256]={0};
        
        for(int i=0;i<pl;i++){
            char ch=p[i];
            fp[ch]+=1;
        }
        
        int cnt=0;
        int start=0;
        int min_len=INT_MAX;
        int start_idx=-1;
        
        for(int i=0;i<sl;i++){
            
            char ch=s[i];
            fs[ch]+=1;
            
            if(fp[ch]!=0 and fs[ch]<=fp[ch])
                cnt+=1;
            
            if(cnt==pl){
                
                char temp=s[start];
                
                while(fp[temp]==0 or fs[temp]>fp[temp]){
                    start+=1;
                    fs[temp]-=1;
                    temp=s[start];
                }
                
                int window_len=i-start+1;
                if(window_len<min_len){
                    min_len=window_len;
                    start_idx=start;
                }
                
            }
            
        }
        
        if(start_idx==-1)
            return "";
        
        string ans=s.substr(start_idx,min_len);  
        
        return ans;
    }
};


#include<bits/stdc++.h>
using namespace std;

string findWindow(string s,string pat){

  int sl=s.length();
  int pl=pat.length();

//corner case
  if(pl>sl)
  	return "none";

//freq maps
  int fs[256]={0}; 
  int fp[256]={0}; 

  for(int i=0;i<pl;i++){
  	char ch=pat[i];
    fp[ch]+=1;
  }

//sliding window(expansion and contraction + update min length)
int cnt=0;
int start=0; //left ptr for shrinking
int min_len=INT_MAX;
int start_idx=-1;

for(int i=0;i<sl;i++){

  char ch=s[i];
  fs[ch]+=1;
  
  //Maintain the cnt of characters matched

  if(fp[ch]!=0 && fs[ch]<=fp[ch])
  	cnt+=1;

  // if all charachters match
  if(cnt==pl){
     //start shrinkinh
    char temp=s[start];
    //loop to remove all unwanted characters
   while(fp[temp]==0 or fs[temp]>fp[temp]){
     fs[temp]--;
     start+=1;
     temp=s[start];
  }

  int window_len=i-start+1;
  if(window_len<min_len){
  	min_len=window_len;
  	start_idx=start;
  }

 }
  
}  
 if(start_idx==-1)
 return "None";

 string ans=s.substr(start_idx,min_len); 
 
 return ans;
}



int main(){

  string s= "a";
  string pat="xyz";

  cout<<findWindow(s,pat);

}






