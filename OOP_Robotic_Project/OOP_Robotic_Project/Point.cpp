#include "Point.h"

/**
 * @file Point.cpp
 * @author Yakub Þiyar Demirbaþ
 * @date December, 2024
 * @brief Implementation of the Point class.
 *
 * This file contains the implementation of the Point class, including its constructors,
 * getter and setter methods, utility methods for distance and angle calculations, and
 * operator overloads.
 */

 //! Default constructor.
 /*!
  Initializes the point to (0, 0).
  */
Point::Point() : x(0.0), y(0.0) {}

//! Parameterized constructor.
/*!
 Initializes the point with the given coordinates.
 \param x X-coordinate of the point.
 \param y Y-coordinate of the point.
 */
Point::Point(double x, double y) : x(x), y(y) {}

//! Gets the X-coordinate.
/*!
 \return The current X-coordinate value.
 */
double Point::getX() const
{
    return x;
}

//! Gets the Y-coordinate.
/*!
 \return The current Y-coordinate value.
 */
double Point::getY() const
{
    return y;
}

//! Sets the X-coordinate.
/*!
 \param x The new X-coordinate value.
 */
void Point::setX(double x)
{
    this->x = x;
}

//! Sets the Y-coordinate.
/*!
 \param y The new Y-coordinate value.
 */
void Point::setY(double y)
{
    this->y = y;
}

//! Gets the coordinates of the point.
/*!
 \param x Reference to store the X-coordinate.
 \param y Reference to store the Y-coordinate.
 */
void Point::getPoint(double& x, double& y) const
{
    x = this->x;
    y = this->y;
}

//! Sets the coordinates of the point.
/*!
 \param x The new X-coordinate value.
 \param y The new Y-coordinate value.
 */
void Point::setPoint(double x, double y)
{
    this->x = x;
    this->y = y;
}

//! Calculates the distance to another point.
/*!
 \param other The other point.
 \return The Euclidean distance between this point and the other point.
 */
double Point::findDistanceTo(const Point& other) const
{
    double dx = other.x - this->x;
    double dy = other.y - this->y;
    return std::sqrt(dx * dx + dy * dy);
}

//! Calculates the angle to another point.
/*!
 \param other The other point.
 \return The angle (in radians) between this point and the other point.
 */
double Point::findAngleTo(const Point& other) const
{
    double dx = other.x - this->x;
    double dy = other.y - this->y;
    return std::atan2(dy, dx); // Returns the angle in radians.
}

//! Compares two points for equality.
/*!
 \param other The point to compare with.
 \return True if the points are equal, false otherwise.
 */
bool Point::operator==(const Point& other) const
{
    return (this->x == other.x && this->y == other.y);
}

//! Outputs the coordinates of the point.
/*!
 \param out The output stream.
 \param point The point to output.
 \return The output stream.
 */
std::ostream& operator<<(std::ostream& out, const Point& point)
{
    out << "(" << point.x << ", " << point.y << ")";
    return out;
}
