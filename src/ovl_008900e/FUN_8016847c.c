/* FUN_8016847c
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x8016847c  body 0x8016847c..0x8016852b  size 176 B
 * body sha256 b2438005a0452768dee65aeaa8e8dc0181d9c58b074d5d813c9a28891e877793
 * provider record sha256 31d9399b9710c14ec5e9699e77a52ecb4242685d021d7d391daa1f49dee3429c
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016847c(int param_1)

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
        FUN_80167c6c(param_1);
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
