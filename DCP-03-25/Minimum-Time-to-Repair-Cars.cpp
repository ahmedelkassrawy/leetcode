class Solution {
private:
    bool time(vector<int>& ranks, int cars,long long idx)
    {
        long long done = 0;

        for(int r : ranks)
        {
            done += sqrt(idx/r);
            if(done >= cars) return true;
        }

        return done >= cars;
    }    
public:
    long long repairCars(vector<int>& ranks, int cars) 
    {
        long long l = 1;
        long long r = 1e14;

        while(l < r)
        {
            long long mid = (l + r) / 2;
            if(time(ranks,cars,mid))
            {
                r = mid;
            }
            else l = mid + 1;
        }

        return l;
    }
};