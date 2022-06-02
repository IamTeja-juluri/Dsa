class Solution {
public:
   
    int threeSumSmaller(vector<int> &nums, int target) {

    int n=nums.size();   

     sort(nums.begin(),nums.end());
       int cnt=0;

       for(int i=2;i<n;i++){
           int left=0;
           int right=i-1;
           while(left<right){
                if(nums[left]+nums[right]<(target-nums[i])){
                  cnt=cnt+right-left;
                  left+=1;
                }
                else
                  right-=1;
           }
       }

       return cnt;
     



    }
};
