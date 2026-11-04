/* FUN_8017fe54
 * image   ovl_0078c0e (ovl), base 0x8017b410
 * address 0x8017fe54  body 0x8017fe54..0x8017feb7  size 100 B
 * body sha256 bb33efdcd74f77669bae14b7d11ba58a1ca56755155c104da168f45130896332
 * provider record sha256 767020f8f8b974c2f10dcb6e77fbce580931d733f7123a606bb143430a06a9e4
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8017fe54(int param_1)

{
  int iVar1;
  int iVar2;
  int unaff_s1;
  
  iVar2 = 3;
  FUN_8017f844();
  while( true ) {
    iVar1 = FUN_80180020(param_1 << 4);
    iVar2 = iVar2 + -1;
    if ((iVar1 != 0) && (unaff_s1 = FUN_8017ff0c(), unaff_s1 == 0)) break;
    if (iVar2 == 0) {
      return unaff_s1;
    }
  }
  return 0;
}
