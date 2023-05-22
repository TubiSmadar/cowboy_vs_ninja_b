#ifndef POINT_HPP
#define POINT_HPP
#include <cmath>
#include <iostream>

namespace ariel {
    class Point {
        private:
        double xCoordinate;
        double yCoordinate;

        public:
        Point(double xCoordinate, double yCoordinate);
        double getX();
        double getY();
        double distance (Point one);
        std::string print(Point one);
        static Point moveTowards(Point one, Point two, double distance);
    };
}


#endif //POINT_HPP
