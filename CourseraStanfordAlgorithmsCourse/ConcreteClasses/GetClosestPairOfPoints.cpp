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
};

class GetClosestPairOfPoints
{

	double get_ecliden_distance_between_2_points(point p, point q)
	{
		return sqrt((myPow(myAbs(p.x - q.x), (ll)2)) + (myPow(myAbs(p.y - q.y), (ll)2)));
	}

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
	pair <point, point> getClosestPairOfPoints(vector <point> points)
	{
		vector < point > xSorted = points, ySorted = points;

		sort(xSorted.begin(), xSorted.end(), sort_min_x_first_min_y_on_tie);
		sort(ySorted.begin(), ySorted.end(), sort_min_y_first_min_x_on_tie);

		return this->get_closest_pair_rec(xSorted, ySorted);
	}
};