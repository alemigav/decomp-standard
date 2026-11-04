/* FUN_801658ec
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801658ec  body 0x801658ec..0x801659d7  size 236 B
 * body sha256 ba89726e735a424b50c7dadb94eb7f8643bfe926f557654facd46cf36d85cde8
 * provider record sha256 17c9e48f79edd446d85c95f63e2d05d2519606486f4b652483f569a83eb7d6db
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801658ec(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  char cVar2;
  
  if (*(char *)(param_1 + 6) == '\0') {
    FUN_80164d90();
    *(undefined1 *)(param_1 + 699) = 8;
    uVar1 = func_0x80033604();
    FUN_80166980(param_1,uVar1 & 0xf,0xb);
    *(undefined1 *)(param_1 + 0x207) = 0;
  }
  FUN_80164d5c(param_1,param_2,param_3);
  cVar2 = *(char *)(param_1 + 0x207) + '\x01';
  *(char *)(param_1 + 0x207) = cVar2;
  if (((int)cVar2 % 3 & 0xffU) == 0) {
    uVar1 = func_0x80033604();
    FUN_80166980(param_1,uVar1 & 0xf,0xb);
    uVar1 = func_0x80033604();
    FUN_80166980(param_1,uVar1 & 0xf,0xb);
  }
  return;
}
