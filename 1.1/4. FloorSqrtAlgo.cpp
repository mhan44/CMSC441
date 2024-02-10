using namespace std;
#include <iostream>
#include <cmath>

int main(){
	int n;
	cout << "Enter int" << endl;
	cin >> n;
	int x = 1;
	int y = 1;
	while(x<n){
		x = y*y;
		y++;
	}
	int z = y-2;
	cout << z << endl;
	cout << floor(sqrt(n)) << endl;
	return 0;
}