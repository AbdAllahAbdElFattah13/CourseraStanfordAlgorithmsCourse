#include "headers.h"
#include "GraphClass.cpp"


class GraphAlgorithrms
{
public:

	//modfies only the edge list, to save time
	ll randomContractionAlgorithm(Graph g)
	{
		while (g.n > 2)
		{
			ll randEdgeIndex = rand() % g.edges.size();
			//Edge randEdge = g.edges[randEdgeIndex];
			Edge randEdge = *next(g.edges.begin(), randEdgeIndex);
			//Edge randEdge = g._edges[randEdgeIndex];

			g.defuseTwoNodeIntoOne(randEdge.start, randEdge.end);
		}


		return g.edges.size() / 2;
		//return g.edges.size();
	}

	ll	contractionAlgorithm(Graph g, ll trails)
	{
		cout << "trails: " << trails << endl;
		srand(time(NULL));

		ll minCut = LONG_MAX;
		FOR(i, 0, trails)
		{
			ll curCut = randomContractionAlgorithm(g);
			minCut = min(curCut, minCut);
			cout << "i: " << i << ", minCut: " << curCut << endl;
		}
		return minCut;
	}
};