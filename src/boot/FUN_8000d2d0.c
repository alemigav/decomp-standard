/* FUN_8000d2d0
 * image   boot (boot), base 0x80000480
 * address 0x8000d2d0  body 0x8000d2d0..0x8000d35f  size 144 B
 * body sha256 9f6fb597ac7524d4a1544599119182cee93dc015727661195da26459e19a4ef5
 * provider record sha256 b58bb82a68301342f58eb3af3b907135d8978e0dd7e93cdea772c6cad08a42f1
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8000d2d0(uint param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 & 3) != 0) {
    FUN_8000c620(0x80011cb0,0x80011cb4,0x33);
  }
  if (param_2 == (undefined4 *)0x0) {
    FUN_8000c620(0x80011cb0,0x80011cb4,0x34);
  }
  iVar1 = FUN_8000d2b0();
  uVar2 = 0xffffffff;
  if (iVar1 == 0) {
    uVar2 = 0;
    *param_2 = *(undefined4 *)(param_1 | 0xa0000000);
  }
  return uVar2;
}
