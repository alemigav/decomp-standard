/* FUN_801624b8
 * image   ovl_009d3ba (ovl), base 0x80161cf0
 * address 0x801624b8  body 0x801624b8..0x8016261f  size 360 B
 * body sha256 ee9168728cce33bf1dfef31416a739d6f97b54ced75a7a2139d55bd4959b9fc6
 * provider record sha256 69cbe6cb3bef7fb1ad5f2c22f974a8ecdaacc69841ecbfb6c78aebea246f278e
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801624b8(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  ushort uVar3;
  int iVar2;
  short sVar4;
  
  if (*(char *)(param_1 + 6) == '\0') {
    uVar1 = func_0x80033604();
    *(uint *)(param_1 + 0x1e8) = ((uVar1 & 1) + 1) * 0x1000000 + 0xf00;
    *(undefined1 *)(param_1 + 6) = 1;
    uVar3 = func_0x80033604();
    *(ushort *)(param_1 + 500) = (uVar3 & 0x1f) + 0x3c;
    uVar1 = func_0x80033604();
    if ((uVar1 & 1) != 0) {
      uVar1 = func_0x80033604();
      func_0x80077d18((uVar1 & 1) == 0,param_1);
    }
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  iVar2 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x20);
  iVar2 = (uint)*(ushort *)(param_1 + 0x66) + iVar2;
  *(short *)(param_1 + 0x66) = (short)iVar2;
  if (*(short *)(param_1 + 0x2b4) + 0x180 < iVar2 * 0x10000 >> 0x10) {
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x2b4) + 0x180;
  }
  if ((int)*(short *)(param_1 + 0x66) < *(short *)(param_1 + 0x2b4) + -0x180) {
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x2b4) + -0x180;
  }
  func_0x80089d54(param_1,param_2,param_3,0x100);
  sVar4 = *(short *)(param_1 + 500) + -1;
  *(short *)(param_1 + 500) = sVar4;
  if (sVar4 == -1) {
    *(undefined4 *)(param_1 + 4) = 0x1050000;
  }
  return;
}
