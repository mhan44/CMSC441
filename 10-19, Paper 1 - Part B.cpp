#include <iostream>
#include <chrono>
#include <vector>
using namespace std::chrono;
using namespace std;

void printArray(int A[], int n);

int main(){
	int n;
	cout << "Enter size of array: ";
	cin >> n;
	//int A[n];
	vector<int> A(n);
	for(int i = 0; i<n; i++){
		A[i] = rand()%100;
	}
	
	//cout << "Input randomized array: "; printArray(A,n);
	
	auto start = high_resolution_clock::now();
	//int B[n];
	vector<int> B(n/2);
	int count = 0;
	//every even i, compare with A[i] with A[i+1], then add larger elements to new array B, indexed by count that is incremented every iteration, O(n)
	for(int i = 0; i<n; i+=2){
		if(A[i] > A[i+1]){
			B[count] = A[i];
			count++;
		}else{
			B[count] = A[i+1];
			count++;
		}
	}

	//cout << "New array of n/2 larger elements: "; printArray(B,n/2);

	//compare every sequential element in O(n) time
	int max = B[0];
	for(int i = 1; i < n/2; i++){
		if(B[i] > max){
			max = B[i];
		}
	}
	
	cout << "Maximum of input array: " << max << endl;
	
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time in microseconds for max algorithm, of size " << n << ": " << duration.count() << endl;
	
	return 0;	
}

//for each element in input array, print element
void printArray(int A[], int n){
	for(int i = 0; i<n; i++){
		cout << A[i] << ' ';
	}
	cout << endl;
}