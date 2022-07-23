class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int count=0;
        
        int n1=g.size(),n2=s.size();
        int i=0,j=0;
        
        while(i<n1 && j<n2){
            if(s[j]<g[i])
                j+=1;
            else{
             count+=1;
             i+=1;
             j+=1;   
            }
        }
        
        return count;
        
    }
};
