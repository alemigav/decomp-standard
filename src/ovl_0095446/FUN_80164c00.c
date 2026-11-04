/* FUN_80164c00
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x80164c00  body 0x80164c00..0x80164d3f  size 320 B
 * body sha256 953e977fade20197fe6a5e81e50d31a7925316dae943e1826884488d862ff4be
 * provider record sha256 36241c3aa1fdb902ee6f271ac7b4ed691e763e1c7ee282061d9c12cb22162829
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164c00(int param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  short sVar2;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x1003f00;
    *(undefined1 *)(param_1 + 6) = 1;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
    uVar1 = func_0x80033604();
    *(ushort *)(param_1 + 500) = (uVar1 & 0x1f) + 0x82;
    *(undefined2 *)(param_1 + 0x1e0) = 10;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  if (0xf < *(short *)(param_1 + 0x1e0)) {
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,4);
  }
  if (10 < *(short *)(param_1 + 0x1e0)) {
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,4);
  }
  func_0x80089d54(param_1,param_2,param_3,0x10040);
  func_0x80032b5c(param_1,0x800);
  sVar2 = *(short *)(param_1 + 500) + -1;
  *(short *)(param_1 + 500) = sVar2;
  if (sVar2 == -1) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  return;
}
