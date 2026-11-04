/* FUN_8006171c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006171c  body 0x8006171c..0x8006178f  size 116 B
 * body sha256 071e34ade25a409c0454b0ab61a2274a0593d64f0e868a9be100fbcfbaa5c860
 * provider record sha256 37f2e8f20f23415421b96e3d61241ba768cb04309b97ea2b3eec2165d3f32d82
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80061694::caseD_1(void)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  ushort uVar4;
  ushort uVar5;
  int unaff_s0;
  uint unaff_s2;
  undefined1 uStack00000011;
  
  uVar1 = (&uStack00000011)[(uint)(*(ushort *)(unaff_s0 + 0x1f0) >> 0xd) * 2];
  *(undefined1 *)(unaff_s0 + 0x1ea) = 7;
  *(undefined1 *)(unaff_s0 + 0x1e8) = uVar1;
  FUN_8005ab10();
  *(undefined1 *)(unaff_s0 + 7) = 2;
  *(undefined1 *)(unaff_s0 + 0x207) = 9;
  uVar5 = *(ushort *)(unaff_s0 + 0x1aa) & 0xfff;
  if (uVar5 == 0xf) {
    if ((uint)*(byte *)(unaff_s0 + 0x1e9) % 3 == 0) {
      iVar3 = FUN_8008cea0(0xf,0);
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
          cVar2 = DAT_800df8c0;
          if (((unaff_s2 & 8) != 0) || (DAT_800df8c0 < -0x19)) {
            *(short *)(unaff_s0 + 0x66) = *(short *)(unaff_s0 + 0x66) + -0x20;
          }
          if (((unaff_s2 & 2) == 0) && (cVar2 < '\x1a')) {
            return;
          }
          *(short *)(unaff_s0 + 0x66) = *(short *)(unaff_s0 + 0x66) + 0x20;
          return;
        }
        goto LAB_80061a18;
      }
      *(undefined1 *)(unaff_s0 + 7) = 1;
      uVar5 = *(ushort *)(unaff_s0 + 0x1aa);
      uVar4 = *(ushort *)(unaff_s0 + 0x1f0) & 0x1fff | 0x2000;
    }
    else {
      *(undefined1 *)(unaff_s0 + 7) = 1;
      uVar5 = *(ushort *)(unaff_s0 + 0x1aa);
      uVar4 = *(ushort *)(unaff_s0 + 0x1f0) & 0x1fff | 0x8000;
    }
    *(ushort *)(unaff_s0 + 0x1f0) = uVar4;
    if ((uVar5 & 0xfff) == 0x10) {
      FUN_80077adc(0x10d0001,unaff_s0 + 0x28);
      FUN_80052bd0(4,0);
      FUN_80052c6c(5,0xfa,0);
    }
  }
  else {
    iVar3 = FUN_8008cea0(uVar5,0);
joined_r0x800617f8:
    if (iVar3 != 0) goto LAB_80061800;
LAB_80061a18:
    *(undefined1 *)(unaff_s0 + 7) = 3;
  }
  return;
}
