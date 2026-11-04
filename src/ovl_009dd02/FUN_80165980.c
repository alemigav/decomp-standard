/* FUN_80165980
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80165980  body 0x80165980..0x80165a47  size 200 B
 * body sha256 1e3de73f528648ed60f89595e6b2df999a821ff48832d92516e6f2a8a8fd5fa4
 * provider record sha256 37dda18fe49ec07636c0a1c6ad80701c132cca99bc6f7dde226ad1388fcb62b7
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165980(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  FUN_8016561c();
  *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 1;
  cVar1 = '\f';
  if (((uint)*(byte *)(param_1 + 0x26e) % 3 == 0) && (*(char *)(param_1 + 0x2d9) == '\0')) {
    cVar1 = '\x06';
    uVar2 = 9;
  }
  else {
    uVar2 = 0xe;
  }
  FUN_80166b98(param_1,cVar1 + -1,0);
  FUN_80166b98(param_1,cVar1 + -1,3);
  FUN_80165770(param_1,cVar1,uVar2);
  return;
}
