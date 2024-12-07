#pragma once

#define _USE_MATH_DEFINES
#include "math.h"
#include <iostream>

#define SMALL_float 0.0000000001


/**
 * Attempt to include a header file if the file exists.
 * If the file does not exist, create a dummy data structure for that type.
 * If it cannot be determined if it exists, just attempt to include it.
 */
#include "Vector3.h"

struct il2cppQuaternion
{
    union
    {
        struct
        {
            float X;
            float Y;
            float Z;
            float W;
        };
        float data[4];
    };


    /**
     * Constructors.
     */
    inline il2cppQuaternion();
    inline il2cppQuaternion(float data[]);
    inline il2cppQuaternion(il2cppVector3 vector, float scalar);
    inline il2cppQuaternion(float x, float y, float z, float w);


    /**
     * Constants for common il2cppQuaternions.
     */
    static inline il2cppQuaternion Identity();


    /**
     * Returns the angle between two il2cppQuaternions.
     * The il2cppQuaternions must be normalized.
     * @param a: The first il2cppQuaternion.
     * @param b: The second il2cppQuaternion.
     * @return: A scalar value.
     */
    static inline float Angle(il2cppQuaternion a, il2cppQuaternion b);

    /**
     * Returns the conjugate of a il2cppQuaternion.
     * @param rotation: The il2cppQuaternion in question.
     * @return: A new il2cppQuaternion.
     */
    static inline il2cppQuaternion Conjugate(il2cppQuaternion rotation);

    /**
     * Returns the dot product of two il2cppQuaternions.
     * @param lhs: The left side of the multiplication.
     * @param rhs: The right side of the multiplication.
     * @return: A scalar value.
     */
    static inline float Dot(il2cppQuaternion lhs, il2cppQuaternion rhs);

    /**
     * Creates a new il2cppQuaternion from the angle-axis representation of
     * a rotation.
     * @param angle: The rotation angle in radians.
     * @param axis: The vector about which the rotation occurs.
     * @return: A new il2cppQuaternion.
     */
    static inline il2cppQuaternion FromAngleAxis(float angle, il2cppVector3 axis);

    /**
     * Create a new il2cppQuaternion from the euler angle representation of
     * a rotation. The z, x and y values represent rotations about those
     * axis in that respective order.
     * @param rotation: The x, y and z rotations.
     * @return: A new il2cppQuaternion.
     */
    static inline il2cppQuaternion FromEuler(il2cppVector3 rotation);

    /**
     * Create a new il2cppQuaternion from the euler angle representation of
     * a rotation. The z, x and y values represent rotations about those
     * axis in that respective order.
     * @param x: The rotation about the x-axis in radians.
     * @param y: The rotation about the y-axis in radians.
     * @param z: The rotation about the z-axis in radians.
     * @return: A new il2cppQuaternion.
     */
    static inline il2cppQuaternion FromEuler(float x, float y, float z);

    /**
     * Create a il2cppQuaternion rotation which rotates "fromVector" to "toVector".
     * @param fromVector: The vector from which to start the rotation.
     * @param toVector: The vector at which to end the rotation.
     * @return: A new il2cppQuaternion.
     */
    static inline il2cppQuaternion FromToRotation(il2cppVector3 fromVector,
                                            il2cppVector3 toVector);

    /**
     * Returns the inverse of a rotation.
     * @param rotation: The il2cppQuaternion in question.
     * @return: A new il2cppQuaternion.
     */
    static inline il2cppQuaternion Inverse(il2cppQuaternion rotation);

    /**
     * Interpolates between a and b by t, which is clamped to the range [0-1].
     * The result is normalized before being returned.
     * @param a: The starting rotation.
     * @param b: The ending rotation.
     * @return: A new il2cppQuaternion.
     */
    static inline il2cppQuaternion Lerp(il2cppQuaternion a, il2cppQuaternion b, float t);

    /**
     * Interpolates between a and b by t. This normalizes the result when
     * complete.
     * @param a: The starting rotation.
     * @param b: The ending rotation.
     * @param t: The interpolation value.
     * @return: A new il2cppQuaternion.
     */
    static inline il2cppQuaternion LerpUnclamped(il2cppQuaternion a, il2cppQuaternion b,
                                           float t);

    /**
     * Creates a rotation with the specified forward direction. This is the
     * same as calling LookRotation with (0, 1, 0) as the upwards vector.
     * The output is undefined for parallel vectors.
     * @param forward: The forward direction to look toward.
     * @return: A new il2cppQuaternion.
     */
    static inline il2cppQuaternion LookRotation(il2cppVector3 forward);

    /**
     * Creates a rotation with the specified forward and upwards directions.
     * The output is undefined for parallel vectors.
     * @param forward: The forward direction to look toward.
     * @param upwards: The direction to treat as up.
     * @return: A new il2cppQuaternion.
     */
    static inline il2cppQuaternion LookRotation(il2cppVector3 forward, il2cppVector3 upwards);

    /**
     * Returns the norm of a il2cppQuaternion.
     * @param rotation: The il2cppQuaternion in question.
     * @return: A scalar value.
     */
    static inline float Norm(il2cppQuaternion rotation);

    /**
     * Returns a il2cppQuaternion with identical rotation and a norm of one.
     * @param rotation: The il2cppQuaternion in question.
     * @return: A new il2cppQuaternion.
     */
    static inline il2cppQuaternion Normalized(il2cppQuaternion rotation);

    /**
     * Returns a new il2cppQuaternion created by rotating "from" towards "to" by
     * "maxRadiansDelta". This will not overshoot, and if a negative delta is
     * applied, it will rotate till completely opposite "to" and then stop.
     * @param from: The rotation at which to start.
     * @param to: The rotation at which to end.
     # @param maxRadiansDelta: The maximum number of radians to rotate.
     * @return: A new il2cppQuaternion.
     */
    static inline il2cppQuaternion RotateTowards(il2cppQuaternion from, il2cppQuaternion to,
                                           float maxRadiansDelta);

    /**
     * Returns a new il2cppQuaternion interpolated between a and b, using spherical
     * linear interpolation. The variable t is clamped to the range [0-1]. The
     * resulting il2cppQuaternion will be normalized.
     * @param a: The starting rotation.
     * @param b: The ending rotation.
     * @param t: The interpolation value.
     * @return: A new il2cppQuaternion.
     */
    static inline il2cppQuaternion Slerp(il2cppQuaternion a, il2cppQuaternion b, float t);

    /**
     * Returns a new il2cppQuaternion interpolated between a and b, using spherical
     * linear interpolation. The resulting il2cppQuaternion will be normalized.
     * @param a: The starting rotation.
     * @param b: The ending rotation.
     * @param t: The interpolation value.
     * @return: A new il2cppQuaternion.
     */
    static inline il2cppQuaternion SlerpUnclamped(il2cppQuaternion a, il2cppQuaternion b,
                                            float t);

    /**
     * Outputs the angle axis representation of the provided il2cppQuaternion.
     * @param rotation: The input il2cppQuaternion.
     * @param angle: The output angle.
     * @param axis: The output axis.
     */
    static inline void ToAngleAxis(il2cppQuaternion rotation, float &angle,
                                   il2cppVector3 &axis);

    /**
     * Returns the Euler angle representation of a rotation. The resulting
     * vector contains the rotations about the z, x and y axis, in that order.
     * @param rotation: The il2cppQuaternion to convert.
     * @return: A new vector.
     */
    static inline il2cppVector3 ToEuler(il2cppQuaternion rotation);

    /**
     * Operator overloading.
     */
    inline struct il2cppQuaternion& operator+=(const float rhs);
    inline struct il2cppQuaternion& operator-=(const float rhs);
    inline struct il2cppQuaternion& operator*=(const float rhs);
    inline struct il2cppQuaternion& operator/=(const float rhs);
    inline struct il2cppQuaternion& operator+=(const il2cppQuaternion rhs);
    inline struct il2cppQuaternion& operator-=(const il2cppQuaternion rhs);
    inline struct il2cppQuaternion& operator*=(const il2cppQuaternion rhs);
};

inline il2cppQuaternion operator-(il2cppQuaternion rhs);
inline il2cppQuaternion operator+(il2cppQuaternion lhs, const float rhs);
inline il2cppQuaternion operator-(il2cppQuaternion lhs, const float rhs);
inline il2cppQuaternion operator*(il2cppQuaternion lhs, const float rhs);
inline il2cppQuaternion operator/(il2cppQuaternion lhs, const float rhs);
inline il2cppQuaternion operator+(const float lhs, il2cppQuaternion rhs);
inline il2cppQuaternion operator-(const float lhs, il2cppQuaternion rhs);
inline il2cppQuaternion operator*(const float lhs, il2cppQuaternion rhs);
inline il2cppQuaternion operator/(const float lhs, il2cppQuaternion rhs);
inline il2cppQuaternion operator+(il2cppQuaternion lhs, const il2cppQuaternion rhs);
inline il2cppQuaternion operator-(il2cppQuaternion lhs, const il2cppQuaternion rhs);
inline il2cppQuaternion operator*(il2cppQuaternion lhs, const il2cppQuaternion rhs);
inline il2cppVector3 operator*(il2cppQuaternion lhs, const il2cppVector3 rhs);
inline bool operator==(const il2cppQuaternion lhs, const il2cppQuaternion rhs);
inline bool operator!=(const il2cppQuaternion lhs, const il2cppQuaternion rhs);



/*******************************************************************************
 * Implementation
 */

il2cppQuaternion::il2cppQuaternion() : X(0), Y(0), Z(0), W(1) {}
il2cppQuaternion::il2cppQuaternion(float data[]) : X(data[0]), Y(data[1]), Z(data[2]),
                                       W(data[3]) {}
il2cppQuaternion::il2cppQuaternion(il2cppVector3 vector, float scalar) : X(vector.X),
                                                       Y(vector.Y), Z(vector.Z), W(scalar) {}
il2cppQuaternion::il2cppQuaternion(float x, float y, float z, float w) : X(x), Y(y),
                                                             Z(z), W(w) {}


il2cppQuaternion il2cppQuaternion::Identity() { return il2cppQuaternion(0, 0, 0, 1); }


float il2cppQuaternion::Angle(il2cppQuaternion a, il2cppQuaternion b)
{
    float dot = Dot(a, b);
    return acos(fmin(fabs(dot), 1)) * 2;
}

il2cppQuaternion il2cppQuaternion::Conjugate(il2cppQuaternion rotation)
{
    return il2cppQuaternion(-rotation.X, -rotation.Y, -rotation.Z, rotation.W);
}

float il2cppQuaternion::Dot(il2cppQuaternion lhs, il2cppQuaternion rhs)
{
    return lhs.X * rhs.X + lhs.Y * rhs.Y + lhs.Z * rhs.Z + lhs.W * rhs.W;
}

il2cppQuaternion il2cppQuaternion::FromAngleAxis(float angle, il2cppVector3 axis)
{
    il2cppQuaternion q;
    float m = sqrt(axis.X * axis.X + axis.Y * axis.Y + axis.Z * axis.Z);
    float s = sin(angle / 2) / m;
    q.X = axis.X * s;
    q.Y = axis.Y * s;
    q.Z = axis.Z * s;
    q.W = cos(angle / 2);
    return q;
}

il2cppQuaternion il2cppQuaternion::FromEuler(il2cppVector3 rotation)
{
    return FromEuler(rotation.X, rotation.Y, rotation.Z);
}

il2cppQuaternion il2cppQuaternion::FromEuler(float x, float y, float z)
{
    float cx = cos(x * 0.5);
    float cy = cos(y * 0.5);
    float cz = cos(z * 0.5);
    float sx = sin(x * 0.5);
    float sy = sin(y * 0.5);
    float sz = sin(z * 0.5);
    il2cppQuaternion q;
    q.X = cx * sy * sz + cy * cz * sx;
    q.Y = cx * cz * sy - cy * sx * sz;
    q.Z = cx * cy * sz - cz * sx * sy;
    q.W = sx * sy * sz + cx * cy * cz;
    return q;
}

il2cppQuaternion il2cppQuaternion::FromToRotation(il2cppVector3 fromVector, il2cppVector3 toVector)
{
    float dot = il2cppVector3::Dot(fromVector, toVector);
    float k = sqrt(il2cppVector3::SqrMagnitude(fromVector) *
                   il2cppVector3::SqrMagnitude(toVector));
    if (fabs(dot / k + 1) < 0.00001)
    {
        il2cppVector3 ortho = il2cppVector3::Orthogonal(fromVector);
        return il2cppQuaternion(il2cppVector3::Normalized(ortho), 0);
    }
    il2cppVector3 cross = il2cppVector3::Cross(fromVector, toVector);
    return Normalized(il2cppQuaternion(cross, dot + k));
}

il2cppQuaternion il2cppQuaternion::Inverse(il2cppQuaternion rotation)
{
    float n = Norm(rotation);
    return Conjugate(rotation) / (n * n);
}

il2cppQuaternion il2cppQuaternion::Lerp(il2cppQuaternion a, il2cppQuaternion b, float t)
{
    if (t < 0) return Normalized(a);
    else if (t > 1) return Normalized(b);
    return LerpUnclamped(a, b, t);
}

il2cppQuaternion il2cppQuaternion::LerpUnclamped(il2cppQuaternion a, il2cppQuaternion b, float t)
{
    il2cppQuaternion il2cppQuaternion;
    if (Dot(a, b) >= 0)
        il2cppQuaternion = a * (1 - t) + b * t;
    else
        il2cppQuaternion = a * (1 - t) - b * t;
    return Normalized(il2cppQuaternion);
}

il2cppQuaternion il2cppQuaternion::LookRotation(il2cppVector3 forward)
{
    return LookRotation(forward, il2cppVector3(0, 1, 0));
}

il2cppQuaternion il2cppQuaternion::LookRotation(il2cppVector3 forward, il2cppVector3 upwards)
{
    // Normalize inputs
    forward = il2cppVector3::Normalized(forward);
    upwards = il2cppVector3::Normalized(upwards);
    // Don't allow zero vectors
    if (il2cppVector3::SqrMagnitude(forward) < SMALL_float || il2cppVector3::SqrMagnitude(upwards) < SMALL_float)
        return il2cppQuaternion::Identity();
    // Handle alignment with up direction
    if (1 - fabs(il2cppVector3::Dot(forward, upwards)) < SMALL_float)
        return FromToRotation(il2cppVector3::Forward(), forward);
    // Get orthogonal vectors
    il2cppVector3 right = il2cppVector3::Normalized(il2cppVector3::Cross(upwards, forward));
    upwards = il2cppVector3::Cross(forward, right);
    // Calculate rotation
    il2cppQuaternion il2cppQuaternion;
    float radicand = right.X + upwards.Y + forward.Z;
    if (radicand > 0)
    {
        il2cppQuaternion.W = sqrt(1.0 + radicand) * 0.5;
        float recip = 1.0 / (4.0 * il2cppQuaternion.W);
        il2cppQuaternion.X = (upwards.Z - forward.Y) * recip;
        il2cppQuaternion.Y = (forward.X - right.Z) * recip;
        il2cppQuaternion.Z = (right.Y - upwards.X) * recip;
    }
    else if (right.X >= upwards.Y && right.X >= forward.Z)
    {
        il2cppQuaternion.X = sqrt(1.0 + right.X - upwards.Y - forward.Z) * 0.5;
        float recip = 1.0 / (4.0 * il2cppQuaternion.X);
        il2cppQuaternion.W = (upwards.Z - forward.Y) * recip;
        il2cppQuaternion.Z = (forward.X + right.Z) * recip;
        il2cppQuaternion.Y = (right.Y + upwards.X) * recip;
    }
    else if (upwards.Y > forward.Z)
    {
        il2cppQuaternion.Y = sqrt(1.0 - right.X + upwards.Y - forward.Z) * 0.5;
        float recip = 1.0 / (4.0 * il2cppQuaternion.Y);
        il2cppQuaternion.Z = (upwards.Z + forward.Y) * recip;
        il2cppQuaternion.W = (forward.X - right.Z) * recip;
        il2cppQuaternion.X = (right.Y + upwards.X) * recip;
    }
    else
    {
        il2cppQuaternion.Z = sqrt(1.0 - right.X - upwards.Y + forward.Z) * 0.5;
        float recip = 1.0 / (4.0 * il2cppQuaternion.Z);
        il2cppQuaternion.Y = (upwards.Z + forward.Y) * recip;
        il2cppQuaternion.X = (forward.X + right.Z) * recip;
        il2cppQuaternion.W = (right.Y - upwards.X) * recip;
    }
    return il2cppQuaternion;
}

float il2cppQuaternion::Norm(il2cppQuaternion rotation)
{
    return sqrt(rotation.X * rotation.X +
                rotation.Y * rotation.Y +
                rotation.Z * rotation.Z +
                rotation.W * rotation.W);
}

il2cppQuaternion il2cppQuaternion::Normalized(il2cppQuaternion rotation)
{
    return rotation / Norm(rotation);
}

il2cppQuaternion il2cppQuaternion::RotateTowards(il2cppQuaternion from, il2cppQuaternion to,
                                     float maxRadiansDelta)
{
    float angle = il2cppQuaternion::Angle(from, to);
    if (angle == 0)
        return to;
    maxRadiansDelta = fmax(maxRadiansDelta, angle - M_PI);
    float t = fmin(1, maxRadiansDelta / angle);
    return il2cppQuaternion::SlerpUnclamped(from, to, t);
}

il2cppQuaternion il2cppQuaternion::Slerp(il2cppQuaternion a, il2cppQuaternion b, float t)
{
    if (t < 0) return Normalized(a);
    else if (t > 1) return Normalized(b);
    return SlerpUnclamped(a, b, t);
}

il2cppQuaternion il2cppQuaternion::SlerpUnclamped(il2cppQuaternion a, il2cppQuaternion b, float t)
{
    float n1;
    float n2;
    float n3 = Dot(a, b);
    bool flag = false;
    if (n3 < 0)
    {
        flag = true;
        n3 = -n3;
    }
    if (n3 > 0.999999)
    {
        n2 = 1 - t;
        n1 = flag ? -t : t;
    }
    else
    {
        float n4 = acos(n3);
        float n5 = 1 / sin(n4);
        n2 = sin((1 - t) * n4) * n5;
        n1 = flag ? -sin(t * n4) * n5 : sin(t * n4) * n5;
    }
    il2cppQuaternion il2cppQuaternion;
    il2cppQuaternion.X = (n2 * a.X) + (n1 * b.X);
    il2cppQuaternion.Y = (n2 * a.Y) + (n1 * b.Y);
    il2cppQuaternion.Z = (n2 * a.Z) + (n1 * b.Z);
    il2cppQuaternion.W = (n2 * a.W) + (n1 * b.W);
    return Normalized(il2cppQuaternion);
}

void il2cppQuaternion::ToAngleAxis(il2cppQuaternion rotation, float &angle, il2cppVector3 &axis)
{
    if (rotation.W > 1)
        rotation = Normalized(rotation);
    angle = 2 * acos(rotation.W);
    float s = sqrt(1 - rotation.W * rotation.W);
    if (s < 0.00001) {
        axis.X = 1;
        axis.Y = 0;
        axis.Z = 0;
    } else {
        axis.X = rotation.X / s;
        axis.Y = rotation.Y / s;
        axis.Z = rotation.Z / s;
    }
}

il2cppVector3 il2cppQuaternion::ToEuler(il2cppQuaternion rotation)
{
    float sqw = rotation.W * rotation.W;
    float sqx = rotation.X * rotation.X;
    float sqy = rotation.Y * rotation.Y;
    float sqz = rotation.Z * rotation.Z;
    // If normalized is one, otherwise is correction factor
    float unit = sqx + sqy + sqz + sqw;
    float test = rotation.X * rotation.W - rotation.Y * rotation.Z;
    il2cppVector3 v;
    // Singularity at north pole
    if (test > 0.4995f * unit)
    {
        v.Y = 2 * atan2(rotation.Y, rotation.X);
        v.X = M_PI_2;
        v.Z = 0;
        return v;
    }
    // Singularity at south pole
    if (test < -0.4995f * unit)
    {
        v.Y = -2 * atan2(rotation.Y, rotation.X);
        v.X = -M_PI_2;
        v.Z = 0;
        return v;
    }
    // Yaw
    v.Y = atan2(2 * rotation.W * rotation.Y + 2 * rotation.Z * rotation.X,
                1 - 2 * (rotation.X * rotation.X + rotation.Y * rotation.Y));
    // Pitch
    v.X = asin(2 * (rotation.W * rotation.X - rotation.Y * rotation.Z));
    // Roll
    v.Z = atan2(2 * rotation.W * rotation.Z + 2 * rotation.X * rotation.Y,
                1 - 2 * (rotation.Z * rotation.Z + rotation.X * rotation.X));
    return v;
}

struct il2cppQuaternion& il2cppQuaternion::operator+=(const float rhs)
{
    X += rhs;
    Y += rhs;
    Z += rhs;
    W += rhs;
    return *this;
}

struct il2cppQuaternion& il2cppQuaternion::operator-=(const float rhs)
{
    X -= rhs;
    Y -= rhs;
    Z -= rhs;
    W -= rhs;
    return *this;
}

struct il2cppQuaternion& il2cppQuaternion::operator*=(const float rhs)
{
    X *= rhs;
    Y *= rhs;
    Z *= rhs;
    W *= rhs;
    return *this;
}

struct il2cppQuaternion& il2cppQuaternion::operator/=(const float rhs)
{
    X /= rhs;
    Y /= rhs;
    Z /= rhs;
    W /= rhs;
    return *this;
}

struct il2cppQuaternion& il2cppQuaternion::operator+=(const il2cppQuaternion rhs)
{
    X += rhs.X;
    Y += rhs.Y;
    Z += rhs.Z;
    W += rhs.W;
    return *this;
}

struct il2cppQuaternion& il2cppQuaternion::operator-=(const il2cppQuaternion rhs)
{
    X -= rhs.X;
    Y -= rhs.Y;
    Z -= rhs.Z;
    W -= rhs.W;
    return *this;
}

struct il2cppQuaternion& il2cppQuaternion::operator*=(const il2cppQuaternion rhs)
{
    il2cppQuaternion q;
    q.W = W * rhs.W - X * rhs.X - Y * rhs.Y - Z * rhs.Z;
    q.X = X * rhs.W + W * rhs.X + Y * rhs.Z - Z * rhs.Y;
    q.Y = W * rhs.Y - X * rhs.Z + Y * rhs.W + Z * rhs.X;
    q.Z = W * rhs.Z + X * rhs.Y - Y * rhs.X + Z * rhs.W;
    *this = q;
    return *this;
}

il2cppQuaternion operator-(il2cppQuaternion rhs) { return rhs * -1; }
il2cppQuaternion operator+(il2cppQuaternion lhs, const float rhs) { return lhs += rhs; }
il2cppQuaternion operator-(il2cppQuaternion lhs, const float rhs) { return lhs -= rhs; }
il2cppQuaternion operator*(il2cppQuaternion lhs, const float rhs) { return lhs *= rhs; }
il2cppQuaternion operator/(il2cppQuaternion lhs, const float rhs) { return lhs /= rhs; }
il2cppQuaternion operator+(const float lhs, il2cppQuaternion rhs) { return rhs += lhs; }
il2cppQuaternion operator-(const float lhs, il2cppQuaternion rhs) { return rhs -= lhs; }
il2cppQuaternion operator*(const float lhs, il2cppQuaternion rhs) { return rhs *= lhs; }
il2cppQuaternion operator/(const float lhs, il2cppQuaternion rhs) { return rhs /= lhs; }
il2cppQuaternion operator+(il2cppQuaternion lhs, const il2cppQuaternion rhs)
{
    return lhs += rhs;
}
il2cppQuaternion operator-(il2cppQuaternion lhs, const il2cppQuaternion rhs)
{
    return lhs -= rhs;
}
il2cppQuaternion operator*(il2cppQuaternion lhs, const il2cppQuaternion rhs)
{
    return lhs *= rhs;
}

il2cppVector3 operator*(il2cppQuaternion lhs, const il2cppVector3 rhs)
{
    il2cppVector3 u = il2cppVector3(lhs.X, lhs.Y, lhs.Z);
    float s = lhs.W;
    return u * (il2cppVector3::Dot(u, rhs) * 2)
           + rhs * (s * s - il2cppVector3::Dot(u, u))
           + il2cppVector3::Cross(u, rhs) * (2.0 * s);
}

bool operator==(const il2cppQuaternion lhs, const il2cppQuaternion rhs)
{
    return lhs.X == rhs.X &&
           lhs.Y == rhs.Y &&
           lhs.Z == rhs.Z &&
           lhs.W == rhs.W;
}

bool operator!=(const il2cppQuaternion lhs, const il2cppQuaternion rhs)
{
    return !(lhs == rhs);
}
