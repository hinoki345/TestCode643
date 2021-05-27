#include"Geometry.h"

float
Rect::Left()const {
	return center.x-w;
}

float
Rect::Top()const {
	return center.y-h;
}

float
Rect::Right()const {
	return center.x+w;
}

float
Rect::Bottom()const {
	return center.x + w;
}

float Vector2::Magnitude() const
{
	
	return 0.0f;
}
