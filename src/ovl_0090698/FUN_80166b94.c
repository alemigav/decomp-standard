/* FUN_80166b94
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80166b94  body 0x80166b94..0x80166c6f  size 220 B
 * body sha256 63911c619cede0ef5fd092c25d840335021595bf83fbc50be0d68d0874deb544
 * provider record sha256 630720a615cab1453a101dde5a0e6b0659e3110002a3e92354452af7cbb5b3cb
 * callees 1 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_80166b94(int param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)&DAT_800e1068;
  iVar2 = _DAT_800e1068;
  while( true ) {
    if (iVar2 == 0) {
      return 0;
    }
    uVar1 = func_0x8006a42c(param_1 + 0x28,*piVar3);
    iVar2 = *piVar3;
    *(short *)(param_1 + 0x2c2) = (short)(uVar1 << 10);
    *(int *)(param_1 + 0x2c4) = iVar2;
    piVar3 = piVar3 + 1;
    if (((int)(uVar1 << 0x1a) >> 0x10 == (*(ushort *)(param_1 + 0x66) + 0x200 & 0xc00)) &&
       ((uint)(-*(int *)(param_1 + 0x2c) / 0x708) <= *(uint *)(*(int *)(param_1 + 0x2c4) + 0xc)))
    break;
    iVar2 = *piVar3;
  }
  return (uVar1 & 0xffff) + 1;
}
