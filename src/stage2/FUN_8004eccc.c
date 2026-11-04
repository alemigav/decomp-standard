/* FUN_8004eccc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004eccc  body 0x8004eccc..0x8004ed83  size 184 B
 * body sha256 06c3e1ce784f0c585cde9189460f697ed9978d84c8645e8f343a21593bb975e3
 * provider record sha256 04c68e74f17a6372dab660d1212404432cf097f03991ac58f1b74356c0583510
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
uint * FUN_8004eccc(int param_1)

{
  int iVar1;
  uint *puVar2;
  
  puVar2 = &DAT_800e18f8;
  if (&DAT_800e18f8 < DAT_800e85f8) {
    do {
      if (((((*puVar2 & 0x101) == 0x101) &&
           (*(char *)(param_1 + 0x1a2) == *(char *)((int)puVar2 + 0x1a2))) &&
          (*(uint **)(param_1 + 0x280) != puVar2)) &&
         (iVar1 = FUN_8004eb74(param_1,puVar2), iVar1 != 0)) {
        return puVar2;
      }
      puVar2 = puVar2 + 0xda;
    } while (puVar2 < DAT_800e85f8);
  }
  return (uint *)0x0;
}
