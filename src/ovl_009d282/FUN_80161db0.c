/* FUN_80161db0
 * image   ovl_009d282 (ovl), base 0x80161cf0
 * address 0x80161db0  body 0x80161db0..0x80161e1b  size 108 B
 * body sha256 be0bae63a347ee5eed2263fd4b65db797d35123a15330134e9e1f4d0f9db42aa
 * provider record sha256 345c5ef64e3cd13ca2f1196cd2515732ae6295b6a5ea97153747a3e4d5f26a8f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80161db0(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = *(byte *)(param_1 + 5);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    if (*(short *)(param_1 + 0x270) == 0) {
      return;
    }
    *(undefined1 *)(param_1 + 5) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0;
  }
  cVar2 = func_0x80089d54(param_1,param_2,param_3,0x1000);
  *(char *)(param_1 + 5) = *(char *)(param_1 + 5) + cVar2;
  return;
}
