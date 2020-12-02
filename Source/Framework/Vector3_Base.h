/*
	Header - Vector3_Base.h
	Source - None

	Author - Garrett Courtney

	Description:
	Represents a vector with 3 components. These components can be of any type with the template parameter "VectorType"
	The "Vector3Base_t" class typically should not be used in client code. Instead, use the vectors provided in "Vector3.h"
	as they have template arguments given and are generally more friendly to look at.

*/
#pragma once

#include <math.h>



#if defined _DEBUG
	#define IM_INTRINSICS_ENABLED 0
#elif defined _RELEASE
	#define IM_INTRINSICS_ENABLED 1
#endif


namespace InsightMath
{

	template <typename VectorType>
	struct Vector3Base_t
	{
		VectorType X;
		VectorType Y;
		VectorType Z;

		constexpr Vector3Base_t(VectorType Value)
			: X(Value), Y(Value), Z(Value) { }
		constexpr Vector3Base_t(VectorType X, VectorType Y, VectorType Z)
			: X(X), Y(Y), Z(Z) { }
		constexpr Vector3Base_t() 
			{ memset(this, 0, sizeof(Vector3Base_t<VectorType>)); }

		constexpr Vector3Base_t(const Vector3Base_t& Vec)
		{
			this->X = Vec.x;
			this->Y = Vec.Y;
			this->Z = Vec.Z;
		}

		~Vector3Base_t() = default;

		inline constexpr size_t SizeInBytes()
		{
			constexpr size_t Size = sizeof(X) + sizeof(Y) + sizeof(Z);
			return Size;
		}

		inline void SetX(VectorType X) { this->X = X; }
		inline void SetY(VectorType Y) { this->Y = Y; }
		inline void SetZ(VectorType Z) { this->Z = Z; }

		inline void SetXYZ(VectorType X, VectorType Y, VectorType Z)
		{
			this->X = X;
			this->Y = Y;
			this->Z = Z;
		}

		constexpr void ZeroComponents()
		{
			this->X = static_cast<VectorType>(0);
			this->Y = static_cast<VectorType>(0);
			this->Z = static_cast<VectorType>(0);
		}

		bool operator ==(const Vector3Base_t& A)
		{
			bool X = this->X == A.X;
			bool Y = this->Y == A.Y;
			bool Z = this->Z == A.Z;
			return (X && Y && Z);
		}

		bool operator !=(const Vector3Base_t& A)
		{
			bool IsSame = (*this) == A;
			return (IsSame == false);
		}

		Vector3Base_t operator + (const Vector3Base_t& rhs)
		{
			float X = this->X + rhs.X;
			float Y = this->Y + rhs.Y;
			float Z = this->Z + rhs.Z;
			return Vector3Base_t(X, Y, Z);
		}
		Vector3Base_t& operator += (const Vector3Base_t& rhs)
		{
			this->X += rhs.X;
			this->Y += rhs.Y;
			this->Z += rhs.Z;
			return *this;
		}
		Vector3Base_t operator - (const Vector3Base_t& rhs)
		{
			float X = this->X - rhs.X;
			float Y = this->Y - rhs.Y;
			float Z = this->Z - rhs.Z;
			return Vector3Base_t(X, Y, Z);
		}
		Vector3Base_t& operator -= (const Vector3Base_t& rhs)
		{
			this->X -= rhs.X;
			this->Y -= rhs.Y;
			this->Z -= rhs.Z;
			return *this;
		}
		Vector3Base_t operator * (const Vector3Base_t& rhs)
		{
			float X = this->X * rhs.X;
			float Y = this->Y * rhs.Y;
			float Z = this->Z * rhs.Z;
			return Vector3Base_t(X, Y, Z);
		}
		Vector3Base_t& operator *= (const Vector3Base_t& rhs)
		{
			this->X *= rhs.X;
			this->Y *= rhs.Y;
			this->Z *= rhs.Z;
			return *this;
		}
		Vector3Base_t operator / (const Vector3Base_t& rhs)
		{
			float X = this->X / rhs.X;
			float Y = this->Y / rhs.Y;
			float Z = this->Z / rhs.Z;
			return Vector3Base_t(X, Y, Z);
		}
		Vector3Base_t& operator /= (const Vector3Base_t& rhs)
		{
			this->X /= rhs.X;
			this->Y /= rhs.Y;
			this->Z /= rhs.Z;
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
			float Z2 = this->Z * this->Z;
			return sqrtf(X2 + Y2 + Z2);
		}

		/*
			Returns the squared length of this.
		*/
		float LengthSquared()
		{
			Vector3Base_t Vec = Dot(this);
			return Vec.X + Vec.Y + Vec.Z;
		}

		/*
			Normalizes this vector.
		*/
		void Normalize()
		{
			float LengthFactor = 1.0f / this->Length();
			this->X *= LengthFactor;
			this->Y *= LengthFactor;
			this->Z *= LengthFactor;
		}

		// -------------------------
		//		Static Functions	|
		// -------------------------

		/*
			Returns the vector perpendicular to A and B.
		*/
		static Vector3Base_t Cross(const Vector3Base_t& A, const Vector3Base_t& B)
		{
			float X = A.Y * B.Z - A.Z * B.Y;
			float Y = A.Z * B.X - A.X * B.Z;
			float Z = A.X * B.Y - A.Y * B.X;
			return Vector3Base_t(X, Y, Z);
		}

		/*
			Returns the dot product of A and B
		*/
		static float Dot(const Vector3Base_t& A, const Vector3Base_t& B)
		{
			float X = A.X * B.X;
			float Y = A.Y * B.Y;
			float Z = A.Z * B.Z;
			return (X + Y + Z);
		}

		/*
			Returns the normalized vector of A.
		*/
		static Vector3Base_t Normalize(const Vector3Base_t& A)
		{
			float LengthFactor = 1.0f / A.Length();
			return Vector3Base_t(LengthFactor * A.X, LengthFactor * A.Y, LengthFactor * A.Z);
		}

	};
}
