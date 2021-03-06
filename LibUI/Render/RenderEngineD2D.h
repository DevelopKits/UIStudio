#pragma once
#include "Render/RenderEngine.h"
#include <d2d1.h>
#include <atlbase.h>

class RenderD2DEngine : public RenderEngine
{
public:
	RenderD2DEngine();
	~RenderD2DEngine();

	virtual SPtr<RenderContext> CreateRenderContext(const SPtr<RenderWindow>& window) override;

	virtual SPtr<RenderRectangle>
		CreateRenderRectangle(int width, int height, base::Color color) override;

	static void Init();
	static void Uninit();
	static RenderD2DEngine* Get();
	static CComPtr<ID2D1Factory> GetD2DFactory();
private:
	CComPtr<ID2D1Factory> factory_;
};