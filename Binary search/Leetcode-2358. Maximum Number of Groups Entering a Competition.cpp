class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        
  long long n = grades.size();   
	long long low = 1, high = n, maxGrps = n+1;

	while(low <= high) {
		long long mid = (high + low) >> 1;

		long long sum = mid * (mid+1LL) / 2;

		if(sum <= n) {
			maxGrps = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	return maxGrps;
    }
};
