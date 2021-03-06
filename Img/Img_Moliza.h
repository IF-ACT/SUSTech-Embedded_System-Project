#ifndef __IMG_MOLIZA_H
#define __IMG_MOLIZA_H

#include "lcd.h"

Color Img_Moliza[20][20] = {
		{0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4249, 0x4249, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
		{0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2966, 0x2125, 0x31a8, 0x2945, 0x31c7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
		{0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x31c7, 0x31c7, 0x4208, 0x31c8, 0x424a, 0x39e8, 0x2986, 0x2986, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
		{0x0, 0x0, 0x0, 0x0, 0x0, 0x2986, 0x2145, 0xee7b, 0xe67a, 0x39e7, 0x31a7, 0x31c8, 0x31c8, 0x31a6, 0x2945, 0x2966, 0x0, 0x0, 0x0, 0x0},
		{0x0, 0x0, 0x0, 0x0, 0x31c7, 0x2125, 0xd53a, 0xdddb, 0xe67a, 0xee9b, 0x39c7, 0x2966, 0x31c8, 0x31c8, 0x31a7, 0x2125, 0x2986, 0x0, 0x0, 0x0},
		{0x0, 0x0, 0x5aec, 0x31c7, 0x29a7, 0x31c7, 0x39e8, 0x39e9, 0x39e9, 0x39c8, 0x31c9, 0x29a7, 0x29a7, 0x31c7, 0x39e8, 0x39e8, 0x2966, 0x5aeb, 0x0, 0x0},
		{0x0, 0x0, 0x39e8, 0x39e8, 0x2987, 0x39e8, 0x39e8, 0x31c8, 0x31c8, 0x31c8, 0x31c8, 0x31c8, 0x31a8, 0x31c8, 0x39e8, 0x3186, 0x31a7, 0x3186, 0x0, 0x0},
		{0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbd70, 0xd633, 0xd612, 0x7bee, 0xeef4, 0xde74, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
		{0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xeef3, 0xeed3, 0xde74, 0xde73, 0xeef3, 0xde74, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
		{0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf735, 0xde73, 0xe6b5, 0xe6b5, 0xe6d5, 0x0, 0xf714, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
		{0x0, 0x0, 0x0, 0x0, 0x0, 0xcdf2, 0xc5f1, 0xef14, 0xde9a, 0xa535, 0xb5b6, 0xce57, 0xf734, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
		{0x0, 0x0, 0x0, 0x0, 0x0, 0x2166, 0x1925, 0x3187, 0x4229, 0x29a8, 0x2988, 0x2125, 0x3187, 0x2967, 0x73af, 0x0, 0x0, 0x0, 0x0, 0x0},
		{0x0, 0x0, 0x0, 0x31c7, 0x2967, 0x39e9, 0x3a2a, 0x3a0a, 0x3a0a, 0x3209, 0x3188, 0x18e5, 0x21, 0x841, 0x18e5, 0x18e5, 0x2946, 0x0, 0x0, 0x0},
		{0x0, 0x0, 0xd6ba, 0x9cd3, 0x31c8, 0x420a, 0x31c8, 0x2987, 0x31c8, 0x422a, 0x3a09, 0x2967, 0x863, 0x21, 0x2967, 0x31a8, 0x31a8, 0xa535, 0x0, 0x0},
		{0x0, 0x0, 0x0, 0xd6ba, 0xa534, 0x1904, 0x841, 0x862, 0x2126, 0x4a8b, 0x4a8b, 0x31c8, 0x2106, 0x1083, 0x2967, 0x5aec, 0xc619, 0x0, 0x0, 0x0},
		{0x0, 0x0, 0x0, 0x0, 0xd67a, 0xbdd7, 0x9cb2, 0x94b2, 0xa534, 0xbdb7, 0xb5d7, 0xbdd7, 0xbdd7, 0xa514, 0xb5d7, 0x0, 0x0, 0x0, 0x0, 0x0},
		{0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3124, 0xcb69, 0x61c4, 0x61c4, 0xcb69, 0x3124, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
		{0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3124, 0x7267, 0x61c4, 0x61c4, 0x8225, 0x3124, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
		{0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x834b, 0x9ac6, 0xab08, 0x8ac8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
		{0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xcb69, 0xcb69, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}

};

#endif
