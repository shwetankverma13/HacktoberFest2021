
#include <iostream>

using namespace std;


int main() {
   int n,q,i;
   cin >> n >> q;
   int arr[1000][1000];
   for ( i=0; i<n; i++ ){
       int rr;
       cin >> rr;
       for (int ii=0;ii<rr;ii++){
           cin >> arr[i][ii];
       }
   }
   int oarr[q];
   for (i; i<n+q;i++){
       int a,b;
       cin >> a >> b;
       oarr[i-n] = arr[a][b];
   }
   for (i=0;i<q;i++){
       cout << oarr[i];
   }
    return 0;
}
