/* FUN_80058514
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80058514  body 0x80058514..0x8005857f  size 108 B
 * body sha256 5ac2e194c950818f2f41b5a2fdbffb4b139d9c7892bf2203f5e0c370eeb4b162
 * provider record sha256 e50e61fb94c59a5be8f378db9111385634912ccd50660fe5bae9ac4106fb8441
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8005850c::caseD_0(void)

{
  ushort uVar1;
  ushort uVar2;
  uint *unaff_s0;
  
  *(undefined1 *)((int)unaff_s0 + 7) = 1;
  *(undefined1 *)(unaff_s0 + 0x7a) = 6;
  if ((*(byte *)((int)unaff_s0 + 6) & 2) != 0) {
    *(undefined1 *)(unaff_s0 + 0x7a) = 7;
  }
  *(undefined1 *)((int)unaff_s0 + 0x1ea) = 7;
  *(undefined1 *)((int)unaff_s0 + 0x1e9) = 0;
  unaff_s0[0x7a] = 0x700;
  *(undefined2 *)(unaff_s0 + 0x78) = 0x32;
  DAT_800e110c = DAT_800e110c | 0x40;
  *unaff_s0 = *unaff_s0 | 4;
  FUN_80089d54();
  uVar1 = *(ushort *)((int)unaff_s0 + 0x66);
  if ((uVar1 & 0x200) == 0) {
    uVar2 = -(uVar1 >> 2 & 0xff);
  }
  else {
    uVar2 = uVar1 >> 2 & 0xff;
  }
  *(ushort *)((int)unaff_s0 + 0x66) = uVar1 + uVar2;
  if ((*(ushort *)((int)unaff_s0 + 0x66) & 0x3e0) == 0) {
    *(ushort *)((int)unaff_s0 + 0x66) = *(ushort *)((int)unaff_s0 + 0x66) & 0xff00;
    *(undefined1 *)((int)unaff_s0 + 7) = 2;
    if ((*(byte *)((int)unaff_s0 + 6) & 2) != 0) {
      *(undefined1 *)((int)unaff_s0 + 5) = 9;
      *(undefined1 *)((int)unaff_s0 + 7) = 0;
    }
  }
  return;
}
