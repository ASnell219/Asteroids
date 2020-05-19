#include "stdafx.h"
#include "vector3D.h"

namespace nce
{
  const Vector3D Vector3D::zero = Vector3D(0.0f, 0.0f);
  const Vector3D Vector3D::one = Vector3D(1.0f, 1.0f);
  const Vector3D Vector3D::up = Vector3D(0.0f, -1.0f);
  const Vector3D Vector3D::down = Vector3D(0.0f, 1.0f);
  const Vector3D Vector3D::left = Vector3D(-1.0f, 0.0f);
  const Vector3D Vector3D::right = Vector3D(1.0f, 0.0f);
  
  std::istream & operator>>(std::istream & stream, Vector3D & v)
  {
	  std::string line;
	  getline(stream, line);

	  if (line.find("{") != std::string::npos)
	  {
		  std::string cR = line.substr(line.find("{") + 1, (line.find(",") - line.find("{")) - 1);
		  v.x = stof(cR);
		  line = line.substr(line.find(",") + 1, (line.find("}") - line.find(",")) - 1);
		  std::string cG = line.substr(0, line.find(",") - 1);
		  v.y = stof(cG);
		  std::string cB = line.substr(line.find(",") + 1, (line.find("}") - line.find(",")) - 1);
		  v.z = stof(cB);
	  }

	  return stream;
  }

}