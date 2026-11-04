/* FUN_80040794
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80040794  body 0x80040794..0x80040877  size 228 B
 * body sha256 7c92d4b07f92a597dbbcd07a766ab6ae4d127305a0acc5db758f3620020101eb
 * provider record sha256 e7f086799c2cd90dcc633d99294fbb9e3897521286444fed7a534fa15a8a383f
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80040794(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  int local_18;
  int local_14;
  int local_10;
  
  iVar3 = FUN_80074d64((int)*(short *)(DAT_800ebb94 + 0x34),(int)*(short *)(DAT_800ebb94 + 0x38));
  if ((iVar3 == 0) || (*(short *)(DAT_800ebb94 + 0x36) <= iVar3)) {
    local_18 = (int)*(short *)(DAT_800ebb94 + 0x34);
    local_14 = (int)*(short *)(DAT_800ebb94 + 0x36);
    local_10 = (int)*(short *)(DAT_800ebb94 + 0x38);
    iVar3 = FUN_80069f1c(&local_18,2,0x2000,1);
    if (*(short *)(DAT_800ebb94 + 0x36) <= iVar3) {
      return;
    }
    DAT_800ebb94[0x21] = 8;
  }
  else {
    DAT_800ebb94[0x21] = 8;
  }
  DAT_800ebb94[0x20] =
       *(undefined1 *)(*(int *)(DAT_800ebb94 + 0x70) + (uint)(byte)DAT_800ebb94[0x21] * 8 + 2);
  puVar1 = DAT_800ebb94;
  DAT_800ebb94[1] = 0;
  *puVar1 = 0;
  puVar1 = DAT_800ebb94;
  DAT_800ebb94[9] = 0;
  puVar2 = DAT_800ebb94;
  *(undefined2 *)(puVar1 + 0xe) = 0;
  *(short *)(puVar2 + 0x36) = (short)iVar3;
  return;
}
