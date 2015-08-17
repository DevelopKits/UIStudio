#pragma once
#include "Base/object.h"
#include "Base/Geom/rect.h"
#include "Delegate/Delegate.h"

class LayoutObject;
class UIObject;

struct ResizeEventArgs
{
	ResizeEventArgs(const base::Size& a, const base::Size& b)
		: originSize(a), newSize(b) {}
	base::Size originSize;
	base::Size newSize;
};
typedef Event<void(const SPtr<LayoutObject>&, const ResizeEventArgs&)> ResizeEvent;

enum LayoutContainerType
{
	RelativeLayout,
	AnchorLayout,
	HBoxLayout,
	VBoxLayout,
};

enum LayoutChildType
{
	RelativeLayoutChildType,
	AnchorLayoutChildType,
};

class LayoutContainer;
class LayoutObject : public Object
{
public:
	LayoutObject();
	~LayoutObject();

	//ResizeEvent EventResize;

	void Attatch(const SPtr<UIObject>& object);
	void Detach();	

	const base::Rect& bounds() const { return bounds_; }
	int x() const { return bounds_.x(); }
	int y() const { return bounds_.y(); }
	int width() const { return bounds_.width(); }
	int height() const { return bounds_.height(); }
	const base::Size& size() const { return bounds_.size(); }
	base::Rect GetLocalBounds() const;

	void SetBounds(int x, int y, int width, int height);
	void SetBoundsRect(const base::Rect& bounds);
	void SetSize(const base::Size& size);
	void SetPosition(const base::Point& position);
	void SetPosition(int x, int y);
	void SetX(int x);
	void SetY(int y);

	virtual void Layout() = 0;//����children��λ��

	virtual base::Size GetPerferedSize();//���¼��������С
protected:	
	WPtr<UIObject> owner_;
	base::Rect bounds_; // ʵ��λ��
};
