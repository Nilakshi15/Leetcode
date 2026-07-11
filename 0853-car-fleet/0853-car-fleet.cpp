class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n = position.size();

        vector<pair<int, double>> cars;

        // Store {position, time to reach target}
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // Sort by position (closest to target first)
        sort(cars.begin(), cars.end(), greater<pair<int, double>>());

        int fleets = 0;
        double fleetTime = 0;

        for (auto car : cars) {

            // Cannot catch the fleet ahead
            if (car.second > fleetTime) {
                fleets++;
                fleetTime = car.second;
            }
        }

        return fleets;
    }
};