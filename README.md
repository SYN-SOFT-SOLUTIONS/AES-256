# AES-256
AES-256 (Advanced Encryption Standard with 256-bit key) on C++

This project provides a clean, standalone implementation of **AES-256** (Advanced Encryption Standard with 256-bit key) in C++ with **CBC mode** and **PKCS#7 padding**.

## Features
- AES-128 / AES-192 / AES-256 support (configurable via `AESKeyLength`)
- CBC mode (Cipher Block Chaining) with IV
- PKCS#7 padding (automatic on encrypt, automatic removal on decrypt)
- No external dependencies 
- Secure key expansion, SubBytes, ShiftRows, MixColumns, etc.

## How to Use in Your Project

1. **Add files to your project**
   - `AES.h`
   - `AES.cpp`

2. **Include the header**
   ```cpp
   #include "AES.h"
