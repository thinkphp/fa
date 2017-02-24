#include <iostream>
#include <fstream>
#include <vector>
#define FIN "test.in"
#define FOUT "maximumPrimes.out"

using namespace std;

int maxx(int a, int b) {

    if(a > b) return a;

        else 
              return b;
};

int DivEtImpera(vector<int> vec, int li, int ls) {

    int a,
        b;

    if(li < ls) {

       int m = (li + ls)>>1;

       a = DivEtImpera(vec, li, m);

       b = DivEtImpera(vec, m + 1, ls);

       return maxx(a,b);
    }

    return vec[ li ]; 
};

int isPrime(int num) {

    int isprime = 1;

    if(num == 2) return 1;

    if(num == 1) return 0;

    for(int i = 2; i * i <= num ; i++) {

        if( num % i == 0 ) { isprime = 0; break; }
    } 
 
 return isprime;
};

int main() {

    int i,
        j,
        n, 
        m,
        elem, 
        num;
         

    vector<int> vec; 

    ifstream fin( FIN );

    ofstream fout( FOUT );

    fin>>n>>m;

for(j = 1; j <= n; ++j) {

    for(i = 0; i < m; i++) {

        fin>>elem;

        vec.push_back( elem ); 
    }

    num = DivEtImpera( vec, 0, vec.size() - 1);

    fout<<num<<endl; 

    if(isPrime( num )) cout<<num<<endl;

    vec.clear(); 
}
 return 0;
};