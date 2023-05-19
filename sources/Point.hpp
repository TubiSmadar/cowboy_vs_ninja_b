#ifndef POINT_HPP
#define POINT_HPP
namespace ariel {
    class Point {
        private:
        double xCoordinate;
        double yCoordinate;

        public:
        Point(double xCoordinate, double yCoordinate);

        double distance (Point one);
        void print(Point one);
        Point moveTowards(Point one, Point two, double distance);
    };
}


#endif //POINT_HPP
