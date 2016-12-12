#include "headers.h"
#include "GraphClass.cpp"


class GraphAlgorithrms
{
	//void dfs(Graph g, ll s)
	//{
	//	g.visited[s] = 1;

	//	for (auto child : g.adjacencyList[s])
	//	{
	//		if (!g.visited[child.to])
	//			dfs(g, child.to);
	//	}
	//}
	ll leavingTime = 0;
	//ll dfsForKosarajuAlgorithm(Graph &g, ll node, ll pass, map <ll, ll, std::greater<ll> > &order, ll leader = -1)
	//{
	//	ll ret = 0;
	//	g.visited[node] = true;
	//	if (pass == 2)
	//	{
	//		g.parent[node] = leader;
	//		ret = 1;
	//	}
	//	for (auto child : g.adjacencyList[node])
	//	{
	//		if (!g.visited[child.to])
	//			ret += dfsForKosarajuAlgorithm(g, child.to, pass, order, leader);
	//	}
	//	if (pass == 1) order[leavingTime++] = node;
	//	return ret;
	//}

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

	Graph* reverseGraph(Graph& g)
	{
		Graph gRev(g.n, g.isDirected);

		FOR(i, 0, g.n)
		{
			for (auto it : g.adjacencyList[i])
			{
				gRev.adjacencyList[it.to].push_back(GraphNode(i, it.cost));
			}
		}

		return &gRev;
	}

	//multiset <ll, greater<ll> > kosarajuAlgorithmToGetSCC(Graph &g, Graph &gRev)
	//{
	//	//timeLeaving -> node
	//	map <ll, ll, std::greater<ll> > graphOrder;
	//	
	//	FOR(i, 0, g.n)
	//	{
	//		graphOrder[i] = i;
	//	}

	//	//1st pass over gRev and updating the leavingTime
	//	FOR(i, 0, g.n)
	//	{
	//		if (!g.visited[i])
	//			dfsForKosarajuAlgorithm(g, i, 1, graphOrder);
	//	}
	//	cout << "done with the first pass" << endl;
	//	multiset <ll, greater<ll> > SCCs;
	//	//2nd pass over g and set the leader
	//	for (auto ptr : graphOrder)
	//	{
	//		if (!g.visited[ptr.second])
	//		{
	//			ll curSCC = dfsForKosarajuAlgorithm(g, ptr.second, 2, graphOrder, ptr.second);
	//			if (curSCC > 10) cout << "curSSC: " << curSCC << endl;
	//			SCCs.insert(curSCC);
	//			if (SCCs.size() > 5)
	//			{
	//				SCCs.erase(prev(SCCs.end()));
	//			}
	//		}
	//	}
	//	cout << "done with the second pass" << endl;

	//	return SCCs;
	//}

	multiset <ll, greater<ll> > kosarajuAlgorithmToGetSCC(Graph& g, Graph &gRev)
	{
		bool *visited = new bool[g.n + 5]();
		//memset(visited, false, sizeof(visited));
		stack<ll> order;

		cout << "\nstart first pass" << endl;
		FOR(i, 0, gRev.n)
		{
			if (!visited[i])
				gRev.fillOrder(i, visited, order);
		}

		FOR(i, 0, g.n + 5)
		{
			visited[i] = 0;
		}

		cout << "\nstart the sec pass" << endl;
		multiset<ll, greater<ll> > ret;
		while (!order.empty())
		{
			ll curSCC, top = order.top();
			order.pop();
			if (!visited[top])
			{
				curSCC = g.DFSUtill(top, visited);
				//cout << curSCC << endl;
				ret.insert(curSCC);
				//if (ret.size() > 5) ret.erase(*(ret.rbegin()));
			}
		}
		cout << "done with the second pass." << endl;

		return ret;
	}

	multiset <ll, greater<ll> > kosarajuAlgorithmToGetSCC(Graph& g)
	{
		cout << "started rev g" << endl;
		Graph gRev(g.n, g.isDirected);

		FOR(i, 0, g.n)
		{
			for (auto it : g.adjacencyList[i])
			{
				gRev.adjacencyList[it.to].push_back(GraphNode(i, it.cost));
			}
		}

		cout << "done rev g" << endl;

		return this->kosarajuAlgorithmToGetSCC(g, gRev);
	}
};