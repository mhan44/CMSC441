#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std::chrono;
using namespace std;

/* Generate the set of all subsets, the powerset. In this method, we represent sets as binary numbers, where 0 = exclude and 1 = include, and the position/index
of the value represents an element in a set. Thus 000 = null set, 001 = {a3}, 011 = {a2,a3}, 111 = {a1,a2,a3}, etc. We know from binary number representation 
that for n digits, the max number binary can represent is (2^n)-1, thus to generate the powerset of n digits, we just generate all binary numbers for n digits. 
*/
vector<string> bitstring(int);
//function to convert an integer value to its binary representation of string type
string binaryconversion(int);
/* Another powerset generation algorithm that implements minimal change in its method. Recursively creates a list of all bit strings of length n, and returns
the list, using a positive integer as input.
*/
vector<string> graycode(int);
//simple print function for a vector
void print2(vector<string>,int);

int main(){
	//Initialize input array and its size n
	int n;
	cout << "Enter set size: ";
	cin >> n;
	vector<int> array;
	for(int i = 1; i<=n; i++){
		array.push_back(i);
	}
	
	cout << "Choose generation method, (1 = Bit string, 2 = Gray code): ";
	int choice;
	cin >> choice;
	
	if(choice == 1){
		cout << "Using Bit string: =================" << endl;
		auto start = high_resolution_clock::now(); //start time
		vector<string> powerset; //initialize
		powerset = bitstring(n); //execute
		auto stop = high_resolution_clock::now(); //end time
		auto duration = duration_cast<microseconds>(stop - start); //total differenece 
		cout << "Time in microseconds for Bit string algorithm: " << duration.count() << endl;
		//print2(powerset, n);
		cout << "=======================================" << endl;
	}else{
		cout << "Using Gray code: =================" << endl;
		auto start = high_resolution_clock::now(); //start time
		vector<string> powerset; //initialize
		powerset = graycode(n); //execute
	 	auto stop = high_resolution_clock::now(); //end time
		auto duration = duration_cast<microseconds>(stop - start); //total difference
		cout << "Time in microseconds for Gray code algorithm: " << duration.count() << endl;
		//print2(powerset,n);
		cout << "=======================================" << endl;
	}

	return 0;	
}

vector<string> bitstring(int n){
	int psize = pow(2,n); //power set size = 2^n - 1
	vector<string> powerset; //container for all subsets
	
	//for every integer from 1 to 2^n-1
	for(int i = 0; i<psize; i++){
		//convert the integer to its binary representation, thus a subset of the original set
		powerset.push_back(binaryconversion(i));
	}
	
	return powerset; //return powerset
}
string binaryconversion(int n){
	if(n == 0){ //base case, for the first subset, the null set
		return "0";	
	}
	string final = "";
	//while the integer is greater than 0, perform integer division by 2. If there is a remainder, append 1 to the string, else append 0
	while(n > 0){
		if( (n%2) == 0){
			final = "0" + final; //left to right, because we divide n as a whole initially, then approach 0
		}else{
			final = "1" + final;	
		}
		n = n/2;
	}
	return final;	
}

vector<string> graycode(int n){
	if(n == 1){ //base case, if there's 1 digit, then return {0,1}
		vector<string> temp;
		temp.push_back("0");
		temp.push_back("1");
		return temp;
	}
	
	vector<string> final; //final powerset
	vector<string> L1 = graycode(n-1); //recursively generate L1
	vector<string>L2; //reverse L1
	//initialize L2 to be the reverse of L1
	for(int i = L1.size()-1; i>-1; i--){
		L2.push_back(L1[i]);
	}	
	
	//append 0 to each bit string of L1, then append each to the powerset
	for(int j = 0; j<L1.size(); j++){	
		final.push_back("0" + L1[j]);
	}
	//append 1 to each bit string of L2, then append to the powerset
	for(int k = 0; k<L2.size(); k++){
		final.push_back("1" + L2[k]);	
	}
	
	return final; //final powerset
}

void print2(vector<string> A, int n){
	for(int i = 0; i < A.size(); i++){
		cout << i+1 << ": " << A[i] << endl;	
	}
	
}