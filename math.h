#pragma once
#include <math.h>
#include <algorithm>

namespace nce
{
	namespace Math
	{
		constexpr float PI = 3.1415f;
		constexpr float TwoPI = PI * 2.0f;
		constexpr float HalfPI = PI * 0.5f;

		constexpr float DegreesToRadians = PI / 180;
		constexpr float RadiansToDegress = 180 / PI;

		inline float Clamp(float t, float low, float high)
		{
			return std::min<float>(high, std::max<float>(t, low));
		}

		inline float Clamp01(float t)
		{
			return std::min<float>(1.0f, std::max<float>(t, 0.0f));
		}

		template <typename T>
		inline T Lerp(const T& v1, const T& v2, float t)
		{
			t = Clamp01(t);
			return ((v1 * (1.0f - t)) + (v2 * t));
		}

		template <typename T>
		inline T LerpUnclamped(const T& v1, const T& v2, float t)
		{
			return (v1 * (1.0f - t) + v2 * t);
		}

		inline float GetRandom01()
		{
			return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
		}

		inline float GetRandomRange(float min, float max)
		{
			return min + (max - min) * GetRandom01();
		}


	}
}
