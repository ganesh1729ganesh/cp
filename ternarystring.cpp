#include <bits/stdc++.h>
using namespace std;

bool isValid(string s,int k){
	
	int arr[4] ={0};
	
	for(int i=0;i<k-1;i++){
		int idx = s[i]-'0';
		arr[idx]++;
	}
	
	
	for(int i=k-1;i<s.length();i++){
		
		int idx = s[i]-'0';
		arr[idx]++;
		
		if(arr[1]>0 and arr[2]>0 and arr[3]>0) return true;
		
		idx = s[i-k+1] - '0';
		
		arr[idx]--;
	}
	
	return false;
	
}

int ternary(string s){
	
	int l =3;
	int r = s.length();
	int res = INT_MAX;
	
	while(l<=r){
		int mid = l+(r-l)/2;
		
		if(isValid(s,mid)){
			res = min(mid,res);
			r = mid-1;
		}
		else l = mid+1;
	}
	if(res==INT_MAX) return 0;
	
  	return res;
	
}

int main() {
  
  int t;
  cin>>t;
  while(t--){
  	string s;
  	cin>>s;
  	cout<<ternary(s)<<endl;
  }
	
	
	
	
	return 0;
}