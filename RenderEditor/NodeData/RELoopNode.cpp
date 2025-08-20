#include "RELoopNode.hpp"
#include "RELoopModel.h"
void RELoopNode::setModel(RELoopModel * model)
{
	_model = model;
}

void RELoopNode::execute()
{
	_loopCountTemp--;
	if (_loopCountTemp < 0)
	{
		_loopCountTemp = _param.count;
		_loopCountTemp--;
	}

	if (_model)
		_model->updateCount();
	
	
}
