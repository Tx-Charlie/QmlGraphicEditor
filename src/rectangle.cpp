#include "point.h"
#include "linesegment.h"
#include "rectangle.h"

namespace RD = Rosdistant;
using namespace RD;

Rectangle::Rectangle()
{

}

Rectangle::Rectangle(const Point& point1, const Point& point2, const Point& point3, const Point& point4)
{
    insertLastPoint(point1);
    insertLastPoint(point2);
    insertLastPoint(point3);
    insertLastPoint(point4);
}

Rectangle::Rectangle(const Point& point1, const Point& point2)
{
    insertLastPoint(point1);
    insertLastPoint(Point(point2.x(), point1.y()));
    insertLastPoint(point2);
    insertLastPoint(Point(point1.x(), point2.y()));
}

Rectangle::Rectangle(const Point& point, double width, double height)
{
    insertLastPoint(point);
    insertLastPoint(Point(point.x()+width, point.y()));
    insertLastPoint(Point(point.x()+width, point.y()+height));
    insertLastPoint(Point(point.x(), point.y()+height));
}

Rectangle::~Rectangle()
{

}

QString Rectangle::toString() const
{
    return QString("Rectangle(%1; %2; %3; %4)").
            arg(topSide().toString(), rightSide().toString(),
                bottomSide().toString(), leftSide().toString());
}

int Rectangle::necessaryPointsQuant() const
{
    return 4;
}

Point Rectangle::getCentralPoint() const
{
    return LineSegment(pointByIndex(0), pointByIndex(3)).getCentralPoint();
}

bool Rectangle::isClosed() const
{
    return true;
}

bool Rectangle::isValid() const
{
    if (!Figure::isValid())
        return false;

    return topSide().length() == bottomSide().length() &&
            leftSide().length() == rightSide().length();
}

LineSegment Rectangle::topSide() const
{
    return getSide(0);
}

LineSegment Rectangle::rightSide() const
{
    return getSide(1);
}

LineSegment Rectangle::bottomSide() const
{
    return getSide(2);
}

LineSegment Rectangle::leftSide() const
{
    return getSide(3);
}
