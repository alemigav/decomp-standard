/* FUN_80166248
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80166248  body 0x80166248..0x80166313  size 204 B
 * body sha256 da6de522de89b0a89ec53431a8df1ecfa186aa0cd9c23bf3056df82f142a5542
 * provider record sha256 98e4993502e7804f8e7cedcd8d29a7722bba50d65abc30305066f77b36871177
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166248(int param_1)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = *(int *)(param_1 + 0x234);
  *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 1;
  uVar2 = *(uint *)(iVar3 + 0x1be8);
  if ((DAT_800e9012 & 8) != 0) {
    uVar2 = uVar2 | 0x4a;
  }
  uVar4 = 0;
  *(uint *)(iVar3 + 0x1be8) = uVar2;
  sVar1 = *(short *)(param_1 + 0x66);
  *(undefined2 *)(iVar3 + 0x1d1a) = 0xff10;
  *(undefined2 *)(iVar3 + 0x1d20) = 0;
  *(undefined2 *)(iVar3 + 0x1d1c) = 0;
  *(undefined2 *)(iVar3 + 0x1d1e) = 0xf;
  *(undefined2 *)(iVar3 + 0x1d24) = 0;
  *(undefined4 *)(iVar3 + 0x1c48) = 0x2f2f2f;
  *(short *)(iVar3 + 0x1d18) = sVar1 + 0x800;
  FUN_8016703c(param_1,0x13,1);
  do {
    FUN_8016703c(param_1,0x13,2);
    uVar4 = uVar4 + 1;
  } while (uVar4 < 4);
  return;
}
