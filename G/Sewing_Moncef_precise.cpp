#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("sewing.in","r",stdin);
	freopen("sewing.out","w",stdout);
	int tc=100;
	while(tc--){
		int n;double X,Y;
		cin>>n;cin>>X>>Y;
		double req=1,ans = 0,x;
		for(int i=0;i<n;i++){
			cin>>x;
			if(req<=0)continue;
			ans += Y*req;
			req=req*2-x;
			swap(X,Y);
			Y/=2;
		}
		if(req>0){
			cout<<"impossible\n";
			continue;
		}
		cout.precision(6);
		cout<<fixed<<ans<<endl;
	}
}