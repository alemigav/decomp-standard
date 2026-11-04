/* FUN_80052bd0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80052bd0  body 0x80052bd0..0x80052c6b  size 156 B
 * body sha256 6f2138b55d81bb14dc107bc052166aca81aaeb766394e3ee5d873dac978c2729
 * provider record sha256 ed2e09fb47ac871072e13d113ea540873b8aa1470f382b88a1d7769a4ed80cd5
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80052bd0(int param_1,undefined2 param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  
  DAT_800e90f4 = 1;
  uVar3 = FUN_80052f10(&DAT_8010bfd8);
  if ((uVar3 < 0x20) && (param_1 != 0)) {
    PTR_DAT_8010bfa0 = (undefined *)FUN_80052eec(&DAT_8010bfd8);
    *PTR_DAT_8010bfa0 = 1;
    puVar1 = PTR_DAT_8010bfa0;
    PTR_DAT_8010bfa0[1] = param_1 != 0;
    puVar2 = PTR_DAT_8010bfa0;
    *(short *)(puVar1 + 4) = (short)param_1;
    *(undefined2 *)(puVar2 + 2) = param_2;
    *(undefined2 *)(puVar2 + 6) = 0;
  }
  return;
}
