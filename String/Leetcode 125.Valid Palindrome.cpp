class Solution {
public:
    bool isPalindrome(string s) {
        
        string temp="";
        
        for(int i=0;s[i]!='\0';i++){
            if( s[i]>=65 && s[i]<=90 ){
                s[i]=s[i]+32;
                temp+=s[i];
            }
            else if( (s[i]>=97 && s[i]<=122) || (s[i]>=48 && s[i]<=57) ){
                temp+=s[i];
            }
            else{
               continue;
            }
        }
        
        int i=0,j=temp.size()-1;
        
        while(i<=j){
            if(temp[i++]!=temp[j--]){
                return false;
            }
        }
        return true;
        
    }
};
