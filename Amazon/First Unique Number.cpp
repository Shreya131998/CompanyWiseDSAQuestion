// You have a queue of integers, and you need to support the following operations efficiently:



// Initialize the queue with a list of numbers.


// Find the first unique number in the queue (the first number that appears only once).


// Add a new number to the queue.

class FirstUnique {
public:
    queue<int>q;
    unordered_map<int,int>m;
    FirstUnique(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
            m[nums[i]]++;
        }
    }
    
    int showFirstUnique() {
        while(!q.empty() && m[q.front()]>1){
            q.pop();
        }
        return !q.empty()?q.front():-1;
    }
    
    void add(int value) {
        q.push(value);
        m[value]++;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */