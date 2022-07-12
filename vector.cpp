#include<bits/stdc++.h>
using namespace std;
#include<vector>

//vecto <kieu du lieu> ten_vecto
// vecto<int> v(n,value)
int main(){
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	
    cout<<v.size()<<endl;
    cout<<"phan tu dau tien"<<v[0]<<endl;
    cout<<"phan tu cuoi cung"<<v[v.size()-1];
// vong lap for each
	for(int x:v){
		cout<<x<<endl;
	}
	// su dung con tro iterator
	for(vector<int>::iterator it=v.begin();it!=v.end();it++){
		cout<<*it<<endl;
	}
	// hoac co the thay (vector<int>::iterator)=auto
	return 0;
}
