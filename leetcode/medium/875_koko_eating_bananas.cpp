    #include <vector>
    #include <algorithm>
    using namespace std;
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size();
        int z;
        int ht;

        sort(piles.begin(), piles.end(), greater<>());

        int maxx = piles[0];
        int l = 1;
        int r = maxx;
        int mid;
        int currMin = r;

        while (l <= r)
        {

            mid = (r + l) / 2;
            ht = h;
            z = n - 1;

            while (ht > 0 && z >= 0)
            {
                ht = ht - ceil((double)piles[z] / mid);
                z--;
            }
            if (z >= 0 || ht < 0)
            {
                l = mid + 1;
            }
            else
            {
                currMin = min(mid, currMin);
                r = mid - 1;
            }
        }
        return currMin;
    }