class Solution {
public:
    int helper(string s,int k,char ch){
        
        int ans=0;
        int j=0;
        int cnt=0;
        
        for(int i=0;i<s.size();i++){
            if(s[i]!=ch)
                cnt+=1;
            while(cnt>k){
                if(s[j]!=ch)
                    cnt-=1;
                j+=1;    
            }
            ans=max(ans,i-j+1);
        }
        
        
        return ans;
    }
     
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        return max(helper(answerKey,k,'T'),helper(answerKey,k,'F'));
    }
};
