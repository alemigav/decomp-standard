/* FUN_8016224c
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x8016224c  body 0x8016224c..0x8016230f  size 196 B
 * body sha256 9f74d2220fce997d6ad7e04be2ff5b7d2774e19c4758978bc032e62bfed89cb5
 * provider record sha256 af5f2be500b9ce6c1fb506d021b114110600b9e693d91f0c09e9337357d7de7a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016224c(int param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar2;
  short sVar3;
  uint uVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x300;
    *(undefined1 *)(param_1 + 6) = 1;
    uVar2 = func_0x80033604();
    *(ushort *)(param_1 + 500) = (uVar2 & 0xff) + 10 & 0x1f;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x80089d54(param_1,param_2,param_3,0x400);
  sVar3 = *(short *)(param_1 + 500) + -1;
  *(short *)(param_1 + 500) = sVar3;
  if (sVar3 == -1) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    uVar1 = func_0x80033604();
    if ((uVar1 & 1) != 0) {
      *(undefined4 *)(param_1 + 4) = 0x1040000;
    }
  }
  return;
}
