/* FUN_80165dc4
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80165dc4  body 0x80165dc4..0x80165e13  size 80 B
 * body sha256 34962e0fd2aca53e9513fce052f389d48971c5b91cf57b8ffee275e97822a765
 * provider record sha256 64055c336860c7b015879504d80fdfe0504cddde181845962882140df4779c24
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165dc4(int param_1,uint param_2,uint param_3,int param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_1 + 0x234);
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      uVar2 = uVar2 + 1;
      *(uint *)(iVar1 + 0x60) =
           *(uint *)(iVar1 + 0x60) & 0xff000000 | param_5 << 0x10 | param_4 << 8 | param_3;
      iVar1 = iVar1 + 0x178;
    } while (uVar2 < param_2);
  }
  return;
}
