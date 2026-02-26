// =============================================================================
// AES.h — заголовочный файл для реализации алгоритма AES
// Режимы: CBC (Cipher Block Chaining)
// Поддерживаемые длины ключей: 128, 192, 256 бит
// 
// Разработчик: Syn-Soft LTD, Merkulov E. V.
// Copyright © 2026 Syn-Soft LTD. Все права защищены.
// =============================================================================

/*
 * AES.cpp — AES (Rijndael) encryption implementation
 * Copyright 2026 Syn-Soft LTD
 *
 * Licensed under the Apache License, Version 2.0
 * http://www.apache.org/licenses/LICENSE-2.0
 */

#pragma once

#include <vector>
#include <cstdint>
#include <cstddef>  // для size_t

// =============================================================================
// Перечисление для выбора длины ключа AES
// =============================================================================
enum AESKeyLength {
    AES_128,    // 128 бит (16 байт) — 10 раундов
    AES_192,    // 192 бита (24 байта) — 12 раундов
    AES_256     // 256 бит (32 байта) — 14 раундов
};

// =============================================================================
// Класс AES — реализация алгоритма шифрования Rijndael
// =============================================================================
class AES {
private:
    AESKeyLength keyLength_;  // Длина ключа

    // =========================================================================
    // Вспомогательные функции
    // =========================================================================
    uint32_t getNk() const;  // Получить количество 32-битных слов в ключе
    uint32_t getNr() const;  // Получить количество раундов

    // =========================================================================
    // Внутренние функции алгоритма AES
    // =========================================================================
    void keyExpansion(const uint8_t* key, uint8_t* roundKey);
    void addRoundKey(uint8_t state[4][4], const uint8_t* roundKey);
    void subBytes(uint8_t state[4][4]);
    void shiftRows(uint8_t state[4][4]);
    void mixColumns(uint8_t state[4][4]);
    void invSubBytes(uint8_t state[4][4]);
    void invShiftRows(uint8_t state[4][4]);
    void invMixColumns(uint8_t state[4][4]);

public:
    // =========================================================================
    // Конструктор
    // =========================================================================
    explicit AES(AESKeyLength keyLength);

    // =========================================================================
    // Основные методы шифрования/дешифрования
    // =========================================================================
    std::vector<uint8_t> EncryptCBC(const uint8_t* input, size_t length, 
                                    const uint8_t* key, const uint8_t* iv);
    std::vector<uint8_t> DecryptCBC(const uint8_t* input, size_t length, 
                                    const uint8_t* key, const uint8_t* iv);
};
