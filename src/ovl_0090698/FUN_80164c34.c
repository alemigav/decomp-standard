/* FUN_80164c34
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80164c34  body 0x80164c34..0x80164ccb  size 152 B
 * body sha256 1628bb3ecd4668db511ea0cb3d9ce97ae8180def307434c6d7ddb789f0150036
 * provider record sha256 ea12a197c2343080a56e231d4c05db315aae695047149dcad8e8a57e7abc88dd
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164c34(uint *param_1)

{
  uint uVar1;
  
  *(undefined2 *)((int)param_1 + 0x1e2) = 0x28;
  *(undefined2 *)(param_1 + 0x7d) = 0x800;
  *(undefined1 *)((int)param_1 + 6) = 1;
  *(undefined2 *)(param_1 + 0x78) = 0;
  *(undefined2 *)(param_1 + 0x79) = 0;
  param_1[0x7a] = 0x1000300;
  *(undefined1 *)((int)param_1 + 0x2bf) = 1;
  *(undefined2 *)((int)param_1 + 0x2b6) = 0;
  *param_1 = *param_1 & 0xe3ffffff;
  *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
  FUN_8016753c();
  uVar1 = func_0x80033604();
  FUN_80167688(param_1,0x2004,(uVar1 & 1) + 1);
  return;
}
