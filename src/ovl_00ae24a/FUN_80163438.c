/* FUN_80163438
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x80163438  body 0x80163438..0x80163697  size 608 B
 * body sha256 9d88c981052028829b1090ece140ad49e79565a4ecb0a8e1dfad562692695575
 * provider record sha256 127bdb215b2e5d62dbe0c5c1bebd86f6c029a214dc0ed159efd3e03fc2a3d672
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163438(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  short sVar3;
  int iVar2;
  uint uVar4;
  uint uVar5;
  undefined1 local_20 [8];
  
  *(ushort *)(param_1 + 0x2c2) = *(ushort *)(param_1 + 0x2c2) | 2;
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x2001f00;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 500) = 0;
    *(undefined1 *)(param_1 + 0x206) = 0;
    func_0x80077d18(0xb,param_1);
    *(undefined2 *)(param_1 + 0x1f6) = 0;
    uVar4 = func_0x80033604();
    uVar5 = func_0x80033604();
    *(byte *)(param_1 + 0x207) = (byte)((int)(uVar4 & 0xff) >> (uVar5 & 3)) & 7;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  if ((*(char *)(param_1 + 0x206) == '\0') &&
     (sVar3 = *(short *)(param_1 + 500) + 1, *(short *)(param_1 + 500) = sVar3, sVar3 == 0x32)) {
    *(byte *)(param_1 + 0x206) = *(byte *)(param_1 + 0x206) | 1;
    func_0x80077d18(0xb,param_1);
  }
  if ((*(char *)(param_1 + 0x206) == '\x01') &&
     (sVar3 = *(short *)(param_1 + 500), *(short *)(param_1 + 500) = sVar3 + -1, sVar3 == 1)) {
    *(undefined1 *)(param_1 + 0x206) = 2;
    func_0x80077d18(10,param_1);
  }
  *(undefined2 *)(param_1 + 0x1e0) = *(undefined2 *)(param_1 + 500);
  if (4000 < *(int *)(param_1 + 0x28)) {
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) - (int)*(short *)(param_1 + 500);
  }
  iVar2 = func_0x80089d54(param_1,param_2,param_3,0x80);
  if (iVar2 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1000000;
    *(ushort *)(param_1 + 0x2c2) = *(ushort *)(param_1 + 0x2c2) & 0xfffd;
  }
  iVar2 = 4;
  if ((*(ushort *)(param_1 + 0x1f6) & 0x1f) == 0) {
    uVar4 = 0;
    uVar5 = 0;
    do {
      iVar2 = iVar2 + -1;
      if ((((int)(uint)*(byte *)(param_1 + 0x2c4) >> (uVar4 & 0x1f) & 1U) == 0) &&
         (((int)(uint)*(byte *)(param_1 + 0x2c4) >> (uVar4 + 4 & 0x1f) & 1U) == 0)) {
        local_20[uVar5 & 0xff] = (char)uVar4;
        uVar5 = uVar5 + 1;
      }
      uVar4 = uVar4 + 1;
    } while (iVar2 != 0);
    uVar5 = uVar5 & 0xff;
    if (uVar5 != 0) {
      if (*(uint *)(param_1 + 0x28c) < 7000) {
        *(undefined1 *)(param_1 + 0x207) = 0;
      }
      uVar4 = func_0x80033604();
      if (uVar5 == 0) {
        trap(0x1c00);
      }
      uVar1 = local_20[(uVar4 & 0xff) % uVar5];
      uVar4 = func_0x80033604();
      uVar5 = func_0x80033604();
      FUN_801667c0(uVar1,*(undefined4 *)
                          (&DAT_80166fb8 +
                          ((int)(uVar4 & 0xff) >> (uVar5 & 3) & 1U) * 4 +
                          *(char *)(param_1 + 0x207) * 8));
    }
  }
  *(short *)(param_1 + 0x1f6) = *(short *)(param_1 + 0x1f6) + 1;
  return;
}
