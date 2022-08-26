class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        
        int count[26]={0};
        int n=s.size();
        
        for(int i=0;i<n;i++)
            count[s[i]-'a']=i;
        
        int i=0;
        
        while(i<n){
            
            int maxLimit=count[s[i]-'a'];
            int j=i;
            
            while(j<maxLimit){
                j+=1;
                maxLimit=max(maxLimit,count[s[j]-'a']);
            }
            res.push_back(j-i+1);
            i=j+1;
        }
        
        return res;
    }
};
