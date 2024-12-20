#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>

/**
 * @file Point.h
 * @author Yakub Þiyar Demirbaþ
 * @date December, 2024
 * @brief Declaration of the Point class.
 *
 * This file contains the declaration of the Point class, which represents a 2D point
 * with operations for setting/getting coordinates, calculating distances and angles,
 * and operator overloading for comparison and output.
 */

class Point
{
private:
    double x; /*!< X-coordinate of the point. */
    double y; /*!< Y-coordinate of the point. */

public:
    //! Default constructor.
    /*!
     Initializes the point to (0, 0).
     */
    Point();

    //! Parameterized constructor.
    /*!
     Initializes the point with the given coordinates.
     \param x X-coordinate of the point.
     \param y Y-coordinate of the point.
     */
    Point(double x, double y);

    //! Gets the X-coordinate.
    /*!
     \return The current X-coordinate value.
     */
    double getX() const;

    //! Sets the X-coordinate.
    /*!
     \param x The new X-coordinate value.
     */
    void setX(double x);

    //! Gets the Y-coordinate.
    /*!
     \return The current Y-coordinate value.
     */
    double getY() const;

    //! Sets the Y-coordinate.
    /*!
     \param y The new Y-coordinate value.
     */
    void setY(double y);

    //! Gets the point's coordinates.
    /*!
     \param x Reference to store the X-coordinate.
     \param y Reference to store the Y-coordinate.
     */
    void getPoint(double& x, double& y) const;

    //! Sets the point's coordinates.
    /*!
     \param x The new X-coordinate value.
     \param y The new Y-coordinate value.
     */
    void setPoint(double x, double y);

    //! Calculates the distance to another point.
    /*!
     \param other The other point.
     \return The Euclidean distance between this point and the other point.
     */
    double findDistanceTo(const Point& other) const;

    //! Calculates the angle to another point.
    /*!
     \param other The other point.
     \return The angle (in radians) between this point and the other point.
     */
    double findAngleTo(const Point& other) const;

    //! Compares two points for equality.
    /*!
     \param other The point to compare with.
     \return True if the points are equal, false otherwise.
     */
    bool operator==(const Point& other) const;

    //! Outputs the point's coordinates.
    /*!
     \param out The output stream.
     \param point The point to output.
     \return The output stream.
     */
    friend std::ostream& operator<<(std::ostream& out, const Point& point);
};

#endif // POINT_H
