/*
	Header - Vector3_Base.h
	Source - None

	Author - Garrett Courtney

	Description:
	Represents a vector with 3 components. These components can be of any type with the template parameter "VectorType"
	The "Vector2Base_t" class typically should not be used in client code. Instead, use the vectors provided in "Vector2.h"
	as they have template arguments given and are generally more friendly to look at.

*/
#pragma once

#include <math.h>



namespace InsightMath
{

	template <typename VectorType>
	struct Vector2Base_t
	{
		VectorType X;
		VectorType Y;

		constexpr Vector2Base_t(VectorType Value)
			: X(Value), Y(Value) { }
		constexpr Vector2Base_t(VectorType X, VectorType Y)
			: X(X), Y(Y) { }
		constexpr Vector2Base_t()
		{
			memset(this, 0, sizeof(this));
		}

		constexpr Vector2Base_t(const Vector2Base_t& Vec)
		{
			this->X = Vec.x;
			this->Y = Vec.Y;
		}

		~Vector2Base_t() = default;

		inline constexpr size_t SizeInBytes()
		{
			constexpr size_t Size = sizeof(X) + sizeof(Y);
			return Size;
		}

		inline void SetX(VectorType X) { this->X = X; }
		inline void SetY(VectorType Y) { this->Y = Y; }

		inline void SetXY(VectorType X, VectorType Y)
		{
			this->X = X;
			this->Y = Y;
		}

		constexpr void ZeroComponents()
		{
			this->X = static_cast<VectorType>(0);
			this->Y = static_cast<VectorType>(0);
		}

		bool operator ==(const Vector2Base_t& A)
		{
			bool X = this->X == A.X;
			bool Y = this->Y == A.Y;
			return (X && Y);
		}

		bool operator !=(const Vector2Base_t& A)
		{
			bool IsSame = (*this) == A;
			return (IsSame == false);
		}

		Vector2Base_t operator + (const Vector2Base_t& rhs)
		{
			float X = this->X + rhs.X;
			float Y = this->Y + rhs.Y;
			return Vector2Base_t(X, Y);
		}
		Vector2Base_t& operator += (const Vector2Base_t& rhs)
		{
			this->X += rhs.X;
			this->Y += rhs.Y;
			return *this;
		}
		Vector2Base_t operator - (const Vector2Base_t& rhs)
		{
			float X = this->X - rhs.X;
			float Y = this->Y - rhs.Y;
			return Vector2Base_t(X, Y, Z);
		}
		Vector2Base_t& operator -= (const Vector2Base_t& rhs)
		{
			this->X -= rhs.X;
			this->Y -= rhs.Y;
			return *this;
		}
		Vector2Base_t operator * (const Vector2Base_t& rhs)
		{
			float X = this->X * rhs.X;
			float Y = this->Y * rhs.Y;
			return Vector2Base_t(X, Y);
		}
		Vector2Base_t& operator *= (const Vector2Base_t& rhs)
		{
			this->X *= rhs.X;
			this->Y *= rhs.Y;
			return *this;
		}
		Vector2Base_t operator / (const Vector2Base_t& rhs)
		{
			float X = this->X / rhs.X;
			float Y = this->Y / rhs.Y;
			return Vector2Base_t(X, Y, Z);
		}
		Vector2Base_t& operator /= (const Vector2Base_t& rhs)
		{
			this->X /= rhs.X;
			this->Y /= rhs.Y;
			return *this;
		}

		// ---------------------
		//		Operations		|
		// ---------------------

		/*
			Returns the length of this.
		*/
		float Length()
		{
			float X2 = this->X * this->X;
			float Y2 = this->Y * this->Y;
			return sqrtf(X2 + Y2);
		}

		/*
			Returns the squared length of this.
		*/
		float LengthSquared()
		{
			Vector2Base_t Vec = Dot(this);
			return Vec.X + Vec.Y;
		}

		/*
			Returns the normalized vector of this.
		*/
		Vector2Base_t Normalize()
		{
			float LengthFactor = 1.0f / this->Length();
			return Vector2Base_t(LengthFactor * this->X, LengthFactor * this->Y);
		}

		/*
			Returns the dot product of this and A
		*/
		float Dot(const Vector2Base_t& A)
		{
			float X = this->X * A.X;
			float Y = this->Y * A.Y;
			return (X + Y);
		}

		/*
			Returns the vector perpendicular to this and B.
		*/
		Vector2Base_t Cross(const Vector2Base_t& B)
		{
			float X = this->Y * B.Z - this->Z * B.Y;
			float Y = this->Z * B.X - this->X * B.Z;
			return Vector2Base_t(X, Y);
		}

		// -------------------------
		//		Static Functions	|
		// -------------------------

		/*
			Returns the vector perpendicular to A and B.
		*/
		static Vector2Base_t Cross(const Vector2Base_t& A, const Vector2Base_t& B)
		{
			float X = A.Y * B.Z - A.Z * B.Y;
			float Y = A.Z * B.X - A.X * B.Z;
			return Vector2Base_t(X, Y);
		}

		/*
			Returns the dot product of A and B
		*/
		static float Dot(const Vector2Base_t& A, const Vector2Base_t& B)
		{
			float X = A.X * B.X;
			float Y = A.Y * B.Y;
			return (X + Y);
		}

		/*
			Returns the normalized vector of A.
		*/
		static Vector2Base_t Normalize(const Vector2Base_t& A)
		{
			float LengthFactor = 1.0f / A.Length();
			return Vector2Base_t(LengthFactor * A.X, LengthFactor * A.Y);
		}

	};
}
