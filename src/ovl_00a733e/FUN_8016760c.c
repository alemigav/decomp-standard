/* FUN_8016760c
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x8016760c  body 0x8016760c..0x801676cb  size 192 B
 * body sha256 22e06bbf9de4c45718c13f16c21b0adcc0cfef62e88ed7a81847bcfc7f95c50a
 * provider record sha256 8e328ee0fe0fe4b3e5e9ada4ab33fab6ac9c76f970b712f2fa359e8ab8814c46
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8016760c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x234) + (short)(&DAT_80167d6c)[param_2 * 2] * 0x178;
  if (((DAT_800e139f & 0x80) == 0) && (-1 < _DAT_800e1322)) {
    iVar1 = func_0x80033024(&DAT_800e1158,iVar2 + 0x4c,(int)(short)(&DAT_80167d6c)[param_2 * 2 + 1])
    ;
    if (iVar1 == 0) {
      return 0;
    }
    iVar2 = *(int *)(param_1 + 0x2c) - *(int *)(iVar2 + 0x50);
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    if (iVar2 < 0xce4) {
      return 1;
    }
  }
  return 0;
}
