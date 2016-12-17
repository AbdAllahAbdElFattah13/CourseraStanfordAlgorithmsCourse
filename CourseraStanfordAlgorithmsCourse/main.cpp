#include "LectureImplementation.cpp"

int main()
{

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	read_fast;


	ll numberOfNodes;

	while (cin >> numberOfNodes)
	{
		Graph *g = new Graph(numberOfNodes, true);
		FOR(nodeID, 0, numberOfNodes)
		{
			ll unneeded, numberOfEdges, to, cost;
			cin >> unneeded >> numberOfEdges;
			FOR(edge, 0, numberOfEdges)
			{
				cin >> to >> cost;
				--to;
				g->addEdge(nodeID, to, cost);
			}
		}
		vll dist = g->shortestPathUsingDijkstra(0);
		vll wantedAnswers = { 7, 37, 59, 82, 99, 115, 133, 165, 188, 197 };
		// vll wantedAnswers = { 1, 2, 3, 4, 5, 6, 7, 8};

		string answer = "";
		for_auto(wantedAnswer, wantedAnswers)
		{
			if (dist[wantedAnswer - 1] == OO)
				dist[wantedAnswer - 1] = 1000000;
			cout << dist[wantedAnswer - 1] << endl;
			answer += (to_string(dist[wantedAnswer - 1]) + ',');
		}
		answer.pop_back();
		cout << answer << endl;
		delete g;
	}
#ifndef ONLINE_JUDGE
	cout << "Time: " << (int)(clock() * 1000. / CLOCKS_PER_SEC)  << " ms\n\n";
#endif



	return 0;
}
