/* FUN_8003590c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003590c  body 0x8003590c..0x800359ab  size 160 B
 * body sha256 d9bc6d35843f543d88af1d7dfd175e8c5abe401994635677c1e8ee7988badd6b
 * provider record sha256 5458de01065864b5c5964bcc122bf0e3e5faef08b79ecb8ffc38007cde6b492d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8003590c(short param_1,short param_2)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  
  uVar2 = (ushort)(((int)param_1 & 0x80000000U) == 0) << 0xb | 0x400;
  iVar1 = -(int)param_2;
  if (iVar1 != 0) {
    iVar3 = (int)param_1 << 0xc;
    if (iVar1 == 0) {
      trap(0x1c00);
    }
    if ((iVar1 == -1) && (iVar3 == -0x80000000)) {
      trap(0x1800);
    }
    uVar2 = FUN_80040a14(iVar3 / iVar1);
    if (iVar1 < 0) {
      uVar2 = -uVar2;
    }
  }
  return (int)(short)uVar2;
}
