#pragma once

#include "math.h"
#include "string.h"


struct il2cppVector3
{
    union
    {
        struct
        {
            float X;
            float Y;
            float Z;
        };
        float data[3];
    };


    /**
     * Constructors.
     */
    inline il2cppVector3();
    inline il2cppVector3(float data[]);
    inline il2cppVector3(float value);
    inline il2cppVector3(float x, float y);
    inline il2cppVector3(float x, float y, float z);

    /**
     * Constants for common vectors.
     */
    static inline il2cppVector3 Zero();
    static inline il2cppVector3 One();
    static inline il2cppVector3 Right();
    static inline il2cppVector3 Left();
    static inline il2cppVector3 Up();
    static inline il2cppVector3 Down();
    static inline il2cppVector3 Forward();
    static inline il2cppVector3 Backward();


    /**
     * Returns the angle between two vectors in radians.
     * @param a: The first vector.
     * @param b: The second vector.
     * @return: A scalar value.
     */
    static inline float Angle(il2cppVector3 a, il2cppVector3 b);

    /**
     * Returns a vector with its magnitude clamped to maxLength.
     * @param vector: The target vector.
     * @param maxLength: The maximum length of the return vector.
     * @return: A new vector.
     */
    static inline il2cppVector3 ClampMagnitude(il2cppVector3 vector, float maxLength);

    /**
     * Retorna o componente de a na direção de b (projeção escalar).
     * @param a: O vetor de destino.
     * @param b: O vetor que está sendo comparado.
     * @return: Um valor escalar.
     */
    static inline float Component(il2cppVector3 a, il2cppVector3 b);

    /**
     * Retorna o produto vetorial de dois vetores.
     * @param lhs: O lado esquerdo da multiplicação.
     * @param rhs: O lado direito da multiplicação.
     * @return: Um novo vetor.
     */
    static inline il2cppVector3 Cross(il2cppVector3 lhs, il2cppVector3 rhs);

    /**
     * Returns the distance between a and b.
     * @param a: The first point.
     * @param b: The second point.
     * @return: A scalar value.
     */
    static inline float Distance(il2cppVector3 a, il2cppVector3 b);

    static inline char ToChar(il2cppVector3 a);

    /**
     * Returns the dot product of two vectors.
     * @param lhs: The left side of the multiplication.
     * @param rhs: The right side of the multiplication.
     * @return: A scalar value.
     */
    static inline float Dot(il2cppVector3 lhs, il2cppVector3 rhs);

    /**
     * Converte uma representação esférica de um vetor em cartesiano
     * coordenadas.
     * Isso usa a convenção ISO (raio r, inclinação theta, azimute phi).
     * @param rad: A magnitude do vetor.
     * @param theta: O ângulo no plano XY do eixo X.
     * @param phi: O ângulo do eixo Z positivo para o vetor.
     * @return: Um novo vetor.
     */
    static inline il2cppVector3 FromSpherical(float rad, float theta, float phi);

    /**
     * Returns a vector linearly interpolated between a and b, moving along
     * a straight line. The vector is clamped to never go beyond the end points.
     * @param a: The starting point.
     * @param b: The ending point.
     * @param t: The interpolation value [0-1].
     * @return: A new vector.
     */
    static inline il2cppVector3 Lerp(il2cppVector3 a, il2cppVector3 b, float t);

    /**
     * Returns a vector linearly interpolated between a and b, moving along
     * a straight line.
     * @param a: The starting point.
     * @param b: The ending point.
     * @param t: The interpolation value [0-1] (no actual bounds).
     * @return: A new vector.
     */
    static inline il2cppVector3 LerpUnclamped(il2cppVector3 a, il2cppVector3 b, float t);

    /**
     * Returns the magnitude of a vector.
     * @param v: The vector in question.
     * @return: A scalar value.
     */
    static inline float Magnitude(il2cppVector3 v);

    /**
     * Returns a vector made from the largest components of two other vectors.
     * @param a: The first vector.
     * @param b: The second vector.
     * @return: A new vector.
     */
    static inline il2cppVector3 Max(il2cppVector3 a, il2cppVector3 b);

    /**
     * Returns a vector made from the smallest components of two other vectors.
     * @param a: The first vector.
     * @param b: The second vector.
     * @return: A new vector.
     */
    static inline il2cppVector3 Min(il2cppVector3 a, il2cppVector3 b);

    /**
     * Returns a vector "maxDistanceDelta" units closer to the target. This
     * interpolation is in a straight line, and will not overshoot.
     * @param current: The current position.
     * @param target: The destination position.
     * @param maxDistanceDelta: The maximum distance to move.
     * @return: A new vector.
     */
    static inline il2cppVector3 MoveTowards(il2cppVector3 current, il2cppVector3 target,
                                      float maxDistanceDelta);

    /**
     * Returns a new vector with magnitude of one.
     * @param v: The vector in question.
     * @return: A new vector.
     */
    static inline il2cppVector3 Normalized(il2cppVector3 v);

    /**
     * Returns an arbitrary vector orthogonal to the input.
     * This vector is not normalized.
     * @param v: The input vector.
     * @return: A new vector.
     */
    static inline il2cppVector3 Orthogonal(il2cppVector3 v);

    /**
     * Creates a new coordinate system out of the three vectors.
     * Normalizes "normal", normalizes "tangent" and makes it orthogonal to
     * "normal" and normalizes "binormal" and makes it orthogonal to both
     * "normal" and "tangent".
     * @param normal: A reference to the first axis vector.
     * @param tangent: A reference to the second axis vector.
     * @param binormal: A reference to the third axis vector.
     */
    static inline void OrthoNormalize(il2cppVector3 &normal, il2cppVector3 &tangent,
                                      il2cppVector3 &binormal);

    /**
     * Returns the vector projection of a onto b.
     * @param a: The target vector.
     * @param b: The vector being projected onto.
     * @return: A new vector.
     */
    static inline il2cppVector3 Project(il2cppVector3 a, il2cppVector3 b);

    /**
     * Returns a vector projected onto a plane orthogonal to "planeNormal".
     * This can be visualized as the shadow of the vector onto the plane, if
     * the light source were in the direction of the plane normal.
     * @param vector: The vector to project.
     * @param planeNormal: The normal of the plane onto which to project.
     * @param: A new vector.
     */
    static inline il2cppVector3 ProjectOnPlane(il2cppVector3 vector, il2cppVector3 planeNormal);

    /**
     * Returns a vector reflected off the plane orthogonal to the normal.
     * The input vector is pointed inward, at the plane, and the return vector
     * is pointed outward from the plane, like a beam of light hitting and then
     * reflecting off a mirror.
     * @param vector: The vector traveling inward at the plane.
     * @param planeNormal: The normal of the plane off of which to reflect.
     * @return: A new vector pointing outward from the plane.
     */
    static inline il2cppVector3 Reflect(il2cppVector3 vector, il2cppVector3 planeNormal);

    /**
     * Returns the vector rejection of a on b.
     * @param a: The target vector.
     * @param b: The vector being projected onto.
     * @return: A new vector.
     */
    static inline il2cppVector3 Reject(il2cppVector3 a, il2cppVector3 b);

    /**
     * Rotates vector "current" towards vector "target" by "maxRadiansDelta".
     * This treats the vectors as directions and will linearly interpolate
     * between their magnitudes by "maxMagnitudeDelta". This function does not
     * overshoot. If a negative delta is supplied, it will rotate away from
     * "target" until it is pointing the opposite direction, but will not
     * overshoot that either.
     * @param current: The starting direction.
     * @param target: The destination direction.
     * @param maxRadiansDelta: The maximum number of radians to rotate.
     * @param maxMagnitudeDelta: The maximum delta for magnitude interpolation.
     * @return: A new vector.
     */
    static inline il2cppVector3 RotateTowards(il2cppVector3 current, il2cppVector3 target,
                                        float maxRadiansDelta,
                                        float maxMagnitudeDelta);

    /**
     * Multiplies two vectors element-wise.
     * @param a: The lhs of the multiplication.
     * @param b: The rhs of the multiplication.
     * @return: A new vector.
     */
    static inline il2cppVector3 Scale(il2cppVector3 a, il2cppVector3 b);

    /**
     * Returns a vector rotated towards b from a by the percent t.
     * Since interpolation is done spherically, the vector moves at a constant
     * angular velocity. This rotation is clamped to 0 <= t <= 1.
     * @param a: The starting direction.
     * @param b: The ending direction.
     * @param t: The interpolation value [0-1].
     */
    static inline il2cppVector3 Slerp(il2cppVector3 a, il2cppVector3 b, float t);

    /**
     * Returns a vector rotated towards b from a by the percent t.
     * Since interpolation is done spherically, the vector moves at a constant
     * angular velocity. This rotation is unclamped.
     * @param a: The starting direction.
     * @param b: The ending direction.
     * @param t: The interpolation value [0-1].
     */
    static inline il2cppVector3 SlerpUnclamped(il2cppVector3 a, il2cppVector3 b, float t);

    /**
     * Returns the squared magnitude of a vector.
     * This is useful when comparing relative lengths, where the exact length
     * is not important, and much time can be saved by not calculating the
     * square root.
     * @param v: The vector in question.
     * @return: A scalar value.
     */
    static inline float SqrMagnitude(il2cppVector3 v);

    /**
     * Calculates the spherical coordinate space representation of a vector.
     * This uses the ISO convention (radius r, inclination theta, azimuth phi).
     * @param vector: The vector to convert.
     * @param rad: The magnitude of the vector.
     * @param theta: The angle in the XY plane from the X axis.
     * @param phi: The angle from the positive Z axis to the vector.
     */
    static inline void ToSpherical(il2cppVector3 vector, float &rad, float &theta,
                                   float &phi);


    /**
     * Operator overloading.
     */
    inline struct il2cppVector3& operator+=(const float rhs);
    inline struct il2cppVector3& operator-=(const float rhs);
    inline struct il2cppVector3& operator*=(const float rhs);
    inline struct il2cppVector3& operator/=(const float rhs);
    inline struct il2cppVector3& operator+=(const il2cppVector3 rhs);
    inline struct il2cppVector3& operator-=(const il2cppVector3 rhs);
};

inline il2cppVector3 operator-(il2cppVector3 rhs);
inline il2cppVector3 operator+(il2cppVector3 lhs, const float rhs);
inline il2cppVector3 operator-(il2cppVector3 lhs, const float rhs);
inline il2cppVector3 operator*(il2cppVector3 lhs, const float rhs);
inline il2cppVector3 operator/(il2cppVector3 lhs, const float rhs);
inline il2cppVector3 operator+(const float lhs, il2cppVector3 rhs);
inline il2cppVector3 operator-(const float lhs, il2cppVector3 rhs);
inline il2cppVector3 operator*(const float lhs, il2cppVector3 rhs);
inline il2cppVector3 operator/(const float lhs, il2cppVector3 rhs);
inline il2cppVector3 operator+(il2cppVector3 lhs, const il2cppVector3 rhs);
inline il2cppVector3 operator-(il2cppVector3 lhs, const il2cppVector3 rhs);
inline bool operator==(const il2cppVector3 lhs, const il2cppVector3 rhs);
inline bool operator!=(const il2cppVector3 lhs, const il2cppVector3 rhs);



/*******************************************************************************
 * Implementation
 */

il2cppVector3::il2cppVector3() : X(0), Y(0), Z(0) {}
il2cppVector3::il2cppVector3(float data[]) : X(data[0]), Y(data[1]), Z(data[2]) {}
il2cppVector3::il2cppVector3(float value) : X(value), Y(value), Z(value) {}
il2cppVector3::il2cppVector3(float x, float y) : X(x), Y(y), Z(0) {}
il2cppVector3::il2cppVector3(float x, float y, float z) : X(x), Y(y), Z(z) {}


il2cppVector3 il2cppVector3::Zero() { return il2cppVector3(0, 0, 0); }
il2cppVector3 il2cppVector3::One() { return il2cppVector3(1, 1, 1); }
il2cppVector3 il2cppVector3::Right() { return il2cppVector3(1, 0, 0); }
il2cppVector3 il2cppVector3::Left() { return il2cppVector3(-1, 0, 0); }
il2cppVector3 il2cppVector3::Up() { return il2cppVector3(0, 1, 0); }
il2cppVector3 il2cppVector3::Down() { return il2cppVector3(0, -1, 0); }
il2cppVector3 il2cppVector3::Forward() { return il2cppVector3(0, 0, 1); }
il2cppVector3 il2cppVector3::Backward() { return il2cppVector3(0, 0, -1); }


float il2cppVector3::Angle(il2cppVector3 a, il2cppVector3 b)
{
    float v = Dot(a, b) / (Magnitude(a) * Magnitude(b));
    v = fmax(v, -1.0);
    v = fmin(v, 1.0);
    return acos(v);
}

il2cppVector3 il2cppVector3::ClampMagnitude(il2cppVector3 vector, float maxLength)
{
    float length = Magnitude(vector);
    if (length > maxLength)
        vector *= maxLength / length;
    return vector;
}

float il2cppVector3::Component(il2cppVector3 a, il2cppVector3 b)
{
    return Dot(a, b) / Magnitude(b);
}

il2cppVector3 il2cppVector3::Cross(il2cppVector3 lhs, il2cppVector3 rhs)
{
    float x = lhs.Y * rhs.Z - lhs.Z * rhs.Y;
    float y = lhs.Z * rhs.X - lhs.X * rhs.Z;
    float z = lhs.X * rhs.Y - lhs.Y * rhs.X;
    return il2cppVector3(x, y, z);
}

float il2cppVector3::Distance(il2cppVector3 a, il2cppVector3 b)
{
    return il2cppVector3::Magnitude(a - b);
}

float il2cppVector3::Dot(il2cppVector3 lhs, il2cppVector3 rhs)
{
    return lhs.X * rhs.X + lhs.Y * rhs.Y + lhs.Z * rhs.Z;
}

il2cppVector3 il2cppVector3::FromSpherical(float rad, float theta, float phi)
{
    il2cppVector3 v;
    v.X = rad * sin(theta) * cos(phi);
    v.Y = rad * sin(theta) * sin(phi);
    v.Z = rad * cos(theta);
    return v;
}

il2cppVector3 il2cppVector3::Lerp(il2cppVector3 a, il2cppVector3 b, float t)
{
    if (t < 0) return a;
    else if (t > 1) return b;
    return LerpUnclamped(a, b, t);
}

il2cppVector3 il2cppVector3::LerpUnclamped(il2cppVector3 a, il2cppVector3 b, float t)
{
    return (b - a) * t + a;
}

float il2cppVector3::Magnitude(il2cppVector3 v)
{
    return sqrt(SqrMagnitude(v));
}

il2cppVector3 il2cppVector3::Max(il2cppVector3 a, il2cppVector3 b)
{
    float x = a.X > b.X ? a.X : b.X;
    float y = a.Y > b.Y ? a.Y : b.Y;
    float z = a.Z > b.Z ? a.Z : b.Z;
    return il2cppVector3(x, y, z);
}

il2cppVector3 il2cppVector3::Min(il2cppVector3 a, il2cppVector3 b)
{
    float x = a.X > b.X ? b.X : a.X;
    float y = a.Y > b.Y ? b.Y : a.Y;
    float z = a.Z > b.Z ? b.Z : a.Z;
    return il2cppVector3(x, y, z);
}

il2cppVector3 il2cppVector3::MoveTowards(il2cppVector3 current, il2cppVector3 target,
                             float maxDistanceDelta)
{
    il2cppVector3 d = target - current;
    float m = Magnitude(d);
    if (m < maxDistanceDelta || m == 0)
        return target;
    return current + (d * maxDistanceDelta / m);
}

il2cppVector3 il2cppVector3::Normalized(il2cppVector3 v)
{
    float mag = Magnitude(v);
    if (mag == 0)
        return il2cppVector3::Zero();
    return v / mag;
}

il2cppVector3 il2cppVector3::Orthogonal(il2cppVector3 v)
{
    return v.Z < v.X ? il2cppVector3(v.Y, -v.X, 0) : il2cppVector3(0, -v.Z, v.Y);
}

void il2cppVector3::OrthoNormalize(il2cppVector3 &normal, il2cppVector3 &tangent,
                             il2cppVector3 &binormal)
{
    normal = Normalized(normal);
    tangent = ProjectOnPlane(tangent, normal);
    tangent = Normalized(tangent);
    binormal = ProjectOnPlane(binormal, tangent);
    binormal = ProjectOnPlane(binormal, normal);
    binormal = Normalized(binormal);
}

il2cppVector3 il2cppVector3::Project(il2cppVector3 a, il2cppVector3 b)
{
    float m = Magnitude(b);
    return Dot(a, b) / (m * m) * b;
}

il2cppVector3 il2cppVector3::ProjectOnPlane(il2cppVector3 vector, il2cppVector3 planeNormal)
{
    return Reject(vector, planeNormal);
}

il2cppVector3 il2cppVector3::Reflect(il2cppVector3 vector, il2cppVector3 planeNormal)
{
    return vector - 2 * Project(vector, planeNormal);
}

il2cppVector3 il2cppVector3::Reject(il2cppVector3 a, il2cppVector3 b)
{
    return a - Project(a, b);
}

il2cppVector3 il2cppVector3::RotateTowards(il2cppVector3 current, il2cppVector3 target,
                               float maxRadiansDelta,
                               float maxMagnitudeDelta)
{
    float magCur = Magnitude(current);
    float magTar = Magnitude(target);
    float newMag = magCur + maxMagnitudeDelta *
                            ((magTar > magCur) - (magCur > magTar));
    newMag = fmin(newMag, fmax(magCur, magTar));
    newMag = fmax(newMag, fmin(magCur, magTar));

    float totalAngle = Angle(current, target) - maxRadiansDelta;
    if (totalAngle <= 0)
        return Normalized(target) * newMag;
    else if (totalAngle >= M_PI)
        return Normalized(-target) * newMag;

    il2cppVector3 axis = Cross(current, target);
    float magAxis = Magnitude(axis);
    if (magAxis == 0)
        axis = Normalized(Cross(current, current + il2cppVector3(3.95, 5.32, -4.24)));
    else
        axis /= magAxis;
    current = Normalized(current);
    il2cppVector3 newVector = current * cos(maxRadiansDelta) +
                        Cross(axis, current) * sin(maxRadiansDelta);
    return newVector * newMag;
}

il2cppVector3 il2cppVector3::Scale(il2cppVector3 a, il2cppVector3 b)
{
    return il2cppVector3(a.X * b.X, a.Y * b.Y, a.Z * b.Z);
}

il2cppVector3 il2cppVector3::Slerp(il2cppVector3 a, il2cppVector3 b, float t)
{
    if (t < 0) return a;
    else if (t > 1) return b;
    return SlerpUnclamped(a, b, t);
}

il2cppVector3 il2cppVector3::SlerpUnclamped(il2cppVector3 a, il2cppVector3 b, float t)
{
    float magA = Magnitude(a);
    float magB = Magnitude(b);
    a /= magA;
    b /= magB;
    float dot = Dot(a, b);
    dot = fmax(dot, -1.0);
    dot = fmin(dot, 1.0);
    float theta = acos(dot) * t;
    il2cppVector3 relativeVec = Normalized(b - a * dot);
    il2cppVector3 newVec = a * cos(theta) + relativeVec * sin(theta);
    return newVec * (magA + (magB - magA) * t);
}

float il2cppVector3::SqrMagnitude(il2cppVector3 v)
{
    return v.X * v.X + v.Y * v.Y + v.Z * v.Z;
}

void il2cppVector3::ToSpherical(il2cppVector3 vector, float &rad, float &theta,
                          float &phi)
{
    rad = Magnitude(vector);
    float v = vector.Z / rad;
    v = fmax(v, -1.0);
    v = fmin(v, 1.0);
    theta = acos(v);
    phi = atan2(vector.Y, vector.X);
}


struct il2cppVector3& il2cppVector3::operator+=(const float rhs)
{
    X += rhs;
    Y += rhs;
    Z += rhs;
    return *this;
}

struct il2cppVector3& il2cppVector3::operator-=(const float rhs)
{
    X -= rhs;
    Y -= rhs;
    Z -= rhs;
    return *this;
}

struct il2cppVector3& il2cppVector3::operator*=(const float rhs)
{
    X *= rhs;
    Y *= rhs;
    Z *= rhs;
    return *this;
}

struct il2cppVector3& il2cppVector3::operator/=(const float rhs)
{
    X /= rhs;
    Y /= rhs;
    Z /= rhs;
    return *this;
}

struct il2cppVector3& il2cppVector3::operator+=(const il2cppVector3 rhs)
{
    X += rhs.X;
    Y += rhs.Y;
    Z += rhs.Z;
    return *this;
}

struct il2cppVector3& il2cppVector3::operator-=(const il2cppVector3 rhs)
{
    X -= rhs.X;
    Y -= rhs.Y;
    Z -= rhs.Z;
    return *this;
}

char il2cppVector3::ToChar(il2cppVector3 a) {
    const char* x = (const char*)(int)a.X;
    const char* y = (const char*)(int)a.Y;
    const char* z = (const char*)(int)a.Z;
    char buffer[25];
    strncpy(buffer, x, sizeof(buffer));
    strncpy(buffer, ", ", sizeof(buffer));
    strncpy(buffer, y, sizeof(buffer));
    strncpy(buffer, ", ", sizeof(buffer));
    strncpy(buffer, z, sizeof(buffer));
    strncpy(buffer, ", ", sizeof(buffer));
    return buffer[24];
}

il2cppVector3 operator-(il2cppVector3 rhs) { return rhs * -1; }
il2cppVector3 operator+(il2cppVector3 lhs, const float rhs) { return lhs += rhs; }
il2cppVector3 operator-(il2cppVector3 lhs, const float rhs) { return lhs -= rhs; }
il2cppVector3 operator*(il2cppVector3 lhs, const float rhs) { return lhs *= rhs; }
il2cppVector3 operator/(il2cppVector3 lhs, const float rhs) { return lhs /= rhs; }
il2cppVector3 operator+(const float lhs, il2cppVector3 rhs) { return rhs += lhs; }
il2cppVector3 operator-(const float lhs, il2cppVector3 rhs) { return rhs -= lhs; }
il2cppVector3 operator*(const float lhs, il2cppVector3 rhs) { return rhs *= lhs; }
il2cppVector3 operator/(const float lhs, il2cppVector3 rhs) { return rhs /= lhs; }
il2cppVector3 operator+(il2cppVector3 lhs, const il2cppVector3 rhs) { return lhs += rhs; }
il2cppVector3 operator-(il2cppVector3 lhs, const il2cppVector3 rhs) { return lhs -= rhs; }

bool operator==(const il2cppVector3 lhs, const il2cppVector3 rhs)
{
    return lhs.X == rhs.X && lhs.Y == rhs.Y && lhs.Z == rhs.Z;
}

bool operator!=(const il2cppVector3 lhs, const il2cppVector3 rhs)
{
    return !(lhs == rhs);
}