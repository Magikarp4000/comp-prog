#include "combo.h"
#include <bits/stdc++.h>
using namespace std;
#define OPTM ios_base::sync_with_stdio(0); cin.tie(0);
#define INF int(1e9+7)
#define ln '\n'
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define FOR(i,s,n) for (int i = s; i < n; i++)
#define FORR(i,n,s) for (int i = n; i > s; i--)
#define FORX(u, arr) for (auto u : arr)
#define PB push_back
#define in(v,x) (v.find(x) != v.end())
#define F first
#define S second
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define UM unordered_map
#define US unordered_set
#define PQ priority_queue
#define ALL(v) v.begin(), v.end()
const ll LLINF = 1e18+1;
 
std::string guess_sequence(int n) {
  string s;
  int firstp = press("AB");
  if (firstp == 0) {
    if (press("X") == 1) s = "X";
    else s = "Y";
  }
  else if (firstp == 1) {
    if (press("A")) s = "A";
    else s = "B";
  }
  else s = "A";
  if (n == 1) return s;
  char start = s[0];
  FOR(i,1,n-1) {
    string cur = "", orig = s;
    if (start == 'A') {
      cur += orig;
      cur += "B";
      cur += orig;
      cur += "XB";
      cur += orig;
      cur += "XX";
      cur += orig;
      cur += "XY";
      int x = press(cur);
      if (x == i) s.PB('Y');
      else if (x == i+1) s.PB('B');
      else s.PB('X');
    }
    if (start == 'B') {
      cur += orig;
      cur += "A";
      cur += orig;
      cur += "XA";
      cur += orig;
      cur += "XX";
      cur += orig;
      cur += "XY";
      int x = press(cur);
      if (x == i) s.PB('Y');
      else if (x == i+1) s.PB('A');
      else s.PB('X');
    }
    if (start == 'X') {
      cur += orig;
      cur += "A";
      cur += orig;
      cur += "BA";
      cur += orig;
      cur += "BB";
      cur += orig;
      cur += "BY";
      int x = press(cur);
      if (x == i) s.PB('Y');
      else if (x == i+1) s.PB('A');
      else s.PB('B');
    }
    if (start == 'Y') {
      cur += orig;
      cur += "A";
      cur += orig;
      cur += "BA";
      cur += orig;
      cur += "BB";
      cur += orig;
      cur += "BX";
      int x = press(cur);
      if (x == i) s.PB('X');
      else if (x == i+1) s.PB('A');
      else s.PB('B');
    }
  }
  string res = s;
  if (start == 'A') {
    if (press(s+'B') == n) res += 'B';
    else if (press(s+'X') == n) res += 'X';
    else res += 'Y';
  }
  if (start == 'B') {
    if (press(s+'A') == n) res += 'A';
    else if (press(s+'X') == n) res += 'X';
    else res += 'Y';
  }
  if (start == 'X') {
    if (press(s+'A') == n) res += 'A';
    else if (press(s+'B') == n) res += 'B';
    else res += 'Y';
  }
  if (start == 'Y') {
    if (press(s+'A') == n) res += 'A';
    else if (press(s+'B') == n) res += 'B';
    else res += 'X';
  }
  return res;
}