#pragma once

#include "REVec3Data.hpp"
#include "REVec3ComputeModel.h"

#include <QtNodes/NodeDelegateModel>

#include <QtCore/QObject>
#include <QtWidgets/QLabel>

/// The model dictates the number of inputs and outputs for the Node.
/// In this example it has no logic.
class REVec3CrossModel : public REVec3ComputeModel
{
public:
	~REVec3CrossModel() = default;

public:
	QString caption() const override { return QStringLiteral("cross3"); }

	QString name() const override { return QStringLiteral("cross3"); }

private:
	void compute() override
	{
		PortIndex const outPortIndex = 0;

		if (_vec3a && _vec3b) {
			_result = std::make_shared<REVec3Data>(glm::cross(_vec3a->value(), _vec3b->value()));
		}
		else {
			_result.reset();
		}

		Q_EMIT dataUpdated(outPortIndex);
	}
};
