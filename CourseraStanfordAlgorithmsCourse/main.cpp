#include "LectureImplementation.cpp"

int main()
{

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	read_fast;

	lecture_implementations li;
	ll n, _case = 0;
	while (cin >> n)
	{
		Graph g(n, true);
		FOR(i, 0, n)
		{
			ll v, u;
			cin >> v;
			while (cin >> u)
			{
				if (u == -1) break;
				g.addEdge(v - 1, u - 1);
			}
		}

		ll minCut = li.minCut(g);

		cout << "minCut: " << minCut << ", at case: " << ++_case << endl;
#ifndef ONLINE_JUDGE
		cout << "Time: " << (int)(clock() * 1000. / CLOCKS_PER_SEC) << " ms\n\n";
#endif
	}
	return 0;
}
