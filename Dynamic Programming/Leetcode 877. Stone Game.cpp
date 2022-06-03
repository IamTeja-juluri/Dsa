//app1
class Solution {
public:
     vector<vector<int>> dp;
    
    int game(vector<int>&nums,int i,int j){
        
        if(i==j){
            return nums[i];
        }
        if(i>j){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int l=nums[i]+min(game(nums,i+2,j),game(nums,i+1,j-1));
        int r=nums[j]+min(game(nums,i,j-2),game(nums,i+1,j-1));
        
        return dp[i][j]=max(l,r);
        
    }
    
    
    bool stoneGame(vector<int>& nums) {
        
          dp.resize(nums.size(),vector<int>(nums.size(),-1) );
        
        int p1score=game(nums,0,nums.size()-1);
        int p2score=accumulate(nums.begin(),nums.end(),0) -p1score;
        
        return p1score>p2score;
        
        
    }
};

//app2
class Solution {
public:
    int dp[501][501];
    
   int solve(vector<int>&piles,int l,int r)
   {
     if(l==r-1) return max(piles[l],piles[r]);
     
     if(dp[l][r]!=-1) return dp[l][r];
     
     int leftchoice =piles[l] + max(solve(piles,l+2,r),solve(piles,l+1,r-1));
     int rightchoice=piles[r] + max(solve(piles,l,r-2),solve(piles,l+1,r-1));
     
     return dp[l][r]=max(leftchoice,rightchoice);
   }
    bool stoneGame(vector<int>& piles) {
     memset(dp,-1,sizeof(dp));
     int r=piles.size()-1;
     int alice=solve(piles,0,r);
     
      int sum=0;
      for(int i=0;i<piles.size();i++)
      {
        sum+=piles[i];
      }
      
      return alice>(sum-alice);
      
    }
};

//app3
class Solution {
public:
    
    int dp[500+1][500+1][2];
    int knapsack(vector<int>&arr,int i,int j,
                 int chance)
    {
        if(i>j)
            return 0;
        if(dp[i][j][chance]!=-1)
            return dp[i][j][chance];
        if(chance==1)
        {
            return dp[i][j][chance]= max(arr[i]+knapsack(arr,i+1,j,0),
                     arr[j]+knapsack(arr,i,j-1,0));
        }
        if(chance==0)
        {
            return dp[i][j][chance]= min(knapsack(arr,i+1,j,1),
                     knapsack(arr,i,j-1,1));
        }
        return 0;
    }
    
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof dp);
        int sum=0;
        for(auto i : piles)
        {
            sum+=i;
        }
        int sum1=knapsack(piles,0,piles.size()-1,1);
        int sum2=sum-sum1;
        if(sum1>sum2)
            return true;
        return false;
        
    }
};
