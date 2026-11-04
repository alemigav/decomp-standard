/* FUN_800b1a98
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b1a98  body 0x800b1a98..0x800b1b07  size 112 B
 * body sha256 4bb3399f4fba47fec8e048685167417cb2ffe7949f2b2e0624a85852f3cb9775
 * provider record sha256 4a275402e9a0475b63dc7338f6170e383c1f082f6ba0565931dcdfa8f669b510
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800b1a98(void)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  do {
    uVar3 = 0;
    iVar1 = uVar4 * 0x10;
    do {
      *(undefined1 *)(iVar1 + -0x7fea7560) = 0xff;
      uVar3 = uVar3 + 1;
      iVar1 = uVar3 + uVar4 * 0x10;
    } while (uVar3 < 0x10);
    uVar4 = uVar4 + 1;
  } while (uVar4 < 8);
  puVar2 = (undefined1 *)0x80158a80;
  uVar4 = 0;
  do {
    *puVar2 = 0xff;
    uVar3 = uVar4 + 1;
    puVar2 = (undefined1 *)(uVar4 + 0x80158a81);
    uVar4 = uVar3;
  } while (uVar3 < 0x20);
  return;
}
