/* FUN_80082010
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80082010  body 0x80082010..0x800821ff  size 496 B
 * body sha256 75c05ea733eaea1efa0c102ec4213342b667fe1a1edff1a1480911870ff1a211
 * provider record sha256 6debf2454399247cbadd9efd8b934df502ecab270db796b79589fab0da195fc5
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80082010(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined1 *)(param_1 + 0x1ea) = 7;
    if ((*(ushort *)(param_1 + 0x268) & 0x40) != 0) {
      *(undefined1 *)(param_1 + 0x1ea) = 0;
    }
    if ((*(ushort *)(param_1 + 0x268) & 0x100) != 0) {
      FUN_800334c8(param_1,param_2,param_3,(*(ushort *)(param_1 + 0x268) & 0x80) != 0);
    }
  }
  if ((**(uint **)(param_1 + 0x214) & 0x4000) != 0) {
    FUN_80077f30(0,((**(uint **)(param_1 + 0x214) & 0x2000) >> 0xd) * 3 + 4,param_1);
    DAT_800e112a = DAT_800e112a | 2;
  }
  FUN_800334c8(param_1,param_2,param_3,*(byte *)(param_1 + 0x269) >> 7);
  iVar2 = FUN_80089d54(param_1,param_2,param_3,
                       (uint)(*(byte *)(param_1 + 0x269) >> 7) << 0x10 | 0x200);
  if (iVar2 == 0) {
    FUN_80032bd8(param_1,0,0);
    if ((*(ushort *)(param_1 + 0x268) & 8) != 0) {
      iVar2 = FUN_80089d54(param_1,param_2,param_3,
                           (uint)((*(ushort *)(param_1 + 0x268) & 0x80) != 0) << 0x10 | 0x200);
      if (iVar2 != 0) {
        *(undefined1 *)(param_1 + 6) = 2;
        if ((*(ushort *)(param_1 + 0x268) & 4) != 0) {
          *(undefined1 *)(param_1 + 6) = 1;
        }
        *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + *(short *)(param_1 + 0x272);
      }
      FUN_80032bd8(param_1,0,0);
    }
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + *(short *)(param_1 + 0x270);
  }
  else {
    *(undefined1 *)(param_1 + 6) = 2;
    if ((*(ushort *)(param_1 + 0x268) & 4) != 0) {
      *(undefined1 *)(param_1 + 6) = 1;
    }
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + *(short *)(param_1 + 0x272);
    FUN_80032bd8(param_1,0,0);
  }
  return;
}
