/* FUN_80163620
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80163620  body 0x80163620..0x8016371f  size 256 B
 * body sha256 4fb02dd31c87d70eb21a0aed3c7536d77e494bfd5a111b927b11c4af8510c02d
 * provider record sha256 d2b06302709b27f55843b8b366fe95a5c27c1a7e12a0848399f8d20b7458d3ed
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80163620(int param_1,byte param_2)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  
  if ((**(uint **)(param_1 + 0x214) & 0x1000000) != 0) {
    uVar3 = (uint)param_2;
    iVar2 = FUN_80167894(param_1,uVar3,100);
    if ((iVar2 != 0) &&
       (iVar2 = *(int *)(param_1 + 0x234) + uVar3 * 0x178, sVar1 = *(short *)(iVar2 + 0x56),
       (ushort)(*(short *)(iVar2 + 0x4e) + 0xe73U) < 0x4a9b)) {
      if (sVar1 < -21999) {
        return 0;
      }
      if (sVar1 < -11000) {
        func_0x80077d18(5,param_1);
        FUN_80167374(param_1,param_2 - 1,6);
        FUN_80167374(param_1,uVar3,6);
        FUN_80167374(param_1,param_2 + 1,6);
        return 1;
      }
    }
  }
  return 0;
}
