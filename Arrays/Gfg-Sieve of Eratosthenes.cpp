class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        // Write Your Code here
        vector<int> ans;
        
        vector<bool>isPrime(N+1,true);
        
        for(int i=2;i*i<=N;i++){
            if(isPrime[i]){
                for(int j=i*i;j<=N;j=j+i)
                isPrime[j]=false;
            }
        }
        
        for(int i=2;i<=N;i++)
           if(isPrime[i])
           ans.push_back(i);
        
        return ans;
    }
};
