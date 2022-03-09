class Solution {
public:
    int titleToNumber(string s) {
        
        int num=0;
        int n=s.size()-1;
        int i=0;
        
        while(n>=0){
            num=num+pow(26,i)*(s[n]-'A'+1);
            i++;
            n--;
        }
        
        return num;
    }
};
