/* This is an example solution to the "Co-prime Substring" problem from
 * JNJD 2016, held on May 8, 2016.
 *
 * This solution has O(N²log(M)) time complexity per test case
 *
 * Solution by MHASNI Moncef
 */
#include<bits/stdc++.h>
using namespace std;
#define MAX 1002
#define ll long long
ll Md[MAX][MAX];
void mod (char *a,int s,int e,ll b){
    ll ans =0;
    for(int i=s;i<=e;i++){
        ans = ans*10 + (a[i]-'0'); // (sum xi*10^i) %m = (sum xi*10^i%m)%m
        ans %=b;
        Md[s][i]=ans;
    }
}
int gcd(ll a,ll b){
    if(b)return gcd(b,a%b);
    return a;
}
int solve(char *a,int i,int j,ll b){
   if(b) return (gcd(b,Md[i][j]));
   return (i==j && a[i]=='1');
}
int main(){
    freopen("coprime.in","r",stdin);
    freopen("out.txt","w",stdout);
    int tc;cin>>tc;
    while(tc--){
        cerr<<tc<<endl;
        ll N,M,ans=0;char S[MAX];
        scanf("%Ld%Ld",&N,&M);
        scanf("%s",S);
        for(int i=0;i<N;i++){
            mod(S,i,N-1,M);
            for(int j=N-1;j>=i;j--){
            if(solve(S,i,j,M)==1)
                ans++;
        }
       }
        cout<<ans<<endl;
    }
}
