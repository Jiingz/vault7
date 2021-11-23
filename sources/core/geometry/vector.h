#pragma once
#include <string>
#include <DirectXMath.h>
#define _USE_MATH_DEFINES
#include <math.h>
#define NULLVECTOR4 Vector4(0, 0, 0, 0)
#define NULLVECTOR3 Vector3(0, 0, 0)
#define NULLVECTOR2 Vector2(0, 0)

struct Vector4
{
	float X, Y, Z, W;

	Vector4()
	{
		X = 0.0f;
		Y = 0.0f;
		Z = 0.0f;
		W = 0.0f;
	}

	Vector4(const float x, const float y, const float z, const float w)
	{
		X = x;
		Y = y;
		Z = z;
		W = w;
	}

	Vector4 operator +(const float A) const
	{
		return Vector4(A + X, A + Y, A + Z, A + W);
	}

	Vector4 operator +(const Vector4& A) const
	{
		return Vector4(A.X + X, A.Y + Y, A.Z + Z, A.W + W);
	}

	Vector4 operator *(const float A) const
	{
		return Vector4(A * X, A * Y, A * Z, A * W);
	}

	Vector4 operator *(const Vector4& A) const
	{
		return Vector4(A.X * X, A.Y * Y, A.Z * Z, A.W * W);
	}

	Vector4 operator -(const float A) const
	{
		return Vector4(A * X, A * Y, A * Z, A * W);
	}

	Vector4 operator -(const Vector4& A) const
	{
		return Vector4(A.X - X, A.Y - Y, A.Z - Z, A.W - W);
	}

	Vector4 operator /(const float A) const
	{
		return Vector4(A / X, A / Y, A / Z, A / W);
	}

	Vector4 operator /(const Vector4& A) const
	{
		return Vector4(A.X / X, A.Y / Y, A.Z / Z, A.W / W);
	}

	float DotProduct(const Vector4& vec) const
	{
		return X * vec.X + Y * vec.Y + Z * vec.Z + W * vec.W;
	}

	float LengthSquared() const
	{
		return X * X + Y * Y + Z * Z + W * W;
	}

	float Length() const
	{
		return static_cast<float>(sqrtf(LengthSquared()));
	}

	Vector4 PerpendicularTo() const
	{
		return Vector4(Z, W, -X, -Y);
	}

	Vector4 Normalize()
	{
		const float length = this->Length();
		if (length != 0.0f)
		{
			const float inv = 1.0f / length;
			X *= inv;
			Y *= inv;
			Z *= inv;
			W *= inv;
		}
		return Vector4(X, Y, Z, W);
	}

	float DistanceTo(const Vector4& A) const
	{
		const float out = sqrtf(powf(A.X - X, 2) + powf(A.Y - Y, 2) + powf(A.Z - Z, 2) + powf(A.W - W, 2));
		return out < 0 ? out * -1 : out;
	}

	operator std::string() const
	{
		return std::string(
			"[X: " + std::to_string(X) + " Y: " + std::to_string(Y) + " Z: " + std::to_string(Z) + " W: " +
			std::to_string(W) + "]");
	}
}typedef Vector4;


struct Vector2
{
	float X, Y;

	Vector2()
	{
		X = 0.0f;
		Y = 0.0f;
	}

	Vector2(const float x, const float y)
	{
		X = x;
		Y = y;
	}

	/// <summary> 
	  /// Returns a position that runs from the source position to the target position with the length of the range specified.
	  /// </summary>
	inline Vector2 Extend(Vector2 target, float range)
	{
		return *this + (target - *this).Normalize() * range;
	}

	static float RadianToDegree(double angle)
	{
		return (float)(angle * (180.0 / M_PI));
	}

	static bool Close(float a, float b, float eps)
	{
		if (abs(eps) < FLT_EPSILON)
		{
			eps = (float)1e-9;
		}
		return abs(a - b) <= eps;
	}

	inline float Polar()
	{
		if (Close(this->X, 0, 0))
		{
			if (this->Y > 0)
			{
				return 90;
			}
			return this->Y < 0 ? 270 : 0;
		}

		auto theta = RadianToDegree(atan((this->Y) / this->X));
		if (this->X < 0)
		{
			theta = theta + 180;
		}
		if (theta < 0)
		{
			theta = theta + 360;
		}
		return theta;
	}

	inline float AngleBetween(Vector2 p2)
	{
		auto theta = this->Polar() - p2.Polar();
		if (theta < 0)
		{
			theta = theta + 360;
		}
		if (theta > 180)
		{
			theta = 360 - theta;
		}
		return theta;
	}

	inline Vector2 Rotated(float angle) const
	{
		auto c = cos(angle);
		auto s = sin(angle);

		return Vector2((float)(this->X * c - this->Y * s), (float)(this->Y * c + this->X * s));
	}


	Vector2 operator +(const float A) const
	{
		return Vector2(A + X, A + Y);
	}

	Vector2 operator +(const Vector2& A) const
	{
		return Vector2(A.X + X, A.Y + Y);
	}

	Vector2 operator *(const float A) const
	{
		return Vector2(A * X, A * Y);
	}

	Vector2 operator *(const Vector2& A) const
	{
		return Vector2(A.X * X, A.Y * Y);
	}

	Vector2 operator -(const float A) const
	{
		return Vector2(A * X, A * Y);
	}

	Vector2 operator -(const Vector2& A) const
	{
		return Vector2(A.X - X, A.Y - Y);
	}

	Vector2 operator /(const float A) const
	{
		return Vector2(A / X, A / Y);
	}

	Vector2 operator /(const Vector2& A) const
	{
		return Vector2(A.X / X, A.Y / Y);
	}

	float DotProduct(const Vector2& vec) const
	{
		return X * vec.X + Y * vec.Y;
	}

	float LengthSquared() const
	{
		return X * X + Y * Y;
	}

	float Length() const
	{
		return static_cast<float>(sqrtf(LengthSquared()));
	}

	Vector2 PerpendicularTo() const
	{
		return Vector2(Y, -X);
	}

	Vector2 Normalize()
	{
		const float length = this->Length();
		if (length != 0.0f)
		{
			const float inv = 1.0f / length;
			X *= inv;
			Y *= inv;
		}
		return Vector2(X, Y);
	}

	static Vector2 CoordinatesAtAngle(float angle, const float& distance)
	{
		static double pi{ 3.14159265358979323846 };

		angle = static_cast<float>(pi) * angle / 180.0f;
		const Vector2 point{ static_cast<float>(distance * cos(angle)), static_cast<float>(distance * sin(angle)) };

		return point;
	}

	bool IsValid() const
	{
		return this->Length() > 0;
	}

	float DistanceTo(const Vector2& A, bool squared = true) const
	{
		const float dist = powf(A.X - X, 2) + powf(A.Y - Y, 2);
		return squared ? sqrtf(dist) : dist;
	}

	operator std::string() const
	{
		return std::string("[X: " + std::to_string(X) + " Y: " + std::to_string(Y) + "]");
	}
}typedef Vector2;

struct Vector3
{
	float X, Y, Z;

	Vector3()
	{
		X = 0.0f;
		Y = 0.0f;
		Z = 0.0f;
	}

	Vector3(const float x, const float y, const float z)
	{
		X = x;
		Y = y;
		Z = z;
	}

	inline float Distance(Vector2 segmentStart, Vector2 segmentEnd, bool squared = false)
	{
		Vector2 point = this->To2D();
		auto a =
			abs((segmentEnd.Y - segmentStart.Y) * point.X - (segmentEnd.X - segmentStart.X) * point.Y +
				segmentEnd.X * segmentStart.Y - segmentEnd.Y * segmentStart.X);
		return (squared ? a * a : a) / segmentStart.DistanceTo(segmentEnd, squared);
	}

	static float RadianToDegree(double angle)
	{
		return (float)(angle * (180.0 / M_PI));
	}

	static bool Close(float a, float b, float eps)
	{
		if (abs(eps) < FLT_EPSILON)
		{
			eps = (float)1e-9;
		}
		return abs(a - b) <= eps;
	}

	inline float Polar()
	{
		if (Close(this->X, 0, 0))
		{
			if (this->Y > 0)
			{
				return 90;
			}
			return this->Y < 0 ? 270 : 0;
		}

		auto theta = RadianToDegree(atan((this->Y) / this->X));
		if (this->X < 0)
		{
			theta = theta + 180;
		}
		if (theta < 0)
		{
			theta = theta + 360;
		}
		return theta;
	}

	inline float AngleBetween(Vector3 p2)
	{
		auto theta = this->Polar() - p2.Polar();
		if (theta < 0)
		{
			theta = theta + 360;
		}
		if (theta > 180)
		{
			theta = 360 - theta;
		}
		return theta;
	}

	inline Vector3 Rotated(float angle) const
	{
		auto c = cos(angle);
		auto s = sin(angle);

		return Vector3((float)(this->X * c - this->Y * s), (float)(this->Y * c + this->X * s), (float)(this->Z * c - this->Z * s));
	}

	/// <summary> 
	  /// Returns a position that runs from the source position to the target position with the length of the range specified.
	  /// </summary>
	inline Vector3 Extend(Vector3 target, float range)
	{
		return *this + (target - *this).Normalize() * range;
	}

	Vector3 operator +(const float A) const
	{
		return Vector3(A + X, A + Y, A + Z);
	}

	Vector3 operator +(const Vector3& A) const
	{
		return Vector3(A.X + X, A.Y + Y, A.Z + Z);
	}


	Vector3 operator *(const float A) const
	{
		return Vector3(A * X, A * Y, A * Z);
	}

	bool operator ==(const Vector3& A) const
	{
		return X == A.X && Y == A.Y && Z == A.Z;
	}

	static Vector3 Zero()
	{
		return Vector3{ 0,0,0 };
	}

	Vector3 operator *(const Vector3& A) const
	{
		return Vector3(A.X * X, A.Y * Y, A.Z * Z);
	}

	Vector3 operator -(const float A) const
	{
		return Vector3(A * X, A * Y, A * Z);
	}

	Vector3 operator -(const Vector3& A) const
	{
		return Vector3(A.X - X, A.Y - Y, A.Z - Z);
	}

	Vector3 operator /(const float A) const
	{
		return Vector3(A / X, A / Y, A / Z);
	}

	Vector3 operator /(const Vector3& A) const
	{
		return Vector3(A.X / X, A.Y / Y, A.Z / Z);
	}

	Vector3 CrossProduct(const Vector3& vec) const
	{
		return Vector3(Y * vec.Z - Z * vec.Y, Z * vec.X - X * vec.Z, X * vec.Y - Y * vec.X);
	}

	Vector3 Multiply(float a)
	{
		return Vector3(X * a, Y * a, Z * a);
	}

	inline Vector2 To2D() const
	{
		return Vector2(this->X, this->Y);
	}

	float DotProduct(const Vector3& vec) const
	{
		return X * vec.X + Y * vec.Y + Z * vec.Z;
	}

	float LengthSquared() const
	{
		return X * X + Y * Y + Z * Z;
	}

	float LengthSquared2D() const
	{
		return X * X + Z * Z;
	}

	float Length() const
	{
		return static_cast<float>(sqrtf(LengthSquared()));
	}

	bool IsValid() const
	{
		return Length() > 0;
	}

	float Length2D() const
	{
		return static_cast<float>(sqrtf(LengthSquared2D()));
	}


	Vector3 PerpendicularTo() const
	{
		return Vector3(Z, Y, -X);
	}


	Vector3 Normalize()
	{
		const float length = this->Length2D();
		if (length != 0.0f)
		{
			const float inv = 1.0f / length;
			X *= inv;
			Y *= inv;
			Z *= inv;
		}
		return Vector3(X, Y, Z);
	}

	float DistanceTo(const Vector3& A, bool squared = true) const
	{
		const float dist = powf(A.X - X, 2) + powf(A.Y - Y, 2) + powf(A.Z - Z, 2);
		//	const float out = sqrtf(powf(A.X - X, 2) + powf(A.Y - Y, 2) + powf(A.Z - Z, 2));
		return squared ? sqrtf(dist) : dist;
	}

	operator std::string() const
	{
		return std::string("[X: " + std::to_string(X) + " Y: " + std::to_string(Y) + " Z: " + std::to_string(Z) + "]");
	}
}typedef Vector3;

inline Vector3 To3D(Vector2 vec)
{
	return Vector3(vec.X, vec.Y, 0.f);
}