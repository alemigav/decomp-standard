/* FUN_8016296c
 * image   ovl_00b5346 (ovl), base 0x80161cf0
 * address 0x8016296c  body 0x8016296c..0x80162a8b  size 288 B
 * body sha256 d5e621afcaf0d996e25112a861988faf3223694023fdcfc469649c32c6d24904
 * provider record sha256 6009fa47fd14c45edac82e08b401e88351d9b9122c5a119b6da9a45cc4205a6f
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016296c(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  ushort uVar2;
  short sVar3;
  undefined2 uVar4;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x1e0) = 2;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    uVar1 = func_0x80033604();
    uVar4 = 0xfffe;
    if ((uVar1 & 1) != 0) {
      uVar4 = 2;
    }
    *(undefined2 *)(param_1 + 0x2ba) = uVar4;
    *(undefined2 *)(param_1 + 500) = 0x1000;
  }
  *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + *(short *)(param_1 + 0x2ba);
  func_0x80032b5c(param_1,0);
  func_0x80089d54(param_1,param_2,param_3,0x80);
  uVar2 = *(short *)(param_1 + 500) - 2;
  *(ushort *)(param_1 + 500) = uVar2;
  if ((int)((uint)uVar2 << 0x10) < 0) {
    *(short *)(param_1 + 0x2ba) = -*(short *)(param_1 + 0x2ba);
    *(undefined2 *)(param_1 + 500) = 0x1000;
  }
  if (_DAT_800e12da == 0x11) {
    sVar3 = -*(short *)(param_1 + 0x2e);
    *(short *)(param_1 + 0x134) = *(short *)(param_1 + 0x2e);
  }
  else {
    *(undefined2 *)(param_1 + 0x134) = 0xff38;
    sVar3 = 200;
  }
  *(short *)(param_1 + 0x13a) = sVar3;
  return;
}
