/* FUN_80048294
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80048294  body 0x80048294..0x800482df  size 76 B
 * body sha256 1c984aa2b475fded42a4b309034ba3f52dec5006c82c6446b66c2edbda70fb54
 * provider record sha256 43b61f2bd9c4bb9b8c14de53f782b38b7f288c9d00322befa138248410b028d4
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
float FUN_80048294(float param_1)

{
  if (0.0 < param_1) {
    return 1.5707964 - 1.0 / param_1;
  }
  return -1.5707964 - 1.0 / param_1;
}
