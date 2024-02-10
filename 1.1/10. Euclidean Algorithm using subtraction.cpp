#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n = 24;
	int m = 60;
	int r = 0;
	bool cond = true;
	
	while(n!=0){
		cout << "M: " << m << ", N: " << n << endl;
		if(m<n){
			r = n;
			n = m;
			m = r;
		}else{
			m = m-n;
		}
	}
	
	cout << m << endl;
	
	/*while(n>0){
		//cout << m << " " << n << endl;
		while(cond == true){
			cout << m << endl;
			if( (m-n)<0 || n<=0){
				cond = false;
				break;
			}else{
				m = m-n;	
			}
		}
		//r = m % n;
		r = m;
		m = n;
		n = r;		
	}*/
	
	return 0;
}