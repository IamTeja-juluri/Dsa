// 1. Here every cell don't have it's own cost instead we are given rows and columns costs. This indirectly means that, path doesn't matter as long as we are reaching home[destination].

// 2. Here home can be anywhere in the matrix... 
//     For eg : Sample Test home is on right side frome source, so it doesn't mean it always on the right side...
//     It can be anywhere
    
//     so we can't bound ourselves to only go right, down side...
    
// Approach : It's pretty straightforward to get the minimum cost, we just need to reach the home..
// We just need to calculate the how many rows and columns we need to reach home...

// Here we using min and max function because if 

// source ---> destination is like this means starPos occur before homePos then we simply can go startPos to homePos

// but what if destination <---- source is like this means startPos occur after homePos then, we simply need to go destination to source as on left side index is smaller and on right side index is bigger...
class Solution {
public:
   
    int minCost(vector<int>& s, vector<int>& h, vector<int>& row, vector<int>& col) {
        
        
        int cost=0;
        
        for(int i=min(s[0],h[0]);i<=max(s[0],h[0]);i++)
            cost+=row[i];
        
         for(int i=min(s[1],h[1]);i<=max(s[1],h[1]);i++)
            cost+=col[i];
        
        return cost-row[s[0]]-col[s[1]];
        
    }
};
