/* FUN_80055234
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80055234  body 0x80055234..0x80055573  size 832 B
 * body sha256 5ea90756f573396d5d1227bba0f6ddc4d7cc84f985d876c538511eba576c0026
 * provider record sha256 c142f812efcd40cbe26e52cf4e102e2eac07302750b2189898e0432b1dae9022
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x80055440) */
/* WARNING: Removing unreachable block (ram,0x800553e4) */
/* WARNING: Removing unreachable block (ram,0x80055450) */
/* WARNING: Removing unreachable block (ram,0x80055458) */
/* WARNING: Removing unreachable block (ram,0x800553c8) */
/* WARNING: Removing unreachable block (ram,0x800553f8) */
/* WARNING: Removing unreachable block (ram,0x80055408) */
/* WARNING: Removing unreachable block (ram,0x80055410) */

void FUN_80055234(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  float in_f0;
  float fVar4;
  float fVar5;
  
  if (DAT_800e8b3e < 2) {
    iVar2 = (int)DAT_800df8c0;
    if ((('@' < DAT_800df8c1) || (DAT_800df8c1 < -0x19)) && ((0x19 < iVar2 || (iVar2 < -0x19)))) {
      iVar2 = iVar2 * 3;
    }
    if (iVar2 < 0x41) {
      if (iVar2 < -0x40) {
        uVar1 = (param_2 & 0xff) >> 3;
        if (uVar1 == 0) {
          DAT_8010dd68 = DAT_8010dd68 - 1;
        }
        else {
          DAT_8010dd68 = DAT_8010dd68 - uVar1;
        }
        if ((int)(param_2 & 0xff) < (int)-DAT_8010dd68) {
          DAT_8010dd68 = -(param_2 & 0xff);
        }
      }
      else if ((iVar2 < 0x1a) && (-0x1a < iVar2)) {
        DAT_8010dd68 = 0;
      }
      else {
        if (iVar2 < -0x19) {
          iVar2 = iVar2 + 0x19;
        }
        else {
          iVar2 = iVar2 + -0x19;
        }
        DAT_8010dd68 = (int)(((iVar2 * 0x100) / 6) * (param_2 & 0xff)) / 0xc >> 8;
      }
    }
    else {
      uVar1 = (param_2 & 0xff) >> 3;
      if (uVar1 == 0) {
        uVar1 = DAT_8010dd68 + 1;
      }
      else {
        uVar1 = DAT_8010dd68 + uVar1;
      }
      DAT_8010dd68 = param_2 & 0xff;
      if ((int)uVar1 <= (int)DAT_8010dd68) {
        DAT_8010dd68 = uVar1;
      }
    }
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + DAT_8010dd68._2_2_;
  }
  else {
    iVar3 = (int)DAT_800df8c0;
    iVar2 = -(int)DAT_800df8c1;
    FUN_80047d70((float)iVar2,(float)iVar3);
    fVar5 = in_f0 - 1.5708;
    fVar4 = (float)(iVar3 * iVar3 + iVar2 * iVar2);
    FUN_80048060(fVar4);
    DAT_8010dd70 = (int)(fVar4 * in_f0);
    DAT_8010dc0c = fVar5;
    *(short *)(param_1 + 0x66) = (short)(int)(((DAT_8010dd6c + fVar5 + 1.57081) * 4096.0) / 6.2831);
  }
  return;
}
