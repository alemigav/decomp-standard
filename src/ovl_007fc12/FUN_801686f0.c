/* FUN_801686f0
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x801686f0  body 0x801686f0..0x801687e3  size 244 B
 * body sha256 e82e0a841630eb14f0dc8dfae28143f08f3f4e6ea0ae0fb34202e80b971ab70e
 * provider record sha256 8c2a2fc78fb0dea2ed4be60fca264d37c5f93e43cf7e37001fe2c8f08a28a545
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801686f0(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(undefined4 *)(param_1 + 4) = 0x1010000;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined2 *)(param_1 + 0x1f6) = 10;
    *(undefined1 *)(param_1 + 6) = 1;
    *(uint *)(param_1 + 0x1e8) =
         (4 - (uint)((*(ushort *)(param_1 + 0x26c) & 0x20) != 0)) * 0x1000000 + 0x300;
  }
  func_0x800334c8(param_1,param_2,param_3,0,0xfa);
  cVar2 = func_0x80089d54(param_1,param_2,param_3,0x400);
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar2;
  func_0x80032b5c(param_1,0);
  return;
}
