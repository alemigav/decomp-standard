/* FUN_80163518
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80163518  body 0x80163518..0x8016373b  size 548 B
 * body sha256 f133a19eb72867677583f625d93dc5afb4fb19605d0b23b6c626e7ddc61bc286
 * provider record sha256 61fa4e0e27c2aefae83074f5c9aaca0f8e20997c31b67cdfc3a38621ce7b1491
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163518(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  ushort uVar3;
  int iVar2;
  ushort uVar4;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(undefined1 *)(param_1 + 6) = 3;
        *(undefined2 *)(param_1 + 0x1e0) = 0x19;
        *(undefined2 *)(param_1 + 0x1e4) = 0;
        *(undefined4 *)(param_1 + 0x120) = 0;
        *(undefined4 *)(param_1 + 0x124) = 0;
        *(undefined4 *)(param_1 + 0x128) = 0;
        *(undefined4 *)(param_1 + 300) = 0x1e001e;
        *(undefined4 *)(param_1 + 0x130) = 0;
        *(undefined4 *)(param_1 + 0x134) = 0xff9c03e8;
        *(undefined4 *)(param_1 + 0x138) = 0x3e80578;
        *(undefined4 *)(param_1 + 0x13c) = 0;
        *(undefined4 *)(param_1 + 0x1e8) = 0xe000300;
      }
      else if (bVar1 != 3) goto LAB_8016371c;
      func_0x80032b5c(param_1,(int)*(short *)(param_1 + 0x2b6));
      iVar2 = func_0x80089d54(param_1,param_2,param_3,0x400);
      if (iVar2 != 0) {
        *(undefined4 *)(param_1 + 4) = 0x1000000;
        *(undefined1 *)(param_1 + 0x2be) = 2;
        *(undefined2 *)(param_1 + 0x1e0) = 0x1c2;
        func_0x80032b5c(param_1,(int)*(short *)(param_1 + 0x2b6));
        *(undefined1 *)(param_1 + 0x2d2) = 0;
        iVar2 = *(int *)(param_1 + 0x2c) + 0x4e2;
        *(int *)(param_1 + 0x2c) = iVar2;
        *(int *)(param_1 + 0x2c8) = iVar2;
        _DAT_800e1128 = _DAT_800e1128 & 0xffdf;
        FUN_80163908(param_1,param_2,param_3);
      }
      goto LAB_8016371c;
    }
    if (bVar1 != 0) goto LAB_8016371c;
    *(undefined1 *)(param_1 + 6) = 1;
    uVar4 = *(ushort *)(param_1 + 0x66) & 0xfff;
    uVar3 = *(short *)(param_1 + 0x2c2) - uVar4;
    *(ushort *)(param_1 + 500) = uVar3 & 0xfff;
    *(undefined2 *)(param_1 + 0x1f6) = 0x18;
    *(ushort *)(param_1 + 0x66) = uVar4;
    if ((uVar3 & 0x800) != 0) {
      *(ushort *)(param_1 + 500) = uVar4 - *(short *)(param_1 + 0x2c2) & 0xfff;
      *(short *)(param_1 + 0x1f6) = -*(short *)(param_1 + 0x1f6);
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0x3000300;
  }
  if (*(short *)(param_1 + 500) < 1) {
    *(undefined1 *)(param_1 + 6) = 2;
    *(undefined2 *)(param_1 + 0x66) = *(undefined2 *)(param_1 + 0x2c2);
  }
  else {
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + *(short *)(param_1 + 0x1f6);
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + -0x18;
  }
  func_0x80089d54(param_1,param_2,param_3,0x400);
LAB_8016371c:
  FUN_80167938(param_1);
  return;
}
