/* FUN_8006169c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006169c  body 0x8006169c..0x8006171b  size 128 B
 * body sha256 2e4d86b5ba63dad14d8633c95ffd50b9117114a8471b55fd421e113aee0ad9ae
 * provider record sha256 2e7aadef78d160c6c09c15674740dac58fb2fb569d30adf1021205aebe2ca38b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80061694::caseD_0(void)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  ushort uVar4;
  ushort uVar5;
  int unaff_s0;
  uint unaff_s2;
  undefined4 uStack00000010;
  
  *(int *)(unaff_s0 + 0x1e8) =
       *(short *)((int)&uStack00000010 + (uint)(*(ushort *)(unaff_s0 + 0x1f0) >> 0xd) * 2) *
       0x1000000 + 0x700;
  (*(code *)(&PTR_LAB_8011102c)[(*(ushort *)(unaff_s0 + 0x1aa) & 0xfff) - 1])();
  FUN_80052d10(10,0,(&DAT_80110f6e)[((*(ushort *)(unaff_s0 + 0x1aa) & 0xfff) - 2) * 6],0);
  uVar1 = ((undefined1 *)((int)register0x00000074 + 0x11))
          [(uint)(*(ushort *)(unaff_s0 + 0x1f0) >> 0xd) * 2];
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
