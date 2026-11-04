/* FUN_8004f54c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004f54c  body 0x8004f54c..0x8004f633  size 232 B
 * body sha256 95ff9ede3c89ed7a0c98ec38248cca258cd4d9ed11cac929e0390abc283d1960
 * provider record sha256 39b270efd21d5c469ba841cea0d7676829edc24520f3fcdc0a02478ea6233e2b
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint * FUN_8004f54c(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  int *piVar4;
  uint *puVar5;
  
  puVar5 = &DAT_800e18f8;
  if (&DAT_800e18f8 < DAT_800e85f8) {
    piVar4 = &DAT_800e1a20;
    do {
      if ((((*puVar5 & 0x101) == 0x101) && ((*puVar5 & 2) == 0)) &&
         (*(int *)(param_1 + 0x2c) == piVar4[-1] - (uint)*(ushort *)((int)piVar4 + 0x12))) {
        iVar2 = -(uint)(*(ushort *)(param_2 + 3) >> 1) + (uint)*(ushort *)(piVar4 + 1);
        iVar1 = -(uint)(*(ushort *)(param_2 + 3) >> 1) + (uint)*(ushort *)((int)piVar4 + 6);
        bVar3 = (uint)(iVar2 * 2) < (uint)((piVar4[-2] - *param_2) + iVar2);
        if ((uint)(iVar1 * 2) < (uint)((*piVar4 - param_2[2]) + iVar1)) {
          bVar3 = bVar3 | 2;
        }
        if (bVar3 == 0) {
          return puVar5;
        }
      }
      puVar5 = puVar5 + 0xda;
      piVar4 = piVar4 + 0xda;
    } while (puVar5 < DAT_800e85f8);
  }
  return *(uint **)(param_1 + 0x280);
}
