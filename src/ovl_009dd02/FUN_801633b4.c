/* FUN_801633b4
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801633b4  body 0x801633b4..0x80163563  size 432 B
 * body sha256 9b7ff669ff209b1a5908e465b97268016da43c263ea2193d8e2b1738df3d85ce
 * provider record sha256 0f7f637d40c2db142c751afd98b1619979aabcd36b56eb5808cec1357a090c4c
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801633b4(int param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  short sVar3;
  undefined1 uVar4;
  int iVar2;
  undefined1 *puVar5;
  uint uVar6;
  
  if (*(char *)(param_1 + 0x2b4) == '\0') {
    puVar5 = &DAT_800e1130;
  }
  else {
    puVar5 = _DAT_800e13ec;
  }
  func_0x80032e74(param_1,*(undefined4 *)(puVar5 + 0x28),*(undefined4 *)(puVar5 + 0x30),0x40);
  FUN_80166d64(param_1,*(undefined4 *)(puVar5 + 0x28),*(undefined4 *)(puVar5 + 0x30),0x300);
  func_0x800334c8(param_1,param_2,param_3,0);
  sVar3 = func_0x80089d54(param_1,param_2,param_3,0x40);
  func_0x80032b5c(param_1,0);
  *(short *)(param_1 + 0x130) = *(short *)(param_1 + 0x130) - *(short *)(param_1 + 0x1e0);
  uVar6 = **(uint **)(param_1 + 0x214);
  func_0x80033648(param_1);
  if (((uVar6 & 0x10000) != 0) && (*(char *)(param_1 + 0x206) == '\0')) {
    uVar4 = FUN_80166838(param_1);
    *(undefined1 *)(param_1 + 0x206) = uVar4;
  }
  if ((uVar6 & 0x20000) != 0) {
    bVar1 = false;
    _DAT_800e1128 = _DAT_800e1128 & 0xffbf;
    *(char *)(param_1 + 0x2d6) = *(char *)(param_1 + 0x2d6) + '\x01';
    *(char *)(param_1 + 0x2d7) = *(char *)(param_1 + 0x2d7) + '\x01';
    iVar2 = FUN_80166d14(param_1,0x11,0x28);
    if (iVar2 == 0) {
      iVar2 = FUN_80166d14(param_1,0x17,0x28);
      if (iVar2 != 0) {
        bVar1 = true;
      }
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      *(undefined2 *)(param_1 + 6) = 0x200;
    }
  }
  if (sVar3 != 0) {
    FUN_80163564(param_1);
  }
  return;
}
