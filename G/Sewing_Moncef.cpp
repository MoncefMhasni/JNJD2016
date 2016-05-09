/* This is an example solution to the "Sewing" problem from
 * JNJD 2016, held on May 8, 2016.
 *
 * This solution has O(N) time complexity per test case
 *
 * Solution by MHASNI Moncef
 */
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define f first
#define s second
vector<pair<double,double> > thread;
double solve(vector<int> v,int N,long long req,int d){
	if(req == 0) return 0;
	if(d>=N && req !=0) return -1; 
	double ans = 0;
	if(req<=v[d]) {
		int L,C;
		if(d%2)
			L=C=round(sqrt(req));
		else {
			L=round(sqrt(0.5*req));
			C=2*L;
		}
			
		ans = (L-1)*C*thread[d].s+(L)*(C-1)*thread[d].f;
		return ans;
	}
	else if(v[d]>0){
		ans -= v[d]*thread[d].s;
		if(d+1<N)
		v[d+1]+= 2*v[d];
	}
	double tmp = solve(v,N,req*2,d+1);
	return (tmp >=0 ? ans + tmp : -1);

}
int main()
{
	freopen("sewing.in","r",stdin);
	freopen("sewing.out","w",stdout);
	int N,tc=100;double A,B;
	while(tc--){
		cin>>N>>A>>B;
		thread.clear();
		thread.push_back(mp(B,0.5*A));
		vector<int> v(N);
		for(int i=0;i<N;i++){
			cin>>v[i];
			thread.push_back(mp(thread.back().s,0.5*thread.back().f) );
		}

		double ans=0;
		ans = solve(v,N,2,0);
		if (ans <0 ) 
			cout<<"impossible"<<endl;
		else 
			printf("%.6lf\n",ans );
	}

}