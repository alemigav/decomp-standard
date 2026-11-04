/* FUN_80052d10
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80052d10  body 0x80052d10..0x80052df3  size 228 B
 * body sha256 e03e5efe83e53877abc8d7d348c92c7ef6bda48cefd788fc48132507e0cb6f95
 * provider record sha256 3761b1aec2a03d274875cf7da3906c162850d664917bddd42a77a5486efa65e1
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80052d10(int param_1,int param_2,int param_3,undefined2 param_4)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  
  DAT_800e90f4 = 1;
  uVar2 = FUN_80052f10(&DAT_8010c124);
  if ((uVar2 < 0x20) && (param_1 != 0)) {
    PTR_DAT_8010bfa4 = (undefined *)FUN_80052eec(&DAT_8010c124);
    iVar3 = (param_3 - param_2) * 0x80;
    if (param_1 == 0) {
      trap(0x1c00);
    }
    if ((param_1 == -1) && (iVar3 == -0x80000000)) {
      trap(0x1800);
    }
    *PTR_DAT_8010bfa4 = 1;
    puVar1 = PTR_DAT_8010bfa4;
    *(short *)(PTR_DAT_8010bfa4 + 4) = (short)param_1;
    *(undefined2 *)(puVar1 + 2) = param_4;
    *(short *)(puVar1 + 8) = (short)(param_2 << 7);
    *(short *)(puVar1 + 6) = (short)(iVar3 / param_1);
  }
  return;
}
