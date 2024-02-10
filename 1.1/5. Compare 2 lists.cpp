#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> n;
	int array[4] = {2,5,5,5};
	int array2[6] = {2,2,3,5,5,7};
	for(int i = 0; i < 4; i++){
		for(int j = 0; j<6; j++){
			if(array[i] == array2[j]){
				n.push_back(array[i]);
				break;
			}
		}
	}
	for(unsigned int i = 0; i<n.size(); i++){
		cout << n.at(i) << endl;
	}
	return 0;
}