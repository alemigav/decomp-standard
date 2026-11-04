/* FUN_800a54ec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a54ec  body 0x800a54ec..0x800a5677  size 396 B
 * body sha256 61c9f09d6cd9d81da27c5634f204e3d459153d842d91502148a541881988172f
 * provider record sha256 030f3f652a24fe474634c43c7def961d02eff7a2de2b3f33831aab2ec4bf049c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a54ec(uint param_1,int param_2,char param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 *puVar4;
  double dVar5;
  
  puVar4 = (undefined1 *)(_DAT_80143f0c + (param_1 & 0xffff) * 0x68);
  *(undefined2 *)(puVar4 + 4) = 0x1000;
  *puVar4 = 0;
  *(undefined2 *)(puVar4 + 2) = 0;
  puVar4[1] = 1;
  *(undefined2 *)(puVar4 + 0x18) = 0;
  *(undefined2 *)(puVar4 + 0x1a) = 0;
  *(undefined2 *)(puVar4 + 0x1c) = 0;
  *(undefined2 *)(puVar4 + 0x1e) = 0;
  *(undefined2 *)(puVar4 + 0x40) = 0;
  *(undefined2 *)(puVar4 + 0x42) = 0;
  *(undefined2 *)(puVar4 + 0x44) = 0;
  *(undefined2 *)(puVar4 + 0x46) = 0;
  if (param_3 != '\0') {
    iVar1 = param_1 * 0x68 + _DAT_80143f0c;
    *(undefined2 *)(iVar1 + 0x20) = 0;
    *(undefined2 *)(iVar1 + 0x22) = 0;
    *(undefined4 *)(iVar1 + 0x24) = 0x3f800000;
    *(undefined2 *)(iVar1 + 0x28) = 0x14;
  }
  iVar1 = param_1 * 0x68 + _DAT_80143f0c;
  *(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)(param_2 + 4);
  dVar5 = (double)*(int *)(param_2 + 8);
  if (*(int *)(param_2 + 8) < 0) {
    dVar5 = dVar5 + 4294967296.0;
  }
  *(double *)(iVar1 + 8) = dVar5;
  uVar2 = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(iVar1 + 0x14) = uVar2;
  *(undefined4 *)(iVar1 + 0x10) = uVar2;
  *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)(iVar1 + 0x38) = *(undefined4 *)(param_2 + 0x14);
  *(undefined1 *)(iVar1 + 0x5d) = *(undefined1 *)(param_2 + 0x18);
  iVar1 = param_1 * 0x68 + _DAT_80143f0c;
  if (*(int *)(iVar1 + 0x38) == 0) {
    *(undefined4 *)(iVar1 + 0x3c) = 0;
  }
  else {
    uVar3 = *(int *)(iVar1 + 0x30) - (*(int *)(iVar1 + 0x34) + *(int *)(iVar1 + 0x38));
    *(uint *)(iVar1 + 0x3c) = uVar3;
    if (uVar3 < 10) {
      *(undefined4 *)(iVar1 + 0x3c) = 0;
    }
  }
  if ((*(uint *)(param_2 + 4) & 0xf0000000) != 0x80000000) {
    iVar1 = param_1 * 0x68 + _DAT_80143f0c;
    *(ushort *)(iVar1 + 2) = *(ushort *)(iVar1 + 2) | 1;
  }
  return;
}
