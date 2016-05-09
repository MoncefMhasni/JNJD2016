/* This is an example solution to the "Try me first" problem from
 * JNJD 2016, held on May 8, 2016.
 *
 * This solution has O(1) time complexity per test case
 *
 * Solution by MHASNI Moncef
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	freopen("trymefirst.in","r",stdin);
	freopen("out.txt","w",stdout);
	ll x,y,z;
	while(cin>>x>>y>>z){
		if (z == x + y)cout<<"+";
		if (z == x - y)cout<<"-";
		if (z == x * y)cout<<"*";
		cout<<endl;
	}
}
