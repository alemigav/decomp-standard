/* FUN_801687d8
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x801687d8  body 0x801687d8..0x80168863  size 140 B
 * body sha256 5d3b0a4c18f6684f88465f5c4e5dec6ac5eb9e3c7d12680889fc0e59bee74015
 * provider record sha256 27995b40052ad8f2db4864ac99ea0103d56b4e9440fa590e1622ba8f72e2b1d4
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801687d8(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x8050700;
    *(undefined1 *)(param_1 + 6) = 1;
    *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) | 0x400;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x200);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
    *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) & 0xfbff;
  }
  return;
}
