//A Bitonic Point is a point in bitonic sequence before which elements are strictly increasing and after which elements are strictly decreasing
// A Bitonic point doesn’t exist if array is only decreasing or only increasing.
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{-3, -2, 4, 6, 10, 8, 7, 1};
    int n=v.size();
    int low=0,high=n-1,btp=-1;
   while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(v[mid]>v[mid+1] && v[mid]>v[mid-1])
        {
            btp=mid;
            break;
        }
       else if(v[mid]<v[mid+1])
        {
            low=mid+1;
        }
        else //if(v[mid>v[mid+1)
        {
            high=mid-1;
        }
    }
    cout<<v[btp]<<endl;
    return 0;
}
