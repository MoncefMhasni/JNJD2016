/* This is an example solution to the "Find and replace" problem from
 * JNJD 2016, held on May 8, 2016.
 *
 * This solution has O(N) time complexity per test case
 *
 * Solution by MHASNI Moncef
 */
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("out.txt","w",stdout);
	string s;
	while(cin>>s){
		for(int i=0;i<s.length();i++){
			cout<< (s[i]=='x' ? "yx" : (s[i]=='y' ? "xy" : string(1,s[i])));
		}
		cout<<endl;
	}
}