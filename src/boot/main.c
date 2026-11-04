/* main
 * image   boot (boot), base 0x80000480
 * address 0x80000520  body 0x80000520..0x80000597  size 120 B
 * body sha256 f693c9e99c2a546784f8198b2b82948f3e3de3ee31aac2ee44a0e2c3c7bcc8bb
 * provider record sha256 5a1dcb62ae9cb0c68c6a960b6f43db113c8347bd00b5c59ba3f9494fa1d6b8c1
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void main(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)&DAT_800138a0;
  iVar1 = 0x1477;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (iVar1 != -1);
  FUN_800004f0(0);
  vector_installer();
  if (_DAT_80000300 != 0) {
    boot_loader();
    return;
  }
  do {
  } while( true );
}
