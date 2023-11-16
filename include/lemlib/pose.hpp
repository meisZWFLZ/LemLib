/**
 * @file include/lemlib/pose.hpp
 * @author LemLib Team
 * @brief Pose class declarations
 * @version 0.4.5
 * @date 2023-01-23
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

#include <string>
#include <ostream>

namespace lemlib {
class Pose {
    public:
        /** @brief x value*/
        float x;
        /** @brief y value*/
        float y;
        /** @brief theta value*/
        float theta;
        /**
         * @brief Create a new pose
         *
         * @param x component
         * @param y component
         * @param theta heading. Defaults to 0
         */
        Pose(float x, float y, float theta = 0);
        /**
         * @brief Add a pose to this pose
         *
         * @param other other pose
         * @return Pose
         */
        Pose operator+(const Pose& other);
        /**
         * @brief Subtract a pose from this pose
         *
         * @param other other pose
         * @return Pose
         */
        Pose operator-(const Pose& other);
        /**
         * @brief Multiply a pose by this pose
         *
         * @param other other pose
         * @return Pose
         */
        float operator*(const Pose& other);
        /**
         * @brief Multiply a pose by a float
         *
         * @param other float
         * @return Pose
         */
        Pose operator*(const float& other);
        /**
         * @brief Divide a pose by a float
         *
         * @param other float
         * @return Pose
         */
        Pose operator/(const float& other);
        /**
         * @brief Linearly interpolate between two poses
         *
         * @param other the other pose
         * @param t t value
         * @return Pose
         */
        Pose lerp(Pose other, float t);
        /**
         * @brief Get the distance between two poses
         *
         * @param other the other pose
         * @return float
         */
        float distance(Pose other);
        /**
         * @brief Get the angle between two poses
         *
         * @param other the other pose
         * @return float in radians
         */
        float angle(Pose other);
        /**
         * @brief Rotate a pose by an angle
         *
         * @param angle angle in radians
         * @return Pose
         */
        Pose rotate(float angle);
        /**
         * @brief Check that x, y, and theta are equal between two poses
         *
         * @param other the other pose
         * @return bool
         */
        bool operator==(const Pose& other) const;
        /**
         * @brief Check that x, y, and theta are NOT equal between two poses
         *
         * @param other the other pose
         * @return bool
         */
        bool operator!=(const Pose& other) const;
};

/**
 * @brief output and format pose into a stream   
 *
 * @param pose
 * @return std::ostream
 */
std::ostream& operator<<(std::ostream& os, const lemlib::Pose& pose);

/**
 * @brief Format a pose
 *
 * @param pose
 * @return std::string
 */
std::string format_as(const Pose& pose);
} // namespace lemlib
