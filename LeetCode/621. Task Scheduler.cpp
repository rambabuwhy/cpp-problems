/*
You are given a char array representing tasks CPU need to do. It contains capital letters A to Z where each letter represents a different task. Tasks could be done without the original order of the array. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

You need to return the least number of units of times that the CPU will take to finish all the given tasks.


Algorithm

The maximum number of tasks is 26. Let's allocate an array frequencies of 26 elements to keep the frequency of each task.

Iterate over the input array and store the frequency of task A at index 0, the frequency of task B at index 1, etc.

Sort the array and retrieve the maximum frequency f_max. This frequency defines the max possible idle time: idle_time = (f_max - 1) * n.

Pick the elements in the descending order one by one. At each step, decrease the idle time by min(f_max - 1, f) where f is a current frequency. Remember, that idle_time is greater or equal to 0.

Return busy slots + idle slots: len(tasks) + idle_time.

*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> freq(26);
        for (int t : tasks) {
            freq[t - 'A']++;
        }

        sort(freq.begin(),freq.end());

    
        int max_freq = freq[25];
        int idle_time = (max_freq - 1) * n;
        
        for (int i = freq.size() - 2; i >= 0 && idle_time > 0; --i) {
            idle_time -= min(max_freq - 1, freq[i]); 
        }
        idle_time = max(0, idle_time);

        return idle_time + tasks.size();
        
    }
};
