  #include<bits/stdc++.h>
  using namespace std;
  #include <ext/pb_ds/assoc_container.hpp>
  #include <ext/pb_ds/tree_policy.hpp>
  using namespace __gnu_pbds;
  #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
  template <class K, class V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
  typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update>pref_trie;
  using namespace __gnu_cxx;
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
  #define M 4 // column of square
  #define UNASSIGNED -1
  #define setbits(x)      __builtin_popcountll(x)
  #define zrobits(x)      __builtin_ctzll(x)
  #define mod1             998244353
  #define mod2             1e9+7
  #define inf              1e18
  #define f(i, l, r) for(lli i=l;i<r;i++)
  #define p(x,y)         fixed<<setprecision(y)<<x
  #define mk(type,arr,n)  type *arr=new type[n];// dynamic memory allocation
  #define w(x)            int x; cin>>x; while(x--)
  #define fbo find_by_order    // value at  index in sorted array
  #define ook order_of_key  // Index of pair {i,j}  if Pair {i, j} is not in the map but it will show the index number if it was there in sorted array
  #define lc (id<<1)      //segtree left child;
  #define rc (id<<1)|1    //segtree right child;
  #define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  //=======================
  inline long long  MAX2(long long  a, long long  b){return (a)>(b)?(a):(b);}
  inline long long  MAX3(long long  a, long long  b,long long  c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
  inline long long  MIN2(long long  a, long long  b){return (a)<(b)?(a):(b);}
  inline long long  MIN3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}

  //=======================

ll power(ll x, ll y, ll mod) { ll res = 1; x = x % mod; while (y > 0) { if (y & 1) { res = (res * x);}  y = y >> 1; x = (x * x); res = res % mod; x = x % mod;}  return res % mod;}
ll invert(ll a, ll b) {return power(a, b - 2, b);} //For finding (a^-1)%b
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
vector<ll> sieve(ll n) {ll*arr = new ll[n + 1](); vector<ll> vect; for (ll i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (ll j = (ll)i * (ll)i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, invert(b, m), m) + m) % m;} //If m is prime
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x;}
ll lcm(ll x, ll y) {return (x * y) / gcd(x, y);}

  typedef pair<int, int>  pii;
  typedef vector<int>     vi;
  typedef deque<int>     dqi;
  typedef vector<pii>     vpii;
  typedef vector<vi>      vvi;
  #define pqb             priority_queue<int>
  #define pqs             priority_queue<int,vi,greater<int>>
  //=======================
  //=======================
//================================================================================ binomial temps
  #define lli long long int
  #define lld long double
  #define f(i, l, r) for(lli i=l;i<r;i++)
  #define IO_fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
  #define mp make_pair
  #define pb push_back
  #define pr pair<lli,lli>
  #define setp(a,b) fixed<<setprecision(b)<<a<<endl;
  #define N 100005
  #define MN 300005
  vector<int> sz;
  // vector<ll> adj[200005];
  // ll dp1[50005][501];
  // ll dp2[50005][501];
  // ll diameter[200005];
  // ll mypath = 0;

  /////DONT ERASE///////////DONT ERASE////////DONT ERASE//////////DONT ERASE////////////DONT ERASE////////DONT ERASE//////////DONT ERASE////////////
  //  ll res =  0;
  // int downPath[200001];
  // vector<int> tree[200001];
  // int depth[200001],depth1[200001];

  // void eval_depth(int src, int par,int val)
  // {
  //     int src_depth = val;
  //     int leaf = 1;
  //     depth[src] = src_depth;
  //     for(int child : adj[src])
  //     {
  //         if(child != par)
  //         {
  //            leaf = 0;
  //             eval_depth(child, src,val+1);
  //         }
  //     }

  // }
  // void eval_depth2(int src, int par,int val)
  // {
  //     int src_depth = val;
  //     int leaf = 1;
  //     depth1[src] = src_depth;
  //     for(int child : adj[src])
  //     {
  //         if(child != par)
  //         {
  //            leaf = 0;
  //             eval_depth2(child, src,val+1);
  //         }
  //     }

  // }

  // void eval_downPaths(int src, int par , int val)
  // {
  //     bool leaf = 1;
  //     dp1[src][0]  =1;
  //     for(int child : adj[src])
  //     {
  //         if(child != par)
  //         {
  //             leaf = 0;
  //             eval_downPaths(child, src, val);
  //              for( int k = 1;k<=val;k++)
  //         {
  //                  dp1[src][k] += dp1[child][k-1];
  //           }
  //         }

  //       }
  //          res+=dp1[src][val];
  //          ll  tot = 0;
  //          for(int child : adj[src])
  //          {
  //              if( child!=par)
  //              {
  //               for(int x = 1; x<=val-1;x++)
  //               {
  //                   tot += dp1[child][x-1]*(dp1[src][val-x]-dp1[child][val-x-1]);
  //               }
  //              }
  //          }
  //          res+=tot/2;
  // }
  //  void solve(ll src, ll par)
  //  {  vector<ll>child_path;
  //     ll ans = 0;
  //     for(auto child: adj[src])
  //     {
  //       if(child != par)
  //       {
  //         solve(child,src);
  //          child_path.pb(downPath[child]);
  //          ans = max(ans,diameter[child]);
  //       }
  //     }
  //       int n = child_path.size();
  //       sortall(child_path);
  //       if(n==0) diameter[src] = 0;
  //       else if(n==1) diameter[src]=child_path[0]+1;
  //       else
  //       {
  //          diameter[src] = 2+child_path[n-1]+child_path[n-2];
  //       }
  //     diameter[src] = max(diameter[src],ans);



  // }
   //BAAD ME LIKHNE ME PROBLEM HOGI GAANDU.
  /////DONT ERASE///////////DONT ERASE////////DONT ERASE//////////DONT ERASE////////////DONT ERASE////////DONT ERASE//////////DONT ERASE////////////
//    vector<int> v[N];
// int dep[N],up[N][21];
//    void binary_lift(int src,int par)
//    {
//      up[src][0] = par;
//      for (int i = 1; i < 20; ++i)
//      {
//         if(up[src][i-1]!=-1)
//         {
//           up[src][i]  = up[up[src][i-1]][i-1];
//         }
//         else {
//             up[src][i] = -1;
//         }
//      }
//       for(int child : v[src])
//       {
//         if(child !=par)
//         {
//           binary_lift(child,src);
//         }
//       }

//    }
//     int ans_q( int node, int jump_req)
//     {
//        if(node ==-1|| jump_req==0) return node;
//         for (int i = 19; i >= 0; --i)
//         {
//           if(jump_req>=(1<<i))
//           {
//             return ans_q(up[node][i],jump_req-(1<<i));
//           }
//         }
//     }
/////DONT ERASE///////////DONT ERASE////////DONT ERASE//////////DONT ERASE////////////DONT ERASE////////DONT ERASE//////////DONT ERASE/////////////////
//BAAD ME LIKHNE ME PROBLEM HOGI GAANDU.


int main(){
  int T;
  cin>>T;
  // FOR FINDING FACTORIAL OF NUMBERS FROM 1 TO 2*10^5 and here MODULO is 1e9+7
   ll *fact = new ll[200000 + 5];
   ll *ifact = new ll[200000 + 5];
  fact[0] = 1, ifact[0] = 1;
  for (ll i = 1; i <= 2e5+2; i++) {
    fact[i] = mod_mul(fact[i - 1], i, mod1);
    ifact[i] = invert(fact[i],mod1);
  }
  while(T--)
  {
     int n;
     cin>>n;
      vector<int> vec(n+1);
       for( int i = 1;i<=n;i++ )
       { int x;
        cin>>x;
        vec[i] = x;
       }
       sort(vec.begin() + 1,vec.end());
     if(count(vec.begin() + 1,vec.end(),vec.back())>1){ cout<<fact[n]<<"\n"; continue;}
     if(count(vec.begin() + 1,vec.end(),vec.back()-1)==0){ cout<< 0<<" \n"; continue;}
         ll cnt = count(all(vec),vec.back()-1);
         ll ans = fact[n];
          for (int i = 1; i <=n; ++i)
          {
             if(i-1< cnt) continue;

                ll dec = ((combination((i - 1),cnt,mod1,fact,ifact) * fact[cnt])%mod1 * fact[n - cnt - 1])%mod1;
                 ans = mod_sub(ans,dec,mod1);

          }
           cout<<ans<<"\n";

  }
   return 0;
}


