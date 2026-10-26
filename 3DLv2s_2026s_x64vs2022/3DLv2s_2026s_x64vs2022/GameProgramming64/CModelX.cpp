#include <stdio.h>
#include <string.h>
#include "CModelX.h"
#include "glut.h"
#include <ctype.h>	//isspace関数の宣言

/*
* IsDelimiter(c)
* cが\t \r \n スペースなどの空白文字
* または,;"などの文字であれば
* 区切り文字としてtrueを返す
*/
bool CModelX::IsDelimiter(char c)
{
	//isspace(c)
	//cが空白文字なら0以外を返す
	if (isspace(c) != 0)
		return true;
	/*
	strchr(文字列, 文字)
	文字列に文字が含まれていれば、
	見つかった文字へのポインタを返す
	見つからなかったらNULLを返す
	*/
	if (strchr(",;\"", c) != NULL)
		return true;
	//区切り文字ではない
	return false;
}

char* CModelX::GetToken()
{

	/*
	GetToken
	文字列データから、単語を1つ取得する
	*/
	char* p = mpPointer;
	char* q = mToken;

	// 空白や区切り文字を読み飛ばす
	while (*p != '\0' && IsDelimiter(*p)) p++;

	if (*p == '{' || *p == '}') {
		*q++ = *p++;
	}
	else {
		while (*p != '\0' && !IsDelimiter(*p) && *p != '}')
			*q++ = *p++;
	}

	*q = '\0';
	mpPointer = p;

	// コメントなら改行まで読み飛ばす
	if (!strcmp("//", mToken)) {
		while (*p != '\0' && !strchr("\r\n", *p)) p++;
		mpPointer = p;
		return GetToken();
	}

	return mToken;

	return nullptr;
}

CModelX::CModelX()
	: mpPointer(nullptr)
{
	//mTokenを初期化
	memset(mToken, 0, sizeof(mToken));
}

void CModelX::Load(const char* file) {
	//
	//ファイルサイズを取得する
	//
	FILE* fp;	//ファイルポインタ変数の作成
	fp = fopen(file, "rb");	//ファイルをオープンする
	if (fp == NULL) {	//エラーチェック
		printf("fopen error:%s￥n", file);
		return;
	}
	//ファイルの最後へ移動
	fseek(fp, 0L, SEEK_END);
	//ファイルサイズの取得
	int size = ftell(fp);
	//ファイルサイズ+1バイト分の領域を確保
	char* buf = mpPointer = new char[size + 1];
	//
	//ファイルから3Dモデルのデータを読み込む
	//
	//ファイルの先頭へ移動
	fseek(fp, 0L, SEEK_SET);
	//確保した領域にファイルサイズ分データを読み込む
	fread(buf, size, 1, fp);
	//最後に\0を設定する（文字列の終端）
	buf[size] = '\0';
	fclose(fp);	//ファイルをクローズする
	//文字列の最後まで繰り返し
	while (*mpPointer != '\0') {
		GetToken();	//単語の取得
		//単語がFrameの場合
		if (strcmp(mToken, "Frame") == 0) {
			printf("%s ", mToken);	//Frame出力
			GetToken();	//Frame名を取得
			printf("%s\n", mToken); //Frame名を出力
		}
		else	if (strcmp(mToken, "AnimationSet") == 0) {
			printf("%s ", mToken);	//Frame出力
			GetToken();	//AnimationSet名を取得
			printf("%s\n", mToken); //Frame名を出力
		}

	}

	SAFE_DELETE_ARRAY(buf);	//確保した領域を開放する
}
