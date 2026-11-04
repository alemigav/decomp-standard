/* FUN_8006e9f4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e9f4  body 0x8006e9f4..0x8006ea2f  size 60 B
 * body sha256 8283a3bee3a0427b3719f015a71336ede8b2527dbe1af3b57b32afd9b8366f99
 * provider record sha256 e7e402cc490281320ec427a2d117c4c10a4e2c0b3bf446e2cc4f05356c6ed910
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8006e9c4::caseD_3(short param_1)

{
  undefined2 uVar1;
  int unaff_s0;
  undefined2 *unaff_s1;
  
  if (unaff_s0 == 0) {
    trap(0x1c00);
  }
  if ((unaff_s0 == -1) && (param_1 == -0x80000000)) {
    trap(0x1800);
  }
  uVar1 = FUN_800844cc((int)(short)((int)param_1 / unaff_s0));
  *unaff_s1 = uVar1;
  DAT_80115120 = 0;
  return;
}
