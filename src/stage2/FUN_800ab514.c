/* FUN_800ab514
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ab514  body 0x800ab514..0x800ab573  size 96 B
 * body sha256 12f4ff4e37bf4c2321265dcdee05a6652b5563747bacb9e00e47bf18d51b3735
 * provider record sha256 2b1a135232cde9c58c0799b20c955854a885b708a2f56c42b9e08984c1176b4c
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800ab514(uint *param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = FUN_800a84e8(param_2);
  if (uVar1 == 0) {
    trap(0x1c00);
  }
  *param_1 = ((*param_1 << 0x10) / uVar1) * 1000 >> 5;
  return;
}
