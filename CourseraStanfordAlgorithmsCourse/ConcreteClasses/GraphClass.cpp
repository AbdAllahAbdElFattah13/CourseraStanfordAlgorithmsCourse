#pragma once
#include "headers.h"

class Edge
{
public:
	ll start, end, cost;

	Edge()
	{
		start = end = cost = -1;
	}

	Edge(ll s, ll e)
	{
		this->start = s; this->end = e; cost = -1;
	}

	Edge(ll s, ll e, ll c)
	{
		this->start = s; this->end = e; this->cost = c;
	}
};

class GraphNode
{
public:
	ll to, cost;
	GraphNode(ll t, ll c) : to(t), cost(c){}

	GraphNode() : GraphNode(-1, -1) {};

};

class Graph
{
public:
	ll n, m;
	bool isDirected;
	list <Edge> edges;
	vector < vector <GraphNode> > adjacencyList;
	//vector <ll> parent;

	Graph(ll _n, bool directed = false) : n(_n), isDirected(directed)
	{
		//cout << "called" << endl;
		this->adjacencyList.resize(_n);
		//resetParent(_n);
	}

	void addEdge(ll start, ll end, ll cost = -1)
	{
		//adding to adj list
		adjacencyList[start].push_back(GraphNode(end, cost));
		if (!isDirected)
			adjacencyList[end].push_back(GraphNode(start, cost));

		//adding to edges list
		edges.push_back(Edge(start, end, cost));
		//_edges.push_back(Edge(start, end, cost));
		if (!isDirected)
			edges.push_back(Edge(end, start, cost));
	}

	vector <GraphNode> getNeighbours(ll v)
	{
		return adjacencyList[v];
	}

	void defuseTwoNodeIntoOne(ll u, ll v)
	{
		for (auto cur = this->edges.begin(); cur != this->edges.end();)
		{
			if (cur->start == v) cur->start = u;
			if (cur->end == v)  cur->end = u;

			if (cur->start == cur->end) this->edges.erase(cur++);
			else ++cur;
		}

		//this->edges.erase(
		//	remove_if(this->edges.begin(), this->edges.end(),
		//	[&](Edge cur) -> bool
		//{
		//	if (cur.start == v) cur.start = u;
		//	if (cur.end == v)  cur.end = u;

		//	if (cur.start == cur.end) return true;
		//	else return false;
		//}));

		-- this->n;
		return;
	}

	ll DFSUtill(ll root, bool *vistied)
	{
		ll SCCCount = 0;
		stack <ll> st;
		st.push(root);
		while (!st.empty())
		{
			ll cur = st.top();
			st.pop();

			if (!vistied[cur])
			{
				vistied[cur] = true;
				++SCCCount;
			}

			for (ll i = ((ll)this->adjacencyList[cur].size()) - 1; i > -1; --i)
			{
				ll child = this->adjacencyList[cur][i].to;
				if (!vistied[child])
					st.push(child);
			}
		}
		return SCCCount;
	}
	
	void fillOrder(ll root, bool *visited, stack<ll> &order)
	{
		stack <ll> st;
		st.push(root);
		bool *finishingTimeVisited = new bool[this->n + 5]();

		while (!st.empty())
		{
			ll cur = st.top();
			st.pop();

			if (!visited[cur])
			{
				visited[cur] = true;
				st.push(cur);
				for (ll i = ((ll)this->adjacencyList[cur].size()) - 1; i > -1; --i)
				{
					ll child = this->adjacencyList[cur][i].to;
					if (!visited[child])
						st.push(child);
				}
			}
			else
			{
				//st.pop();
				//order.push(cur);
				if (!finishingTimeVisited[cur])
				{
					finishingTimeVisited[cur] = 1;
					order.push(cur);
				}
			}
		}
		delete finishingTimeVisited;
	}
	
	vll shortestPathUsingDijkstra(ll s)
	{
		bool *visited = new bool[this->n + 5]();
		vll dist(n, OO);

		//weight, v "remember it's a max heap"
		priority_queue < pll, vpll, greater <pll> > pq; 

		pq.push(make_pair(0, s));
		dist[s] = 0;

		while (!pq.empty())
		{
			pll curNode = pq.top();
			pq.pop();

			ll curV = curNode.second,
				minDistanceSoFar = curNode.first;

			visited[curV] = 1;
			//dist[curV] = curDistance;

			for (auto child : this->adjacencyList[curV])
			{
				if (!visited[child.to])
				{
					if (minDistanceSoFar + child.cost < dist[child.to])
					{
						dist[child.to] = dist[curV] + child.cost;
						pq.push(make_pair(dist[child.to], child.to));
					}
				}
			}
		}
		return dist;
	}

	~Graph()
	{

	}
};