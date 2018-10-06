#include "stdio.h"
#include "windows.h"
/*
By:迷 雾 少 年
QQ:1462063314
*/
int  Base_(char *szSting);
int  AsciiToB(char p)
{
	int i = 0;
		  if (p >= 0 && p <= 25)
		i = 65 + p;
	if (p >= 26 && p <= 51)
		i = 71 + p;
	if (p >= 52 && p <= 61)
		i = p - 4;
		if (p == 62) i = '+';
	if (p == 63) i = '/';
	return i;
}
//把3个字符转为Base64格式的字符
int  Base64(char *_Char, char *Resu)
{
	int _Data = 0;
	int _Int_[4] = { 0 };
	//_Data = 5533549;
	_Data = Base_(_Char);
	//_Data =7929856;
	Resu[3] = _Data & 0x3F;
	// 0xFC0
	Resu[2] = (_Data & 0XFC0) >> 6;
	// 0x3F000
	Resu[1] = (_Data & 0x3F000) >> 12;
	// FC0000
	Resu[0] = (_Data & 0xFC0000) >> 18;
	//Resu[0] = (_Data & 0x3F000000) >> 24;
	/*查表咯*/
	Resu[0] = AsciiToB(Resu[0]);
	Resu[1] = AsciiToB(Resu[1]);
	Resu[2] = AsciiToB(Resu[2]);
	Resu[3] = AsciiToB(Resu[3]);
	return 0;
}
int  Base_(char *szSting)
{
	int  i = 0;
	char *p = (char*)&i;
	*p = szSting[2];
	p++;
	*p = szSting[1];
	p++;
	*p = szSting[0];
	p++;
	*p = szSting[0];
	return i;
}
int _Base_(char *In, char *_Out)
{
	char Res[5] = { 0 };
	int i = 0;
	int iz;
	char Out[5] = { 0 };
	char out[250] = { 0 };
	int lenth = strlen(In);
	for (i = 0; i < lenth;)
	{
		lstrcpynA(Res, In + i, 4);
		Res[4] = 0;
		Base64(Res, Out);
		lstrcatA(out, Out);
		i = i + 3;
		//还剩余1字节
		if (lenth - i == 2)
		{
			iz = 1;

		}
		if (lenth - i == 1)
		{
			iz = 2;
		}
	}
	//把A都替换为=
	lenth = strlen(out) - 1;
	for (i = 0; i < iz; i++)
	{
		out[lenth - i] = '=';

	}
	lstrcpyA(_Out, out);
	return 0;
}
int main()
{
	char sz_Out_String[200] = { 0 };
	char out[280] = { 0 };
	printf("请输入要转换的字符C:");
	scanf("%s", sz_Out_String);
	_Base_(sz_Out_String, out);
	printf("\n转换结果%s\n", out);
	return 0;
}