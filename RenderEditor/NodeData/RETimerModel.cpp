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
		result = 1;
	else
		result = 1;

	return result;
}

NodeDataType RETimerModel::dataType(PortType, PortIndex) const
{
	return REFloatData().type();
}

void RETimerModel::setInData(std::shared_ptr<NodeData> data, PortIndex const index)
{

	auto numberData = std::dynamic_pointer_cast<REFloatData>(data);

	if (!data) {
		Q_EMIT dataInvalidated(0);
		_speed = 1.0;

		return;
	}

	if (index == 0)
	{
		_speed = numberData->value();
	}

	Q_EMIT dataUpdated(0);
}

std::shared_ptr<NodeData> RETimerModel::outData(PortIndex index)
{
	_count += 0.9 * _speed;
	_result->setValue(_count);
	return std::static_pointer_cast<NodeData>(_result);
}


void RETimerModel::onTimerOut()
{
	Q_EMIT dataUpdated(0);
}