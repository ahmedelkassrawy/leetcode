class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        int n = position.size();
        vector<pair<int,double>> cars; //{position,time to reach}

        for(int i = 0; i < n; i++)
        {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i],time});
        }

        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double lasttime = 0.0;

        for(auto &car : cars)
        {
            if(car.second > lasttime)
            {
                fleets++;
                lasttime = car.second;
            }
        }

        return fleets;
    }
};


//we take a vector of pair storing the pos,time
//then sort them descendinlgy according to which is nearest to the target
//if the time of the car is > the last time reccorded 
//this is a new fleet and we store the time in lasttime variable
