class Solution {
public:
    string makeFancyString(string s) {
        if(s.size()<=2)
            return s;
        int l = 0;
        int r = 2;
        string res(1,s[0]);
       for(int i=1;i<s.size()-1;i++){
            if(s[i]== s[l] && s[i]==s[r]){
               r+=1;
            }else{
                l=i;
                r+=1;
                res.push_back(s[i]); // use push_back method to avoid memory limit exceeded issue as res=res+s[i] always creates a new string
            }
       } 
       res.push_back(s[s.size()-1]); 
       return res;
    }
};
