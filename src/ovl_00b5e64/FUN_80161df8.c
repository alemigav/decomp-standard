/* FUN_80161df8
 * image   ovl_00b5e64 (ovl), base 0x80161cf0
 * address 0x80161df8  body 0x80161df8..0x80161f3b  size 324 B
 * body sha256 a4374689a75daa5a385cf3555da24155cca51d616b776ae6e5ae7d5335966b5d
 * provider record sha256 3d2f328597982e5c1d3fd6057b3a893bcf4ce39e39cd9bc11af93f7d82bf9475
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80161df8(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)(param_1 + 5);
  if (bVar1 == 0xb) {
    *(undefined4 *)(param_1 + 0x1e8) = 0x1000700;
    *(undefined4 *)(param_1 + 0x2b4) = 1;
    *(undefined4 *)(param_1 + 0x2b8) = 0;
LAB_80161e90:
    *(undefined1 *)(param_1 + 5) = 0xc;
LAB_80161e94:
    iVar2 = func_0x80089d54(param_1,param_2,param_3,*(int *)(param_1 + 0x2b4) << 0x10 | 0x200);
    if (iVar2 == 0) {
      return;
    }
    *(undefined1 *)(param_1 + 5) = 0xd;
    *(int *)(param_1 + 0x1e8) = *(int *)(param_1 + 0x2b8) * 0x1000000 + 0x700;
  }
  else {
    if (bVar1 < 0xc) {
      if (bVar1 == 10) {
        *(undefined4 *)(param_1 + 0x2b8) = 1;
        *(undefined4 *)(param_1 + 0x1e8) = 0x700;
        *(undefined4 *)(param_1 + 0x2b4) = 0;
        goto LAB_80161e90;
      }
    }
    else {
      if (bVar1 == 0xc) goto LAB_80161e94;
      if (bVar1 == 0xd) goto LAB_80161ed0;
    }
    bVar1 = *(byte *)(param_1 + 5);
    *(undefined1 *)(param_1 + 5) = 0xd;
    *(uint *)(param_1 + 0x2b4) = bVar1 & 1;
    *(uint *)(param_1 + 0x1e8) = (uint)(bVar1 >> 1) * 0x1000000 + 0x700;
  }
LAB_80161ed0:
  iVar2 = func_0x80089d54(param_1,param_2,param_3,*(int *)(param_1 + 0x2b4) << 0x10 | 0x200);
  if (iVar2 != 0) {
    *(undefined1 *)(param_1 + 4) = 2;
  }
  return;
}
