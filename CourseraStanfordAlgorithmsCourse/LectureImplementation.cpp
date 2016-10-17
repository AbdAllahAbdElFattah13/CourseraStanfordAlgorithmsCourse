#include "headers.h"

class point
{
public:
	ll x;
	ll y;
	int index;

	point()
	{
		x = y = 0;
		index = -1;
	}

	point(ll x, ll y)
	{
		this->x = x;
		this->y = y;
	}

	//point(point &p)
	//{
	//	this->x = p.x;
	//	this->y = p.y;
	//}
};

class lecture_implementations
{
	static bool  sort_min_x_first_min_y_on_tie(point p, point q)
	{
		if (p.x != q.x) return p.x < q.x;
		return p.y < q.y;
	}

	static bool  sort_min_y_first_min_x_on_tie(point p, point q)
	{
		if (p.y != q.y) return p.y < q.y;
		return p.x < p.x;
	}

	pair <point, point>* get_closest_intersection_pair(vector <point> xSorted, vector <point> ySorted, double delta)
	{
		ll xSortedSize = xSorted.size(), ySortedSize = ySorted.size();
		vector <point>  yPointsOfInterset;
		ll xMid = xSorted[(xSortedSize / 2) - 1].x; //is this line Correct?

		//getting Points of intersts, such that they are eaither -delta, or +delta away from xMid
		FOR(i, 0, ySortedSize)
		{
			if (xMid - delta <= ySorted[i].x && ySorted[i].x <= xMid + delta)// x in [xMid - deltea, xMid + delta]
				yPointsOfInterset.push_back(ySorted[i]);
		}

		pair <point, point> *ret = NULL;
		double minDistance = delta;
		ll sz = yPointsOfInterset.size();

		FOR(i, 0, sz)
		{
			FOR(j, i + 1, sz)
			{
				double curDistance = get_ecliden_distance_between_2_points(yPointsOfInterset[i], yPointsOfInterset[j]);
				if (curDistance < minDistance)
				{
					minDistance = curDistance;
					ret = new pair<point, point>(yPointsOfInterset[i], yPointsOfInterset[j]);
				}
			}
		}

		return ret;
	}

	pair <point, point> get_closest_pair_rec(vector <point> xSorted, vector <point> ySorted)
	{
		ll xSortedSize = xSorted.size(), ySortedSize = ySorted.size();

		//base case
		if (xSortedSize <= 5 || ySortedSize <= 5)
		{
			pair <point, point> ret;
			double minDistance = OO;

			FOR(i, 0, xSortedSize)
			{
				FOR(j, 0, xSortedSize)
				{
					point p(xSorted[i]), q(xSorted[j]);
					if (p.index == q.index) continue;
					double distance = get_ecliden_distance_between_2_points(p, q);
					if (distance < minDistance)
					{
						minDistance = distance;
						ret = make_pair(p, q);
					}
				}
			}
			return ret;
		}

		ll midX = xSortedSize / 2;
		vector <point> Q(xSorted.begin(), xSorted.begin() + midX),
			R(xSorted.begin() + midX, xSorted.end()),
			Qx = Q, Qy, Rx = R, Ry;

		ll biggestXInQ = Q[Q.size() - 1].x; //to determain which will go into Qy, and which goes to Ry
		FOR(i, 0, ySortedSize)
		{
			//if the cur sorted point comes before the last point in Q, then it will go into Qy
			if (ySorted[i].x <= biggestXInQ) Qy.push_back(ySorted[i]);
			//if not, then it comes after the last point in Q, then it's in the Ry vector
			else Ry.push_back(ySorted[i]);
		}

		pair <point, point> xClosestPair = this->get_closest_pair_rec(Qx, Qy),
			yClosestPair = this->get_closest_pair_rec(Rx, Ry);

		double xClosestPairDistance = get_ecliden_distance_between_2_points(xClosestPair.first, xClosestPair.second),
			yClosestPairDistance = get_ecliden_distance_between_2_points(yClosestPair.first, yClosestPair.second);

		double minSoFar = min(xClosestPairDistance, yClosestPairDistance); //aka delta 

		pair <point, point>* intersectionClosestPair = this->get_closest_intersection_pair(xSorted, ySorted, minSoFar);
		double intersectionPairDistance = intersectionClosestPair ? get_ecliden_distance_between_2_points(intersectionClosestPair->first, intersectionClosestPair->second) : OO;

		if (intersectionPairDistance < minSoFar) return *intersectionClosestPair;
		if (xClosestPairDistance < yClosestPairDistance) return xClosestPair;
		return yClosestPair;
	}
public:

	double get_ecliden_distance_between_2_points(point p, point q)
	{
		return sqrt((myPow(myAbs(p.x - q.x), (ll)2)) + (myPow(myAbs(p.y - q.y), (ll)2)));
	}

	void merge_sort(vll &v)
	{
		this->merge_sort_helper(v, 0, v.size());
	}

	ll count_inversions(vll v)
	{
		return this->count_inversions_hlper(v, 0, v.size());
	}

	pair <point, point> getClosestPairOfPoints(vector <point> points)
	{
		vector < point > xSorted = points, ySorted = points;

		sort(xSorted.begin(), xSorted.end(), sort_min_x_first_min_y_on_tie);
		sort(ySorted.begin(), ySorted.end(), sort_min_y_first_min_x_on_tie);

		return this->get_closest_pair_rec(xSorted, ySorted);
	}

	ll quickSort(vll &numbers, ll start, ll end, ll way)
	{
		if (end <= start) return 0;
		ll pivotIndex = getPivotIndex(numbers, start, end, way);
		ll limit = partitionByPivot(numbers, start, end, pivotIndex);
		ll steps = (end - start) - 1;

		ll firstPart = quickSort(numbers, start, limit, way);
		ll secondPart = quickSort(numbers, limit + 1, end, way);
		return steps + firstPart + secondPart;
	}

private:
	void merge_sort_helper(vll &v, ll start_index, ll end_index)
	{
		//base case
		if (end_index - start_index <= 1)
			return;

		//call the right half
		this->merge_sort_helper(v, start_index, ((end_index + start_index) / 2));

		//call the left half
		this->merge_sort_helper(v, ((end_index + start_index) / 2), end_index);

		//merge
		this->merge(v, start_index, ((end_index + start_index) / 2), ((end_index + start_index) / 2), end_index);
	}

	void merge(vll &v, ll i, ll i_end, ll j, ll j_end)
	{
		vll toReturn;
		ll size = j_end - i;	//aka total size
		toReturn.resize(size);

		for (ll k = 0; k < size; ++k)
		{
			if (i == i_end) toReturn[k] = v[j++];
			else if (j == j_end)	toReturn[k] = v[i++];
			else if (v[i] <= v[j]) toReturn[k] = v[i++];
			else toReturn[k] = v[j++];
		}
		i = j_end - size;

		for (ll k = 0; k < size; ++k)
			v[i + k] = toReturn[k];
	}

	ll count_inversions_hlper(vll &v, ll start_index, ll end_index)
	{
		//base case
		if (end_index - start_index <= 1)
			return 0;

		//call the right half
		ll left = this->count_inversions_hlper(v, start_index, ((end_index + start_index) / 2));

		//call the left half
		ll right = this->count_inversions_hlper(v, ((end_index + start_index) / 2), end_index);

		//merge
		ll cross = this->merge_count(v, start_index, ((end_index + start_index) / 2), ((end_index + start_index) / 2), end_index);
		return left + right + cross;
	}

	ll merge_count(vll &v, ll i, ll i_end, ll j, ll j_end)
	{
		vll toReturn;
		ll size = j_end - i, cross_inversions = 0;	//aka total size
		toReturn.resize(size);

		for (ll k = 0; k < size; ++k)
		{
			if (i == i_end) toReturn[k] = v[j++];
			else if (j == j_end)	toReturn[k] = v[i++];
			else if (v[i] <= v[j]) toReturn[k] = v[i++];
			else
			{
				toReturn[k] = v[j++];
				cross_inversions += (i_end - i);
			}
		}
		i = j_end - size;

		for (ll k = 0; k < size; ++k)
			v[i + k] = toReturn[k];

		return cross_inversions;
	}

	ll getPivotIndex(vll numbers, ll start, ll end, ll way)
	{
		switch (way)
		{
		case 1: return start;
		case 2: return end - 1;
		default:
			ll len = (end - start);
			ll mid = (len / 2) + start;
			mid = (len & 1) ? mid : mid - 1;

			pll a[3];
			a[0].first = numbers[start];
			a[0].second = start;

			a[1].first = numbers[mid];
			a[1].second = mid;

			a[2].first = numbers[end - 1];
			a[2].second = end - 1;

			sort(a, a + 3);
			return a[1].second;
		}
	}

	ll partitionByPivot(vll &numbers, ll start, ll end, ll pivotIndex)
	{
		ll i = start + 1, p = numbers[pivotIndex];
		swap(numbers[pivotIndex], numbers[start]);
		FOR(j, start + 1, end)
		{
			if (numbers[j] < p)
			{
				swap(numbers[i], numbers[j]);
				++i;
			}
		}
		swap(numbers[start], numbers[i - 1]);
		return i - 1;
	}
};
