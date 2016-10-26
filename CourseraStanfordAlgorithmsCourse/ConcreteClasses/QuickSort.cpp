#include "headers.h"

class QuickSort
{
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

public:
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
};