#include "ConcreteClasses\CountInversions.cpp"
#include "ConcreteClasses\GetClosestPairOfPoints.cpp"
#include "ConcreteClasses\QuickSort.cpp"
#include "ConcreteClasses\GraphClass.cpp"
#include "ConcreteClasses\GraphAlgorithms.cpp"


class lecture_implementations
{
	CountInversions *countInversionsObj;
	GetClosestPairOfPoints *getClosestPairOfPointsObj;
	QuickSort *quickSortObj;
	GraphAlgorithrms *graohAlgoObj;
public:
	lecture_implementations()
	{
		this->countInversionsObj = new CountInversions();
		this->getClosestPairOfPointsObj = new GetClosestPairOfPoints();
		this->quickSortObj = new QuickSort();
		this->graohAlgoObj = new GraphAlgorithrms();
	}
	~lecture_implementations()
	{
		delete this->countInversionsObj;
		delete this->getClosestPairOfPointsObj;
		delete this->quickSortObj;
		delete this->graohAlgoObj;
	}


	void merge_sort(vll &v)
	{
		ll unNeededAnswer = countInversionsObj->count_inversions(v);
	}

	ll count_inversions(vll v)
	{
		return countInversionsObj->count_inversions(v);
	}

	pair <point, point> getClosestPairOfPoints(vector <point> points)
	{
		return getClosestPairOfPointsObj->getClosestPairOfPoints(points);
	}

	ll quickSort(vll &numbers, ll start, ll end, ll way)
	{
		return quickSortObj->quickSort(numbers, start, end, way);
	}

	ll minCut(Graph g)
	{
		return this->graohAlgoObj->contractionAlgorithm(g, (ll)(g.n * g.n * log(g.n)));
	}
};