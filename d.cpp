#include<bits/stdc++.h>
using namespace std;
//aag lage basti me bhai tera masti me//
//ek achcha programmer wo hai cntise pata ho ki konsa contest  dena hai aur konsa nhi//
#define gc getchar_unlocked
#define inf 1e18
#define pb push_back
#define fo(i,n) for(int i=0;i<n;i++)
#define fo1(i,n) for(int i=1;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             998244353 
#define inf             1e18
#define p(x,y)         fixed<<setprecision(y)<<x
#define mk(type,arr,n)  type *arr=new type[n];// dynamic memory allocation
#define w(x)            int x; cin>>x; while(x--)
#define lc (id<<1)      //segtree left child;
#define rc (id<<1)|1    //segtree right child;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
//=======================
typedef pair<int, int>  pii;
typedef vector<ll>     vi;
typedef vector<pii>     vpii;
typedef vector<vi>      vvi;
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
//=======================
const int MOD = 1e9+7;
const int N = 300005, M = N;
//=======================
vector <int> vec;
int dp[105][3][105][105];
int cnt[3];
void up(ll x,ll y)
{
	if (y==0)
		return;
	if (x==0)
	{
		x=y;
	}
	x = min(x,y);
}
ll power(ll a, ll b)	//a is base, b is exponent
	{
		if(b==0)
			return 1;
		if(b==1)
			return a;
		if(b%2 == 1)
			return (power(a,b-1)*a)%mod;
		ll q = power(a,b/2);
		return (q*q)%mod;
	}
// int cost(int pos) {
//   if(pos == 0 || pos == n - 1) return 0;
//   return (vec[pos] > vec[pos - 1] && vec[pos] > vec[pos + 1]) || (vec[pos] < vec[pos - 1] && vec[pos] < vec[pos + 1]);  
// }
	
int main()
{ FIO;
int t,n;
cin>>n>>t;
string s;
cin>>s;
if(t==2)
{
if (n%2==1)
{
	string z = "";
	for (int i = 0; i < n/2; ++i)
	 {
	 	z+="BA";/* code */
	 } 
	 z+="B";
	string c = "";
	for (int i = 0; i < n/2; ++i)
	{
	c+="AB";	/* code */
	}
	c+="A";
	
	int f=0,d=0 ; 
	for (int i = 0; i < n; ++i)
	{
		if (z[i]!=s[i])
		{
			f++;
		}
		if(c[i]!=s[i])
		{
			d++;
		}
	}
  if(f<d)
  {
  	cout<<f<<endl;

  	cout<<z;
  }
  else
  {
  	cout<<d<<endl;
  	cout<<c;

  }
}
if (n%2==0)
{
	string z = "";
	for (int i = 0; i < n/2; ++i)
	 {
	 	z+="BA";/* code */
	 } 
	string c = "";
	for (int i = 0; i < n/2; ++i)
	{
	c+="AB";	/* code */
	}
	
	int f=0,d=0 ; 
	for (int i = 0; i < n; ++i)
	{
		if (z[i]!=s[i])
		{
			f++;
		}
		if(c[i]!=s[i])
		{
			d++;
		}
	}
  if(f<d)
  {
  	cout<<f<<endl;

  	cout<<z;
  }
  else
  {
  	cout<<d<<endl;
  	cout<<c;

  }
}
}
if(t>2)
{   int an = 0;
	for(int i=1;i<n;i++){
		if(s[i]==s[i-1]){
			for(int j=0;j<3;j++)
				if('A'+j!=s[i-1]&&'A'+j!=s[i+1]){s[i]='A'+j;an++;break;}
		}
	}
	cout<<an<<endl;
	cout<<s;
  


}
}








