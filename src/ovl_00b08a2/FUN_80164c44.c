/* FUN_80164c44
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x80164c44  body 0x80164c44..0x80164e13  size 464 B
 * body sha256 7b02e537a4ffb4f2743e008b524457e1f8259fef5e57e8b87e17e928509e8f3b
 * provider record sha256 e2e7a9966898fcd8d509d0c94c6dec8d50a1e6bf2a8b263310fd381e6c89d92c
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164c44(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  char cVar2;
  uint *puVar3;
  
  puVar3 = *(uint **)(param_1 + 0x234);
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    puVar3 = *(uint **)(param_1 + 0x234);
    *(undefined4 *)(param_1 + 0x1e8) = 0;
    *(undefined1 *)(param_1 + 6) = 1;
    *puVar3 = *puVar3 | 1;
    *(undefined2 *)(param_1 + 0x68) = 0x40;
    *(undefined2 *)(param_1 + 0x66) = 0;
    *(short *)(param_1 + 100) =
         *(short *)(&DAT_801671c0 + (uint)*(byte *)(param_1 + 0x2b4) * 2) + -0x400;
    *(byte *)(_DAT_800e13f0 + 0x2c4) =
         *(byte *)(_DAT_800e13f0 + 0x2c4) | (byte)(1 << (*(byte *)(param_1 + 0x2b4) + 4 & 0x1f));
  case 1:
    func_0x80089d54(param_1,param_2,param_3,0x40);
    sVar1 = *(short *)(puVar3 + 0x49);
    *(short *)(puVar3 + 0x49) = sVar1 + 0x40;
    if (0x1000 < (short)(sVar1 + 0x40)) {
      *(undefined4 *)(param_1 + 0x1e8) = 0x16001f00;
      *(undefined1 *)(param_1 + 6) = 2;
      *(undefined2 *)(puVar3 + 0x49) = 0x1000;
    }
    break;
  case 2:
    cVar2 = func_0x80089d54(param_1,param_2,param_3,0x80);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar2;
    *(short *)(param_1 + 0x68) = *(short *)(param_1 + 0x68) + 8;
    break;
  case 3:
    *(undefined1 *)(param_1 + 6) = 4;
    *(undefined4 *)(param_1 + 0x1e8) = 0x3f00;
  case 4:
    func_0x80089d54(param_1,param_2,param_3,0x40);
    sVar1 = *(short *)(puVar3 + 0x49);
    *(ushort *)(puVar3 + 0x49) = sVar1 - 0x80U;
    if ((int)((uint)(ushort)(sVar1 - 0x80U) << 0x10) < 0) {
      *(undefined2 *)(puVar3 + 0x49) = 0;
      *(undefined4 *)(param_1 + 4) = 0x1000000;
      *(byte *)(_DAT_800e13f0 + 0x2c4) =
           *(byte *)(_DAT_800e13f0 + 0x2c4) & ~(byte)(1 << (*(byte *)(param_1 + 0x2b4) + 4 & 0x1f));
    }
    *(short *)(param_1 + 0x68) = *(short *)(param_1 + 0x68) + -4;
  }
  return;
}
