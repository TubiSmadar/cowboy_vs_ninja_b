        #include "Point.hpp"

        namespace ariel {
        Point::Point(double xCoordinate, double yCoordinate) : yCoordinate(yCoordinate), xCoordinate(xCoordinate){
        

        }
        double Point::getX(){return this->xCoordinate;}
        double Point::getY(){return this->yCoordinate;}
        double Point::distance(Point a)
        {
        double deltaX = a.getX() - xCoordinate;
        double deltaY = a.getY() - yCoordinate;
        return std::sqrt(deltaX * deltaX + deltaY * deltaY);
        }


        std::string Point::print(Point a){
                std::string info = "(" + std::to_string(xCoordinate) + "," + std::to_string(yCoordinate) + ")";
                return info;
        }

        Point Point::moveTowards(Point source, Point dest, double distance){
        if(distance < 0) 
                throw std::invalid_argument("Distance can not be negative!");

        double powX = dest.xCoordinate - source.xCoordinate;
        double powY = dest.yCoordinate - source.yCoordinate;
        double newDistance = source.distance(dest);
        if(newDistance <= distance) {
                return dest;}
        else
        {
            double flag = distance / newDistance;
            double newX = source.xCoordinate + (powX * flag);
            double newY = source.yCoordinate + (powY * flag);

            return Point(newX, newY);
        }
        }
        }
