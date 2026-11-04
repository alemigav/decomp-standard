/* FUN_80165408
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80165408  body 0x80165408..0x8016557b  size 372 B
 * body sha256 32c8d25c8c205f9140f8a4f2893639ec7abc9d36f80d7dbf9abee10f06d7eb5d
 * provider record sha256 513a32cc5395a4e4b51d7aee7571d45426468a28f1cc62df075bea4382d48c51
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165408(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  uVar3 = func_0x80033604();
  uVar3 = uVar3 & 7;
  iVar5 = uVar3 * 2 + 3;
  if ((2 < *(byte *)(param_1 + 0x2bd)) && (((int)(uint)*(byte *)(param_1 + 700) >> uVar3 & 1U) == 0)
     ) {
    *(byte *)(param_1 + 700) = *(byte *)(param_1 + 700) | (byte)(1 << uVar3);
    *(char *)(param_1 + 0x2bd) = *(char *)(param_1 + 0x2bd) + -1;
    iVar4 = *(int *)(param_1 + 0x234) + iVar5 * 0x178;
    uVar3 = *(uint *)(iVar4 + 0x178);
    if ((DAT_800e9012 & 8) != 0) {
      uVar3 = uVar3 | 0x1062;
    }
    *(uint *)(iVar4 + 0x178) = uVar3;
    *(undefined4 *)(iVar4 + 0x1d8) = 0x101f3f;
    sVar1 = *(short *)(param_1 + 0x66);
    *(undefined2 *)(iVar4 + 0x1a4) = 100;
    *(undefined2 *)(iVar4 + 0x296) = 0;
    *(undefined2 *)(iVar4 + 0x1a2) = 0;
    *(undefined1 *)(iVar4 + 0x289) = 0x1e;
    *(undefined2 *)(iVar4 + 0x1a6) = 0;
    *(short *)(iVar4 + 0x1a0) = sVar1 + 0x800;
    uVar2 = *(undefined2 *)(param_1 + 0x66);
    *(undefined2 *)(iVar4 + 0x1aa) = 0x400;
    *(undefined2 *)(iVar4 + 0x1a8) = uVar2;
  }
  FUN_8016703c(param_1,iVar5,7);
  *(undefined4 *)(*(int *)(param_1 + 0x234) + iVar5 * 0x178 + 0x60) = 0x102f4f;
  *(undefined1 *)(param_1 + 5) = 2;
  FUN_801647c8(param_1,param_2,param_3);
  return;
}
