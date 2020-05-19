#include "stdafx.h"
#include "color.h"

namespace nce
{
	const Color Color::red = Color(1.0f, 0.0f, 0.0f );
	const Color Color::green = Color( 0.0f, 1.0f, 0.0f );
	const Color Color::blue = Color( 0.0f, 0.0f, 1.0f );
	const Color Color::white = Color( 1.0f, 1.0f, 1.0f );
	const Color Color::orange = Color( 1.0f, 0.5f, 0.0f );
	const Color Color::yellow = Color( 1.0f, 1.0f, 0.0f);
	const Color Color::magenta = Color( 1.0f, 0.0f, 1.0f );
	const Color Color::cyan = Color( 0.0f, 1.0f, 1.0f );

	std::istream & nce::operator>>(std::istream & stream, Color & c)
	{
		std::string line;
		getline(stream, line);

		if (line.find("{") != std::string::npos)
		{
			std::string cR = line.substr(line.find("{") + 1, (line.find(",") - line.find("{")) - 1);
			c.r = stof(cR);
			line = line.substr(line.find(",") + 1, (line.find("}") - line.find(",")) - 1);
			std::string cG = line.substr(0, line.find(",") - 1);
			c.g = stof(cG);
			std::string cB = line.substr(line.find(",") + 1, (line.find("}") - line.find(",")) - 1);
			c.b = stof(cB);
		}

		return stream;
	}
}
//heck off

