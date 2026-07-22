class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        // Adjacency list to store graph
        vector<vector<int>> graph(numCourses);
        
        // indegree[i] = number of prerequisites needed for course i
        vector<int> indegree(numCourses, 0);
        
        // Build the graph
        for (auto &p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            
            // prereq -> course
            graph[prereq].push_back(course);
            
            // Increase indegree because course depends on prereq
            indegree[course]++;
        }
        
        queue<int> q;
        
        // Push all courses having 0 prerequisites
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> order;
        
        // Kahn's Algorithm (Topological Sorting)
        while (!q.empty()) {
            
            int current = q.front();
            q.pop();
            
            // Add current course to answer
            order.push_back(current);
            
            // Visit all dependent courses
            for (int nextCourse : graph[current]) {
                
                // One prerequisite is completed
                indegree[nextCourse]--;
                
                // If no prerequisites left, push into queue
                if (indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }
        
        // If all courses are completed, return order
        if (order.size() == numCourses) {
            return order;
        }
        
        return {};
    }
};