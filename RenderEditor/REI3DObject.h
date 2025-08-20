#pragma once
#include "REBaseType.h"
class REI3DObject
{
public:
	REI3DObject() = default;
	~REI3DObject() = default;

	//获取位置
	virtual void setPosition(const glm::vec3 & position) = 0;
	//设置位置
	virtual glm::vec3 getPosition() const = 0;

	//旋转
	virtual void setRotation(float angle, const glm::vec3 & axis) = 0;
	//获取旋转矩阵
	virtual glm::mat4 getRotateMat() const = 0;

	//缩放
	virtual void setScalar(const glm::vec3 & scalar) = 0;
	//获取缩放
	virtual glm::vec3 getScalar() const = 0;

	//获取模型矩阵(mvp-m)
	virtual void setModelMat(const glm::mat4& model) = 0;
	//设置模型矩阵(mvp-m)
	virtual glm::mat4 getModelMat() const = 0;
};

