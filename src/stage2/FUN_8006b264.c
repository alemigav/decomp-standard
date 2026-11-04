/* FUN_8006b264
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006b264  body 0x8006b264..0x8006b28b  size 40 B
 * body sha256 54f141b93d64ab98ccedbdc7300a17b9e9e790a6e656421c22ee8c0b01e3a11b
 * provider record sha256 a85d33696fe9857f20208898415030b62126a6bd1cd00ee0cc473d36f6042140
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8006b264(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  for (uVar1 = *(uint *)(param_1 + 0xc); (uVar1 & 1) == 0; uVar1 = (int)uVar1 >> 1) {
    iVar2 = iVar2 + -0x708;
  }
  return iVar2;
}
