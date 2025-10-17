/*
 * fast < input.txt
 *
 * Compute and plot all line segments involving 4 points in input.txt
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <unordered_map>

#include "point.h"
#include "window.h"

using namespace std;

int main(int argc, const char* argv[]) {
    WindowPtr window = create_window(argc, argv);
    if (!window)
        return 1;

    // The array of points
    vector<Point> points {};

    // Read tolerance from cin
    double tolerance{};
    cin >> tolerance;

    // Read points from cin
    int N{};
    cin >> N;

    for (int i{0}; i < N; ++i) {
        double x{}, y{};
        cin >> x >> y;
        points.push_back(Point{x, y});
    }

    // draw points to screen all at once
    window->draw_points(points);

    auto begin = chrono::high_resolution_clock::now();
    
    for (auto& p : points) {
        
        unordered_map<double, vector<Point>> angles {}; // Angle and vector of points on the same angle
    
        for (auto& other_p : points) {
            if (&p == &other_p) continue;

            double slope = std::round(p.slopeTo(other_p) / tolerance) * tolerance;

            //cout << slope << endl;

            angles[slope].push_back(other_p);
                
        }
    
        for (auto& [angle, group] : angles) {
            if (group.size() >= 3) {
                group.push_back(p);
                window->draw_line(group);
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    cout << "Computing line segments took "
         << std::chrono::duration_cast<chrono::milliseconds>(end - begin).count()
         << " milliseconds." << endl;

    // wait for user to terminate program
    window->run();

    return 0;
}
