#include <queue>
using namespace std;
class RecentCounter {
public:
    RecentCounter() {
        q = new queue<int>();
    }

    int ping(int t) {
        q->emplace(t);
        while (!q->empty() && q->front() < t - 3000) {
            q->pop();
        }
        return q->size();
    }

    ~RecentCounter() {
        delete q;
    }

private:
    queue<int>* q;
};
