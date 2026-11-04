/* FUN_80058e60
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80058e60  body 0x80058e60..0x80058e8b  size 44 B
 * body sha256 0ba422759030b9b364502dcb14135037ff2a84aef05dc54029991f03107e35fb
 * provider record sha256 4a650951c72d2c872c4bd8b9cc6a7a536354a6bb5f1c1c0700296da77d69d7ea
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80058e58::caseD_0(void)

{
  ushort uVar1;
  ushort uVar2;
  int unaff_s0;
  
  *(undefined1 *)(unaff_s0 + 6) = 1;
  *(int *)(unaff_s0 + 0x1e8) =
       *(short *)(&DAT_8010dca0 + *(char *)(unaff_s0 + 0x1ed) * 2) * 0x1000000 + 0x700;
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
