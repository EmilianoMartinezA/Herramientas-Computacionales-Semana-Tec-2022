#include <bits/stdc++.h>

using namespace std;

const int N = 4;
 const int INF = 1000000;
int monedas [N] = {1, 2, 3, 5};
int memo [100001];
int cambio (int valor) {
     if (valor < 0) return INF;
     if (valor == 0) return 0;
     if (memo[valor] ! = -1) return memo[valor];
     int res s = INF;
     for (int = 0 ; i< N ; i++) {
        res = min(res, cambio(valor - monedas[i]));
     }
     return memo [valor] = res + 1;
}
int main ( ){
memset(memo, -1, sizeof memo);

 int valor = 7;
 for (int i=0; i <= valor ; i++){
     cout << i << " "<<cambio(i) << endl;
    }
 return 0;
}
