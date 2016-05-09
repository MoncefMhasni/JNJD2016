/* This is an example solution to the "Treasure hunt" problem from
 * JNJD 2016, held on May 8, 2016.
 *
 * This solution has O(8*N²) time complexity
 *
 * Solution by MHASNI Moncef
 */
#include <bits/stdc++.h>
#define inf 1<<30	
#define MAX 501
#define pii pair<int,int>
#define f first
#define s second
#define mp make_pair
#define pb push_back
using namespace std;
int N,M;
vector<int> D[1<<4][MAX];
int solve(vector<string> g,int xs,int ys,int xe,int ye){
    if(xs==xe&&ys==ye)return 0;
    queue<pair<int,int> >Q;
    Q.push(mp(xs,ys));
    vector<int> Keys[MAX];
    for(int i=0;i<MAX;i++)Keys[i].resize(M,0);
    while(!Q.empty()){
        int a =Q.front().f,b=Q.front().s;
        Q.pop();
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int u = a+i,v=b+j;
                if( u<0 ||v <0 || u >= N || v >= M || abs(i)+abs(j)>1)continue;
                int keys =Keys[a][b];             
                if((g[u][v]=='A'||g[u][v]=='B'||g[u][v]=='C')&& !(keys&(1<<g[u][v]-'A')))continue;
                int type = g[u][v]-'a';

                if( type>= 0 && type <3){
                	int tmp = keys | 1<<type;
                	Keys[u][v] = tmp;
	            	if(D[tmp][u][v]==inf){
	            		Q.push(mp(u,v));
	            	}
                	D[tmp][u][v]=min(D[tmp][u][v],1+D[keys][a][b]);
                }
                else {
                	if(D[keys][u][v]==inf){
                		Q.push(mp(u,v));
                	}
                	D[keys][u][v]=min(D[keys][u][v],1+D[keys][a][b]);
                	Keys[u][v]=max(Keys[u][v],keys);
                }
	        }
	    }
	}
    int ans = inf;
    for(int i=0;i<1<<4;i++)
    	ans = min (ans,D[i][xe][ye]);
    return ans;
}
int main(){
    freopen("treasure.in","r",stdin);
    freopen("out.txt","w",stdout);
    vector<string> G;
    int tc;cin>>tc;
    while(tc--){
        cin>>N>>M;
        G.clear();G.resize(N);
        int xs,xe,ys,ye;
        for(int i=0;i<N;i++){
        	for(int k =0;k<1<<4;k++){
            D[k][i].clear();
            D[k][i].resize(M,inf);
        	}

            cin>>G[i];
            for(int j=0;j<G[i].length();j++){
                if(G[i][j]=='S'){
                    xs = i;ys=j;
                }
                if(G[i][j]=='E'){
                    xe=i;ye=j;
                }
            }
        }
		D[0][xs][ys]=0;
        int ans=solve(G,xs,ys,xe,ye);
        cout<<(ans==inf? -1 : ans)<<endl;
    }
}
