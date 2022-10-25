#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> arr = {3,1,2,5,3};
	int rep, mis;
	for(int i=0;i<5;i++){
		if(arr[abs(arr[i])-1] < 1) {rep = abs(arr[i]); break;}
		else{
			arr[abs(arr[i])-1] = -arr[abs(arr[i])-1] ;
		}
	}
	for(auto it:arr) cout<<it;
}