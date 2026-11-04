/* FUN_8016525c
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x8016525c  body 0x8016525c..0x80165363  size 264 B
 * body sha256 f4968630d35abd61c6954e821f5c20ea2e8dd573d3e2cf796e7bc017ce63fe5b
 * provider record sha256 118f53665048f0cf0293c0c02faa5eb3438c65f69d036d2c450ef6a8a6e7c96c
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016525c(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  uint uVar2;
  char cVar3;
  undefined4 uVar4;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(undefined4 *)(param_1 + 4) = 0x1080000;
        *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) | 0x4000;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0x18000f00;
    *(undefined1 *)(param_1 + 6) = 1;
    func_0x800331fc(&DAT_800e1130,param_2,param_3,0);
    uVar2 = func_0x80033604();
    uVar4 = 0xb;
    if ((uVar2 & 1) != 0) {
      uVar4 = 10;
    }
    func_0x80077d18(uVar4,param_1);
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
  }
  func_0x8003331c(param_1,param_2,param_3,0);
  cVar3 = func_0x80089d54(param_1,param_2,param_3,0x100);
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar3;
  return;
}
