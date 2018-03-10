//
//
#include "Vector3.h"

#include <limits>


        const Vector3 Vector3::Zero = Vector3(0,0,0);
        const Scalar Vector3::Epsilon = std::numeric_limits::epsilon();


        Vector3::Vector3()
        {
        }

        Vector3::Vector3(Scalar x, Scalar y, Scalar z)
                : X( x )
                , Y( y )
                , Z( z )
        {
        }

	 Bool Vector3::operator==(const Vector3&amp; vector) const
        {
                return X == vector.X &amp;&amp; Y == vector.Y &amp;&amp; Z == vector.Z;
        }

         Bool Vector3::operator!=(const Vector3&amp; vector) const
        {
                return X != vector.X || Y != vector.Y || Z != vector.Z;
        }

         Vector3 Vector3::operator+(const Vector3&amp; vector) const
        {
                return Vector3(X + vector.X, Y + vector.Y, Z + vector.Z);
        }

         Vector3 Vector3::operator-(const Vector3&amp; vector) const
        {
                return Vector3(X - vector.X, Y - vector.Y, Z - vector.Z);
        }

         Vector3 Vector3::operator-() const
        {
                return Vector3(-X,-Y,-Z);
        }

         Vector3 Vector3::operator*(Scalar num) const
        {
                return Vector3(X * num, Y * num, Z * num);

        }

	Scalar Vector3::operator*(const Vector3 & vector) const
	{
		return x_ * other.x_ + y_ * other.y_ + z_ * other.z_;
	}
         Vector3 Vector3::operator/(Scalar num) const
        {
                return Vector3(X / num, Y / num, Z / num);
        }


        Vector3& Vector3::operator+=(const Vector3& vector)
        {
                X += vector.X;
                Y += vector.Y;
                Z += vector.Z;
                return *this;
        }

        Vector3& Vector3::operator-=(const Vector3& vector)
        {
                X -= vector.X;
                Y -= vector.Y;
                Z -= vector.Z;
                return *this;
        }

        Vector3& Vector3::operator*=(Scalar num)
        {
                X *= num;
                Y *= num;
                Z *= num;
                return *this;
        }

	Vector3 Vector3::operator^(const Vector3 & vector) const
	{
		return Vector3(y_ * other.z_ - z_ * other.y_,
					z_ * other.x_ - x_ * other.z_,
					x_ * other.y_ - y_ * other.x_
		);
	}
	

        Vector3& Vector3::operator/=(Scalar num)
        {
                this-&gt;X /= num;
                this-&gt;Y /= num;
                this-&gt;Z /= num;
                return *this;
        }
	 Scalar len(const Vector3& vect)
        {
                return sqrt(vect.X * vect.X + vect.Y * vect.Y + vect.Z * vect.Z);
        }

         Scalar len2(const Vector3& vect)
        {
                return vect.X * vect.X + vect.Y * vect.Y + vect.Z * vect.Z;
        }

         void Normalize(Vector3& vect)
        {
                vect /= len(vect);
        }

         void SetLength(Vector3& vect, Scalar length)
        {
                vect *= length / len(vect);
        }

         
         Vector3 Normalized(const Vector3& vect)
        {
                return vect / len(vect);
        }

	Vector3& Rotate(const Vector3& vec1, Scalar angle, const Vector3& axis);       //it isn't stealing if its under gpl
	{
	Vector3 axisNorm = axis;
	axisNorm.Normalize();
	Scalar cosA = std::cos(angle);
	Scalar sinA = std::sin(angle);
	Vector3 self = *this;
	Vector3 a = self - axisNorm * (axisNorm * self);
	Vector3 b = a ^ axisNorm;
	Vector3 delta = a * cosA + b * sinA - a;
	self += delta;
	*this = self;
	return *this;
	}
