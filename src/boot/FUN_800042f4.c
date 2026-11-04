/* FUN_800042f4
 * image   boot (boot), base 0x80000480
 * address 0x800042f4  body 0x800042f4..0x8000436f  size 124 B
 * body sha256 cff06dd8f78846eaa960f65e553fea2d0ee469204aae30c81302ba95405daf1c
 * provider record sha256 7e270632b5e04046caf65c0d25e99401dd867592e3494c6f0138bd95569dd984
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800042f4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while (param_1 != 0) {
    iVar1 = *(int *)(param_1 + -4);
    *(int *)(param_1 + -4) = iVar2;
    iVar2 = param_1;
    param_1 = iVar1;
  }
  while (iVar2 != 0) {
    iVar2 = *(int *)(iVar2 + -4);
    (**(code **)(param_2 + 0x24))(*(undefined4 *)(param_2 + 0x28));
  }
  return 0;
}
