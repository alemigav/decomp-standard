/* FUN_80168388
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80168388  body 0x80168388..0x80168437  size 176 B
 * body sha256 2d978455bce42900fef9b6aa4bfd89e6e3197915cac1c00c664dcdc9937d2d89
 * provider record sha256 d8f60b3b1426131c917c49889881e099204a44db656f68a7e26102e4bf13bc2e
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80168388(int param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 == 1) {
    func_0x80077d18(8,param_1);
    cVar2 = *(char *)(param_1 + 6);
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 == 0) {
        FUN_8016775c(param_1);
        return;
      }
      return;
    }
    if (bVar1 != 2) {
      return;
    }
    iVar3 = func_0x80036be4(param_1,0xb,0xf,0);
    if (iVar3 == 0) {
      return;
    }
    cVar2 = *(char *)(param_1 + 6);
    *(undefined1 *)(param_1 + 0x2b7) = 1;
  }
  *(char *)(param_1 + 6) = cVar2 + '\x01';
  return;
}
