//
// Created by lbert on 2/6/2023.
//

#ifndef ZYGISKPG_UNITY_H
#define ZYGISKPG_UNITY_H

#include <codecvt>
#include <math.h>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <locale>
#include <string>

struct il2cppVector2
{
    union
    {
        struct
        {
            float X;
            float Y;
        };
        float data[2];
    };


    /**
     * Constructors.
     */
    inline il2cppVector2();
    inline il2cppVector2(float data[]);
    inline il2cppVector2(float value);
    inline il2cppVector2(float x, float y);


    /**
     * Constants for common vectors.
     */
    static inline il2cppVector2 Zero();
    static inline il2cppVector2 One();
    static inline il2cppVector2 Right();
    static inline il2cppVector2 Left();
    static inline il2cppVector2 Up();
    static inline il2cppVector2 Down();


    /**
     * Returns the angle between two vectors in radians.
     * @param a: The first vector.
     * @param b: The second vector.
     * @return: A scalar value.
     */
    static inline float Angle(il2cppVector2 a, il2cppVector2 b);

    /**
     * Returns a vector with its magnitude clamped to maxLength.
     * @param vector: The target vector.
     * @param maxLength: The maximum length of the return vector.
     * @return: A new vector.
     */
    static inline il2cppVector2 ClampMagnitude(il2cppVector2 vector, float maxLength);

    /**
     * Returns the component of a in the direction of b (scalar projection).
     * @param a: The target vector.
     * @param b: The vector being compared against.
     * @return: A scalar value.
     */
    static inline float Component(il2cppVector2 a, il2cppVector2 b);

    /**
     * Returns the distance between a and b.
     * @param a: The first point.
     * @param b: The second point.
     * @return: A scalar value.
     */
    static inline float Distance(il2cppVector2 a, il2cppVector2 b);

    /**
     * Returns the dot product of two vectors.
     * @param lhs: The left side of the multiplication.
     * @param rhs: The right side of the multiplication.
     * @return: A scalar value.
     */
    static inline float Dot(il2cppVector2 lhs, il2cppVector2 rhs);

    /**
     * Converts a polar representation of a vector into cartesian
     * coordinates.
     * @param rad: The magnitude of the vector.
     * @param theta: The angle from the X axis.
     * @return: A new vector.
     */
    static inline il2cppVector2 FromPolar(float rad, float theta);

    /**
     * Returns a vector linearly interpolated between a and b, moving along
     * a straight line. The vector is clamped to never go beyond the end points.
     * @param a: The starting point.
     * @param b: The ending point.
     * @param t: The interpolation value [0-1].
     * @return: A new vector.
     */
    static inline il2cppVector2 Lerp(il2cppVector2 a, il2cppVector2 b, float t);

    /**
     * Returns a vector linearly interpolated between a and b, moving along
     * a straight line.
     * @param a: The starting point.
     * @param b: The ending point.
     * @param t: The interpolation value [0-1] (no actual bounds).
     * @return: A new vector.
     */
    static inline il2cppVector2 LerpUnclamped(il2cppVector2 a, il2cppVector2 b, float t);

    /**
     * Returns the magnitude of a vector.
     * @param v: The vector in question.
     * @return: A scalar value.
     */
    static inline float Magnitude(il2cppVector2 v);

    /**
     * Returns a vector made from the largest components of two other vectors.
     * @param a: The first vector.
     * @param b: The second vector.
     * @return: A new vector.
     */
    static inline il2cppVector2 Max(il2cppVector2 a, il2cppVector2 b);

    /**
     * Returns a vector made from the smallest components of two other vectors.
     * @param a: The first vector.
     * @param b: The second vector.
     * @return: A new vector.
     */
    static inline il2cppVector2 Min(il2cppVector2 a, il2cppVector2 b);

    /**
     * Returns a vector "maxDistanceDelta" units closer to the target. This
     * interpolation is in a straight line, and will not overshoot.
     * @param current: The current position.
     * @param target: The destination position.
     * @param maxDistanceDelta: The maximum distance to move.
     * @return: A new vector.
     */
    static inline il2cppVector2 MoveTowards(il2cppVector2 current, il2cppVector2 target,
                                      float maxDistanceDelta);

    /**
     * Returns a new vector with magnitude of one.
     * @param v: The vector in question.
     * @return: A new vector.
     */
    static inline il2cppVector2 Normalized(il2cppVector2 v);

    /**
     * Creates a new coordinate system out of the two vectors.
     * Normalizes "normal" and normalizes "tangent" and makes it orthogonal to
     * "normal"..
     * @param normal: A reference to the first axis vector.
     * @param tangent: A reference to the second axis vector.
     */
    static inline void OrthoNormalize(il2cppVector2 &normal, il2cppVector2 &tangent);

    /**
     * Returns the vector projection of a onto b.
     * @param a: The target vector.
     * @param b: The vector being projected onto.
     * @return: A new vector.
     */
    static inline il2cppVector2 Project(il2cppVector2 a, il2cppVector2 b);

    /**
     * Returns a vector reflected about the provided line.
     * This behaves as if there is a plane with the line as its normal, and the
     * vector comes in and bounces off this plane.
     * @param vector: The vector traveling inward at the imaginary plane.
     * @param line: The line about which to reflect.
     * @return: A new vector pointing outward from the imaginary plane.
     */
    static inline il2cppVector2 Reflect(il2cppVector2 vector, il2cppVector2 line);

    /**
     * Returns the vector rejection of a on b.
     * @param a: The target vector.
     * @param b: The vector being projected onto.
     * @return: A new vector.
     */
    static inline il2cppVector2 Reject(il2cppVector2 a, il2cppVector2 b);

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
    static inline il2cppVector2 RotateTowards(il2cppVector2 current, il2cppVector2 target,
                                        float maxRadiansDelta,
                                        float maxMagnitudeDelta);

    /**
     * Multiplies two vectors component-wise.
     * @param a: The lhs of the multiplication.
     * @param b: The rhs of the multiplication.
     * @return: A new vector.
     */
    static inline il2cppVector2 Scale(il2cppVector2 a, il2cppVector2 b);

    /**
     * Returns a vector rotated towards b from a by the percent t.
     * Since interpolation is done spherically, the vector moves at a constant
     * angular velocity. This rotation is clamped to 0 <= t <= 1.
     * @param a: The starting direction.
     * @param b: The ending direction.
     * @param t: The interpolation value [0-1].
     */
    static inline il2cppVector2 Slerp(il2cppVector2 a, il2cppVector2 b, float t);

    /**
     * Returns a vector rotated towards b from a by the percent t.
     * Since interpolation is done spherically, the vector moves at a constant
     * angular velocity. This rotation is unclamped.
     * @param a: The starting direction.
     * @param b: The ending direction.
     * @param t: The interpolation value [0-1].
     */
    static inline il2cppVector2 SlerpUnclamped(il2cppVector2 a, il2cppVector2 b, float t);

    /**
     * Returns the squared magnitude of a vector.
     * This is useful when comparing relative lengths, where the exact length
     * is not important, and much time can be saved by not calculating the
     * square root.
     * @param v: The vector in question.
     * @return: A scalar value.
     */
    static inline float SqrMagnitude(il2cppVector2 v);

    /**
     * Calculates the polar coordinate space representation of a vector.
     * @param vector: The vector to convert.
     * @param rad: The magnitude of the vector.
     * @param theta: The angle from the X axis.
     */
    static inline void ToPolar(il2cppVector2 vector, float &rad, float &theta);


    /**
     * Operator overloading.
     */
    inline struct il2cppVector2& operator+=(const float rhs);
    inline struct il2cppVector2& operator-=(const float rhs);
    inline struct il2cppVector2& operator*=(const float rhs);
    inline struct il2cppVector2& operator/=(const float rhs);
    inline struct il2cppVector2& operator+=(const il2cppVector2 rhs);
    inline struct il2cppVector2& operator-=(const il2cppVector2 rhs);
};

inline il2cppVector2 operator-(il2cppVector2 rhs);
inline il2cppVector2 operator+(il2cppVector2 lhs, const float rhs);
inline il2cppVector2 operator-(il2cppVector2 lhs, const float rhs);
inline il2cppVector2 operator*(il2cppVector2 lhs, const float rhs);
inline il2cppVector2 operator/(il2cppVector2 lhs, const float rhs);
inline il2cppVector2 operator+(const float lhs, il2cppVector2 rhs);
inline il2cppVector2 operator-(const float lhs, il2cppVector2 rhs);
inline il2cppVector2 operator*(const float lhs, il2cppVector2 rhs);
inline il2cppVector2 operator/(const float lhs, il2cppVector2 rhs);
inline il2cppVector2 operator+(il2cppVector2 lhs, const il2cppVector2 rhs);
inline il2cppVector2 operator-(il2cppVector2 lhs, const il2cppVector2 rhs);
inline bool operator==(const il2cppVector2 lhs, const il2cppVector2 rhs);
inline bool operator!=(const il2cppVector2 lhs, const il2cppVector2 rhs);



/*******************************************************************************
 * Implementation
 */

il2cppVector2::il2cppVector2() : X(0), Y(0) {}
il2cppVector2::il2cppVector2(float data[]) : X(data[0]), Y(data[1]) {}
il2cppVector2::il2cppVector2(float value) : X(value), Y(value) {}
il2cppVector2::il2cppVector2(float x, float y) : X(x), Y(y) {}


il2cppVector2 il2cppVector2::Zero() { return il2cppVector2(0, 0); }
il2cppVector2 il2cppVector2::One() { return il2cppVector2(1, 1); }
il2cppVector2 il2cppVector2::Right() { return il2cppVector2(1, 0); }
il2cppVector2 il2cppVector2::Left() { return il2cppVector2(-1, 0); }
il2cppVector2 il2cppVector2::Up() { return il2cppVector2(0, 1); }
il2cppVector2 il2cppVector2::Down() { return il2cppVector2(0, -1); }


float il2cppVector2::Angle(il2cppVector2 a, il2cppVector2 b)
{
    float v = Dot(a, b) / (Magnitude(a) * Magnitude(b));
    v = fmax(v, -1.0);
    v = fmin(v, 1.0);
    return acos(v);
}

il2cppVector2 il2cppVector2::ClampMagnitude(il2cppVector2 vector, float maxLength)
{
    float length = Magnitude(vector);
    if (length > maxLength)
        vector *= maxLength / length;
    return vector;
}

float il2cppVector2::Component(il2cppVector2 a, il2cppVector2 b)
{
    return Dot(a, b) / Magnitude(b);
}

float il2cppVector2::Distance(il2cppVector2 a, il2cppVector2 b)
{
    return il2cppVector2::Magnitude(a - b);
}

float il2cppVector2::Dot(il2cppVector2 lhs, il2cppVector2 rhs)
{
    return lhs.X * rhs.X + lhs.Y * rhs.Y;
}

il2cppVector2 il2cppVector2::FromPolar(float rad, float theta)
{
    il2cppVector2 v;
    v.X = rad * cos(theta);
    v.Y = rad * sin(theta);
    return v;
}

il2cppVector2 il2cppVector2::Lerp(il2cppVector2 a, il2cppVector2 b, float t)
{
    if (t < 0) return a;
    else if (t > 1) return b;
    return LerpUnclamped(a, b, t);
}

il2cppVector2 il2cppVector2::LerpUnclamped(il2cppVector2 a, il2cppVector2 b, float t)
{
    return (b - a) * t + a;
}

float il2cppVector2::Magnitude(il2cppVector2 v)
{
    return sqrt(SqrMagnitude(v));
}

il2cppVector2 il2cppVector2::Max(il2cppVector2 a, il2cppVector2 b)
{
    float x = a.X > b.X ? a.X : b.X;
    float y = a.Y > b.Y ? a.Y : b.Y;
    return il2cppVector2(x, y);
}

il2cppVector2 il2cppVector2::Min(il2cppVector2 a, il2cppVector2 b)
{
    float x = a.X > b.X ? b.X : a.X;
    float y = a.Y > b.Y ? b.Y : a.Y;
    return il2cppVector2(x, y);
}

il2cppVector2 il2cppVector2::MoveTowards(il2cppVector2 current, il2cppVector2 target,
                             float maxDistanceDelta)
{
    il2cppVector2 d = target - current;
    float m = Magnitude(d);
    if (m < maxDistanceDelta || m == 0)
        return target;
    return current + (d * maxDistanceDelta / m);
}

il2cppVector2 il2cppVector2::Normalized(il2cppVector2 v)
{
    float mag = Magnitude(v);
    if (mag == 0)
        return il2cppVector2::Zero();
    return v / mag;
}

void il2cppVector2::OrthoNormalize(il2cppVector2 &normal, il2cppVector2 &tangent)
{
    normal = Normalized(normal);
    tangent = Reject(tangent, normal);
    tangent = Normalized(tangent);
}

il2cppVector2 il2cppVector2::Project(il2cppVector2 a, il2cppVector2 b)
{
    float m = Magnitude(b);
    return Dot(a, b) / (m * m) * b;
}

il2cppVector2 il2cppVector2::Reflect(il2cppVector2 vector, il2cppVector2 planeNormal)
{
    return vector - 2 * Project(vector, planeNormal);
}

il2cppVector2 il2cppVector2::Reject(il2cppVector2 a, il2cppVector2 b)
{
    return a - Project(a, b);
}

il2cppVector2 il2cppVector2::RotateTowards(il2cppVector2 current, il2cppVector2 target,
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

    float axis = current.X * target.Y - current.Y * target.X;
    axis = axis / fabs(axis);
    if (!(1 - fabs(axis) < 0.00001))
        axis = 1;
    current = Normalized(current);
    il2cppVector2 newVector = current * cos(maxRadiansDelta) +
                        il2cppVector2(-current.Y, current.X) * sin(maxRadiansDelta) * axis;
    return newVector * newMag;
}

il2cppVector2 il2cppVector2::Scale(il2cppVector2 a, il2cppVector2 b)
{
    return il2cppVector2(a.X * b.X, a.Y * b.Y);
}

il2cppVector2 il2cppVector2::Slerp(il2cppVector2 a, il2cppVector2 b, float t)
{
    if (t < 0) return a;
    else if (t > 1) return b;
    return SlerpUnclamped(a, b, t);
}

il2cppVector2 il2cppVector2::SlerpUnclamped(il2cppVector2 a, il2cppVector2 b, float t)
{
    float magA = Magnitude(a);
    float magB = Magnitude(b);
    a /= magA;
    b /= magB;
    float dot = Dot(a, b);
    dot = fmax(dot, -1.0);
    dot = fmin(dot, 1.0);
    float theta = acos(dot) * t;
    il2cppVector2 relativeVec = Normalized(b - a * dot);
    il2cppVector2 newVec = a * cos(theta) + relativeVec * sin(theta);
    return newVec * (magA + (magB - magA) * t);
}

float il2cppVector2::SqrMagnitude(il2cppVector2 v)
{
    return v.X * v.X + v.Y * v.Y;
}

void il2cppVector2::ToPolar(il2cppVector2 vector, float &rad, float &theta)
{
    rad = Magnitude(vector);
    theta = atan2(vector.Y, vector.X);
}


struct il2cppVector2& il2cppVector2::operator+=(const float rhs)
{
    X += rhs;
    Y += rhs;
    return *this;
}

struct il2cppVector2& il2cppVector2::operator-=(const float rhs)
{
    X -= rhs;
    Y -= rhs;
    return *this;
}

struct il2cppVector2& il2cppVector2::operator*=(const float rhs)
{
    X *= rhs;
    Y *= rhs;
    return *this;
}

struct il2cppVector2& il2cppVector2::operator/=(const float rhs)
{
    X /= rhs;
    Y /= rhs;
    return *this;
}

struct il2cppVector2& il2cppVector2::operator+=(const il2cppVector2 rhs)
{
    X += rhs.X;
    Y += rhs.Y;
    return *this;
}

struct il2cppVector2& il2cppVector2::operator-=(const il2cppVector2 rhs)
{
    X -= rhs.X;
    Y -= rhs.Y;
    return *this;
}

il2cppVector2 operator-(il2cppVector2 rhs) { return rhs * -1; }
il2cppVector2 operator+(il2cppVector2 lhs, const float rhs) { return lhs += rhs; }
il2cppVector2 operator-(il2cppVector2 lhs, const float rhs) { return lhs -= rhs; }
il2cppVector2 operator*(il2cppVector2 lhs, const float rhs) { return lhs *= rhs; }
il2cppVector2 operator/(il2cppVector2 lhs, const float rhs) { return lhs /= rhs; }
il2cppVector2 operator+(const float lhs, il2cppVector2 rhs) { return rhs += lhs; }
il2cppVector2 operator-(const float lhs, il2cppVector2 rhs) { return rhs -= lhs; }
il2cppVector2 operator*(const float lhs, il2cppVector2 rhs) { return rhs *= lhs; }
il2cppVector2 operator/(const float lhs, il2cppVector2 rhs) { return rhs /= lhs; }
il2cppVector2 operator+(il2cppVector2 lhs, const il2cppVector2 rhs) { return lhs += rhs; }
il2cppVector2 operator-(il2cppVector2 lhs, const il2cppVector2 rhs) { return lhs -= rhs; }

bool operator==(const il2cppVector2 lhs, const il2cppVector2 rhs)
{
    return lhs.X == rhs.X && lhs.Y == rhs.Y;
}

bool operator!=(const il2cppVector2 lhs, const il2cppVector2 rhs)
{
    return !(lhs == rhs);
}

/*
This struct can hold a native C# array. Credits to caoyin.
Think of it like a wrapper for a C array. For example, if you had Player[] players in a dump,
the resulting il2cppArray definition would be il2cppArray<void **> *players;
To get the C array, call getPointer.
To get the length, call getLength.
*/
template <typename T>
struct il2cppArray
{
    void* klass;
    void* monitor;
    void* bounds;
    int   max_length;
    void* vector [1];
    int getLength()
    {
        return max_length;
    }
    T getPointer()
    {
        return (T)vector;
    }
    void foreach(std::function<void(T, int)> func) {
        for(int i = 0; i < max_length; ++i) {
            func((T)vector[i], i);
        }
    }
};

template <typename T>
struct monoArray
{
    void* klass;
    void* monitor;
    void* bounds;
    int   max_length;
    T vector[65535];

    T &operator [] (int i)
    {
        return vector[i];
    }

    const T &operator [] (int i) const
    {
        return vector[i];
    }

    bool Contains(T item)
    {
        for (int i = 0; i < max_length; i++)
        {
            if(vector[i] == item) return true;
        }
        return false;
    }
};

template<typename T>
using Array = monoArray<T>;

struct Vector4
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
    };

    inline Vector4(float x, float y, float z, float w);
};

Vector4::Vector4(float x, float y, float z, float w) : X(x), Y(y), Z(z), W(w){}

inline bool operator==(const Vector4 lhs, const Vector4 rhs);
bool operator==(const Vector4 lhs, const Vector4 rhs)
{
    return lhs.X == rhs.X && lhs.Y == rhs.Y && lhs.Z == rhs.Z && lhs.W == rhs.W;
}

struct il2cppString {
private:
    void *klass;
    void *monitor;
    int length;
    char16_t chars[1];

public:
    inline static il2cppString* Ctor(const char* str) {
        return (il2cppString*)il2cpp_string_new(str);
    }
    inline static il2cppString* Ctor(const std::string& str) {
        return (il2cppString*)il2cpp_string_new(str.c_str());
    }

    std::string getString() const {
        std::u16string u16 = std::u16string(chars);
        std::string u8_conv = std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t>{}.to_bytes(u16);
        return u8_conv;
    }

    const char* getChars() const { return getString().c_str(); }
    int getLength() const { return length; }

    bool equals(const il2cppString* other) const {
        return getString() == other->getString();
    }

    il2cppString* append(const il2cppString* other) {
        std::string combined = getString() + other->getString();
        return Ctor(combined);
    }

    il2cppString* assign(const il2cppString* other) {
	    std::memcpy(this, other, sizeof(il2cppString)); // please god please forgive me for the sins i have commited :sob:
        return this;
    }
};

typedef struct _monoDecimal
{
    void *klass;
    void *monitor;

}monoDecimal;

/*
This struct represents a List. In the dump, a List is declared as List`1.
Deep down, this simply wraps a C array around a C# list. For example, if you had this in a dump,
public class Player {
	List`1<int> perks; // 0xDC
}
getting that list would look like this: il2cppList<int *> *perks = *(il2cppList<int *> **)((uint64_t)player + 0xdc);
You can also get lists that hold objects, but you need to use void ** because we don't have implementation for the Weapon class.
public class Player {
	List`1<Weapon> weapons; // 0xDC
}
getting that list would look like this: il2cppList<void **> *weapons = *(il2cppList<void **> **)((uint64_t)player + 0xdc);
If you need a list of strings, use il2cppString **.
To get the C array, call getItems.
To get the size of a il2cppList, call getSize.
*/
template <typename T>
struct il2cppList {
    void *unk0;
    void *unk1;
    il2cppArray<T> *items;
    int size;
    int version;

    T getItems(){
        return items->getPointer();
    }

    int getSize(){
        return size;
    }

    int getVersion(){
        return version;
    }

    void foreach(std::function<void(T, int)> func) {
        for(int i = 0; i < size; ++i) {
            func((T)items->getPointer()[i], i);
        }
    }
};

/*
This struct represents a Dictionary. In the dump, a Dictionary is defined as Dictionary`1.
You could think of this as a Map in Java or C++. Keys correspond with values. This wraps the C arrays for keys and values.
If you had this in a dump,
public class GameManager {
	public Dictionary`1<int, Player> players; // 0xB0
	public Dictionary`1<Weapon, Player> playerWeapons; // 0xB8
	public Dictionary`1<Player, string> playerNames; // 0xBC
}
to get players, it would look like this: monoDictionary<int *, void **> *players = *(monoDictionary<int *, void **> **)((uint64_t)player + 0xb0);
to get playerWeapons, it would look like this: monoDictionary<void **, void **> *playerWeapons = *(monoDictionary<void **, void **> **)((uint64_t)player + 0xb8);
to get playerNames, it would look like this: monoDictionary<void **, il2cppString **> *playerNames = *(monoDictionary<void **, il2cppString **> **)((uint64_t)player + 0xbc);
To get the C array of keys, call getKeys.
To get the C array of values, call getValues.
To get the number of keys, call getNumKeys.
To get the number of values, call getNumValues.
*/

template<typename TKey, typename TValue>
struct monoDictionary
{
    struct KeysCollection;
    struct ValueCollection;

    struct Entry
    {
        int hashCode;
        int next;
        TKey key;
        TValue value;
    };

    void *kass;
    void *monitor;
    monoArray<int> *buckets;
    monoArray<Entry> *entries;
    int count;
    int version;
    int freeList;
    int freeCount;
    void* comparer;
    KeysCollection *keys;
    ValueCollection *values;
    void *_syncRoot;

    void* get_Comparer()
    {
        return comparer;
    }

    int get_Count()
    {
        return count;
    }

    KeysCollection get_Keys()
    {
        if(!keys) keys = new KeysCollection(this);
        return (*keys);
    }

    ValueCollection get_Values()
    {
        if(!values) values = new ValueCollection(this);
        return (*values);
    }

    TValue operator [] (TKey key)
    {
        int i = FindEntry(key);
        if (i >= 0) return (*entries)[i].value;
        return TValue();
    }

    const TValue operator [] (TKey key) const
    {
        int i = FindEntry(key);
        if (i >= 0) return (*entries)[i].value;
        return TValue();
    }

    int FindEntry(TKey key)
    {
        for (int i = 0; i < count; i++)
        {
            if((*entries)[i].key == key) return i;
        }
        return -1;
    }

    bool ContainsKey(TKey key)
    {
        return FindEntry(key) >= 0;
    }

    bool ContainsValue(TValue value)
    {
        for (int i = 0; i < count; i++)
        {
            if((*entries)[i].hashCode >= 0 &&
               (*entries)[i].value == value) return true;
        }
        return false;
    }

    bool TryGetValue(TKey key, TValue *value)
    {
        int i = FindEntry(key);
        if (i >= 0) {
            *value = (*entries)[i].value;
            return true;
        }
        *value = TValue();
        return false;
    }

    TValue GetValueOrDefault(TKey key)
    {
        int i = FindEntry(key);
        if (i >= 0) {
            return (*entries)[i].value;
        }
        return TValue();
    }

    struct KeysCollection
    {
        monoDictionary *dictionary;

        KeysCollection(monoDictionary *dictionary)
        {
            this->dictionary = dictionary;
        }

        TKey operator [] (int i)
        {
            auto entries = dictionary->entries;
            if(!entries) return TKey();
            return (*entries)[i].key;
        }

        const TKey operator [] (int i) const
        {
            auto entries = dictionary->entries;
            if(!entries) return TKey();
            return (*entries)[i].key;
        }

        int get_Count()
        {
            return dictionary->get_Count();
        }
    };

    struct ValueCollection
    {
        monoDictionary *dictionary;

        ValueCollection(monoDictionary *dictionary)
        {
            this->dictionary = dictionary;
        }

        TValue operator [] (int i)
        {
            auto entries = dictionary->entries;
            if(!entries) return TValue();
            return (*entries)[i].value;
        }

        const TValue operator [] (int i) const
        {
            auto entries = dictionary->entries;
            if(!entries) return TValue();
            return (*entries)[i].value;
        }

        int get_Count()
        {
            return dictionary->get_Count();
        }
    };
};

int GetObscuredIntValue(uint64_t location){
    int cryptoKey = *(int *)location;
    int obfuscatedValue = *(int *)(location + 0x4);

    return obfuscatedValue ^ cryptoKey;
}
bool GetObscuredBoolValue(uint64_t location){
    int cryptoKey = *(int *)location;
    int obfuscatedValue = *(int *)(location + 0x4);

    return (bool)obfuscatedValue ^ cryptoKey;
}
/*
Set the real value of an ObscuredInt.
Parameters:
	- location: the location of the ObscuredInt
	- value: the value we're setting the ObscuredInt to
*/
void SetObscuredIntValue(uint64_t location, int value){
    int cryptoKey = *(int *)location;

    *(int *)(location + 0x4) = value ^ cryptoKey;
}
void SetObscuredBoolValue(uint64_t location, bool value){
    int cryptoKey = *(int *)location;

    *(int *)(location + 0x4) = value ^ cryptoKey;
}
/*
Get the real value of an ObscuredFloat.
Parameters:
	- location: the location of the ObscuredFloat
*/
float GetObscuredFloatValue(uint64_t location)
{
    int cryptoKey = *(int *) location;
    int obfuscatedValue = *(int *) (location + 0x4);

    union intfloat
    {
        int i;
        float f;
    };

    /* use this intfloat to set the integer representation of our parameter value, which will also set the float value */
    intfloat IF;
    IF.i = obfuscatedValue ^ cryptoKey;

    return IF.f;
}

/*
Set the real value of an ObscuredFloat.
Parameters:
	- location: the location of the ObscuredFloat
	- value: the value we're setting the ObscuredFloat to
*/
void SetObscuredFloatValue(uint64_t location, float value) {
    int cryptoKey = *(int *) location;

    union intfloat {
        int i;
        float f;
    };

    /* use this intfloat to get the integer representation of our parameter value */
    intfloat IF;
    IF.f = value;

    /* use this intfloat to generate our hacked ObscuredFloat */
    intfloat IF2;
    IF2.i = IF.i ^ cryptoKey;

    *(float *) (location + 0x4) = IF2.f;
}

#endif //ZYGISKPG_UNITY_H
