/* FUN_80164ff4
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x80164ff4  body 0x80164ff4..0x801656f7  size 148 B
 * body sha256 d4d57b3b4096cd26ca3045d4123734e6485f7981488bd50caf559e950036f888
 * provider record sha256 8e2895014776698bd810d7f222e396f0f6b8c40e871874b33140f0c03f62334f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164ff4(int param_1)

{
  uint uVar1;
  
  if ((*(byte *)(param_1 + 0x26f) & 0x7f) != 0) {
    uVar1 = (uint)*(byte *)(param_1 + 6);
    if ((3 < uVar1) || (uVar1 < 2)) goto LAB_8016504c;
    *(undefined1 *)(param_1 + 6) = 4;
  }
  uVar1 = (uint)*(byte *)(param_1 + 6);
LAB_8016504c:
  if (uVar1 < 9) {
                    /* WARNING: Could not emulate address calculation at 0x80165060 */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&PTR_LAB_801696b0)[uVar1])();
    return;
  }
  return;
}
