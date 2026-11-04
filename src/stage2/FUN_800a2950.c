/* FUN_800a2950
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a2950  body 0x800a2950..0x800a2bcf  size 640 B
 * body sha256 48b66eb6a5841288f3bba9a29811c4cf101792a93fb81df325d0b2b52f5ff189
 * provider record sha256 579077eaf878793666e1a7d7a2b74504b9b33c75a24a94c28c0255e4812ba850
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a2950(ushort param_1,int param_2)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  ushort uVar4;
  float fVar5;
  
  _DAT_80143f14 = param_1;
  _DAT_80143f0c = (*_DAT_80144008)((uint)param_1 * 0x68,0);
  uVar4 = 0;
  DAT_80143f16 = 0;
  _DAT_80143f10 = _DAT_80143f0c;
  if (_DAT_80143f14 != 0) {
    uVar2 = 0;
    do {
      iVar3 = uVar2 * 0x68;
      *(undefined1 *)(iVar3 + _DAT_80143f10) = 0;
      *(undefined1 *)(iVar3 + _DAT_80143f10 + 0x61) = 0;
      uVar4 = uVar4 + 1;
      *(undefined1 *)(iVar3 + _DAT_80143f10 + 0x60) = 0xff;
      uVar2 = (uint)uVar4;
    } while (uVar4 < _DAT_80143f14);
  }
  if (DAT_80143fe8 == '\0') {
    fVar5 = (float)param_2;
    if (param_2 < 0) {
      fVar5 = fVar5 + 4.2949673e+09;
    }
    fVar5 = fVar5 / 50.0;
  }
  else {
    fVar5 = (float)param_2;
    if (param_2 < 0) {
      fVar5 = fVar5 + 4.2949673e+09;
    }
    fVar5 = fVar5 / 25.0;
  }
  fVar5 = (fVar5 / 192.0) * 1.2;
  if (2.1474836e+09 <= fVar5) {
    sVar1 = (short)(int)(fVar5 - 2.1474836e+09);
  }
  else {
    sVar1 = (short)(int)fVar5;
  }
  _DAT_80143f4e = sVar1 + 1;
  _DAT_80143f58 = (*_DAT_80144008)((uint)_DAT_80143f4e * 0xa10,0);
  _DAT_80143f5c = (*_DAT_80144008)((uint)_DAT_80143f4e * 0xa10,0);
  _DAT_80143f62 = 0;
  _DAT_80143f60 = 0;
  _DAT_80143f64 = (*_DAT_80144008)(0x298,0);
  func_0x80006650(_DAT_80143f64,0x298);
  func_0x8000efa0(_DAT_80143f64,0x298);
  return;
}
