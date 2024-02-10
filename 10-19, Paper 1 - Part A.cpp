#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;
//Basic iterative function to print contents of array
void printArray(int A[], int n);
//Insertion sort function, takes in a passed array and the size of the array, an integer n
void insertionSort(int A[], int n);
//Function implementing Hoare's partitioning algorithm, which uses the first element as a pivot to partition an array
int HPar(int A[], int l, int r);
//Quick sort function, calls parition function and recursively sorts sub-arrays of input array
void quickSort(int A[], int l, int r);

int main(){
	//Initialize input array and its size n
	
	int n;
	cout << "Enter size of array: ";
	cin >> n;
	int array[n];
	for(int i = 0; i<n; i++){
		array[i] = rand()%100;
	}
	//int array[10] = {100,2,55,-1,30,-3, 2, -4, 1, -10};
	//int n = 10;
	
	cout << "Choose sorting method, (1 = Insertion, 2 = Quick): ";
	int choice;
	cin >> choice;
	
	if(choice == 1){
	//print unsorted array
		cout << "Using insertion sort: =================" << endl;
		//cout << "Unsorted: "; printArray(array, n);
		//sort array using insertion sort
		auto start = high_resolution_clock::now();
		insertionSort(array, n);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		cout << "Time in microseconds for insertion sort algorithm: " << duration.count() << endl;
		//print sorted array
		//cout << "Sorted:   "; printArray(array,n);
		cout << "=======================================" << endl;
	}else{
		//print unsorted array
		cout << "Using quick sort: =================" << endl;
		//cout << "Unsorted: "; printArray(array, n);
		//sort array using insertion sort
		auto start = high_resolution_clock::now();
		quickSort(array, 0, n-1);
	 	auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		cout << "Time in microseconds for quicksort algorithm: " << duration.count() << endl;
		//print sorted array
		//cout << "Sorted:   "; printArray(array,n);
		cout << "=======================================" << endl;
	}

	return 0;
}

//for each element in input array, print element
void printArray(int A[], int n){
	for(int i = 0; i<n; i++){
		cout << A[i] << ' ';
	}
	cout << endl;
}

/*Insertion sort is a stable and in-place sorting algorithm that for an array of n elements, does pairwise key swaps for every element and inserts them into
the sorted sub array on the right of the array A. Worst/average-case = theta(n^2), Best-case = theta(n)
*/
void insertionSort(int A[],int n){
	for(int i = 1; i<n; i++){ //for every element in the array
		int key = A[i]; //initialize key to current outer iteration
		int j = i-1; //initialize pointer to previous element of the current element
		/* Keep iterating the right sub-array until we find some element k that is smaller than the current element, thus shifting all elements greater than the
		current element by +1 index. This shift is to make room for the current element coming in, where it is then inserted to the left of k. We are able to
		insert immediately once this k is found, because we know that the sub-array is sorted, and thus all elements A[0...k-1] are smaller than k, and thus 
		smaller than the current element. */
		while(j >=0 && A[j] > key){ //if any previous key is greater than the current key
			A[j+1] = A[j]; // shift elements greater than the current key by +1
			j--; //iterate left to right of the sorted sub array
		}
		A[j+1] = key; // we have found an element smaller than the key in the sorted sub-array, now insert current key to the left of that element
	}
}

/* Hoare's partition utilizes 2 indicies starting from the front and the end, where elements of the left of the pivot must be smaller and greater on the right
it will keep iterating until the two incrementing indices meet, swapping any elements that are found to be in the wrong position prior to each increment. */
int HPar(int A[], int l, int r){
	int p = A[l]; //initialize pivot 
	int i = l - 1; //initialize lower index
	int j = r + 1; //initialize upper index

	//until the two indices meet, repeat
	while(i<j){
		do{
			i++;
		}while(A[i] < p); //increment i until an element greater or equal to the pivot is found on the left side
		
		do{
			j--;
		}while(A[j] > p); //decrement j until an element less or equal to the pivot is found on the right side
		
		//swap the mismatching elements to their correct side
		int temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	}
	
	//undo final unnesscary swap after indices have met
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
	
	//Swap pivot and A[j] such that the pivot is now in its correct index, because the indices have met and all elements to its left will be less than or equal,
	// and all elements to its right will be greater than or equal
	temp = A[l];
	A[l] = A[j];
	A[j] = temp;
	
	//The outer while loop has terminated thus the indices have met, there is no more array to traverse thus return the current index
	return j; 
}

//Quick sort will call Hoare's Partition to paritition the array, 
void quickSort(int A[], int l, int r){
	if(l<r){
		int s = HPar(A,l,r); //sort the first element to its correct position
		quickSort(A,l,s); //sort below partition
		quickSort(A,s+1,r); //sort parition element
	}
}