/* FUN_80035874
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80035874  body 0x80035874..0x8003590b  size 152 B
 * body sha256 9443ca5042822c4b9dbd6e8dd0dfaa622ee5ea9bd961be41ebed14a86d240fe7
 * provider record sha256 40bcae4d279625844b59a06be02d7ad25c346a38fbc3a5810aaf31e07e58b4d7
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80035874(short param_1,short param_2)

{
  int iVar1;
  short sVar2;
  int iVar3;
  
  sVar2 = (ushort)(((int)param_1 & 0x80000000U) == 0) * 0x800 + 0xc00;
  iVar1 = -(int)param_2;
  if (iVar1 != 0) {
    iVar3 = (int)param_1 << 0xc;
    if (iVar1 == 0) {
      trap(0x1c00);
    }
    if ((iVar1 == -1) && (iVar3 == -0x80000000)) {
      trap(0x1800);
    }
    sVar2 = FUN_80040a14(iVar3 / iVar1);
    if (iVar1 < 0) {
      sVar2 = sVar2 + 0x800;
    }
  }
  return (int)sVar2;
}
