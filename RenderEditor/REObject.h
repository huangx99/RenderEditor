#pragma once
#include "REI3DObject.h"
#include "REIDrawObject.h"
#include "REMesh.h"
#include "REShader.h"
#include "REObjectStruct.h"
#include <QOpenGLFunctions_3_3_Core>
class REObject : public REI3DObject, public REIDrawObject, protected QOpenGLFunctions_3_3_Core
{
public:
	REObject();
	virtual ~REObject();
public:
	//获取位置
	virtual void setPosition(const glm::vec3 & position);
	//设置位置
	virtual glm::vec3 getPosition() const;

	//旋转
	virtual void setRotation(float angle, const glm::vec3 & axis);
	//获取旋转矩阵
	virtual glm::mat4 getRotateMat() const;

	//缩放
	virtual void setScalar(const glm::vec3 & scalar);
	//获取缩放
	virtual glm::vec3 getScalar() const;

	//获取模型矩阵(mvp-m)
	virtual void setModelMat(const glm::mat4& model);
	//设置模型矩阵(mvp-m)
	virtual glm::mat4 getModelMat() const;

public:
	virtual void draw();

	void setShader(REShaderPtr shader);

	void setMesh(const REMesh& mesh);

private:
	RESObject m_object;
	REShaderPtr m_shader;
	REMesh m_mesh;
};

