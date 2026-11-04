/* FUN_800550ec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800550ec  body 0x800550ec..0x800551d3  size 232 B
 * body sha256 5a71a1087f04749094321f7268a032daf9952ef31501260d9f7c5ddddf377371
 * provider record sha256 c62850230422e5a4e012045f5edb3cec71cd70929208976e003e9e79329ff3ea
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800550ec(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_8010d940;
  if (param_1 != 0) {
    FUN_80077adc(0x2070000,0);
    DAT_800e860b = 1;
    while (iVar2 = FUN_80053844(0xc,10,0xfc,0x8b), iVar2 != 0) {
      FUN_8004cd88(1);
    }
  }
  DAT_800e8608 = 0;
  DAT_800e8609 = 0;
  DAT_800df934 = DAT_800df934 + -0x5320;
  FUN_80027148(*(undefined1 *)(iVar1 + 0x2dd));
  DAT_800e9182 = 2;
  DAT_8010bfa8 = DAT_8010bfa8 << 1;
  FUN_8004cec4(0);
  DAT_800e9182 = 2;
  FUN_8004cdd4();
  return;
}
