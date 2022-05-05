class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
     
        long long sum=0;
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            sum+=shifts[i];
            s[i]=(s[i]-'a'+sum)%26 + 'a';
        }
       
        return s;
    }
};
