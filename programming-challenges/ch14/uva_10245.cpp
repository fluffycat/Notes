//Clibrary:
#include<cassert>
#include<cctype>
#include<cerrno>
//#include<cfenv>
#include<cfloat>
//#include<cinttypes>
#include<ciso646>
#include<climits>
#include<clocale>
#include<cmath>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
//#include<cstdbool>
#include<cstddef>
//#include<cstdint>
#include<cstdio>
#include<cstdlib>
#include<cstring>
//#include<ctgmath>
#include<ctime>
//#include<cuchar>
#include<cwchar>
#include<cwctype>
//Containers:
//#include<array>
#include<bitset>
#include<deque>
//#include<forward_list>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
//#include<unordered_map>
//#include<unordered_set>
#include<vector>
//Input/Output:
#include<fstream>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<ostream>
#include<sstream>
#include<streambuf>
//Other:
#include<algorithm>
//#include<chrono>
//#include<codecvt>
#include<complex>
#include<exception>
#include<functional>
//#include<initializer_list>
#include<iterator>
#include<limits>
#include<locale>
#include<memory>
#include<new>
#include<numeric>
//#include<random>
//#include<ratio>
//#include<regex>
#include<stdexcept>
#include<string>
//#include<system_error>
//#include<tuple>
//#include<typeindex>
#include<typeinfo>
//#include<type_traits>
#include<utility>
#include<valarray>
using namespace std;

typedef long long i64;
typedef unsigned long long u64;
const double PI = acos(-1);
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */
//typedef complex<double> P;
struct P{
  double x, y;
};
double dist2(P &a, P &b){
  return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}
double solve(vector<P> ps){
  int N = ps.size();
  double ans = 1e10;
  for (int i = 0; i < N; i++){
    for (int j = i + 1; j < N; j++){
      ans = min(ans, dist2(ps[i], ps[j]));
    }
  }
  return sqrt(ans);
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  int N;
  while (cin >> N && N){
    vector<P> points(N);
    for (int i = 0; i < N; i++){
      cin >> points[i].x >> points[i].y;
    }
    double ans = solve(points);
    if (ans < 10000) printf("%.04lf\n", ans);
    else printf("INFINITY\n");
  }
}

