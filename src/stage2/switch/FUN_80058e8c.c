/* FUN_80058e8c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80058e8c  body 0x80058e8c..0x80058f37  size 172 B
 * body sha256 f8b1aac26a9f785b02db5d18063c336daec22a197ff29d136d25f9ae09205ec2
 * provider record sha256 c38353d2c82b5fcbae334a62e957106595c9aad4f0e20e5b9b572da6f2942a23
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80058e58::caseD_1(void)

{
  ushort uVar1;
  ushort uVar2;
  int unaff_s0;
  
  if ((**(uint **)(unaff_s0 + 0x214) & 0x4000) != 0) {
    FUN_80077f30(1,((**(uint **)(unaff_s0 + 0x214) & 0x2000) >> 0xd) * 3 + 4);
    DAT_800e112a = DAT_800e112a | 4;
  }
  FUN_80089d54();
  uVar1 = *(ushort *)(unaff_s0 + 0x66);
  if ((uVar1 & 0x200) == 0) {
    uVar2 = -(uVar1 >> 2 & 0xff);
  }
  else {
    uVar2 = uVar1 >> 2 & 0xff;
  }
  *(ushort *)(unaff_s0 + 0x66) = uVar1 + uVar2;
  if ((*(ushort *)(unaff_s0 + 0x66) & 0x3e0) == 0) {
    *(ushort *)(unaff_s0 + 0x66) = *(ushort *)(unaff_s0 + 0x66) & 0xff00;
    *(undefined1 *)(unaff_s0 + 6) = 2;
  }
  return;
}
