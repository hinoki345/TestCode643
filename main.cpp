#include<DxLib.h>

int WINAPI WinMain(HINSTANCE , HINSTANCE , LPSTR , int) {
	/*Sample s;
	cout << sizeof(s) << endl;*/
	DxLib::SetMainWindowText(_T("2016190_ŒÃ‰ê‘å‹P"));
	ChangeWindowMode(true);
	SetGraphMode(960,540,32);
	DxLib_Init();

	SetDrawScreen(DX_SCREEN_BACK);
	
	while (ProcessMessage() == 0) {
		ClearDrawScreen();
	
		ScreenFlip();
	
	}
	DxLib_End();
}