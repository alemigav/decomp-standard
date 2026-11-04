/* FUN_80166f28
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80166f28  body 0x80166f28..0x80167063  size 316 B
 * body sha256 61e715bbad8534d849e284b83af48624e98d4b779fe5f301ed0c8bc73a8233ba
 * provider record sha256 f4d7b29512fa212609d911f956255099875ee6701de09a18b1a13643d767c3ac
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80166f28(undefined4 param_1,int param_2)

{
  uint uVar1;
  byte bVar3;
  char cVar4;
  int iVar2;
  undefined4 uVar5;
  
  bVar3 = *(byte *)(param_2 + 0x11);
  if (bVar3 != 1) {
    if (1 < bVar3) {
      if (bVar3 == 2) {
        uVar1 = func_0x80033604();
        iVar2 = FUN_801671cc((int)((uVar1 & 3) * -0x10000) >> 0x10);
        if (iVar2 < 0) {
          *(undefined1 *)(param_2 + 0x11) = 3;
          bVar3 = func_0x80033604();
          *(byte *)(param_2 + 0x12) = (bVar3 & 3) * '\x1e' + '\x01';
        }
      }
      else if ((bVar3 == 3) &&
              (cVar4 = *(char *)(param_2 + 0x12) + -1, *(char *)(param_2 + 0x12) = cVar4,
              cVar4 == '\0')) {
        *(undefined1 *)(param_2 + 0x11) = 1;
      }
      goto LAB_8016701c;
    }
    if (bVar3 != 0) goto LAB_8016701c;
    *(undefined1 *)(param_2 + 0x11) = 1;
    DAT_80167d6a = 0xf9;
  }
  uVar1 = func_0x80033604();
  iVar2 = FUN_801671cc(uVar1 & 3);
  if (0 < iVar2) {
    *(undefined1 *)(param_2 + 0x11) = 2;
  }
LAB_8016701c:
  iVar2 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,1);
  uVar5 = 0xfffffffe;
  if (0 < iVar2) {
    uVar5 = 2;
  }
  FUN_8016721c(uVar5);
  return;
}
