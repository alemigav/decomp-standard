/* FUN_8006f8b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006f8b0  body 0x8006f8b0..0x8006faf3  size 580 B
 * body sha256 af90ef7a8b2f429639e17e10ae705c85bff6a5883769e1203c68471a6ff77703
 * provider record sha256 520b27392d0c8bbd713f6ce8214c61b59a832e472a7dec8653117b889363353a
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006f8b0(int param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  char *unaff_s0;
  int iVar4;
  int iVar5;
  undefined1 auStack_68 [20];
  int local_54;
  int local_50;
  int local_4c;
  undefined1 auStack_48 [20];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined2 local_28;
  undefined2 local_26;
  short local_24;
  undefined1 auStack_20 [8];
  
  iVar5 = *(int *)(param_1 + 0x1c);
  uVar3 = (uint)*(byte *)(iVar5 + 2);
  bVar1 = *(byte *)(iVar5 + 3);
  uVar2 = uVar3 & 0xc0;
  if (uVar2 == 0x40) {
    if ((bVar1 & 0x80) == 0) {
      unaff_s0 = "";
    }
    else {
      unaff_s0 = (char *)((bVar1 & 0x7f) * 0x178 + 0x38);
    }
  }
  else if (uVar2 < 0x41) {
    if ((*(byte *)(iVar5 + 2) & 0xc0) == 0) {
      unaff_s0 = "\x10";
    }
  }
  else if (uVar2 == 0x80) {
    if ((bVar1 & 0x80) == 0) {
      unaff_s0 = (char *)((&DAT_800e13e8)[uVar3 - 0x80] + 0x14);
    }
    else {
      unaff_s0 = (char *)(*(int *)((&DAT_800e13e8)[uVar3 - 0x80] + 0x234) + (bVar1 & 0x7f) * 0x178 +
                         0x38);
    }
  }
  else if (uVar2 == 0xc0) {
    unaff_s0 = "cFixedList_ tVptr add failed.\n" + uVar3 * 0x368 + 0x14;
  }
  local_54 = (int)*(short *)(iVar5 + 4);
  local_50 = (int)*(short *)(iVar5 + 6);
  local_4c = (int)*(short *)(iVar5 + 8);
  local_28 = *(undefined2 *)(iVar5 + 10);
  local_26 = *(undefined2 *)(iVar5 + 0xc);
  local_24 = *(undefined2 *)(iVar5 + 0xe);
  FUN_80040e58(&local_28,auStack_68);
  FUN_800424ec(unaff_s0,auStack_68,auStack_48);
  iVar4 = *(int *)(param_1 + 0x154);
  *(undefined4 *)(iVar4 + 0x28) = local_34;
  *(undefined4 *)(iVar4 + 0x2c) = local_30;
  *(undefined4 *)(iVar4 + 0x30) = local_2c;
  local_28 = 1000;
  local_26 = 0;
  local_24 = 0;
  FUN_8004276c(auStack_48,&local_28,auStack_20);
  FUN_800608c8(auStack_20,&local_28);
  *(undefined2 *)(iVar4 + 100) = local_28;
  *(undefined2 *)(iVar4 + 0x66) = local_26;
  *(short *)(iVar4 + 0x68) = local_24 + 0x400;
  *(int *)(param_1 + 0x1c) = iVar5 + 0x10;
  return 1;
}
