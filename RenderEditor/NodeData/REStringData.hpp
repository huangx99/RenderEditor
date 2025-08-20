#pragma once

#include <QtNodes/NodeData>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using QtNodes::NodeData;
using QtNodes::NodeDataType;

class REStringData : public NodeData
{
public:
	REStringData()
	{}

	REStringData(const QString& str)
		: _str(str)
	{}

	NodeDataType type() const override { return NodeDataType{ QString::fromUtf8("string"), QString::fromUtf8("string") }; }

	QString value() const { return _str; }

	void setValue(const QString& value) { _str = value; }

private:
	QString _str;
};
