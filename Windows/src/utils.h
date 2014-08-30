// Copyright (C) 2014       Hykem <hykem@hotmail.com>
// Licensed under the terms of the GNU GPL, version 3
// http://www.gnu.org/licenses/gpl-3.0.txt

#define _CRT_SECURE_NO_WARNINGS
#define MAX_PATH _MAX_PATH

#include <stdlib.h>
#include "aes.h"
#include "sha1.h"
#include "lz.h"
#include "ec.h"

typedef unsigned long long u64;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

// Auxiliary functions (endian swap, xor and prng).
short se16(short i);
int se32(int i);
u64 se64(u64 i);
void xor(unsigned char *dest, unsigned char *src1, unsigned char *src2, int size);
void prng(unsigned char *dest, int size);


// Hex string conversion auxiliary functions.
u64 hex_to_u64(const char* hex_str);
void hex_to_bytes(unsigned char *data, const char *hex_str, unsigned int str_length);
bool is_hex(const char* hex_str, unsigned int str_length);

// Crypto functions (AES128-CBC, AES128-ECB, SHA1-HMAC and AES-CMAC).
void aescbc128_decrypt(unsigned char *key, unsigned char *iv, unsigned char *in, unsigned char *out, int len);
void aescbc128_encrypt(unsigned char *key, unsigned char *iv, unsigned char *in, unsigned char *out, int len);
void aesecb128_encrypt(unsigned char *key, unsigned char *in, unsigned char *out);
bool hmac_hash_compare(unsigned char *key, int key_len, unsigned char *in, int in_len, unsigned char *hash, int hash_len);
void hmac_hash_forge(unsigned char *key, int key_len, unsigned char *in, int in_len, unsigned char *hash);
bool cmac_hash_compare(unsigned char *key, int key_len, unsigned char *in, int in_len, unsigned char *hash, int hash_len);
void cmac_hash_forge(unsigned char *key, int key_len, unsigned char *in, int in_len, unsigned char *hash);
char* extract_file_name(const char* file_path, char real_file_name[MAX_PATH]);