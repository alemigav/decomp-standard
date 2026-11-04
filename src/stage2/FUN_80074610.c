/* FUN_80074610
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80074610  body 0x80074610..0x8007485f  size 592 B
 * body sha256 0319823799dacdd15afe56ddae3cdba55935e98e8c0acca8afd933ef471b2c0f
 * provider record sha256 a95b2f95cd0e5d201da5e8a4ce12762d725421a6e3d2a02963cec16b839c2d65
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80074610(undefined2 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (DAT_800e8924 != (code *)0x0) {
    return 0;
  }
  if (DAT_800e139f != '\0') {
    return 0;
  }
  if ((DAT_800e110c & 0x8040) != 0) {
    return 0;
  }
  if (DAT_800e8ca8 < 4) {
    iVar1 = 0x21698;
  }
  else {
    iVar1 = 0x216b8;
  }
  iVar1 = FUN_800837ac((int)&DAT_800c76b0 + iVar1,
                       *(undefined2 *)((&DAT_800dfb60)[(ushort)param_1[1]] + 0x10));
  if (iVar1 == 0) {
    iVar1 = FUN_800837ac(&DAT_800e8ec0,*param_1);
    if (iVar1 == 0) {
      iVar1 = FUN_8008c51c(0x1f);
      if ((iVar1 < 0) && (DAT_800e8ef0 != '0')) {
        uVar2 = 2;
        goto LAB_80074838;
      }
      DAT_800dfbe0 = DAT_801152cc;
      DAT_800e861d = 1;
    }
    else {
      DAT_800dfbe0 = DAT_801152cc;
      FUN_80077adc(0x2280000,0);
      (&DAT_800e18f8)[(uint)*(byte *)((&DAT_800dfb60)[(ushort)param_1[1]] + 0x12) * 0xda] =
           (&DAT_800e18f8)[(uint)*(byte *)((&DAT_800dfb60)[(ushort)param_1[1]] + 0x12) * 0xda] |
           0x11;
      FUN_80083c14(param_1[2]);
      DAT_801317c4 = DAT_800e1110;
      DAT_800e1110 = DAT_800e1110 | 0xff000000;
      DAT_800e110c = DAT_800e110c | 0x40;
      *(undefined2 *)(DAT_800df944 + 4) = 0x8044;
      *(undefined2 *)(DAT_800df944 + 8) = 0x8044;
      *(undefined2 *)(DAT_800df944 + 0xc) = 0x80a8;
      *(undefined2 *)(DAT_800df944 + 0x10) = 0x80a8;
      *(undefined2 *)(DAT_800df944 + 6) = 0x8044;
      *(undefined2 *)(DAT_800df944 + 10) = 0x80a8;
      *(undefined2 *)(DAT_800df944 + 0xe) = 0x80a8;
      *(undefined2 *)(DAT_800df944 + 0x12) = 0x8044;
      DAT_800e861d = 0x23;
    }
    DAT_800e8924 = FUN_80074860;
  }
  else {
    uVar2 = 4;
LAB_80074838:
    FUN_8004ac04(0,0x100,uVar2,0xff000000);
  }
  return 0;
}
