/* FUN_8018277c
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8018277c  body 0x8018277c..0x801827f7  size 124 B
 * body sha256 b858ad7ec9f8733ab1ac8d968041d0570b42cb067c0a2cb1d2ef796ae0a1ad36
 * provider record sha256 e538cfcce75ae1cec53cbe617608e3a320d4b56938f773194e530aee8e6eb799
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8018277c(undefined1 *param_1,undefined1 *param_2,int param_3,int param_4)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  iVar2 = 0;
  if (0 < param_4) {
    puVar4 = param_2 + 7;
    puVar3 = param_1 + 7;
    do {
      *param_2 = *param_1;
      puVar4[-6] = puVar3[-6];
      puVar4[-5] = puVar3[-5];
      puVar4[-4] = puVar3[-4];
      param_1 = param_1 + param_3;
      puVar4[-3] = puVar3[-3];
      iVar2 = iVar2 + 1;
      puVar4[-2] = puVar3[-2];
      param_2 = param_2 + param_3;
      puVar4[-1] = puVar3[-1];
      uVar1 = *puVar3;
      puVar3 = puVar3 + param_3;
      *puVar4 = uVar1;
      puVar4 = puVar4 + param_3;
    } while (iVar2 < param_4);
  }
  return;
}
