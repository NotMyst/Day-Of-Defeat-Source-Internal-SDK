#pragma once
#include <limits>

struct Vector
{
public:
	float x, y, z;

	Vector(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	Vector()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	Vector ToAngle()
	{
		return Vector{
			std::atan2(-z, std::hypot(x, y)) * (180.0f / std::numbers::pi_v<float>),
			std::atan2(y, x) * (180.0f / std::numbers::pi_v<float>),
			0.0f };
	}

	float Length2D(void)
	{
		return sqrtf(x * x + y * y);
	}

	float Dot(Vector v)
	{
		return (x * v.x + y * v.y + z * v.z);
	}

	float Length(void)
	{
		return sqrtf(x * x + y * y + z * z);
	}

	Vector operator+(Vector other)
	{
		return Vector(x + other.x, y + other.y, z + other.z);
	}

	

	Vector operator-(const Vector other)
	{
		return Vector(x - other.x, y - other.y, z - other.z);
	}

	const Vector operator*(const float factor)
	{
		return Vector(x * factor, y * factor, z * factor);
	}

	void operator/=(Vector other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
	}

	void Normalize()
	{
		float div = Length() + std::numeric_limits<float>::epsilon();
		x /= div;
		y /= div;
		z /= div;
	}

	inline bool IsZero()
	{
		return x == 0 && y == 0 && z == 0;
	}

	inline operator bool()
	{
		return !(IsZero());
	}

	inline Vector operator/(int div)
	{
		return Vector(x / div, y / div, z / div);
	}

	float LengthSqr(void)
	{
		return x * x + y * y + z * z;
	}


};

typedef Vector QAngle;

struct Vector2D
{
public:
	float x, y;
};

struct matrix3x4_t
{
public:
	float m_value[3][4];

	inline Vector Origin()
	{
		return Vector{ m_value[0][3], m_value[1][3], m_value[2][3] };
	}
};

#define DECL_ALIGN(x) __declspec(align(x))

// tier0/platform.h, fix this if you dont use MSVC!!
#ifdef _MSC_VER
#define ALIGN4 DECL_ALIGN(4)
#define ALIGN8 DECL_ALIGN(8)
#define ALIGN16 DECL_ALIGN(16)
#define ALIGN32 DECL_ALIGN(32)
#define ALIGN128 DECL_ALIGN(128)

#define ALIGN4_POST
#define ALIGN8_POST
#define ALIGN16_POST
#define ALIGN32_POST
#define ALIGN128_POST
#endif

class ALIGN16 VectorAligned : public Vector
{
public:
	inline VectorAligned(void) {};
	inline VectorAligned(float X, float Y, float Z)
	{
		x = X;
		y = Y;
		z = Z;
	}

	explicit VectorAligned(const Vector& vOther)
	{
		x = vOther.x;
		y = vOther.y;
		z = vOther.z;
	}

	VectorAligned& operator=(const Vector& vOther)
	{
		x = vOther.x;
		y = vOther.y;
		z = vOther.z;
		return *this;
	}

	float w;
} ALIGN16_POST;