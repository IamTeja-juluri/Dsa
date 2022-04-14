class Solution {
public:
    long long countVowels(string word) {
        
        long long count=0;
        long long int n=word.size();
        
        for(long long i=0;word[i]!='\0';i++){
            if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u'){
                long long left=i+1;
                long long right=n-i;
                count+=left*right;
            }
        }
        
        return count;
    }
};
