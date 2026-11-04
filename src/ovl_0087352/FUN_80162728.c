/* FUN_80162728
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80162728  body 0x80162728..0x801627b3  size 140 B
 * body sha256 f4959b20c7284f6d7f725d7fc98917dd2ae3c0f86bc72dbd62988a87dc437928
 * provider record sha256 ddb116e676620f6f7ce1d87f0c9113e227670f1ff5a559342465946dbab74e15
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162728(int param_1)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  
  if (*(char *)(param_1 + 6) == '\0') {
    bVar1 = func_0x80033604();
    *(byte *)(param_1 + 0x2b5) = bVar1 & 7;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  cVar2 = *(char *)(param_1 + 0x2b5) + -1;
  *(char *)(param_1 + 0x2b5) = cVar2;
  if (cVar2 == -1) {
    if ((*(ushort *)(param_1 + 0x1aa) & 0x40) == 0) {
      uVar3 = 2;
    }
    else {
      uVar3 = 3;
    }
    FUN_80165c68(param_1,uVar3);
  }
  return;
}
