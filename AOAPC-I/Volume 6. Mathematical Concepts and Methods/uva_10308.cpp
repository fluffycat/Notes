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
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 */
const int MAXN = 10 * 1024;
vector<pair<int, int> > links[MAXN];
int longest;
int dfs(int s, int fa){
  vector<int> length;
  for (size_t i = 0; i < links[s].size(); i++){
    int t = links[s][i].first;
    int l = links[s][i].second;
    if (t == fa) continue;
    length.push_back(dfs(t, s) + l);
  }
  sort(length.begin(), length.end());
  reverse(length.begin(), length.end());
  //cout << s << ": ";
  //for (auto i : length) cout << i << ", "; cout << endl;
  if (length.size() >= 2){
    longest = max(longest, length[0] + length[1]); 
  }else if (length.size() >= 1){
    longest = max(longest, length[0]);
  }
  return length.size() > 0? length.front() : 0;
}

int main(){
  while (!cin.eof()){
    for (int i = 0; i < MAXN; i++) links[i].clear();
    string line;
    while (getline(cin, line) && line.size()){
      istringstream iss(line);
      int u, v, l; iss >> u >> v >> l;
      links[u].push_back(make_pair(v, l));
      links[v].push_back(make_pair(u, l));
    }
    longest = 0;
    dfs(1, 0);
    cout << longest << endl;
  }
}


