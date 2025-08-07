int minCost(int arr[], int n)
{
	/*Write your code here. 
	 *Don't write main().
	 *Don't take input, it is passed as function argument.
	 *Don't print output.
	 *Taking input and printing output is handled automatically.
	*/ 
	vector<int> vec;
	
	for (int i = 0; i < n; i++) {
            vec.push_back(arr[i]);
        }

	priority_queue<int, vector<int>, greater<int>> pq(vec.begin(), vec.end());
	int ans=0;
	for(int i=0; i<n-1; i++){
		int min1 = pq.top();
		pq.pop();
		int min2 = pq.top();
		pq.pop();

		ans += min1+min2;
		pq.push(min1+min2);
	}
	return ans;
}
