class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> data; // Maps key -> [(timestamp, value), ...]

public:
    // Constructor to initialize the TimeMap
    TimeMap() {}

    // Stores the value with the given key and timestamp
    void set(string key, string value, int timestamp) {
        data[key].push_back({timestamp, value});
    }

    // Retrieves the value for the key at or before the given timestamp
    string get(string key, int timestamp) {
        if (data.find(key) == data.end()) {
            return ""; // Key does not exist
        }

        const vector<pair<int, string>>& records = data[key];
        int left = 0, right = records.size() - 1;
        string result = "";

        // Binary search for the closest timestamp <= given timestamp
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (records[mid].first <= timestamp) {
                result = records[mid].second; // Update result to current value
                left = mid + 1; // Search in the right half
            } else {
                right = mid - 1; // Search in the left half
            }
        }

        return result;
    }
};

/**
 * Usage:
 * TimeMap* obj = new TimeMap();
 * obj->set(key, value, timestamp);
 * string param_2 = obj->get(key, timestamp);
 */

/*
Explanation:
1. **Set Function:**
   - Maps the `key` to a list of pairs `(timestamp, value)`.
   - Appends the new `(timestamp, value)` to the list for the key.

2. **Get Function:**
   - Performs a binary search on the list of `(timestamp, value)` pairs for the given `key`.
   - Finds the value with the largest timestamp <= the given timestamp.
   - Returns an empty string if no valid value is found.

**Key Points:**
- Binary search ensures efficient retrieval in O(log n) time for each `get`.
- Space complexity is O(n), where `n` is the total number of `set` operations.

**Time Complexity:**
- `set`: O(1) for insertion.
- `get`: O(log k), where `k` is the number of entries for the given key.

**Space Complexity:**
- O(n), where `n` is the total number of `(key, timestamp, value)` entries.
*/
