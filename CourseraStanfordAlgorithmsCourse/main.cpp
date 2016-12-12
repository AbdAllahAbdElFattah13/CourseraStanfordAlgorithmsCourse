#include "LectureImplementation.cpp"

//10k, 100k, 400k, OO				10k -> passed
ll cases[4] = { 10000, 100000, 400000, OO };
ll caseIndes = 2;
vpll read_input(ll &n)
{
	vpll ret;
	ll u, v;
	while (cin >> u >> v)
	{
		if (u >= cases[caseIndes] || v >= cases[caseIndes]) continue;
		if (u == v && u == -1) return ret;
		ret.push_back(make_pair(u, v));
		n = max(n, max(u, v));
	}
}

void solve(ll n, vpll input, ll limit)
{
	//cout << "starting graph construaction" << endl;
	Graph g(min(n, limit), true);
	Graph gRev(min(n, limit), true);
	for_auto(i, input)
	{
		//if (!(i.first > limit || i.second > limit))
			g.addEdge(i.first - 1, i.second - 1);
			gRev.addEdge(i.second - 1, i.first - 1);
	}
	//cout << "done graph, stating the SCC" << endl;

	GraphAlgorithrms ga;
	auto output = ga.kosarajuAlgorithmToGetSCC(g, gRev);

	string out = "";
	ll done = 0;
	for_auto(i, output)
	{
		if (done > 6) break;
		++done;
		cout << i << endl;
		out += (to_string(i) + ",");
	}
	cout << out << endl;
}


int main()
{

#ifndef ONLINE_JUDGE
	freopen("in2.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	read_fast;

	while (true)
	{
		ll n = -1;
		cout << "starting reading the input" << endl;
		vpll input = read_input(n);
		cout << "done reading the input" << endl;
		if (n == -1) break;
		ll before = (int)(clock() * 1000. / CLOCKS_PER_SEC);
		solve(n, input, cases[caseIndes]);

#ifndef ONLINE_JUDGE
		cout << "Time: " << (int)(clock() * 1000. / CLOCKS_PER_SEC) - before << " ms\n\n";
		before = (int)(clock() * 1000. / CLOCKS_PER_SEC);
#endif
	}


	return 0;
}
