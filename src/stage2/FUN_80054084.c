/* FUN_80054084
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80054084  body 0x80054084..0x800540d3  size 80 B
 * body sha256 d0f379ba1c60108f1bb310040613dd29c9e3f32356511913c06940f9c833cad2
 * provider record sha256 d3e934b5c907ed71e532ab544b25d7d1f021831ce9275e1e82d434785c787adb
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80054084(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2] + (uint)*(ushort *)((int)param_2 + 10);
  param_1[3] = (uint)*(byte *)(param_2 + 3) * 0x1000000 +
               (uint)*(byte *)((int)param_2 + 0xd) * 0x10000 +
               (uint)*(byte *)((int)param_2 + 0xe) * 0x100 + (uint)*(byte *)((int)param_2 + 0xf);
  return;
}
