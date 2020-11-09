
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the SYUNEW2D_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
extern "C"
{
	//����ꪺID
	int _stdcall GetID(DWORD *ID_1, DWORD *ID_2, char *InPath);

	//����ꪺ����
	int _stdcall NT_GetIDVersion(int *Version, char *InPath);
	//����ꪺ�X�i����
	int _stdcall NT_GetVersionEx(int *Version, char *InPath);

	//�d��[�K��
	int _stdcall FindPort(int start, char *OutPath);


	//�g�@��줸�ը�[�K�ꤤ	
	int _stdcall YWriteEx(BYTE *InData, short address, short len, char *HKey, char *LKey, char *Path);
	//�g�@�Ӧ줸�ը�[�K�ꤤ�A�@�뤣�ϥ�
	int __stdcall YWrite(BYTE InData, short address, char * HKey, char *LKey, char *Path);
	//�q�[�K�ꤤŪ���@��줸��
	int _stdcall YReadEx(BYTE *OutData, short address, short len, char *HKey, char *LKey, char *Path);
	//�q�[�K�ꤤŪ���@�Ӧ줸�աA�@�뤣�ϥ�
	int __stdcall YRead(BYTE *OutData, short address, char * HKey, char *LKey, char *Path);

	//�q�[�K�ꤤŪ�r����
	int __stdcall YReadString(char *string, short Address, int len, char * HKey, char *LKey, char *Path);
	//�g�r�����[�K�ꤤ
	int __stdcall YWriteString(char *InString, short Address, char * HKey, char *LKey, char *Path);
	//�]�m�g�K�X
	int __stdcall SetWritePassword(char * W_HKey, char *W_LKey, char * new_HKey, char *new_LKey, char *InPath);
	//�]�mŪ�K�X
	int __stdcall SetReadPassword(char * W_HKey, char *W_LKey, char * new_HKey, char *new_LKey, char *InPath);

	//�]�m�W�j��k�K�_�@
	int __stdcall SetCal_2(char *Key, char *InPath);
	//�ϥμW�j��k�@��r����i��[�K
	int _stdcall EncString(char *InString, char *OutString, char *Path);
	//�ϥμW�j��k�@��G�i��ƾڶi��[�K
	int _stdcall Cal(BYTE *InBuf, BYTE *OutBuf, char *Path);


	//�ϥμW�j��k��r����i��ѱK(�ϥγn��)
	void _stdcall DecString(char *InString, char *OutString, char *Key);
	//�ϥμW�j��k��G�i��ƾڶi��[�K(�ϥγn��)
	void _stdcall  DecBySoft(BYTE  *   aData, BYTE   *   aKey);
	void _stdcall  EncBySoft(BYTE  *   aData, BYTE   *   aKey);
	//�r����ΤG�i��ƾڪ��ഫ
	void __stdcall  HexStringToByteArray(char * InString, BYTE *out_data);
	void __stdcall  ByteArrayToHexString(BYTE *in_data, char * OutString, int len);
	//��l������,�`�N�A��l�����A�Ҧ����ƾڬ�0�AŪ�g�K�X�]��00000000-00000000�A�W�j��k���|�Q��l��
	int __stdcall ReSet(char *InPath);


	//�H�U��ư�������ഹ������
	//�ͦ�SM2�K�_��
	int __stdcall YT_GenKeyPair(char* PriKey, char *PubKeyX, char *PubKeyY, char *InPath);
	//�]�mPin�X
	int __stdcall  YtSetPin(char *old_pin, char *new_pin, char *InPath);
	//�]�mSM2�K�_��Ψ���
	int __stdcall  Set_SM2_KeyPair(char *PriKey, char *PubKeyX, char *PubKeyY, char *sm2UserName, char *InPath);
	//��^�[�K�ꪺ���_
	int __stdcall Get_SM2_PubKey(char *PubKeyX, char *PubKeyY, char *sm2UserName, char *InPath);
	//��G�i��ƾڶi��SM2�[�K
	int __stdcall SM2_EncBuf(BYTE *InBuf, BYTE *OutBuf, int inlen, char *InPath);
	//��G�i��ƾڶi��SM2�ѱK
	int __stdcall SM2_DecBuf(BYTE *InBuf, BYTE *OutBuf, int inlen, char* pin, char *InPath);
	//��r����i��SM2�[�K
	int __stdcall SM2_EncString(char *InString, char *OutString, char *InPath);
	//��r����i��SM2�ѱK
	int __stdcall SM2_DecString(char *InString, char *OutString, char* pin, char *InPath);
	//������i��ñ�W
	int __stdcall  YtSign(char *msg, char *OutSign, char* pin, char *InPath);
	void __stdcall  GetE(BYTE *Z, BYTE  *Hashmsg, BYTE *OutBuf);
	void __stdcall  GetZ(char *id, char *ecc_kx, char *ecc_ky, BYTE *OutBuf);
	//��ñ�W�i������
	int __stdcall  YtVerfiy(char *id, char *msg, char *kx, char *ky, char *VerfiySign, BOOL *IsVailSign, char *InPath);
	//��^�ꪺ�w�󴹤��ߤ@ID
	int __stdcall GetChipID(char *OutChipID, char *InPath);

	//�H�U��ư�����aU�L����
	//�]�m�O�_���U�L�����L�šA�u����ܡA�_�������
	int _stdcall SetHidOnly(BOOL IsHidOnly, char *InPath);
	//�]�mU�L�������uŪ���A
	int _stdcall SetUReadOnly(char *InPath);
	//��^U�L�����O�_���uŪ���A�A�u���uŪ
	int _stdcall IsUReadOnly(BOOL *IsReadOnly, char *InPath);
	//�d����w���[�K��]�ϱo���q��k�@�^�A��^���OU�L�����|,�YU�L���L�šA�q�L�o�Ӹ��|�]�i�H�����ާ@��
	int _stdcall FindU_2(int start, DWORD in_data, DWORD verf_data, char *OutPath);
	//�d����w���[�K��]�ϱo���q��k�G�^�A��^���OU�L�����|,�YU�L���L�šA�q�L�o�Ӹ��|�]�i�H�����ާ@��
	int _stdcall FindU_3(int start, DWORD in_data, DWORD verf_data, char *OutPath);
	//�d��[�K��A��^���OU�L�����|,�YU�L���L�šA�q�L�o�Ӹ��|�]�i�H�����ާ@��
	int _stdcall FindU(int start, char *OutPath);

}

