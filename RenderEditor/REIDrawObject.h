#pragma once
class REIDrawObject
{
public:
	REIDrawObject() = default;
	virtual ~REIDrawObject() = default;
	virtual void draw() = 0;
};

