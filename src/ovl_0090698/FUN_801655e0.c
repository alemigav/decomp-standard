/* FUN_801655e0
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x801655e0  body 0x801655e0..0x801656d7  size 248 B
 * body sha256 520727a96f6c3d85ff2b0fa4342ccd61e077f5df98a2ec2553be1abed73a7034
 * provider record sha256 4f45dc3cc6432c1c62b0fdaef4d37888cc89f0d480025cb5b73001dc2c721628
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801655e0(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (*(char *)(param_1 + 0x2d9) == '\0') {
    uVar3 = 0;
    do {
      uVar1 = func_0x80033604();
      iVar2 = (uVar1 & 0xf) + 3;
      if ((*(uint *)(*(int *)(param_1 + 0x234) + iVar2 * 0x178) & 0x4b) == 1) {
        FUN_8016703c(param_1,iVar2,5);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 5);
    *(undefined1 *)(param_1 + 0x2d9) = 0x1e;
  }
  *(uint *)(param_1 + 4) =
       (uint)*(byte *)(param_1 + 0x2cf) * 0x10000 + (uint)*(byte *)(param_1 + 0x2d0) * 0x100 +
       (uint)*(byte *)(param_1 + 0x2d1) + 0x1000000;
  FUN_80162148(param_1,param_2,param_3);
  return;
}
