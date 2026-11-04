/* FUN_8008d2e4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008d2e4  body 0x8008d2e4..0x8008d36f  size 140 B
 * body sha256 7171239cfba743416163a4ebc84487aa89dbfbda7ea9a7fe389e9ae0090bbded
 * provider record sha256 69cb8ee0d5ad276e152a1a5a3cc69219bb402cbeaa425f7c43b20757388c2e89
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8008d2e4(int param_1)

{
  undefined2 uVar1;
  uint uVar2;
  undefined2 *puVar3;
  int iVar4;
  
  iVar4 = 0;
  puVar3 = &DAT_8012bec0;
  do {
    uVar2 = param_1 + 7U & 0xfffffff8;
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    iVar4 = iVar4 + 1;
    param_1 = func_0x80004cfc(uVar1,uVar2,0,&DAT_800b9ecc);
    param_1 = uVar2 + param_1;
  } while (iVar4 < 0x6a);
  return param_1;
}
