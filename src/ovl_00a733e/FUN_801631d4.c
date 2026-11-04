/* FUN_801631d4
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x801631d4  body 0x801631d4..0x8016326b  size 152 B
 * body sha256 4d1c5eb846427ac35ef991118f731fdefac4955d5e870d2810b98c9f433927ff
 * provider record sha256 d03abf6402cd3590e8f8cf4dc2de358c772ac5ea68ba75a757bfd812eb4467fd
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801631d4(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if ((((*(uint *)(param_1 + 0x28c) < 0x1194) && (-1 < _DAT_800e1322)) &&
      (iVar1 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x400), iVar1 != 0)) &&
     ((uVar2 = func_0x80033604(), (0x1558 >> (uVar2 & 0xf) & 1U) != 0 ||
      (*(char *)(param_1 + 0x2c0) != '\0')))) {
    *(undefined1 *)(param_1 + 5) = 3;
    *(undefined2 *)(param_1 + 6) = 0;
  }
  return;
}
