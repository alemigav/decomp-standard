/* FUN_80162250
 * image   ovl_0093aba (ovl), base 0x80161cf0
 * address 0x80162250  body 0x80162250..0x801622b7  size 104 B
 * body sha256 6ea08534cb41764eb2d22b804373401e4c1cfff087dacd821e6c37bfb868c407
 * provider record sha256 519efa39643ba3238c6b80139a14cfe3e98eaf83d1602afd010ec3aa74318629
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162250(int param_1)

{
  short sVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x28c);
  sVar1 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x80);
  if ((uVar2 < 3000) && (sVar1 == 0)) {
    *(undefined4 *)(param_1 + 4) = 0x1020000;
  }
  return;
}
