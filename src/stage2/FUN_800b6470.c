/* FUN_800b6470
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b6470  body 0x800b6470..0x800b6633  size 452 B
 * body sha256 8dc4e65a86cea5a9872a953b1ec54278a945dad9729a1911ca9a2573324dddf4
 * provider record sha256 d9473a4c8d885ab79ab4ad2e7607e124454d520d5690eff274ab3d514035e681
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800b6470(void)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  int in_a3;
  ushort *in_t0;
  short *in_t1;
  int iVar4;
  int iVar5;
  int in_t3;
  int in_t6;
  int in_t7;
  int unaff_s0;
  int unaff_s1;
  int unaff_s2;
  int unaff_s3;
  int unaff_s4;
  int unaff_s5;
  int unaff_s6;
  int unaff_s7;
  int in_t8;
  
  do {
    sVar2 = *in_t1;
    in_t1 = in_t1 + 1;
    iVar4 = ((int)sVar2 - (unaff_s7 * 0x6470 + 0x4000 >> 0xf)) -
            (unaff_s6 * -0x7ff5 + 0x4000 >> 0xf);
    unaff_s7 = (iVar4 * -0x7ff5 + 0x4000 >> 0xf) + unaff_s6;
    iVar4 = iVar4 - (unaff_s5 * (short)in_t8 + 0x4000 >> 0xf);
    unaff_s6 = ((short)in_t8 * iVar4 + 0x4000 >> 0xf) + unaff_s5;
    iVar4 = iVar4 - (unaff_s4 * (in_t8 >> 0x10) + 0x4000 >> 0xf);
    unaff_s5 = ((in_t8 >> 0x10) * iVar4 + 0x4000 >> 0xf) + unaff_s4;
    iVar4 = iVar4 - (unaff_s3 * (short)in_t7 + 0x4000 >> 0xf);
    unaff_s4 = ((short)in_t7 * iVar4 + 0x4000 >> 0xf) + unaff_s3;
    iVar4 = iVar4 - (unaff_s2 * (in_t7 >> 0x10) + 0x4000 >> 0xf);
    unaff_s3 = ((in_t7 >> 0x10) * iVar4 + 0x4000 >> 0xf) + unaff_s2;
    iVar4 = iVar4 - (unaff_s1 * (short)in_t6 + 0x4000 >> 0xf);
    unaff_s2 = ((short)in_t6 * iVar4 + 0x4000 >> 0xf) + unaff_s1;
    iVar4 = iVar4 - (unaff_s0 * (in_t6 >> 0x10) + 0x4000 >> 0xf);
    unaff_s1 = ((in_t6 >> 0x10) * iVar4 + 0x4000 >> 0xf) + unaff_s0;
    in_a3 = iVar4 + (in_a3 * 0x6e14 + 0x4000 >> 0xf);
    iVar5 = in_a3 * 2;
    iVar3 = (iVar5 >> 0xf) + 1 >> 1;
    if ((iVar3 != 0) && (iVar5 = -0x8000, -1 < iVar3)) {
      iVar5 = 0x7fff;
    }
    *in_t0 = (ushort)iVar5 & 0xfff8;
    in_t0 = in_t0 + 1;
    bVar1 = 0 < in_t3;
    in_t3 = in_t3 + -1;
    unaff_s0 = iVar4;
  } while (bVar1);
  return;
}
