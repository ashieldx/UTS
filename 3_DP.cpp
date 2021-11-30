#include <iostream>
#include <vector>
using namespace std;

vector<long long int> arr;

int partition(int n, long long int sum){
	int dp[sum/2+1][n+1];
	
	dp[0][0] = 0;
	
	for(int i = 0; i < n+1; i++) dp[0][i] = 1;
	for(int i = 0; i < sum/2+1; i++) dp[i][0] = 0;
	
	for(int i = 1; i < sum/2+1; i++){
		for(int j = 1; j < n+1; j++){
			dp[i][j] = dp[i][j-1];
			
			if(arr[j-1] <= i){
				if(dp[i][j] || dp[i-arr[j-1]][j-1]){
					dp[i][j] = 1;
				}
			}
		}
	}
	return dp[sum/2][n];
}

int main(){
	
	int n;
	cout << "Input number of Bids: ";
	cin >> n;
	
	long long int sum = 0, m;
	
	for(int i = 0; i < n; i++){
		cin >> m;
		arr.push_back(m);
		sum += m;
	}
	
	if(sum&1 || !partition(n, sum)){ 
		cout << "no" << endl;
	}else{
		cout << "yes" << endl;
	}

	return 0;
}
