/* FUN_80161dd0
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80161dd0  body 0x80161dd0..0x8016213f  size 880 B
 * body sha256 cd9f17ba5af48590d66af9f87bf183fd136f886e4d971d47c7c9c7fbf62dbf34
 * provider record sha256 8d39c3a08741de54f26b3aa505bf786b3f798d11e0919a59eeba50b1e2cac194
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80161dd0(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar2;
  int iVar1;
  byte bVar3;
  uint *puVar4;
  undefined *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  uVar7 = 0;
  param_1[1] = 0x1000000;
  *(undefined2 *)(param_1 + 0x9b) = 0;
  *(undefined2 *)(param_1 + 0x9a) = 0;
  *(undefined2 *)(param_1 + 0x99) = 0;
  puVar4 = param_1;
  do {
    puVar4[0xad] = 0;
    uVar7 = uVar7 + 1;
    puVar4 = puVar4 + 1;
  } while (uVar7 < 0xc);
  uVar2 = func_0x80033604();
  if ((_DAT_800e10ec & 0x20) == 0) {
    uVar7 = func_0x80033604();
    puVar5 = &DAT_80166c98;
  }
  else {
    uVar7 = func_0x80033604();
    puVar5 = &DAT_80166cb8;
  }
  *(ushort *)((int)param_1 + 0x1f2) = *(short *)(puVar5 + (uVar7 & 0xf) * 2) + (uVar2 & 3);
  *(undefined1 *)((int)param_1 + 0x1ef) = 0xd;
  *(undefined1 *)((int)param_1 + 0x1ee) = 0xd;
  *(undefined1 *)((int)param_1 + 0x1ed) = 0xd;
  func_0x800339dc(param_1 + 0x82,0,0x25804b0,0,param_1 + 10);
  uVar7 = 2;
  iVar8 = 0x2f0;
  param_1[0xa1] = 1;
  *(undefined2 *)(param_1 + 0x4c) = 500;
  *(undefined2 *)(param_1 + 0x4d) = 0xfc18;
  *(undefined2 *)((int)param_1 + 0x13a) = 1000;
  param_1[0x94] = 0x800e1130;
  *(undefined2 *)((int)param_1 + 0x132) = 0;
  *(undefined2 *)((int)param_1 + 0x156) = 600;
  *(undefined2 *)(param_1 + 0x4e) = 600;
  *(undefined2 *)(param_1 + 0x4b) = 600;
  *(undefined2 *)((int)param_1 + 0x12e) = 600;
  *(undefined2 *)((int)param_1 + 0x28a) = 600;
  *(undefined1 *)(param_1 + 0x97) = 0;
  *(undefined1 *)((int)param_1 + 0x25d) = 2;
  do {
    uVar7 = uVar7 + 1;
    iVar1 = param_1[0x8d] + iVar8;
    *(undefined2 *)(iVar1 + 0x130) = 0;
    *(undefined2 *)(iVar1 + 0x132) = 0;
    *(undefined2 *)(iVar1 + 0x134) = 0x20;
    *(undefined2 *)(iVar1 + 0x136) = 0;
    *(undefined2 *)(iVar1 + 0x138) = 0x180;
    *(undefined2 *)(iVar1 + 0x13a) = 0x80;
    iVar8 = iVar8 + 0x178;
  } while (uVar7 < 4);
  *(undefined2 *)(param_1 + 0x78) = 0;
  *(undefined2 *)((int)param_1 + 0x1e2) = 0;
  *(undefined2 *)(param_1 + 0x79) = 0;
  uVar2 = *(ushort *)((int)param_1 + 0x1aa);
  *(undefined *)((int)param_1 + 5) = (&DAT_80166d28)[*(ushort *)((int)param_1 + 0x1aa) & 0x7f];
  if (uVar2 == 6) {
LAB_80162024:
    uVar7 = func_0x80033604();
    iVar8 = 0x2000f00;
    uVar7 = uVar7 & 0xf;
LAB_80162014:
    param_1[0x7a] = uVar7 * 0x10000 + iVar8;
  }
  else {
    if (uVar2 < 7) {
      if (uVar2 == 2) goto LAB_80162024;
      if ((2 < uVar2) && (uVar2 != 4)) goto LAB_801620dc;
      uVar7 = func_0x80033604();
      iVar8 = 0x1000f00;
      uVar7 = uVar7 & 0x3f;
      goto LAB_80162014;
    }
    if (uVar2 == 8) {
LAB_80162098:
      param_1[0x7a] = 0xf00;
      *(undefined1 *)((int)param_1 + 0x2c9) = 1;
      uVar7 = *param_1;
      uVar6 = 0x8000000;
      goto LAB_801620e4;
    }
    if (uVar2 < 8) {
      uVar7 = func_0x80033604();
      param_1[0x7a] = (uVar7 & 0x1f) * 0x10000 + 0xb000f00;
      bVar3 = func_0x80033604();
      *(byte *)((int)param_1 + 0x206) = (bVar3 & 3) + 1;
      *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) & 0xfd;
      *(undefined1 *)((int)param_1 + 0x2c9) = 1;
      *(undefined1 *)((int)param_1 + 7) = 1;
      goto LAB_80162098;
    }
    if (uVar2 == 9) {
      uVar7 = func_0x80033604();
      param_1[0x7a] = (uVar7 & 0x3f) * 0x10000 + 0x1000f00;
      *(undefined1 *)((int)param_1 + 0x2ca) = 1;
    }
    else if (uVar2 == 0x2003) {
      param_1[0x7a] = 0x6000f00;
      uVar7 = *param_1;
      uVar6 = 0x4000000;
      goto LAB_801620e4;
    }
  }
LAB_801620dc:
  uVar7 = *param_1;
  uVar6 = 0xc000000;
LAB_801620e4:
  *param_1 = uVar7 | uVar6;
  func_0x80089d54(param_1,param_2,param_3,0x100);
  _DAT_800dfa88 = FUN_80166414;
  return;
}
