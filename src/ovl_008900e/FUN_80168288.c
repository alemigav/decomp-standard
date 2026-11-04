/* FUN_80168288
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80168288  body 0x80168288..0x80168387  size 256 B
 * body sha256 58d592b6f7f312ffd56092e466369566b743f0eba357c92285599bcde56dc0ce
 * provider record sha256 3e994f11d1f3c4d772ee90b8f0a6d4bd74c0ebc3703bb7997b17b4128099bc9c
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80168288(int param_1)

{
  byte bVar1;
  char cVar3;
  int iVar2;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(undefined1 *)(param_1 + 6) = 3;
        return;
      }
      if (bVar1 != 3) {
        return;
      }
      iVar2 = func_0x80036be4(param_1,0xb,0xf,0);
      if (iVar2 == 0) {
        return;
      }
      *(undefined1 *)(param_1 + 0x2b7) = 1;
      *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    func_0x80036e70(param_1);
    func_0x80077d18(8,param_1);
    FUN_80162ba4(param_1,&UNK_80168bf4 + (uint)*(byte *)(param_1 + 0x2cb) * 8,0);
    *(undefined1 *)(param_1 + 0x1e8) = 0;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
  cVar3 = func_0x80036be4(param_1,9,0,0);
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar3;
  return;
}
