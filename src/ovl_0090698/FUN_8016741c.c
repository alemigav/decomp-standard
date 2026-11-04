/* FUN_8016741c
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x8016741c  body 0x8016741c..0x8016753b  size 288 B
 * body sha256 1bea15183cb9e5f0b18032c0c1b1f731aeb9e4108a26ffb34140d570c02275fe
 * provider record sha256 3b1463403aa47b777df3b2cd07994c5774405d59eff4b656bb5afe46f8480274
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8016741c(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x2c) - _DAT_800e115c;
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  if ((iVar1 < param_3) && (iVar1 = FUN_80167330(param_1,0,param_2), iVar1 != 0)) {
    func_0x80077d18(1,param_1);
    func_0x80052bd0(2,0);
    func_0x80052c6c(8,200,0);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
    if ((_DAT_800e110c & 0x10000000) != 0) {
      iVar1 = *(int *)(param_1 + 0x2c) - *(int *)(_DAT_800e13ec + 0x2c);
      if (iVar1 < 0) {
        iVar1 = -iVar1;
      }
      if ((iVar1 < param_3) && (iVar1 = FUN_80167330(param_1,1,param_2), iVar1 != 0)) {
        func_0x80077d18(1,param_1);
        uVar2 = 1;
      }
      else {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}
