#pragma once
#include <cassert>
#include "window.h"
#include "math.h"

namespace nce
{
	class Color
	{
	public:
		float r, g, b;

	public:
		Color() {};
		Color(float r, float g, float b) : r(r), g(g), b(b) { }
		Color& operator = (const Color & c) { this->r = c.r; this->g = c.g; this->b = c.b; return *this; }

		float& operator [] (size_t index)
		{
			assert(index < 2 || index > -1);
			if (index == 0)
				return r;
			if (index == 1)
				return g;
			if (index == 2)
				return b;
		}

		const float& operator [] (size_t index) const
		{
			assert(index < 3 || index > -1);
			if (index == 0)
				return r;

			if (index == 1)
				return g;

			if (index == 2)
				return b;
		}

		Color& operator += (const Color & c) { r += c.r; g += c.g; b += c.b; return *this; }
		Color& operator -= (const Color & c) { r -= c.r; g -= c.g; b -= c.b; return *this; }
		Color& operator *= (const Color & c) { r *= c.r; g *= c.g; b *= c.b; return *this; }
		Color& operator /= (const Color & c) { r /= c.r; g /= c.g; b /= c.b; return *this; }

		const Color operator + (const Color & c) const { Color r(*this); return r += c; }
		const Color operator - (const Color & c) const { Color r(*this); return r -= c; }
		const Color operator * (const Color & c) const { Color r(*this); return r *= c; }
		const Color operator / (const Color & c) const { Color r(*this); return r /= c; }

		Color & operator += (float s) { r += s; g += s; b += s; return *this; }
		Color & operator -= (float s) { r -= s; g -= s; b -= s; return *this; }
		Color & operator *= (float s) { r *= s; g *= s; b *= s; return *this; }
		Color & operator /= (float s) { r /= s; g /= s; b /= s; return *this; }

		const Color operator + (float s) const { Color r(*this); return r += s; }
		const Color operator - (float s) const { Color r(*this); return r -= s; }
		const Color operator * (float s) const { Color r(*this); return r *= s; }
		const Color operator / (float s) const { Color r(*this); return r /= s; }

		operator COLORREF() const
		{
			BYTE _r = static_cast<BYTE>(Math::Clamp01(r) * 255.0f);
			BYTE _g = static_cast<BYTE>(Math::Clamp01(g) * 255.0f);
			BYTE _b = static_cast<BYTE>(Math::Clamp01(b) * 255.0f);
			return RGB(_r, _g, _b);
		}

		static const Color red;
		static const Color green;
		static const Color blue;
		static const Color white;
		static const Color orange;
		static const Color yellow;
		static const Color magenta;
		static const Color cyan;

		friend std::ostream & operator << (std::ostream & os, const Color & c)
		{
			return os << "{" << c.r << ", " << c.g << ", " << c.b << "}";
		}
		friend std::istream & operator >> (std::istream & is, Color & v);

	};
}

