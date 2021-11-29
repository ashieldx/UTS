#include <iostream>

using namespace std;

int missing(int *arr, int n){
	
    int temp, r = n, l = 0, d = (arr[n-1] - arr[0])/n;
    while(r >= l){
    	int m = l + (r-l) / 2;
    	if(arr[m] == (arr[0] + d*m)){
    		l = m + 1;
		}else{
			temp = arr[m];
			r = m - 1;
		}
	}
	return temp-d;
}
 
int main(){
	cout << "Input Number of IDs: ";
	
    int n;
    cin >> n;
    
    int arr[n];
    
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
	}
	
	cout << missing(arr, n) << endl;
 
    return 0;
}
