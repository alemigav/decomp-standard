/* FUN_800add28
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800add28  body 0x800add28..0x800ade03  size 220 B
 * body sha256 94d96771b4e46a67355102f1f5aa4b38f1a7deaff0cc489f72af0a4d4f204bce
 * provider record sha256 118da57928fed4d383064beeacb54908d7f9fb3065755b6e04fda047ecff60e5
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800add28(short param_1,short *param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  short sVar3;
  short *psVar4;
  short *local_10 [2];
  
  uVar2 = 0;
  if (_DAT_8014e16c != 0) {
    puVar1 = (undefined4 *)&DAT_8014e170;
    do {
      if ((short *)*puVar1 == param_2) break;
      uVar2 = uVar2 + 1;
      puVar1 = puVar1 + 3;
    } while (uVar2 < _DAT_8014e16c);
  }
  sVar3 = *param_2;
  if (sVar3 != -1) {
    psVar4 = param_2 + 1;
    do {
      if (sVar3 == param_1) {
        if (*psVar4 == 0) {
          local_10[0] = param_2 + 6;
          *(int *)(psVar4 + 3) = *(int *)(psVar4 + 1) + *(int *)(uVar2 * 0xc + -0x7feb1e8c);
          FUN_800a5ce4(local_10,param_2 + 4);
        }
        *psVar4 = *psVar4 + 1;
        return 1;
      }
      param_2 = param_2 + 0xe;
      sVar3 = *param_2;
      psVar4 = psVar4 + 0xe;
    } while (sVar3 != -1);
  }
  return 1;
}
