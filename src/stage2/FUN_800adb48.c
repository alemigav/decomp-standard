/* FUN_800adb48
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800adb48  body 0x800adb48..0x800adc43  size 252 B
 * body sha256 4df4c23851e7a61044d23c830465ea75cee062efa8f455021f7a920ee6344727
 * provider record sha256 a2db181f614ae98a1d0b23535278cc90d5ba0046aa7f727d4a151efa6d3bdf17
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800adb48(short param_1,int param_2,ushort param_3)

{
  undefined4 uVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  if (0 < _DAT_80157e10) {
    psVar2 = (short *)&DAT_80157e20;
    do {
      if (*psVar2 == param_1) break;
      iVar3 = iVar3 + 1;
      psVar2 = psVar2 + 4;
    } while (iVar3 < _DAT_80157e10);
  }
  uVar1 = 0;
  if ((iVar3 == _DAT_80157e10) && (uVar1 = 0, iVar3 < 0x80)) {
    FUN_800a5678();
    iVar4 = 0;
    iVar3 = _DAT_80157e10 * 8;
    *(short *)(&DAT_80157e20 + iVar3) = param_1;
    *(ushort *)(&DAT_80157e22 + iVar3) = param_3;
    *(int *)(&DAT_80157e24 + iVar3) = param_2;
    if (param_3 != 0) {
      do {
        *(undefined1 *)(param_2 + 9) = 0x1f;
        iVar4 = iVar4 + 1;
        param_2 = param_2 + 0xc;
      } while (iVar4 < (int)(uint)param_3);
    }
    _DAT_80157e10 = _DAT_80157e10 + 1;
    FUN_800a56c0();
    uVar1 = 1;
  }
  return uVar1;
}
