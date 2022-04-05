class Solution {
public:
    
    int minSwaps(string s){

    int n = s.length(), l = 0, r = n - 1, swaps= 0;
        
        while(l < r) {
            
        int i = l, j = r;
        
        if(s[i] == s[j])
        {
            l++;
            r--;
            continue;
        }
        
        while(s[j] != s[i])
            j--;
        
        if(i == j) {
            swap(s[j], s[j + 1]);
            swaps++;
        }
        else {
            while(j < r) {
                swap(s[j], s[j + 1]);
                swaps++;
                j++;
            }
            l++;
            r--;
        }
    }
    
    return swaps;
        
    }
    
    
    int minMovesToMakePalindrome(string s) {
        
        return minSwaps(s);
    }
};
