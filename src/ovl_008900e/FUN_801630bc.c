/* FUN_801630bc
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x801630bc  body 0x801630bc..0x801630e7  size 44 B
 * body sha256 1ed740c41589302a4867e4505fc60e5538dc9a4199d1191e9200729f6ef893f3
 * provider record sha256 611267d4683926560fcfb8d7afa26badee0c7ec6d57373c28e00906e5cd77cda
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801630bc(int param_1)

{
  uint *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  puVar1 = *(uint **)(param_1 + 0x234);
  do {
    uVar2 = uVar2 + 1;
    *puVar1 = *puVar1 | 0x8000;
    puVar1 = puVar1 + 0x5e;
  } while (uVar2 < 0x16);
  return;
}
