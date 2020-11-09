
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the SYUNEW2D_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
extern "C"
{
	//獲取鎖的ID
	int _stdcall GetID(DWORD *ID_1, DWORD *ID_2, char *InPath);

	//獲到鎖的版本
	int _stdcall NT_GetIDVersion(int *Version, char *InPath);
	//獲取鎖的擴展版本
	int _stdcall NT_GetVersionEx(int *Version, char *InPath);

	//查找加密鎖
	int _stdcall FindPort(int start, char *OutPath);


	//寫一批位元組到加密鎖中	
	int _stdcall YWriteEx(BYTE *InData, short address, short len, char *HKey, char *LKey, char *Path);
	//寫一個位元組到加密鎖中，一般不使用
	int __stdcall YWrite(BYTE InData, short address, char * HKey, char *LKey, char *Path);
	//從加密鎖中讀取一批位元組
	int _stdcall YReadEx(BYTE *OutData, short address, short len, char *HKey, char *LKey, char *Path);
	//從加密鎖中讀取一個位元組，一般不使用
	int __stdcall YRead(BYTE *OutData, short address, char * HKey, char *LKey, char *Path);

	//從加密鎖中讀字元串
	int __stdcall YReadString(char *string, short Address, int len, char * HKey, char *LKey, char *Path);
	//寫字元串到加密鎖中
	int __stdcall YWriteString(char *InString, short Address, char * HKey, char *LKey, char *Path);
	//設置寫密碼
	int __stdcall SetWritePassword(char * W_HKey, char *W_LKey, char * new_HKey, char *new_LKey, char *InPath);
	//設置讀密碼
	int __stdcall SetReadPassword(char * W_HKey, char *W_LKey, char * new_HKey, char *new_LKey, char *InPath);

	//設置增強算法密鑰一
	int __stdcall SetCal_2(char *Key, char *InPath);
	//使用增強算法一對字元串進行加密
	int _stdcall EncString(char *InString, char *OutString, char *Path);
	//使用增強算法一對二進制數據進行加密
	int _stdcall Cal(BYTE *InBuf, BYTE *OutBuf, char *Path);


	//使用增強算法對字元串進行解密(使用軟件)
	void _stdcall DecString(char *InString, char *OutString, char *Key);
	//使用增強算法對二進制數據進行加密(使用軟件)
	void _stdcall  DecBySoft(BYTE  *   aData, BYTE   *   aKey);
	void _stdcall  EncBySoft(BYTE  *   aData, BYTE   *   aKey);
	//字元串及二進制數據的轉換
	void __stdcall  HexStringToByteArray(char * InString, BYTE *out_data);
	void __stdcall  ByteArrayToHexString(BYTE *in_data, char * OutString, int len);
	//初始化鎖函數,注意，初始化鎖後，所有的數據為0，讀寫密碼也為00000000-00000000，增強算法不會被初始化
	int __stdcall ReSet(char *InPath);


	//以下函數隻支持智能晶片的鎖
	//生成SM2密鑰對
	int __stdcall YT_GenKeyPair(char* PriKey, char *PubKeyX, char *PubKeyY, char *InPath);
	//設置Pin碼
	int __stdcall  YtSetPin(char *old_pin, char *new_pin, char *InPath);
	//設置SM2密鑰對及身份
	int __stdcall  Set_SM2_KeyPair(char *PriKey, char *PubKeyX, char *PubKeyY, char *sm2UserName, char *InPath);
	//返回加密鎖的公鑰
	int __stdcall Get_SM2_PubKey(char *PubKeyX, char *PubKeyY, char *sm2UserName, char *InPath);
	//對二進制數據進行SM2加密
	int __stdcall SM2_EncBuf(BYTE *InBuf, BYTE *OutBuf, int inlen, char *InPath);
	//對二進制數據進行SM2解密
	int __stdcall SM2_DecBuf(BYTE *InBuf, BYTE *OutBuf, int inlen, char* pin, char *InPath);
	//對字元串進行SM2加密
	int __stdcall SM2_EncString(char *InString, char *OutString, char *InPath);
	//對字元串進行SM2解密
	int __stdcall SM2_DecString(char *InString, char *OutString, char* pin, char *InPath);
	//對消息進行簽名
	int __stdcall  YtSign(char *msg, char *OutSign, char* pin, char *InPath);
	void __stdcall  GetE(BYTE *Z, BYTE  *Hashmsg, BYTE *OutBuf);
	void __stdcall  GetZ(char *id, char *ecc_kx, char *ecc_ky, BYTE *OutBuf);
	//對簽名進行驗證
	int __stdcall  YtVerfiy(char *id, char *msg, char *kx, char *ky, char *VerfiySign, BOOL *IsVailSign, char *InPath);
	//返回鎖的硬件晶片唯一ID
	int __stdcall GetChipID(char *OutChipID, char *InPath);

	//以下函數隻限於帶U盤的鎖
	//設置是否顯示U盤部分盤符，真為顯示，否為不顯示
	int _stdcall SetHidOnly(BOOL IsHidOnly, char *InPath);
	//設置U盤部分為只讀狀態
	int _stdcall SetUReadOnly(char *InPath);
	//返回U盤部分是否為只讀狀態，真為只讀
	int _stdcall IsUReadOnly(BOOL *IsReadOnly, char *InPath);
	//查找指定的加密鎖（使得普通算法一），返回的是U盤的路徑,即U盤的盤符，通過這個路徑也可以直接操作鎖
	int _stdcall FindU_2(int start, DWORD in_data, DWORD verf_data, char *OutPath);
	//查找指定的加密鎖（使得普通算法二），返回的是U盤的路徑,即U盤的盤符，通過這個路徑也可以直接操作鎖
	int _stdcall FindU_3(int start, DWORD in_data, DWORD verf_data, char *OutPath);
	//查找加密鎖，返回的是U盤的路徑,即U盤的盤符，通過這個路徑也可以直接操作鎖
	int _stdcall FindU(int start, char *OutPath);

}

