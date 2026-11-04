/* FUN_80074274
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80074274  body 0x80074274..0x80074463  size 496 B
 * body sha256 5ec3e827ef8bec84ca8f75e1c702931b6e48c6d5f2a7afd8028cbd60a14329d6
 * provider record sha256 1a7833efd11cff8045d8377e4aa89adee2e2198d0ce577180dd7debb1ad3ae75
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80074274(void)

{
  ushort uVar1;
  undefined4 *puVar2;
  uint uVar3;
  short sVar4;
  uint uVar5;
  
  if (DAT_800e861e != 1) {
    if (1 < DAT_800e861e) {
      if (DAT_800e861e == 2) {
        uVar5 = (uint)_DAT_8013a124;
        uVar3 = (uint)_DAT_8013a126;
        sVar4 = *(short *)(_DAT_8013a128 + 0x1a) - _DAT_8013a124;
        _DAT_8013a124 = (short)(uVar5 + uVar3);
        *(short *)(_DAT_8013a128 + 0x1a) = sVar4;
        if (0 < (int)((uVar5 + uVar3) * 0x10000)) {
          return;
        }
        DAT_8012bfa8 = 1;
        DAT_80131780 = 1;
        _DAT_8013a124 = 0;
        DAT_800e861e = 3;
        DAT_800e110c = DAT_800e110c | 0x8000;
      }
      else if (DAT_800e861e != 3) {
        return;
      }
      _DAT_8013a124 = _DAT_8013a124 + 1;
      if ((short)_DAT_8013a124 < 7) {
        return;
      }
      *(undefined2 *)(_DAT_8013a128 + 0x1a) = 0;
      DAT_800e861e = 0;
      DAT_800e8928 = 0;
      return;
    }
    if (DAT_800e861e != 0) {
      return;
    }
    _DAT_8013a124 = 1;
    _DAT_8013a126 = 3;
    DAT_801317c4 = DAT_800e1110;
    DAT_800e1110 = DAT_800e1110 | 0x7f000000;
    FUN_80077adc(0x2150000,0);
    DAT_800e861e = 1;
    _DAT_8013a128 = &DAT_800e18f8 + (uint)DAT_800e860f * 0xda;
  }
  puVar2 = _DAT_8013a128;
  uVar1 = _DAT_8013a126;
  *(ushort *)(_DAT_8013a128 + 0x1a) = *(short *)(_DAT_8013a128 + 0x1a) - _DAT_8013a124;
  if (*(short *)(puVar2 + 0x1a) < -399) {
    DAT_800e861e = 2;
    _DAT_8013a126 = -_DAT_8013a126;
  }
  _DAT_8013a124 = _DAT_8013a124 + uVar1;
  return;
}
