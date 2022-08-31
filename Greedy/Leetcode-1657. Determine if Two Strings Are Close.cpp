//two strings must contain same characters
//but frequencies of characters in string 1 should be equal to frequencies of characters of same type or other type in string 2
// refer fraz youtube video

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        int n1=word1.size();
        int n2=word2.size();
        
        if(n1!=n2)
            return false;
        
        
        vector<int> count1(26,0),count2(26,0);
        
        vector<int> counta(26,0),countb(26,0);
        
        for(int i=0;i<word1.size();i++){
            count1[word1[i]-'a']+=1;
            counta[word1[i]-'a']=1;
        }
        
        for(int i=0;i<word2.size();i++){
            count2[word2[i]-'a']+=1;
            countb[word2[i]-'a']=1;
        }
        
        sort(count1.begin(),count1.end());
        sort(count2.begin(),count2.end());
        
        return count1==count2 and counta==countb;
        
    }
};
