#include "stdafx.h"
#include "LayoutContainer.h"
#include "Model/UIObject.h"
#include "Model/UIObjectCollection.h"


LayoutContainer::LayoutContainer(LayoutContainerType type)
	: type_(type)	
	, isNeedLayout_(true)
{
	
}

LayoutContainer::~LayoutContainer()
{

}

void LayoutContainer::Attatch(const SPtr<UIObjectCollection>& children)
{
	children_ = children;
	//ע�Ἧ�ϱ仯�¼�
	//children->EventOnChildChanged
	isNeedLayout_ = true;
}

void LayoutContainer::SetNeedsLayout()
{
	isNeedLayout_ = true;
}
