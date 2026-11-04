/* FUN_80163d6c
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80163d6c  body 0x80163d6c..0x8016400f  size 676 B
 * body sha256 9d8480a1dac60fa0f5b2fbe111ab4aadbc05b0d005f22bdc021c30b8d189aa79
 * provider record sha256 56c43dba473ad6b127e2f6359034d6f234598d41f1ff92ccec52009ccaa04a3e
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163d6c(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined1 *)(param_1 + 6) = 1;
    if (*(char *)(param_1 + 0x2cd) == '\0') {
      uVar4 = func_0x80033604();
      *(undefined2 *)(param_1 + 0x1f6) = *(undefined2 *)(&DAT_80167e5c + (uVar4 & 7) * 2);
    }
    else {
      *(undefined2 *)(param_1 + 0x1f6) = 0x40;
    }
    *(undefined1 *)(param_1 + 0x2d2) = 1;
  case 1:
    *(undefined1 *)(param_1 + 6) = 2;
    if (*(char *)(param_1 + 0x2cd) == '\0') {
      bVar2 = func_0x80033604();
      cVar1 = (bVar2 & 0xf) + 0xf;
    }
    else {
      cVar1 = -1;
    }
    *(char *)(param_1 + 0x206) = cVar1;
    iVar3 = (int)*(short *)(param_1 + 0x1f6);
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    uVar4 = 0x1000000;
    if (iVar3 == 0x20) {
      uVar4 = 0x2000000;
    }
    *(uint *)(param_1 + 0x1e8) = uVar4 | 0x300;
  case 2:
    FUN_80166c70(param_1,(int)*(short *)(param_1 + 0x1f6));
    uVar4 = (uint)*(short *)(param_1 + 0x1f6);
    if ((int)uVar4 < 0) {
      uVar4 = -uVar4;
    }
    if (((*(ushort *)(param_1 + 0x2c2) & 0xfff) + ((uVar4 & 0xffff) - 0x800) & 0xfff) <=
        (uVar4 & 0xffff) << 1) {
      if ((_DAT_800e1128 & 0x20) == 0) {
        *(undefined1 *)(param_1 + 6) = 5;
      }
      else {
        *(undefined1 *)(param_1 + 6) = 4;
        *(undefined4 *)(param_1 + 0x1e8) = 0x300;
      }
    }
    cVar1 = *(char *)(param_1 + 0x206);
    *(char *)(param_1 + 0x206) = cVar1 + -1;
    if (cVar1 == '\x01') {
      *(undefined1 *)(param_1 + 6) = 3;
      bVar2 = func_0x80033604();
      *(byte *)(param_1 + 0x206) = (bVar2 & 0xf) + 0xf;
      *(undefined4 *)(param_1 + 0x1e8) = 0x300;
    }
    break;
  case 3:
    cVar1 = *(char *)(param_1 + 0x206);
    *(char *)(param_1 + 0x206) = cVar1 + -1;
    if (cVar1 == '\x01') {
      *(undefined1 *)(param_1 + 6) = 1;
    }
    break;
  case 4:
    if ((_DAT_800e1128 & 0x20) != 0) break;
  case 5:
    *(undefined1 *)(param_1 + 6) = 6;
    *(undefined2 *)(param_1 + 0x2c2) = 0x800;
    *(undefined1 *)(param_1 + 0x2d2) = 1;
    _DAT_800e1128 = _DAT_800e1128 | 0x20;
    *(undefined2 *)(param_1 + 0x1e0) = 100;
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(undefined4 *)(param_1 + 0x1e8) = 0x2000300;
    break;
  case 6:
    FUN_80166cbc(param_1,0,0,0);
    if (*(int *)(param_1 + 0x2c) <= *(int *)(param_1 + 0x2c8)) {
      *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c8);
      *(undefined1 *)(param_1 + 5) = 5;
      *(undefined2 *)(param_1 + 6) = 0;
    }
  }
  func_0x80089d54(param_1,param_2,param_3,0x400);
  FUN_80167938(param_1);
  return;
}
