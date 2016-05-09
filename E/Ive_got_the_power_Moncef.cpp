/* This is an example solution to the "I've got the power" problem from
 * JNJD 2016, held on May 8, 2016.
 *
 * This solution has O(N)+O(k²) time complexity where k is the order of a permutation
 *
 * Solution by MHASNI Moncef
 */
#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
using namespace std;
vi visited,X;
vector<vi> dcmp(vi v,int N){
    vector<vi> ans;
    for(int i=1;i<=N;i++){
        vi x;
        if(!visited[i]){
            if(v[i]==i)
            x.pb(i);
            else{
                int d =1,tmp = i;
                while(!visited[tmp]){
                    x.pb(tmp);
                    visited[tmp]=1;
                    tmp=v[tmp];
                }
            }
            ans.pb(x);
        }
    }
    return ans;
}
vi power(vi a,int t){
    vi ans(a.size(),0);
    for(int i=0;i<a.size();i++)
        if(i+t<a.size())
        X[a[i]]=a[i+t];
        else
        X[a[i]]=a[i+t-a.size()];
    return ans;
}
int main(){
    freopen("power.in","r",stdin);
    freopen("out.txt","w",stdout);
    int tc;cin>>tc;
    while(tc--){
        int N,P;scanf("%d%d",&N,&P);
        X.clear();
        X.resize(N+1);
        for(int i=1;i<=N;i++)scanf("%d",&X[i]);
        visited.clear();visited.resize(N+1,0);
        vector<vi> D=dcmp(X,N);
        for(int i=0;i<D.size();i++){
            int t = P%D[i].size();
            power(D[i],t);
        }
        for(int i=1;i<=N;i++)
            cout<<X[i]<<" ";
        cout<<endl;
    }
}

