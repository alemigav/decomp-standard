/* FUN_80165fb4
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80165fb4  body 0x80165fb4..0x80166073  size 192 B
 * body sha256 359379a15920a7cfc4e181ab27b1c1af211fe79e68eeb5edcba9ecde55acb604
 * provider record sha256 3dbffb88299aa64df111f7dd6bda6e4c4b924fdb0a272874f8dc1624188ba7fe
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80165fb4(int param_1,int param_2,int param_3,short param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  uint uVar4;
  
  if (param_2 == 0) {
    puVar3 = &DAT_800e1130;
    uVar4 = *(uint *)(param_1 + 0x28c);
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x290) & 0x3fffffff;
    puVar3 = _DAT_800e13ec;
  }
  iVar1 = func_0x80032e74(param_1,*(undefined4 *)(puVar3 + 0x28),*(undefined4 *)(puVar3 + 0x30),
                          (int)param_4);
  uVar2 = 0;
  if (((((int)uVar4 < param_3) && (iVar1 == 0)) && (uVar2 = 0, -1 < *(short *)(puVar3 + 0x1f2))) &&
     (uVar2 = 1, (puVar3[0x26f] & 0x80) != 0)) {
    uVar2 = 0;
  }
  return uVar2;
}
