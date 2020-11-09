#pragma once
#ifdef AUTOMABASE_EXPORTS
#define AUTOMABASE_API __declspec(dllexport)
#else
#define AUTOMABASE_API __declspec(dllimport)
#endif
namespace AutoLib {
	AUTOMABASE_API class DESEncrypt
	{
	public:
		AUTOMABASE_API DESEncrypt();
		AUTOMABASE_API ~DESEncrypt();
		AUTOMABASE_API void Encrypt(byte in[8], byte out[8]);
		AUTOMABASE_API void Decrypt(byte in[8], byte out[8]);
		AUTOMABASE_API void SetEncrptKey(const byte key[8]);
	};
}
