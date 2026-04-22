#ifndef CTITLESCENE H
#define CTITLESCENE_H
#include"CSCeneBase.h"
#include"CFont.h"

//タイトルシーン
class CTitleScene :public CSceneBase
{
public:
	//コンストラクタ
	CTitleScene();
	//デストラクタ
	~CTitleScene();
	//シーン読み込み
	void Load();
	//シーンの更新処理
	void Update();
private:
	CFont mFont;//フォントクラスのインスタンス
};
#endif
