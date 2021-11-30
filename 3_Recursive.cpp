#include <iostream>
#include <vector>
using namespace std;

vector<long long int> arr;

bool subset(int n, long long int sum){
	if(!sum) return true;
	if(!n && sum) return false;
	
	if(arr[n-1] > sum) return subset(n-1, sum);
	
	bool include_last = subset(n-1, sum);
	
	if(include_last){
		return subset(n-1, sum);
	}
	
	bool exclude_last = subset(n-1, sum-arr[n-1]);
	
	if(exclude_last){
		return subset(n-1, sum-arr[n-1]);
	}
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
	
	if(sum&1 || !subset(n, sum/2)){ 
		cout << "no" << endl;
	}else{
		cout << "yes" << endl;
	}
	
	return 0;	
}


