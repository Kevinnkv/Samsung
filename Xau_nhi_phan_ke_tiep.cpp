#include <bits/stdc++.h>

using namespace std;

string s;
void Xnpkt(){
	int l=s.size();
	int i=l-1; // duyet tu cuoi ve
	while(i>=0 && s[i]=='1'){
		s[i]='0';
		i--;
	}
	if(i>=0){//doi ki tu 0 ve ki tu 1
		s[i]='1';
	}
	else s = s + '0'; // truong hop xau toan 1
}
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> s;
		Xnpkt();
		cout << s << endl;
	}
	return 0;
}

