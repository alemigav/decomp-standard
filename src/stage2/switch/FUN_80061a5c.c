/* FUN_80061a5c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80061a5c  body 0x80061a5c..0x80061a83  size 40 B
 * body sha256 fe01ec566f25a20eb7fd6c271f042a18db87b76cc55031f406519159bc0c6f40
 * provider record sha256 87f74f36496a77b97819d0206b8ec3e8466b929037141012b27ed05d16df25d4
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80061694::caseD_3(void)

{
  short sVar1;
  char cVar3;
  int iVar2;
  int unaff_s0;
  uint unaff_s2;
  undefined4 uStack00000020;
  
  sVar1 = *(short *)((int)&uStack00000020 + (uint)(*(ushort *)(unaff_s0 + 0x1f0) >> 0xd) * 2);
  *(undefined1 *)(unaff_s0 + 7) = 4;
  *(int *)(unaff_s0 + 0x1e8) = sVar1 * 0x1000000 + 0x700;
  cVar3 = FUN_80089d54();
  *(char *)(unaff_s0 + 7) = *(char *)(unaff_s0 + 7) + cVar3;
  if ((unaff_s2 & 0x40) != 0) {
    iVar2 = FUN_8008cce4(*(ushort *)(unaff_s0 + 0x1aa) & 0xfff);
    if (iVar2 != 0) {
      *(undefined2 *)(unaff_s0 + 6) = 0x201;
      return;
    }
    if ((DAT_800df918 & 0x40) != 0) {
      cVar3 = FUN_8008d00c();
      if (cVar3 == '\0') {
        FUN_80077adc(0x1010001,unaff_s0 + 0x28);
      }
      else {
        *(undefined2 *)(unaff_s0 + 6) = 0x400;
      }
    }
  }
  cVar3 = DAT_800df8c0;
  if (((unaff_s2 & 8) != 0) || (DAT_800df8c0 < -0x19)) {
    *(short *)(unaff_s0 + 0x66) = *(short *)(unaff_s0 + 0x66) + -0x20;
  }
  if (((unaff_s2 & 2) != 0) || ('\x19' < cVar3)) {
    *(short *)(unaff_s0 + 0x66) = *(short *)(unaff_s0 + 0x66) + 0x20;
  }
  return;
}
