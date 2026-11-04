/* FUN_80162af8
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80162af8  body 0x80162af8..0x80162cf3  size 508 B
 * body sha256 28b8b1e9d6739e701ab05da4f4098525e5f30c0d446257176593d77d33423639
 * provider record sha256 d17eac7155348909a0961e1ce8d7e4c135faa9322ae62a4f54fed1f039f05374
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162af8(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  ushort uVar3;
  int iVar2;
  short sVar4;
  undefined2 uVar5;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined1 *)(param_1 + 6) = 1;
    uVar1 = func_0x80033604();
    uVar5 = 0xffe8;
    if ((uVar1 & 1) != 0) {
      uVar5 = 0x18;
    }
    *(undefined2 *)(param_1 + 500) = uVar5;
    *(undefined2 *)(param_1 + 700) = *(undefined2 *)(param_1 + 0x2c0);
    *(uint *)(param_1 + 0x1e8) = (uint)*(byte *)(param_1 + 0x2b4) * 0x80000 + 0x1000f00;
  case 1:
    sVar4 = *(short *)(param_1 + 0x2c2) + *(short *)(param_1 + 500);
    iVar2 = (int)sVar4;
    *(short *)(param_1 + 0x2c2) = sVar4;
    *(short *)(param_1 + 700) = *(short *)(param_1 + 700) + 0x18;
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    if (0x3ff < iVar2) {
      uVar5 = 0xfff8;
      *(undefined1 *)(param_1 + 6) = 2;
      if (0 < *(short *)(param_1 + 500)) {
        uVar5 = 8;
      }
      *(undefined2 *)(param_1 + 500) = uVar5;
    }
    goto LAB_80162c2c;
  case 2:
    *(short *)(param_1 + 700) = *(short *)(param_1 + 700) + -8;
    *(short *)(param_1 + 0x2c2) = *(short *)(param_1 + 0x2c2) - *(short *)(param_1 + 500);
    if ((int)*(short *)(*(int *)(param_1 + 0x250) + 0x25e) <=
        *(int *)(*(int *)(param_1 + 0x234) + 0x340)) {
      *(undefined1 *)(param_1 + 6) = 3;
      uVar3 = func_0x80033604(param_1);
      *(ushort *)(param_1 + 500) = (uVar3 & 7) + 0xf;
    }
LAB_80162c2c:
    func_0x80089d54(param_1,param_2,param_3,0x100);
    goto LAB_80162cd4;
  case 3:
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar2 != 0) {
      *(undefined1 *)(param_1 + 6) = 4;
      *(uint *)(param_1 + 0x1e8) = (uint)*(byte *)(param_1 + 0x2b4) * 0x10000 + 0x3000f00;
    }
    break;
  case 4:
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar2 != 0) {
      if ((*(char *)(param_1 + 0x2bf) == '\x01') && (*(char *)(param_1 + 0x2c6) == '\0')) {
        *(undefined1 *)(param_1 + 5) = 2;
        *(undefined2 *)(param_1 + 6) = 0;
        *(undefined1 *)(param_1 + 0x2be) = 0;
        *(undefined1 *)(param_1 + 0x2cb) = 2;
      }
      else {
        *(undefined1 *)(param_1 + 6) = 5;
      }
    }
  }
LAB_80162cd4:
  FUN_8016375c(param_1,0);
  return;
}
