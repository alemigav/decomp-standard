/* FUN_80166f84
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80166f84  body 0x80166f84..0x8016703b  size 184 B
 * body sha256 fb7a42046b63decb04236c310243a31861db83c485fc6149270d7fc328b655ba
 * provider record sha256 dda63e198ea8efa0620c8bb39c2801e67b75845515c802bc86ef9bd36a876b7b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_80166f84(int param_1,short param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  short sVar4;
  int iVar5;
  
  if (*(char *)(param_1 + 0x2d3) == '\0') {
    iVar5 = -0x7ff1eed0;
  }
  else {
    iVar5 = _DAT_800e13ec;
  }
  uVar1 = *(undefined2 *)(param_1 + 100);
  uVar2 = *(undefined2 *)(param_1 + 0x68);
  uVar3 = *(undefined2 *)(param_1 + 0x66);
  *(undefined2 *)(param_1 + 100) = 0;
  *(undefined2 *)(param_1 + 0x68) = 0;
  *(ushort *)(param_1 + 0x66) = (*(byte *)(param_1 + 0x2cc) & 3) << 10;
  sVar4 = func_0x80032e74(param_1,*(undefined4 *)(iVar5 + 0x28),*(undefined4 *)(iVar5 + 0x30),
                          (int)param_2);
  *(undefined2 *)(param_1 + 100) = uVar1;
  *(undefined2 *)(param_1 + 0x66) = uVar3;
  *(undefined2 *)(param_1 + 0x68) = uVar2;
  return (int)sVar4;
}
