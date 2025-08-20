#include <QDateTime>
#include "RETimerModel.h"
#include "REFloatData.hpp"

RETimerModel::RETimerModel()
{
	_result = std::make_shared<REFloatData>(0.);
	// 创建 QTimer
	_timer = new QTimer(this);
	connect(_timer, &QTimer::timeout, this, &RETimerModel::onTimerOut);

	_timer->start(1); // 每 24 ms 触发一次
}


unsigned int RETimerModel::nPorts(PortType portType) const
{
	unsigned int result;

	if (portType == PortType::In)
		result = 0;
	else
		result = 1;

	return result;
}

NodeDataType RETimerModel::dataType(PortType, PortIndex) const
{
	return REFloatData().type();
}

std::shared_ptr<NodeData> RETimerModel::outData(PortIndex index)
{
	_count += 0.9;
	_result->setValue(_count);
	return std::static_pointer_cast<NodeData>(_result);
}


void RETimerModel::onTimerOut()
{
	Q_EMIT dataUpdated(0);
}