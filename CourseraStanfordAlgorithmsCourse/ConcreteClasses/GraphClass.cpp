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
	vector <bool> visited;
	vector <ll> parent;

	Graph(ll _n, bool directed = false) : n(_n), isDirected(directed)
	{
		this->adjacencyList.resize(_n);
		resetVisited(_n);
		resetParent(_n);
	}

	void resetVisited(ll n)
	{
		this->visited.clear();
		this->visited.resize(n);
	}
	
	void resetParent(ll n)
	{
		this->parent.clear();
		this->parent.resize(n);
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

	~Graph()
	{

	}
};