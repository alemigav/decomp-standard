/* FUN_8000aaf0
 * image   boot (boot), base 0x80000480
 * address 0x8000aaf0  body 0x8000aaf0..0x8000ab7f  size 144 B
 * body sha256 8db34d748932c0af50ed0235cdabe77b88bb340170238598fcbbed91df9d4ddf
 * provider record sha256 9f595d1689ff6f0a60234e4f9561ac2eee63257b5e6607cf7c05ffd3824c6840
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000aaf0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)&DAT_80016470;
  iVar1 = 0;
  _DAT_800164ac = 1;
  DAT_80014fe0 = 0;
  if (0 < param_1) {
    do {
      *(undefined1 *)puVar2 = 0;
      iVar1 = iVar1 + 1;
      puVar2 = (undefined4 *)((int)puVar2 + 1);
    } while (iVar1 < param_1);
  }
  *puVar2 = 0x10300ff;
  *(undefined1 *)(puVar2 + 1) = 0xff;
  *(undefined1 *)((int)puVar2 + 5) = 0xff;
  *(undefined1 *)((int)puVar2 + 6) = 0xfe;
  return;
}
