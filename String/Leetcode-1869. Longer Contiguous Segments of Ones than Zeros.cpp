class Solution {
public:
    bool checkZeroOnes(string s) {
        
        int n=s.size();
        
        int count1=0,count2=0;
        int max1=0,max2=0;
        
        int i=0;
        
        while(i<n){
            
            while(i<n && s[i]=='1'){
                count1++;
                i++;
            }
            
            while(i<n && s[i]=='0'){
                count2++;
                i++;
            }
            
            max1=max(max1,count1);
            max2=max(max2,count2);
            
            count1=0;
            count2=0;
            
        }
        
        return (max1>max2);
        
    }
};
