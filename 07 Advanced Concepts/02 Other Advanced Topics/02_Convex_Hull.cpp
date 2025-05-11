#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Define a point structure
struct Point {
    int x, y;

    // Sorting rule: first by x, then by y
    bool operator<(const Point& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

// Helper function to compute cross product
int cross(const Point& O, const Point& A, const Point& B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// Main convex hull function using Andrew's algorithm
vector<Point> convexHull(vector<Point>& points) {
    if (points.size() <= 1) return points;

    sort(points.begin(), points.end());

    vector<Point> lower, upper;

    // Build lower hull
    for (const Point& p : points) {
        while (lower.size() >= 2 && cross(lower[lower.size()-2], lower[lower.size()-1], p) <= 0)
            lower.pop_back();
        lower.push_back(p);
    }

    // Build upper hull
    for (int i = points.size() - 1; i >= 0; --i) {
        const Point& p = points[i];
        while (upper.size() >= 2 && cross(upper[upper.size()-2], upper[upper.size()-1], p) <= 0)
            upper.pop_back();
        upper.push_back(p);
    }

    // Remove last point of each hull (duplicate of first of the other)
    lower.pop_back();
    upper.pop_back();

    // Concatenate lower and upper
    lower.insert(lower.end(), upper.begin(), upper.end());
    return lower;
}

int main() {
    vector<Point> points = {{0, 0}, {1, 1}, {2, 2}, {3, 1}, {3, 0}, {2, -1}, {1, -1}};
    
    vector<Point> hull = convexHull(points);
    
    cout << "Convex Hull Points:\n";
    for (const Point& p : hull) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }

    return 0;
}
