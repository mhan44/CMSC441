#include <iostream>
#include <vector>
using namespace std;

int main(){
	int count = 0;
	int n;
	cout << "Enter n: ";
	cin >> n;
	vector<int> vec(n,-1);
	vector<int> vec2(n, 0);
	/*for(int i = 0; i<n; i++){
		cout << vec[i] << endl;
	}*/
	cout << endl;
	
	//outer for loop = number of passes
	//inner for loop = pass and check for ith lockers to switch state closed/open
	for(int i = 1; i<n+1; i++){ //i=1, cannot divide by 0
		cout << "Current I: " << i << endl;
		for(int j = 0; j<n; j++){
			//cout << "i: " << i << ", j: " << j << ", j%i = " << j%i << endl;
			if((j+1) % i == 0){
				vec2[j]++;
				//1 = open, -1 = closed, flip sign to open/close
				if(vec[j] == -1){
					vec[j] = 1;
				}else if (vec[j] == 1){
					vec[j] = -1;
				}	
			}
		}
		cout << "[ ";
		for(int k=0; k<n; k++){
			cout << vec[k] << " ";
		}
		cout << "]" << endl;
	}
	cout << endl;
	
	for(int i = 0; i<n; i++){
		cout << "Locker " << i+1 << ": ";
		if(vec[i] == -1){
			cout << "is closed" << endl;
		}else{
			cout << "is open" << endl;
			count++;
		}
	}
	cout << "For " << n << " lockers, " << count << " are open." << endl;
	
	for(int l = 0; l<n; l++){
		cout << "Locker " << l+1 << " was divided: " << vec2[l] << " times" << endl;
	}
	
	return 0;
}