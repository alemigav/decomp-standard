/* FUN_801635b4
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801635b4  body 0x801635b4..0x80163603  size 80 B
 * body sha256 0fc68e35a28f8f3c07b29668e403d987202967d70af2a8ea464f3003428f9420
 * provider record sha256 494bb110257cd3d34b95b67c251f101c53860a57c817ecba918f61c88d05bdcc
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801635b4(uint *param_1)

{
  int iVar1;
  
  iVar1 = func_0x80089d54();
  if (iVar1 != 0) {
    *(undefined2 *)((int)param_1 + 6) = 0x300;
    *param_1 = *param_1 | 0x8000000;
    *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) & 0xdfff;
  }
  return;
}
