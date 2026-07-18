class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26, 0);

        for (char c : tasks)
            freq[c - 'A']++;

        priority_queue<int> pq;

        for (int f : freq)
            if (f > 0)
                pq.push(f);

        int time = 0;

        while (!pq.empty()) {

            vector<int> temp;
            int cycle = n + 1;

            while (cycle-- && !pq.empty()) {

                int cnt = pq.top();
                pq.pop();

                if (cnt - 1 > 0)
                    temp.push_back(cnt - 1);

                time++;
            }

            for (int x : temp)
                pq.push(x);

            if (pq.empty())
                break;

            time += cycle + 1;
        }

        return time;
    }
};