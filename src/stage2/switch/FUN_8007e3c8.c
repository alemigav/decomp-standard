/* FUN_8007e3c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007e3c8  body 0x8007e3c8..0x8007e447  size 128 B
 * body sha256 14f0047d6e25d79bab8868e3ecc52215c8c6ca1d52aef8379d8ec91e99960657
 * provider record sha256 1838f6a7efe7acfcac2c9aaa8f2acc75f3aed05644ba1035f4eccb8b406fb85d
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8007e304::caseD_3(void)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  int unaff_s0;
  undefined4 uStack00000010;
  
  FUN_800334c8();
  iVar3 = FUN_80089d54();
  if (iVar3 != 0) {
    *(undefined1 *)(unaff_s0 + 6) = 4;
    sVar2 = *(short *)(unaff_s0 + 0x1f6);
    bVar1 = *(byte *)((int)&uStack00000010 + (int)*(char *)(unaff_s0 + 0x206));
    *(short *)(unaff_s0 + 0x1f6) = sVar2 + -1;
    *(uint *)(unaff_s0 + 0x1e8) = (bVar1 + 1) * 0x1000000;
    if (sVar2 == 1) {
      *(undefined1 *)(unaff_s0 + 6) = 5;
      *(uint *)(unaff_s0 + 0x1e8) =
           (*(byte *)((int)&uStack00000010 + (int)*(char *)(unaff_s0 + 0x206)) + 2) * 0x1000000;
    }
  }
  FUN_80032bd8();
  if ((**(uint **)(unaff_s0 + 0x214) & 0x4000) != 0) {
    FUN_80077f30(1,((**(uint **)(unaff_s0 + 0x214) & 0x2000) >> 0xd) * 3 + 4);
    DAT_800e112a = DAT_800e112a | 4;
  }
  return;
}
