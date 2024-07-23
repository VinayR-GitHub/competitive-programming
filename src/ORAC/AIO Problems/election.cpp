#include <bits/stdc++.h>

#define MIN std::min
#define MAX std::max
#define MAG std::abs
#define PAIR std::make_pair
#define FILE(id) \
	std::ios::sync_with_stdio(NULL); \
    std::cin.tie(NULL); \
    freopen(#id "in.txt", "r", stdin); \
    freopen(#id "out.txt", "w", stdout)

struct rect {
    int xmin;
    int xmax;
    int ymin;
    int ymax;

    rect(int xmin, int xmax, int ymin, int ymax):
        xmin(xmin), xmax(xmax), ymin(ymin), ymax(ymax) {}

    int area(void) {
        return (xmax - xmin) * (ymax - ymin);
    }
};

struct directional_bool {
    bool up;
    bool down;
    bool left;
    bool right;

    directional_bool(bool up, bool down, bool left, bool right):
        up(up), down(down), left(left), right(right) {}
};

bool intersect(rect a, rect b) {
    if (MAX(a.xmin, b.xmin) >= MIN(a.xmax, b.xmax)) {
        return false;
    }
    if (MAX(a.ymin, b.ymin) >= MIN(a.ymax, b.ymax)) {
        return false;
    }
    return true;
}

directional_bool cuts(rect primary, rect blocker) {
    if (!intersect(primary, blocker)) {
        return directional_bool(false, false, false, false);
    }
    bool up = blocker.ymax < primary.ymax;
    bool down = blocker.ymin > primary.ymin;
    bool left = blocker.xmin > primary.xmin;
    bool right = blocker.xmax < primary.xmax;
    return directional_bool(up, down, left, right);
}

bool comp(rect f, rect s) {
    return PAIR(PAIR(f.xmin, f.xmax), PAIR(f.ymin, f.ymax)) < PAIR(PAIR(s.xmin, s.xmax), PAIR(s.ymin, s.ymax));
}

int main() {
    FILE(elec);
    int w, h, n;
    std::cin >> w >> h >> n;
    std::deque<rect> rectangles;
    std::set<rect, decltype(comp)*> seen(comp);
    rectangles.push_back(rect(0, w, 0, h));
    seen.insert(rectangles.front());
    int xi, yi, wi, hi;
    while (n--) {
        std::cin >> xi >> yi >> wi >> hi;
        rect blocker = rect(xi, xi + wi, yi, yi + hi);
        int k = rectangles.size();
        while (k--) {
            rect obj = rectangles.front();
            rectangles.pop_front();
            if (!intersect(blocker, obj)) {
                rectangles.push_back(obj);
                continue;
            }
            directional_bool slices = cuts(obj, blocker);
            if (slices.up) {
                rectangles.push_back(rect(obj.xmin, obj.xmax, blocker.ymax, obj.ymax));
                if (seen.find(rectangles.back()) != seen.end()) {
                    rectangles.pop_back();
                } else {
                    seen.insert(rectangles.back());
                }
            }
            if (slices.down) {
                rectangles.push_back(rect(obj.xmin, obj.xmax, obj.ymin, blocker.ymin));
                if (seen.find(rectangles.back()) != seen.end()) {
                    rectangles.pop_back();
                } else {
                    seen.insert(rectangles.back());
                }
            }
            if (slices.left) {
                rectangles.push_back(rect(obj.xmin, blocker.xmin, obj.ymin, obj.ymax));
                if (seen.find(rectangles.back()) != seen.end()) {
                    rectangles.pop_back();
                } else {
                    seen.insert(rectangles.back());
                }
            }
            if (slices.right) {
                rectangles.push_back(rect(blocker.xmax, obj.xmax, obj.ymin, obj.ymax));
                if (seen.find(rectangles.back()) != seen.end()) {
                    rectangles.pop_back();
                } else {
                    seen.insert(rectangles.back());
                }
            }
        }
    }
    int maxarea = 0;
    while (rectangles.size()) {
        maxarea = MAX(maxarea, rectangles.front().area());
        rectangles.pop_front();
    }
    std::cout << maxarea;
    return 0;
}