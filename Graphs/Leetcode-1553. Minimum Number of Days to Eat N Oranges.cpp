class Solution {
public:
    
int minDays(int n)
{
  queue<int> q;
  q.push(n);
  map<int, int> mp;
  int ans = 0;
  while (!q.empty())
  {
    int p = q.size();
    for (int i = 0; i < p; i++)
    {
      int x = q.front();
      q.pop();
      if (x == 0)
        return ans;
      if (mp.find(x - 1) == mp.end())
      {
        q.push(x - 1);
        mp[x - 1]++;
      }
      if (x % 2 == 0)
      {
        if (mp.find(x / 2) == mp.end())
        {
          q.push(x / 2);
          mp[x / 2]++;
        }
      }
      if (x % 3 == 0)
      {
        if (mp.find(x / 3) == mp.end())
        {
          q.push(x / 3);
          mp[x / 3]++;
        }
      }
    }
    ans++;
  }
  return -1;
}
};
