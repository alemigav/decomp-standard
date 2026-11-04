/* FUN_801634b4
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x801634b4  body 0x801634b4..0x80163617  size 356 B
 * body sha256 4e5f612f92245fcf9c591bb3169e0e9b773d6e9fd62606d07635044ac8f1814f
 * provider record sha256 b94807ebf0ef6bce6425540833d94943b7792358d3ab86de86a87985f69f59d8
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801634b4(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  short sVar2;
  undefined2 uVar3;
  uint *puVar4;
  
  bVar1 = *(byte *)(param_1 + 6);
  puVar4 = *(uint **)(param_1 + 0x234);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      func_0x80089d54(param_1,param_2,param_3,0x80);
      sVar2 = *(short *)(puVar4 + 0x49);
      *(short *)(puVar4 + 0x49) = sVar2 + 0x40;
      if ((short)(sVar2 + 0x40) < 0x1001) {
        return;
      }
      *(undefined2 *)(puVar4 + 0x49) = 0x1000;
      *(undefined4 *)(param_1 + 4) = 0x1040000;
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0;
    *(undefined1 *)(param_1 + 6) = 1;
    *puVar4 = *puVar4 | 1;
    *(undefined2 *)(param_1 + 0x68) = 0xffe0;
    *(undefined2 *)(param_1 + 0x66) = 0;
    uVar3 = func_0x80032d14((int)*(short *)(param_1 + 0x2e),
                            (int)((uint)*(ushort *)(param_1 + 0x32) * -0x10000) >> 0x10,
                            (int)*(short *)(_DAT_800e1364 + 0x52),
                            (int)((uint)*(ushort *)(_DAT_800e1364 + 0x56) * -0x10000) >> 0x10);
    *(undefined2 *)(param_1 + 100) = uVar3;
  }
  func_0x80089d54(param_1,param_2,param_3,0x40);
  sVar2 = *(short *)(puVar4 + 0x49);
  *(short *)(puVar4 + 0x49) = sVar2 + 0x40;
  if (0x800 < (short)(sVar2 + 0x40)) {
    *(undefined1 *)(param_1 + 6) = 2;
    *(undefined4 *)(param_1 + 0x1e8) = 0x9001f00;
  }
  return;
}
