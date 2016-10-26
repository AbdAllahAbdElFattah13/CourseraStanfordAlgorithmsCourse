#include "headers.h"

class CountInversions
{
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

public:
	ll count_inversions(vll &v)
	{
		return this->count_inversions_hlper(v, 0, v.size());
	}

};