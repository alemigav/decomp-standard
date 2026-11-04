/* FUN_80164010
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80164010  body 0x80164010..0x801642af  size 672 B
 * body sha256 7e01c251de5dabec3546b6f0b4ebd8bab41837c43e8dbff8d9dd3026652974d2
 * provider record sha256 6ccb8438233dc6625292e9fa03e2e17684983733cad43e263bcc55ff9029c0db
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164010(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  short sVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  bVar1 = *(byte *)(param_1 + 6);
  iVar5 = 9999;
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        func_0x80032bd8(param_1,0,(int)*(short *)(param_1 + 0x2c2));
        iVar5 = func_0x80089d54(param_1,param_2,param_3,0x400);
        if (iVar5 != 0) {
          *(undefined1 *)(param_1 + 0x2be) = 1;
          *(undefined2 *)(param_1 + 0x2b6) = 0x800;
          if ((*(byte *)(param_1 + 0x2cc) & 1) == 0) {
            sVar2 = *(short *)(param_1 + 0x66);
          }
          else {
            sVar2 = *(short *)(param_1 + 100);
          }
          *(short *)(param_1 + 0x66) = sVar2 + 0x800;
          *(undefined2 *)(param_1 + 0x68) = 0x800;
          *(undefined1 *)(param_1 + 0x2ce) = 0x96;
          *(undefined2 *)(param_1 + 100) = 0;
          *(undefined2 *)(param_1 + 0x1e0) = 0x4c9;
          *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + -0x1db;
          func_0x80032b5c(param_1,(int)*(short *)(param_1 + 0x2b6));
          *(undefined4 *)(param_1 + 0x120) = 0;
          *(undefined4 *)(param_1 + 0x124) = 0;
          *(undefined4 *)(param_1 + 0x128) = 0;
          *(undefined4 *)(param_1 + 300) = 0x3200320;
          *(undefined4 *)(param_1 + 0x130) = 0;
          *(undefined4 *)(param_1 + 0x134) = 0xfa8803e8;
          *(undefined4 *)(param_1 + 0x138) = 0x3e80578;
          *(undefined4 *)(param_1 + 0x13c) = 0;
          *(undefined2 *)(param_1 + 0x134) = 0;
          *(undefined4 *)(param_1 + 4) = 0x1000000;
          *(undefined1 *)(param_1 + 0x2d2) = 0;
          _DAT_800e1128 = _DAT_800e1128 & 0xffdf;
          *(undefined1 *)(param_1 + 0x2c1) = 0;
        }
      }
      goto LAB_8016428c;
    }
    if (bVar1 != 0) goto LAB_8016428c;
    *(undefined1 *)(param_1 + 6) = 1;
    if ((*(byte *)(param_1 + 0x2cc) & 1) == 0) {
      *(undefined2 *)(param_1 + 0x1e0) = 0x19;
      *(undefined2 *)(param_1 + 0x1e2) = 0;
    }
    else {
      *(undefined2 *)(param_1 + 0x1e0) = 0;
      *(undefined2 *)(param_1 + 0x1e2) = 0x19;
    }
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(undefined4 *)(param_1 + 0x120) = 0;
    *(undefined4 *)(param_1 + 0x124) = 0;
    *(undefined4 *)(param_1 + 0x128) = 0;
    *(undefined4 *)(param_1 + 300) = 0x1e001e;
    *(undefined4 *)(param_1 + 0x130) = 0;
    *(undefined4 *)(param_1 + 0x134) = 0xff9c03e8;
    *(undefined4 *)(param_1 + 0x138) = 0x3e80578;
    *(undefined4 *)(param_1 + 0x13c) = 0;
    *(undefined4 *)(param_1 + 0x1e8) = 0x300;
  }
  iVar6 = *(int *)(param_1 + 0x2dc);
  if (iVar6 == 0) {
LAB_80164150:
    bVar3 = iVar5 < 0x9c5;
  }
  else {
    bVar3 = false;
    if (*(char *)(iVar6 + 4) != '\a') {
      iVar5 = *(int *)(param_1 + 0x28) - *(int *)(iVar6 + 0x28);
      iVar4 = *(int *)(param_1 + 0x30) - *(int *)(iVar6 + 0x30);
      iVar5 = func_0x80040bb4(iVar5 * iVar5 + iVar4 * iVar4);
      if (*(char *)(iVar6 + 0x2be) != '\x01') {
        iVar5 = 9999;
      }
      goto LAB_80164150;
    }
  }
  if (!bVar3) {
    *(undefined1 *)(param_1 + 6) = 2;
    *(undefined4 *)(param_1 + 0x1e8) = 0xe000300;
  }
  func_0x80089d54(param_1,param_2,param_3,0x400);
LAB_8016428c:
  FUN_80167938(param_1);
  return;
}
