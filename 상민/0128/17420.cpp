#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
/* cod : date for use + date left */
typedef pair<ll, ll> cod;


int main()
{
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<cod> gift;
	map<int, vector<ll>> giftmap;
	ll tmp;
	int cnt = 0;

	for(int idx = 0; idx < N; idx++)
	{
		cin >> tmp;
		gift.push_back({0, tmp});
	}

	for(int idx = 0; idx < N; idx++)
	{
		cin >> tmp;
		gift[idx].first = tmp;

		if(gift[idx].first > gift[idx].second)
		{
			ll factor = (gift[idx].first - gift[idx].second + 29) / 30;
			gift[idx].second += (30 * factor);
			cnt += factor;
		}
	}
		sort(gift.begin(), gift.end());

	for(int idx = 0; idx < N; idx++)
	{
		if(!giftmap.count(gift[idx].first))
			giftmap[gift[idx].first] = {gift[idx].second};
		else
			giftmap[gift[idx].first].push_back(gift[idx].second);
	}

	for(auto iter = giftmap.begin(); iter != giftmap.end(); iter++)
		sort((*iter).second.begin(), (*iter).second.end());

	auto iter = giftmap.begin();
	iter++;
	auto comp = giftmap.begin();

	while(iter != giftmap.end())
	{
		auto longest = (*comp).second.back();

		for(auto idx = 0; idx < (*iter).second.size(); idx++)
		{
			if((*iter).second[idx] < longest)
			{
				auto factor = (longest - (*iter).second[idx] + 29) / 30;
				(*iter).second[idx] += (30 * factor);
				cnt += factor;
			}
		}
		sort((*iter).second.begin(), (*iter).second.end());
		iter++;
		comp++;
	}
	cout << cnt;
}
