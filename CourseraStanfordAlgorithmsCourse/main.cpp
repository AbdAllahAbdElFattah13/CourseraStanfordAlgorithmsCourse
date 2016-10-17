//#include "LectureImplementation.cpp"
//
//
////int main()
////{
////	vll numbers;
////	for (ll i = 13; i > 0; i -= 2) numbers.push_back(i);
////	for (ll i = 12; i > 1; i -= 2) numbers.push_back(i);
////
////	display_vector(numbers);
////
////	lecture_implementations li;
////	li.merge_sort(numbers);
////
////	display_vector(numbers);
////
////	return 0;
////}
//
//pair <point, point> bruteForce(vector <point> v)
//{
//	lecture_implementations li;
//	pair <point, point> ret;
//	double minDistance = OO;
//
//	FOR(i, 0, v.size())
//	{
//		FOR(j, i + 1, v.size())
//		{
//			point p(v[i]), q(v[j]);
//			double distance = li.get_ecliden_distance_between_2_points(p, q);
//			if (distance < minDistance)
//			{
//				minDistance = distance;
//				ret = make_pair(p, q);
//			}
//		}
//	}
//	return ret;
//}
//
//void test()
//{
//	lecture_implementations li;
//	ll nTestCases = 10, maxSize = 50, maxCoord = 100;
//	FOR(t, 0, nTestCases)
//	{
//		ll n = (rand() % maxSize) + 1;
//
//		vector <point> v(n);
//		FOR(i, 0, n)
//		{
//			v[i].index = i;
//			v[i].x = (rand() % maxCoord) + 1;
//			v[i].y = (rand() % maxCoord) + 1;
//		}
//
//		pair <point, point> bruteForceOut = bruteForce(v), mergeOut = li.getClosestPairOfPoints(v);
//
//		cout << "===================" << endl;
//		cout << "n: " << n << endl;
//		cout << "bruteForceOut" << endl;
//		cout << bruteForceOut.first.index << " " << bruteForceOut.second.index << endl;
//		cout << "mergeOut" << endl;
//		cout << min(mergeOut.first.index, mergeOut.second.index) << " " << max(mergeOut.first.index, mergeOut.second.index) << endl << endl;
//
//		if (bruteForceOut.first.index != min(mergeOut.first.index, mergeOut.second.index)
//			|| bruteForceOut.second.index != max(mergeOut.first.index, mergeOut.second.index))
//		{
//			cout << ":(" << endl;
//			FOR(i, 0, v.size())  cout << v[i].x << " " << v[i].y << endl;
//		}
//	}
//	cout << "!" << endl;
//}
//
//
//int main()
//{
//	lecture_implementations li;
//
//#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
//	//freopen("out.txt", "w", stdout);
//#endif
//	read_fast;
//	//srand(clock());
//	//test();
//	ll n;
//	while (cin >> n)
//	{
//		vll numbers(n);
//		read_vector(numbers);
//
//		vll firstWayVector(numbers), secondWayVector(numbers), thierdWayVector(numbers);
//
//		ll firstCount = li.quickSort(firstWayVector, 0, n, 1),
//			secondCount = li.quickSort(secondWayVector, 0, n, 2),
//			thierdCount = li.quickSort(thierdWayVector, 0, n, 3);
//
//		cout << "size: " << n << endl;
//		cout << firstCount << " " << secondCount << " " << thierdCount << endl;
//		cout << (!is_sorted(firstWayVector.begin(), firstWayVector.end()) ? "1st notSorted " : "")
//			<< (!is_sorted(secondWayVector.begin(), secondWayVector.end()) ? "2nd notSorted " : "")
//			<< (!is_sorted(thierdWayVector.begin(), thierdWayVector.end()) ? "3rd notSorted " : "") << endl;
//
//#ifndef ONLINE_JUDGE
//		cout << "Time: " << (int)(clock() * 1000. / CLOCKS_PER_SEC) << " ms\n\n";
//#endif
//	}
//	return 0;
//}
