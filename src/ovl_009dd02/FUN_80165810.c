/* FUN_80165810
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80165810  body 0x80165810..0x80165907  size 248 B
 * body sha256 f399af6c7ad035538cf4d436f0a3c6be3e59a6d5d84132d9e58e134499d87258
 * provider record sha256 37eeb4b2ba0b9a161a109f7fff5440edd2fbb01060dca318bdf440cd1f2db8a8
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165810(int param_1)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  
  cVar1 = *(char *)(param_1 + 5);
  if (*(char *)(param_1 + 6) == '\0') {
    FUN_8016561c();
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 1;
    cVar2 = '\f';
    if (((uint)*(byte *)(param_1 + 0x26e) % 3 == 0) && (*(char *)(param_1 + 0x2d9) == '\0')) {
      cVar2 = '\x06';
      uVar3 = 9;
    }
    else {
      uVar3 = 0xe;
    }
    FUN_80166b98(param_1,cVar2 + -1,0);
    if (((*(byte *)(param_1 + 0x26e) < 3) || (cVar1 == '\x06')) || (cVar1 == '\b')) {
      FUN_80165770(param_1,cVar2,uVar3);
    }
  }
  else {
    FUN_801656c0(param_1);
  }
  return;
}
