/* This is an example solution to the "Baseball" problem from
 * JNJD 2016, held on May 8, 2016.
 *
 * This solution has O(1) time complexity per test case
 *
 * Solution by MHASNI Moncef
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("baseball.in","r",stdin);
	freopen("baseball.out","w",stdout);
	int tc;cin>>tc;
	while(tc--){
		double a;cin>>a;
		double ans = sqrt(2)*a/(sqrt(3)-1);
		cout.precision(6);
		cout<<fixed<<ans<<endl;
	}
}