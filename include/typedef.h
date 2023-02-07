#ifndef _TYPEDEF_H_
#define _TYPEDEF_H_

#include "stdio.h"

typedef unsigned int        m_size_t;                                             // �޷��� 32 bits

typedef unsigned char       m_uint8_t;                                              // �޷���  8 bits
typedef unsigned short int  m_uint16_t;                                             // �޷��� 16 bits
typedef unsigned int        m_uint32_t;                                             // �޷��� 32 bits
typedef unsigned long long  m_uint64_t;                                             // �޷��� 64 bits

typedef signed char         m_int8_t;                                               // �з���  8 bits
typedef signed short int    m_int16_t;                                              // �з��� 16 bits
typedef signed int          m_int32_t;                                              // �з��� 32 bits
typedef signed long long    m_int64_t;                                              // �з��� 64 bits

typedef volatile uint8      m_vuint8_t;                                             // �ױ������� �޷���  8 bits
typedef volatile uint16     m_vuint16_t;                                            // �ױ������� �޷��� 16 bits
typedef volatile uint32     m_vuint32_t;                                            // �ױ������� �޷��� 32 bits
typedef volatile uint64     m_vuint64_t;                                            // �ױ������� �޷��� 64 bits

typedef volatile int8       m_vint8_t;                                              // �ױ������� �з���  8 bits
typedef volatile int16      m_vint16_t;                                             // �ױ������� �з��� 16 bits
typedef volatile int32      m_vint32_t;                                             // �ױ������� �з��� 32 bits
typedef volatile int64      m_vint64_t;                                             // �ױ������� �з��� 64 bits

#endif
