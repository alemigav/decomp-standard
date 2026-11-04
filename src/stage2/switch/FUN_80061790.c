/* FUN_80061790
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80061790  body 0x80061790..0x80061a5b  size 716 B
 * body sha256 a0725e27934183cea6d9da72326c304885ef301fa49ee95c3928c2da9f6c9de9
 * provider record sha256 e604514ec07ec99067077b80816eb5fd5e9230f21c9a3702fc399fae63230a4c
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80061694::caseD_2(void)

{
  char cVar1;
  int iVar2;
  ushort uVar3;
  ushort uVar4;
  int unaff_s0;
  uint unaff_s2;
  
  uVar4 = *(ushort *)(unaff_s0 + 0x1aa) & 0xfff;
  if (uVar4 == 0xf) {
    if ((uint)*(byte *)(unaff_s0 + 0x1e9) % 3 == 0) {
      iVar2 = FUN_8008cea0(0xf,0);
      goto joined_r0x800617f8;
    }
LAB_80061800:
    DAT_800e112a = DAT_800e112a | 1;
    FUN_8005ab48();
    FUN_80089d54();
    (*(code *)(&PTR_FUN_80111078)[(*(ushort *)(unaff_s0 + 0x1aa) & 0xfff) - 1])();
    if ((unaff_s2 & 0x100) == 0) {
      *(undefined2 *)(unaff_s0 + 6) = 0x300;
      return;
    }
    if ((((unaff_s2 & 0x10) == 0) && (DAT_800df8c1 < '\x1a')) ||
       ((*(ushort *)(unaff_s0 + 0x1f0) & 0x8000) != 0)) {
      if ((((unaff_s2 & 0x20) == 0) && (-0x1a < DAT_800df8c1)) ||
         ((*(ushort *)(unaff_s0 + 0x1f0) & 0x2000) != 0)) {
        if ((((unaff_s2 & 0x30) == 0) && (DAT_800df8c1 < '\x1a')) &&
           ((-0x1a < DAT_800df8c1 && ((*(ushort *)(unaff_s0 + 0x1f0) & 0x4000) == 0)))) {
          *(undefined1 *)(unaff_s0 + 7) = 1;
          *(ushort *)(unaff_s0 + 0x1f0) = *(ushort *)(unaff_s0 + 0x1f0) & 0x1fff | 0x4000;
          if ((*(ushort *)(unaff_s0 + 0x1aa) & 0xfff) == 0x10) {
            FUN_80077adc(0x10d0001,unaff_s0 + 0x28);
            return;
          }
          return;
        }
        if ((unaff_s2 & 0x40) != 0) {
          if (((*(short *)(unaff_s0 + 0x1a8) != 0) &&
              (*(short *)(unaff_s0 + 0x1a8) < *(short *)(unaff_s0 + 0x25e))) &&
             ((*(byte *)(unaff_s0 + 0x1e9) & 3) == 0)) {
            FUN_8005c3e8();
          }
          cVar1 = DAT_800df8c0;
          if (((unaff_s2 & 8) != 0) || (DAT_800df8c0 < -0x19)) {
            *(short *)(unaff_s0 + 0x66) = *(short *)(unaff_s0 + 0x66) + -0x20;
          }
          if (((unaff_s2 & 2) == 0) && (cVar1 < '\x1a')) {
            return;
          }
          *(short *)(unaff_s0 + 0x66) = *(short *)(unaff_s0 + 0x66) + 0x20;
          return;
        }
        goto LAB_80061a18;
      }
      *(undefined1 *)(unaff_s0 + 7) = 1;
      uVar4 = *(ushort *)(unaff_s0 + 0x1aa);
      uVar3 = *(ushort *)(unaff_s0 + 0x1f0) & 0x1fff | 0x2000;
    }
    else {
      *(undefined1 *)(unaff_s0 + 7) = 1;
      uVar4 = *(ushort *)(unaff_s0 + 0x1aa);
      uVar3 = *(ushort *)(unaff_s0 + 0x1f0) & 0x1fff | 0x8000;
    }
    *(ushort *)(unaff_s0 + 0x1f0) = uVar3;
    if ((uVar4 & 0xfff) == 0x10) {
      FUN_80077adc(0x10d0001,unaff_s0 + 0x28);
      FUN_80052bd0(4,0);
      FUN_80052c6c(5,0xfa,0);
    }
  }
  else {
    iVar2 = FUN_8008cea0(uVar4,0);
joined_r0x800617f8:
    if (iVar2 != 0) goto LAB_80061800;
LAB_80061a18:
    *(undefined1 *)(unaff_s0 + 7) = 3;
  }
  return;
}
