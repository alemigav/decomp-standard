/* FUN_80166cd4
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x80166cd4  body 0x80166cd4..0x80166d83  size 176 B
 * body sha256 5b126e167482c88d99953a33e60f91988eb5ea7e0a99288bcac3ce9c6dac6a80
 * provider record sha256 50bfe786d3f164f0d969ddac9604165329a97b44a78ecab667f92b172557682a
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166cd4(int param_1)

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
        FUN_801667a8(param_1);
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
