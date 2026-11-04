/* FUN_80162460
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80162460  body 0x80162460..0x80162747  size 744 B
 * body sha256 85cb4da689f1c223d9ce5ae6f144149270892976b7bc893f95cba28fa668fe30
 * provider record sha256 20dccab5be61c7cbc8d3724463de79876be4a7a8f48b2cfd870bb31dc59cc81b
 * callees 11 direct (11 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162460(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  short sVar4;
  int local_28;
  undefined4 local_24;
  int local_20;
  
  if (*(char *)((int)param_1 + 6) == '\0') {
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x78) = 0x1e;
    *(undefined2 *)(param_1 + 0x79) = 0;
    *(undefined1 *)((int)param_1 + 0x206) = 0;
    *(undefined1 *)((int)param_1 + 0x2b5) = 0;
    *(undefined1 *)((int)param_1 + 0x2c9) = 0;
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) & 0xfd;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
    *param_1 = *param_1 & 0xefffffff | 0x4000000;
    uVar2 = func_0x80033604();
    *(undefined2 *)(param_1 + 0xb1) = *(undefined2 *)(&DAT_80166d7a + (uVar2 & 7) * 4);
    uVar2 = func_0x80033604();
    *(undefined2 *)((int)param_1 + 0x2c6) = *(undefined2 *)(&DAT_80166d7a + (uVar2 & 7) * 4);
  }
  iVar3 = FUN_80166bd4(param_1);
  local_28 = *(int *)(iVar3 + 0x28) + (int)*(short *)(param_1 + 0xb1);
  local_24 = *(undefined4 *)(iVar3 + 0x2c);
  local_20 = *(int *)(iVar3 + 0x30) + (int)*(short *)((int)param_1 + 0x2c6);
  func_0x800653d0(param_1,&local_28,0,0);
  sVar4 = func_0x80032e74(param_1,(int)*(short *)(param_1 + 0x98),
                          (int)*(short *)((int)param_1 + 0x262),0x10);
  *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + sVar4;
  func_0x80032b5c(param_1,0);
  if (param_1[0xa3] < 3000) {
    cVar1 = *(char *)((int)param_1 + 0x206);
    *(char *)((int)param_1 + 0x206) = cVar1 + '\x01';
    if ((_DAT_800e112a & 4) != 0) {
      *(char *)((int)param_1 + 0x206) = cVar1 + '\x15';
    }
    iVar3 = func_0x80032fac(param_1 + 10,iVar3 + 0x28,(int)*(short *)((int)param_1 + 0x66),0x80);
    if ((iVar3 == 0) && (600 < param_1[0xa3])) {
      *(undefined1 *)((int)param_1 + 5) = 3;
      *(undefined2 *)((int)param_1 + 6) = 0;
    }
  }
  else {
    if (*(char *)((int)param_1 + 0x206) != '\0') {
      *(char *)((int)param_1 + 0x206) = *(char *)((int)param_1 + 0x206) + -1;
    }
    iVar3 = func_0x80032fac(param_1 + 10,iVar3 + 0x28,(int)*(short *)((int)param_1 + 0x66),0x80);
    if ((iVar3 == 0) && ((_DAT_800e112a & 4) != 0)) {
      *(char *)((int)param_1 + 0x206) = *(char *)((int)param_1 + 0x206) + '\x14';
    }
  }
  if ((('@' < *(char *)((int)param_1 + 0x206)) || ((_DAT_800e112a & 1) != 0)) ||
     ((_DAT_800e1128 & 0x20) != 0)) {
    *(undefined1 *)((int)param_1 + 5) = 2;
    *(undefined2 *)((int)param_1 + 6) = 0;
    *(undefined1 *)((int)param_1 + 0x206) = 0;
  }
  func_0x80089d54(param_1,param_2,param_3,0x100);
  FUN_801664d8(param_1);
  if ((*(char *)((int)param_1 + 699) == '\0') &&
     (uVar2 = func_0x80033604(param_1), (uVar2 & 0x3f) == 0)) {
    uVar2 = func_0x80033604();
    *(undefined *)((int)param_1 + 699) = (&DAT_80166c80)[uVar2 & 7];
  }
  FUN_80166980(param_1,4,6);
  FUN_80166b60(param_1);
  FUN_80166ba0(param_1);
  return;
}
