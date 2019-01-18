# Questions

## What's `stdint.h`?

The <stdint.h> header shall declare sets of integer types having specified widths.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

Using uint8_t, uint32_t, int32_t or uint16_t in a program allows to fill up exactly the amount of usable 
space in a file which is important for bitmap headers.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

A UINT8 is an 8-bit unsigned integer, so it's a 1 byte.
A DWORD is a 32-bit unsigned integer, so it's a 4 bytes.
A LONG is a 32-bit signed integer, so it's a 4 bytes.
A WORD is a 16-bit unsigned integer, so it's a 2 bytes.

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? 
## Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The first two bytes of a BMP file is a WORD which specifies the file type, and the signature word BM (0x4D42) 
indicating that it is a BMP file, using two characters.

## What's the difference between `bfSize` and `biSize`?

bfSize specifies the file size in bytes of the full bitmap file, including header and image.
biSize specifies the file size in bytes of the structure, the info header part of a BMP header.

## What does it mean if `biHeight` is negative?

When biHeight is negative, the bitmap is a top-down DIB (device-independent bitmap) and its origin is 
the upper left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

DWORD biClrUsed specifies the actual number of color indices in the color table used by the bitmap.

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

Because the file is unattainable, so it can't be opened, and segmentation fault is avoided.

## Why is the third argument to `fread` always `1` in our code? (For example, see lines 40, 44, and 75.)

This argument specifies how many elements we want to read and it's 1 struct.

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

The padding would be 3, because 3 pixels * 3 bytes per pixel * 3 padding (bytes are added to bring the 
scanline) = 12, which is a multiple of 4.

## What does `fseek` do?

fseek moves to a specific location in the file position in a given file.

## What is `SEEK_CUR`?

SEEK_CUR is an integer constant which, when used as argument to the fseek function, moves file pointer 
position to given location.
