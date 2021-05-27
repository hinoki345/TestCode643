#include<DxLib.h>
#include"Geometry.h"
#include<math.h>

bool IsHit(const Rect& rcA,const Rect& rcB)
{
	if((rcA.center.x - rcB.center.x)>rcA.w);
	return true;
}

bool IsHit(const Circle& cA, const Circle& cB)
{
	if((cA.center.x - cB.center.x) * (cA.center.x - cB.center.x)
		+ (cA.center.y - cB.center.y) * (cA.center.x - cB.center.x)
		<= (cA.radias + cB.radias) * (cA.radias + cB.radias));

	return true;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(true);
	SetWindowText(L"‹éŒ`‚Ì“–‚½‚è”»’è");
	DxLib_Init();
	
	SetDrawScreen(DX_SCREEN_BACK);

	Circle cA = { 100,100,50 };
	Circle cB = { 400,300, 89};

	//Rect rcA = { 100,100,75,75 };
	//Rect rcB = { 400,300,75,120 };

	char keyState[256];
	while (ProcessMessage() == 0) {
		ClearDrawScreen();
		GetHitKeyStateAll(keyState);
		constexpr float speed = 4.0f;
		if (keyState[KEY_INPUT_UP])
		{
			cA.center.y -= speed;

		}

		if (keyState[KEY_INPUT_LEFT])
		{
			cA.center.x -= speed;
		}

		if (keyState[KEY_INPUT_RIGHT])
		{
			cA.center.x += speed;

		}

		if (keyState[KEY_INPUT_DOWN])
		{
			cA.center.y += speed;

		}

		UINT32 color = 0xffffff;
		if (IsHit(cA, cB))
		{
			color = 0xffaaaa;
			float diffX=cA.center.x - cB.center.x;
			float diffY=cA.center.y - cB.center.y;
			float singX = diffX < 0 ? -1.0f : 1.0f;
			float singY = diffY < 0 ? -1.0f : 1.0f;

			//float diffX = (rcA.w + rcB.w) - float(rcA.center.x - rcB.center.x);
			//float diffY = (rcA.h + rcB.h) - float(rcA.center.y - rcB.center.y);
			if (diffX < diffY) {
				cA.center.x -= diffX;
			}
			else
			{
				cA.center.y -= diffY;
			}
		}

		DrawCircleAA(cA.center.x, cA.center.y, cA.radias, 32, color, true);
		DrawCircleAA(cB.center.x, cB.center.y, cB.radias, 32, color, true);

		ScreenFlip();
	}
	DxLib::DxLib_End();
	return 0;
}