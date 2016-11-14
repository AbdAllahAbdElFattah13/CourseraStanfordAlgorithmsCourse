#include "LectureImplementation.cpp"

void solve(ll n, vpll input)
{
	cout << "solving with n = " << n << endl;
	Graph g(n, true), gRrv(n, true);
	for_auto(p, input)
	{
		g.addEdge(p.first, p.second);
		gRrv.addEdge(p.second, p.first);
	}
	GraphAlgorithrms ga;
	multiset <ll, greater<ll> > allSCCLen = ga.kosarajuAlgorithmToGetSCC(g, gRrv);

	cout << "#SCC: " << allSCCLen.size() << endl;
	string out = "";
	for_auto(i, allSCCLen)
	{
		out += to_string(i) + ',';
	}
	out.pop_back();

	cout << out << endl << endl;

}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("in2.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	read_fast;

	ll v, u, n = -OO, before;
	vpll input;

	while (cin >> u >> v)
	{
		lecture_implementations li;
		if (u == v && u == -1)
		{
			cout << "done with reading the input, calling the function" << endl;
			before = (int)(clock() * 1000. / CLOCKS_PER_SEC);
			solve(n, input);
			input.clear();
			n = -OO;
			continue;
		}
		if (u == v) continue;
		n = max(n, max(u, v));
		--u; --v;
		input.push_back(make_pair(u, v));
	}

#ifndef ONLINE_JUDGE
		cout << "Time: " << (int)(clock() * 1000. / CLOCKS_PER_SEC) - before << " ms\n\n";
#endif
	return 0;
}
