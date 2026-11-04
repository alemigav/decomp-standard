/* FUN_80165a48
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80165a48  body 0x80165a48..0x80165c5f  size 536 B
 * body sha256 4f0140cac0ead46bae58620765a1b18ac00ec3d498027972fc9cdf3c63d1b949
 * provider record sha256 267b4105dad5a4cc95208cbbdb29e04a5b7f38c23e1c6bbf90364c9a58ac2135
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165a48(int param_1)

{
  byte bVar6;
  short sVar4;
  ushort uVar5;
  int iVar1;
  uint uVar2;
  uint uVar3;
  byte local_18 [8];
  
  local_18[0] = 0;
  local_18[1] = 2;
  local_18[2] = 4;
  *(ushort *)(param_1 + 0x272) = *(ushort *)(param_1 + 0x272) | 0x4000;
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    uVar2 = func_0x80033604();
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined1 *)(param_1 + 0x206) = 0;
    *(uint *)(param_1 + 0x1e8) =
         (uint)*(byte *)(param_1 + 0x2b4) * 0x1000000 + (uVar2 & 3) * 0x10000 + 0xf00;
    if ((*(ushort *)(param_1 + 0x270) & 0x4000) != 0) {
      bVar6 = func_0x80033604();
      *(byte *)(param_1 + 0x206) = (bVar6 & 1) + 1;
    }
  case 1:
    func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),0x100)
    ;
    sVar4 = func_0x80032f64(param_1,*(ushort *)(param_1 + 0x270) & 0xfff,0x20);
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + sVar4;
    if (sVar4 == 0) {
      *(undefined1 *)(param_1 + 6) = 2;
    }
    break;
  case 2:
    uVar2 = func_0x80033604();
    uVar3 = func_0x80033604();
    bVar6 = local_18[*(char *)(param_1 + 0x206)];
    *(undefined1 *)(param_1 + 6) = 3;
    *(uint *)(param_1 + 0x1e8) =
         ((uint)bVar6 + (uVar2 & 1)) * 0x1000000 + (uVar3 & 7) * 0x10000 + 0xf00;
    uVar5 = func_0x80033604();
    *(ushort *)(param_1 + 500) = (uVar5 & 0x7f) + 0x3c;
  case 3:
    iVar1 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x22c),
                            *(undefined4 *)(param_1 + 0x230),0x100);
    if (iVar1 != 0) {
      uVar2 = func_0x80033604();
      uVar3 = func_0x80033604();
      *(uint *)(param_1 + 0x1e8) =
           ((uint)local_18[*(char *)(param_1 + 0x206)] + (uVar2 & 1)) * 0x1000000 +
           (uVar3 & 7) * 0x10000 + 0xf00;
    }
    uVar5 = *(ushort *)(param_1 + 0x272) & 0x7fff;
    *(ushort *)(param_1 + 0x272) = uVar5;
    if ((**(uint **)(param_1 + 0x214) & 0x10000) != 0) {
      *(ushort *)(param_1 + 0x272) = uVar5 | 0x8000;
    }
    sVar4 = *(short *)(param_1 + 500) + -1;
    *(short *)(param_1 + 500) = sVar4;
    if (sVar4 == -1) {
      *(undefined1 *)(param_1 + 6) = 4;
    }
    break;
  case 4:
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  return;
}
