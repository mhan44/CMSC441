#include <iostream>
#include <vector>
using namespace std;

int main(){
	
	
	// variables
   int n,no_open=0;
   cout<<"enter the number of lockers:";

   // read the number of lockers
   cin>>n;

   // initialize all lockers with 0, 0 for locked and 1 for open
   int lock[n]={};

   // toggle the locks
   // in each pass toggle every ith lock
   // if open close it and vice versa-
   for(int i=1;i<=n;i++){
       for(int a=0;a<n;a++)
       {
           if((a+1)%i==0)
           {
               if(lock[a]==0)
               	lock[a]=1;
               else if(lock[a]==1)
               	lock[a]=0;
           }
       }
   }

   cout<<"After last pass status of all locks:"<<endl;

   // print the status of all locks
   for(int x=0;x<n;x++)
   {
       if(lock[x]==0){
           cout<<"lock "<<x+1<<" is close."<<endl;
       }else if(lock[x]==1){
           cout<<"lock "<<x+1<<" is open."<<endl;
           // count the open locks
           no_open++;
       }
   }
   // print the open locks
   cout<<"total open locks are :"<<no_open<<endl;

	return 0;
}