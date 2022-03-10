class Solution {
public:
    string largestOddNumber(string num) {
     
        string temp="";
        int n=num.size();
        n-=1;
        int j=-1;
        
        while(n>=0){
            if(num[n]%2==1){
                j=n;
                break;
            }
            n--;
        }
        
        if(j==-1) return "";
        string ans=num.substr(0,j+1);
        return ans;
    }
};
