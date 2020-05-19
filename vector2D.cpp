#include "stdafx.h"
#include "vector2D.h"

namespace nce
{
  const Vector2D Vector2D::zero = Vector2D(0.0f, 0.0f);
  const Vector2D Vector2D::one = Vector2D(1.0f, 1.0f);
  const Vector2D Vector2D::up = Vector2D(0.0f, 1.0f);
  const Vector2D Vector2D::down = Vector2D(0.0f, -1.0f);
  const Vector2D Vector2D::left = Vector2D(-1.0f, 0.0f);
  const Vector2D Vector2D::right = Vector2D(1.0f, 0.0f);
  
  std::istream & operator>>(std::istream & stream, Vector2D & v)
  {
	  std::string line;
	  getline(stream, line);

	  if (line.find("{") != std::string::npos)
	  {
		  std::string vx = line.substr(line.find("{") + 1, (line.find(",") - line.find("{")) - 1);
		  v.x = stof(vx);
		  std::string vy = line.substr(line.find(",") + 1, (line.find("}") - line.find(",")) - 1);
		  v.y = stof(vy);
	  }

	  return stream;
  }

}