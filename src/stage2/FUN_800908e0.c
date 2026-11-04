/* FUN_800908e0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800908e0  body 0x800908e0..0x80090a8b  size 428 B
 * body sha256 62fad1b45f34f198ee3eccba9372f6620f07ed8a1eb7982d7606361a560897c3
 * provider record sha256 4c83c448483fc677e53b116e18816bb51696cf47f6e8e805b9ab3488d6a28eb0
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800908e0(void)

{
  char cVar1;
  char cVar3;
  int iVar2;
  int unaff_s0;
  int unaff_s2;
  
  cVar1 = *(char *)(unaff_s0 + 0x1a);
  if (*(char *)(unaff_s0 + 0x29) == '\0') {
    if (0x50 < *(byte *)(unaff_s0 + 0x28)) {
      *(undefined1 *)(unaff_s0 + 0x29) = 1;
    }
    cVar3 = *(char *)(unaff_s0 + 0x28) + '\x04';
  }
  else {
    if (*(byte *)(unaff_s0 + 0x28) < 10) {
      *(undefined1 *)(unaff_s0 + 0x29) = 0;
    }
    cVar3 = *(char *)(unaff_s0 + 0x28) + -4;
  }
  *(char *)(unaff_s0 + 0x28) = cVar3;
  if ((DAT_800e10ec < 0) && (1 < *(byte *)(unaff_s0 + 0x1a))) {
    if (((*(ushort *)(unaff_s2 + 0x1825c) & 0x1000) != 0) &&
       ((1 < (byte)(&DAT_8012f970)[*(byte *)(unaff_s0 + 0x1a)] &&
        (iVar2 = FUN_800837ac(&DAT_800e8d94,(&DAT_8012f970)[*(byte *)(unaff_s0 + 0x1a)]), iVar2 != 0
        )))) {
      *(undefined *)(unaff_s0 + 0x1a) = (&DAT_8012f970)[*(byte *)(unaff_s0 + 0x1a)];
    }
    if ((((*(ushort *)(unaff_s2 + 0x1825c) & 0x4000) != 0) &&
        (1 < (byte)(&LAB_8012f988)[*(byte *)(unaff_s0 + 0x1a)])) &&
       (iVar2 = FUN_800837ac(&DAT_800e8d94,(&LAB_8012f988)[*(byte *)(unaff_s0 + 0x1a)]), iVar2 != 0)
       ) {
      *(undefined1 *)(unaff_s0 + 0x1a) = (&LAB_8012f988)[*(byte *)(unaff_s0 + 0x1a)];
    }
    if (cVar1 != *(char *)(unaff_s0 + 0x1a)) {
      *(undefined1 *)(unaff_s0 + 2) = 4;
      FUN_80077adc(0x4040000,0);
    }
  }
  if ((*(uint *)(unaff_s2 + 0x18268) & 0x2000) != 0) {
    *(undefined1 *)(unaff_s0 + 2) = 2;
    FUN_80077adc(0x4050000,0);
    FUN_8006c070(_DAT_8013a388);
  }
  if (*(char *)(unaff_s0 + 2) == '\x03') {
    FUN_8009109c();
  }
  FUN_80097fd0();
  return;
}
