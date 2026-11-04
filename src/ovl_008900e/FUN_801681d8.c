/* FUN_801681d8
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x801681d8  body 0x801681d8..0x80168287  size 176 B
 * body sha256 b5bd377faa6c8ebbcb3c1d7c47db13028bb0df9a8f97aa53efef9997be749737
 * provider record sha256 ef09c12cf49742291bcf6e33ac8aa544e88f9ea20b45d6f957df118ca4142fe3
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801681d8(int param_1)

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
        FUN_80167024(param_1);
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
