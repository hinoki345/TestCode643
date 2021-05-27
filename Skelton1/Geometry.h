#pragma once

struct Vector2 {
	float x, y;
	//Vector2(float inx, float iny) :x(inx), y(iny) {};
	float Magnitude()const;
	void Nomalize();
	Vector2 Nomalize()const;
	void operator +=(const Vector2& v);
	void operator -=(const Vector2& w);

};




//Vector2 operator+(const Vector2& lval, const Vector2& rval) {
//	return Vector2(lval.x + rval.x, lval.y + rval.y);
//}
//
//Vector2 operator-(const Vector2& lval, const Vector2& rval) {
//	return Vector2(lval.x - rval.x, lval.y - rval.y);
//}

//座標＝ベクトル
using Position2 = Vector2;

struct Rect {
	Position2 center;//中心点
	float w;//幅
	float h;//高さ
	float Left()const;//左
	float Top()const;//上
	float Right()const;//右
	float Bottom()const;//下
	float Width()const;
	float Height()const;
};

struct Circle {
	Position2 center;
	float radias;
};