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
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 */
const int maxnode = 128 * 1024 * 2;
int a[maxnode/2];
int n;
struct MergeTree{
  struct Node{
    int o, L, R;
    Node(int _o, int _L, int _R): o(_o), L(_L), R(_R){};
    int m()  const { return (L + R) / 2; }
    int lo() const { return o * 2; }
    int ro() const { return o * 2 + 1 ; }
    int sz() const { return R - L + 1; }
    Node lch() const { return Node(lo(), L, m()); }
    Node rch() const { return Node(ro(), m() + 1, R); }
    bool isLeaf() const { return L == R; }
  };
  int qL, qR;
  vector<int> sorted[maxnode];
  MergeTree(): qL(0), qR(0){}
  bool overlap(const Node &no){
    return qL <= no.R && no.L <= qR;
  }
  bool contain(const Node &no){
    return qL <= no.L && no.R <= qR;
  }
  void reset(const Node &no){
    sorted[no.o].clear();
    if (no.isLeaf()) return;
    reset(no.lch());
    reset(no.rch());
  }
  void _init(const Node &no){
    if (no.isLeaf()){
      sorted[no.o].push_back(a[no.L]);
    }else{
      _init(no.lch()); 
      _init(no.rch());
      sorted[no.o].resize(no.sz());
      merge(sorted[no.lo()].begin(), sorted[no.lo()].end(), 
        sorted[no.ro()].begin(), sorted[no.ro()].end(),
        sorted[no.o].begin());
    }
  }
  int query(const Node &no, int v){
    if (!overlap(no)) return 0;
    if (contain(no)){
      return lower_bound(sorted[no.o].begin(), sorted[no.o].end(), v) - sorted[no.o].begin();
    }else{
      int total = 0;
      total += query(no.lch(), v);
      total += query(no.rch(), v);
      return total;
    }
  }
  MergeTree& gao(int L, int R){
    qL = L, qR = R;
    return *this;
  }
};
int Min, Max;
int m;
MergeTree tree;
int bsolve(int from, int to, int k){
  MergeTree::Node root(1, 0, n - 1);
  int lo = Min, hi = Max; //[lo,hi]
  while (lo < hi){
    int mid = (lo + hi + 1) / 2;
    int less_than_mid_cnt = tree.gao(from, to).query(root, mid);
    //printf("%d: %d\n", mid, less_than_mid_cnt);
    if (less_than_mid_cnt > k) hi = mid - 1;
    else if (less_than_mid_cnt <= k) lo = mid; 
  }
  return lo;
}
int TestNum;
int main(){
  scanf("%d", &TestNum);
  while (TestNum--){
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    MergeTree::Node root(1, 0, n - 1);
    Min = *min_element(a, a + n);
    Max = *max_element(a, a + n);  
    tree._init(root);
    while (m--){
      int i, j, k; scanf("%d %d %d", &i, &j, &k);
      printf("%d\n", bsolve(i - 1, j - 1, k - 1));
    }
    tree.reset(root);
  }
}

