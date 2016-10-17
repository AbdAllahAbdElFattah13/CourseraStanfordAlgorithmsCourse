
#ifndef ONLINE_JUDGE
#define _CRT_SECURE_NO_DEPRECATE
#endif

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <math.h>
#include <limits.h>
#include <stack> 
#include <iomanip>
#include <string.h>
#include <cstring>
using namespace std;

#define ll long long
#define pll pair <ll, ll>
#define vll vector <ll>
#define vpll vector < pll >
#define OO INT_MAX;

#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define FOR(name, s, e) for(ll name = s; name < (ll)e; ++name)
#define read_vector(numbers) for (auto& i : numbers) cin >> i
#define display_vector(numbers) FOR(i, 0, numbers.size()) if (i == numbers.size() -1) cout << numbers[i] << endl; else cout << numbers[i] << " ";
#define for_auto(i, a) for(auto& i : a)
#define all(a) a.begin(), a.end()

template<class T> istream& operator >>(istream& in, vector<T>& Col){ for (auto &el : Col) in >> el; return in; }

template <class T> T inline myAbs(T n)  { return (n < 0) ? -n : n; }
template <class T> T inline myPow(T base, T power) { T toRet = 1; while (power--) { toRet *= base; }; return toRet; }
