/* FUN_8015de0c
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015de0c  body 0x8015de0c..0x8015e1cf  size 316 B
 * body sha256 d3c93cf0c6a4633d328d4bae4cdedec0a5d94b8b8ecf301483b75f0dc3761e35
 * provider record sha256 21aa74e657fdf6096beb569e8b6aad40b72cd2dcc4051bae8b50152fb36f1d8f
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Switch with 1 destination removed at 0x8015dee8 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Exceeded maximum restarts with more pending */

void FUN_8015de0c(void)

{
  bool bVar1;
  int iVar2;
  undefined *puVar3;
  uint uVar4;
  
  func_0x8004ce90(0);
  func_0x800274f8(0x200,0x555,7,0);
  func_0x800275c0(0,0,0,0);
  while (iVar2 = func_0x8002767c(0), iVar2 == 0) {
    func_0x8004cd88(1);
  }
  func_0x800274f8(0x200,0xfffffaac,7,0);
  func_0x800275c0(0,0,0,0);
  uVar4 = 0;
  bVar1 = true;
  do {
                    /* WARNING (jumptable): Second-stage recovery error */
                    /* WARNING: This code block may not be properly labeled as switch case */
    if ((bVar1) && (iVar2 = func_0x8002767c(0), iVar2 != 0)) {
      uVar4 = 1;
    }
    iVar2 = 0;
    DAT_80160b84 = 0x14;
    DAT_80160b90 = 0x98;
    DAT_80160b94 = 0xa8;
    puVar3 = &DAT_80160b78;
    do {
      iVar2 = iVar2 + 1;
      _DAT_800df8b4 = func_0x80046f98(_DAT_800df8b4,puVar3);
      puVar3 = puVar3 + 0x10;
    } while (iVar2 < 2);
    func_0x8004cd88(1);
    bVar1 = uVar4 < 7;
  } while( true );
}
