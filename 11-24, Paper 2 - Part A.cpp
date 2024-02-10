#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <algorithm>
using namespace std::chrono;
using namespace std;

/*Generating Permutations using minimal change, therefore we use a vector of vectors of integers, the inner vectors being the permutations for the original string
Vectors are used because they are very light, almost the same if not the same time complexity as arrays, meaning no loss in performance, with additional features.
Recursive function that if the base case n==1, then add that signle permutation of 1 character, else insert the current character n into all positions of the 
permutations from 12...n-1, starting right to left then switching left to right for every new permutation
*/
vector<vector<int>> perm(vector<int>, int);
/* Johnson and Trotter algorithm, takes in a single integer n as input and returns n! permutations of n characters. Skips generating permutations for smaller 
values of n, meaning we don't need to generate (n-1)! permutations that are generated from (n-2)! permutations, that originite from the 1! permutation.|
To do this, we implement the rules of mobile numbers and use two arrays to define the integer values and their arrow directions. Explaination in depth within
the function comments.
*/  
vector<vector<int>> JT(int);
//For Johnson and Trotter algorithm, check if there are any mobile numbers still in the array, required for algorithm loop.
bool checkMobileNumber(vector<int>, vector<string>);
//simple print function for nested vectors
void print1(vector<vector<int>>);

int main(){
	//Initialize input array and its size n
	int n;
	cout << "Enter size of array: ";
	cin >> n;
	vector<int> array;
	for(int i = 1; i<=n; i++){
		array.push_back(i);
	}
	
	cout << "Choose generation method, (1 = Minimal Change, 2 = Johnson and Trotter): ";
	int choice;
	cin >> choice;
	
	if(choice == 1){
		cout << "Using Minimal Change D&C: =================" << endl;
		auto start = high_resolution_clock::now(); //start time
		//Execute algorithm
		vector<vector<int>> minimal_change = perm(array,n);
		auto stop = high_resolution_clock::now(); //end time
		auto duration = duration_cast<microseconds>(stop - start); //total differenece 
		cout << "Time in microseconds for minimal change algorithm: " << duration.count() << endl;
		//Print total permutations
		//print1(minimal_change);
		cout << "=======================================" << endl;
	}else{
		cout << "Using Johnson and Trotter: =================" << endl;
		auto start = high_resolution_clock::now(); //start time
		vector<vector<int>> johnson_trotter = JT(n);
	 	auto stop = high_resolution_clock::now(); //end time
		auto duration = duration_cast<microseconds>(stop - start); //total difference
		cout << "Time in microseconds for Johnson and Trotter algorithm: " << duration.count() << endl;
		//print total permutations
		//print1(johnson_trotter);
		cout << "=======================================" << endl;
	}

	return 0;	
}

vector<vector<int>> perm(vector<int> A, int n){
	vector<vector<int>> final; // the vector of permutations for the current n iteration, for n characters
	if(n == 1){ //base case, permutations of a single character
		vector<int> new_perm; //create new permutation
		new_perm.push_back(A[n-1]); //simply just the last character of the original string
		final.push_back(new_perm); //add to vector of total n! permutations, as the FIRST entry
	}else{
		/*recursive call, obtains the previous (n-1)! permutations to add the single n character to every position.Know that this will recurse to the base case, 
		thus the first (n-1)! vector of permutations will just be {1}, then we add 2 to every position to create{12, 21}, then on the n=3 iteration
		we add 3 to every position, and so on.
		*/
		vector<vector<int>> final2 = perm(A, n-1); // vector of (n-1)! permutations
		//for every permutation in the vector of the previous (n-1)! permutations, insert n into each position 
		for(unsigned int j = 0; j < final2.size(); j++){ 
			vector<int> next = final2[j]; //previous permutation
			for(int i = 0; i <= next.size(); i++){
					vector<int> new_perm = next;
					new_perm.insert(new_perm.begin()+i,A[n-1]); //insert n into position i
					final.push_back(new_perm); //construct this iteration's n! permutations
			}
			
		}	
 
	}
	return final; //return n! permutations
}

vector<vector<int>> JT(int n){
	//initialize first permutation with <1 <2 ... <n, as mobile numbers
	//while there exists a mobile number (number greater than its adjacent neighbor (its arrow points to): 
		//find and select the largest mobile integer k 
		//swap k and its adjacent integer its pointed to
		//reverse direction of all integers larger than k
		
	//initialize vectors
	vector<int> A;
	vector<string> B;
	for(int i = 1; i<=n; i++){
			A.push_back(i);
			B.push_back("<");
	}
	
	//vectors of permutations and arrows
	vector<vector<int>> totalA;
	vector<vector<string>> totalB;
	
	//initialize
	totalA.push_back(A);
	totalB.push_back(B);
	
	int max_val = -1; //initialize max
	int max_i = -1; //initialize max index
	//while a mobile number exists inside the vector
	while(checkMobileNumber(totalA.back(),totalB.back()) != false){
		
		//create deep copies to store new permutations, NOTE: NOT NECESSARY, time waster
		//vector<int> A = totalA.back();
		//vector<string> B = totalB.back();
		
		//get max mobile number
		for(int i = 0; i<A.size(); i++){ //for every element in the vector
			//base case to reset max mobile number if it is the first element and points to nothing
			if(max_i == 0 && B[max_i] == "<"){
				max_val = -1;	
			}
			//base case to reset max mobile number if it is the last element and points to nothing
			if(max_i == A.size()-1 && B[max_i] == ">"){
				max_val = -1;	
			}
			//if the number is greater than the current max, if its arrow is pointed to the left, and if its index is not the first element
			if(B[i] == "<" && i != 0){
				if(A[i] > A[i-1] && A[i] > max_val){
					max_val = A[i];
					max_i = i; //assign new max to its index	
				}
			//if the number is greater than the current max, if its arrow is pointed to the right, and if its index is not the last element
			}else if(B[i] == ">" && i != (A.size()-1)){	
				if(A[i] > A[i+1] && A[i] > max_val){
					max_val = A[i];
					max_i = i; //assign new max to its index
				}
			}
		}
		
			/*if(A[i]	> max_val){
				//if the number is greater than the current max, if its arrow is pointed to the left, and if its index is not the first element
				if(B[i] == "<" && i != 0){
					//if the number is greater than the number its pointed to
					if(A[i] > A[i-1]){
						max_val = A[i];
						max_i = i; //assign new max to its index
					}
				//if the number is greater than the current max, if its arrow is pointed to the right, and if its index is not the last element
				}else if(B[i] == ">" && i != (n-1)){
					if(A[i] > A[i+1]){
						max_val = A[i];
						max_i = i; //assign new max to its index
			
					}
				}
			}
		}*/
		
		//swap max mobile number with its target
		if(B[max_i] == "<"){
			swap(A[max_i], A[max_i-1]);
			swap(B[max_i], B[max_i-1]);
			max_i--;
		}else{
			swap(A[max_i], A[max_i+1]);
			swap(B[max_i], B[max_i+1]);
			max_i++;
		}
		
		//swap arrows of all numbers greater than the mobile number
		for(int i = 0; i<A.size(); i++){
			if(A[i] > max_val){
				if(B[i] == "<"){
					B[i] = ">";	
				}else if(B[i] == ">"){
					B[i] = "<";	
				}
			}
		}
		
		totalA.push_back(A); //append new permutation to back of total
		totalB.push_back(B); //append new arrows for the latest permutation
	}
	return totalA; //return total list of permutations
}

bool checkMobileNumber(vector<int> A, vector<string> B){
	//for every element in the vector, if any number satisfies the mobile integer definition, return true, else reutnr false
	for(int i = 0; i<A.size(); i++){
		if(B[i] == "<" && i != 0){
			if(A[i] > A[i-1]){
				return true;	
			}
		}else if(B[i] == ">" && i != (A.size()-1)){
			if(A[i] > A[i+1]){
				return true;	
			}
		}
	}
	return false;
}

void print1(vector<vector<int>> A){
	for(unsigned int i = 0; i < A.size(); i++){
		cout << i << ": ";
		for(unsigned int j = 0; j < A[i].size(); j++){
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}