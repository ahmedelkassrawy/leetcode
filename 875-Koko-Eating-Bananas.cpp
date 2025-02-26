class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        long long ans = r;
        while(l <= r)
        {
            long long mid = (l + r) / 2;
            long long hours = 0;
            
            for(int i = 0; i< piles.size(); i++)
            {
                hours += (piles[i] + mid - 1) / mid; 
                //34an 3ayzeen ceil el rakm lhowa 
                //piles[i] / mid 34an n3rf hyakol kam wahda flsa3a
                //fmsln 7 / 3 who hykol mnha 3 mrat mra 3 wmra 3 wmra 1 enma
                //howa howa el4art da
                //hours += (piles[i] / mid) + (piles[i] % mid != 0 ? 1 : 0);

            }
            if(hours <= h)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return ans;
    }
};