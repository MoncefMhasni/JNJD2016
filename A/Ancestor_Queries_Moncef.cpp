/* This is an example solution to the "Ancestor Queries" problem from
 * JNJD 2016, held on May 8, 2016.
 *
 * The preprocessing has 2*O(n+m) time complexity, and each query is answerd in O(1)
 *
 * Solution by MHASNI Moncef
 */
#include <bits/stdc++.h>
using namespace std;
#define Nmax 100003
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define mp make_pair
vector<vi> v;
int visited[Nmax];
int pre[Nmax];
int post[Nmax];
int xd;
void preorder(int s){
    visited[s]=1;
    pre[s]=xd++;
	for(vi::iterator i=v[s].begin();i!=v[s].end();++i){
		if(!visited[*i]) {
			preorder(*i);
		}
	}

}
void postorder(int s){
	for(vi::iterator i=v[s].begin();i!=v[s].end();++i){
        if(!visited[*i]) {
            visited[s]=1;
			postorder(*i);
		}
	}
        post[s]=xd++;
        visited[s]=1;

}
int main(){
	freopen("ancestor.in","r",stdin);
	freopen("out.txt","w",stdout);
	int tc;cin>>tc;
	while(tc--){
		cerr<<10-tc<<endl;
		int N;cin>>N;v.clear();v.resize(N);
		for(int i=1;i<N;i++){
			int x,y;scanf("%d%d",&x,&y);
			v[x-1].pb(y-1);
			v[y-1].pb(x-1);
		}
        memset(visited,0,sizeof(visited));xd=0;preorder(0);
        memset(visited,0,sizeof(visited));xd=0;visited[0]=1;post[0]=N;postorder(0);
		int M;cin>>M;
		while(M--){
			int a,b;scanf("%d%d",&a,&b);a--;b--;
			if(pre[a]<pre[b]&&post[a]>post[b])
				cout<<"1";
			else cout<<"0";
		}
		cout<<endl;
	}
}
