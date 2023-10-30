#include <unity.h>
#include "ZIP_Router_logging.h"
void test_large_frame_print()
{
  uint8_t cmd1[] = {0x55, 0xC0, 0xB5, 0x10, 0x9F, 0x03, 0x57, 0x01, 0x12, 0x41, 
      0x26, 0xD6, 0xF6, 0xE0, 0xB9, 0x0B, 0x28, 0xA2, 0x61, 0x9A, 0x65, 0x56,
      0xB5, 0xC8, 0xEB, 0xB4, 0xC4, 0xB7, 0x86, 0xEE, 0x5F, 0x82, 0x60, 0x5D,
      0x65, 0xE5, 0x9B, 0xAF, 0x72, 0x47, 0xAD, 0x30, 0x37, 0x86, 0x09, 0xDE,
      0x42, 0x58, 0x8C, 0x4F, 0xB0, 0x39, 0x93, 0x8D, 0xF1, 0x5C, 0x9A, 0xEC,
      0x9C, 0xC8, 0x2E, 0xF0, 0xD2, 0x7F, 0xF8, 0x56, 0xD9, 0x13, 0xF7, 0x23,
      0xEE, 0xA8, 0x17, 0x13, 0x14, 0x79, 0x35, 0x1C, 0x03, 0x3B, 0x1B, 0xED,
      0x59, 0xFE, 0x24, 0x7E, 0xB2, 0x1D, 0x6D, 0xE4, 0xC7, 0xA6, 0xCA, 0xDC,
      0x34, 0x58, 0xB0, 0xD0, 0x7F, 0xF0, 0x9C, 0xF7, 0x7E, 0xF4, 0x3B, 0x95,
      0xDC, 0x3C, 0x79, 0xF8, 0xBC, 0xAE, 0x21, 0xC9, 0x1E, 0xB5, 0x46, 0x94,
      0x71, 0x98, 0x59, 0xB3, 0xCF, 0x6F, 0xC9, 0xE6, 0xD1, 0x3F, 0x28, 0xCD,
      0xB7, 0x24, 0x69, 0xC7, 0xB2, 0x17, 0x42, 0xA6, 0xEF, 0x9F, 0xAA, 0xC4,
      0xA8, 0xDC, 0xAE, 0xEB, 0xA0, 0x08};

  const char *output = "55 C0 B5 10 9F 03 57 01 12 41 26 D6 F6 E0 B9 0B 28 A2 61 9A 65 56 B5 C8 EB B4 C4 B7 86 EE 5F 82 60 5D 65 E5 9B AF 72 47 AD 30 37 86 09 DE 42 58 8C 4F B0 39 93 8D F1 5C 9A EC 9C C8 2E F0 D2 7F F8 56 D9 13 F7 23 EE A8 17 13 14 79 35 1C 03 3B 1B ED 59 FE 24 7E B2 1D 6D E4 C7 A6 CA DC 34 58 B0 D0 7F F0 9C F7 7E F4 3B 95 DC 3C 79 F8 BC AE 21 C9 1E B5 46 94 71 98 59 B3 CF 6F C9 E6 D1 3F 28 CD B7 24 69 C7 B2 17 42 A6 EF 9F AA C4 A8 DC AE EB A0 08 ";
  
  TEST_ASSERT_EQUAL_STRING(print_frame(cmd1, sizeof(cmd1)), output);
  TEST_ASSERT_EQUAL_STRING(print_frame(cmd1, 257), "frame too long");
  TEST_ASSERT_EQUAL_STRING(print_frame(0, 257), "can not print frame");
  TEST_ASSERT_EQUAL_STRING(print_frame(cmd1, 0), "can not print frame");
}

